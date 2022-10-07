<?php
include('config.inc');


echo "
<center><br><table border=1 style='border-collapse: collapse' cellpadding='10'>
<tr bgcolor=#ffffcc><td>"; // tabelka dla zmian akcji

  
  $db = mysql_connect("$mysql_address","$mysql_login","$mysql_passwd");

  if (! mysql_select_db("$mysql_db"))
    echo 'nie moge wybrac bazy Banku';

	// warunki przy zmianie statusu przegladaniu
	if ($akcja > "")
	 {
	$kogo_robimy = substr($akcja,1);	
	$co_robimy = substr($akcja,0,1);

		// opcja przydziel
	  if ($co_robimy == p)
		{
		include('pass_list_przydziel.inc');
		};
		// koniec "opcja przydziel"

		// pokazuje liste hasel jednorazowych w liscie
		if ($co_robimy == v)
		{
		$zapytanie = "SELECT * FROM pass_list WHERE pid=$kogo_robimy";
		$lista = mysql_query($zapytanie);
		$A = mysql_fetch_array($lista);
		
		for($i=1;$A[used] >= $i; $i++)
			{ $bg[$i] = " bgcolor=#ff9f9f"; }
			
			for ($j=$i; 20 >= $j; $j++)
			{ $bg[$j] = " bgcolor=#ccff99"; }

		
		echo "<center><table border=1 bordercolor=black cellpadding='4' style='border-collapse: collapse' bgcolor=white>
		<tr class=naglowek><td colspan=4> lista hasel numer: $kogo_robimy</td></tr>
		<tr><td$bg[1]>01: $A[1]</td><td$bg[6]>06: $A[6]</td><td$bg[11]>11: $A[11]</td><td$bg[16]>16: $A[16]</td></tr>
		<tr><td$bg[2]>02: $A[2]</td><td$bg[7]>07: $A[7]</td><td$bg[12]>12: $A[12]</td><td$bg[17]>17: $A[17]</td></tr>
		<tr><td$bg[3]>03: $A[3]</td><td$bg[8]>08: $A[8]</td><td$bg[13]>13: $A[13]</td><td$bg[18]>18: $A[18]</td></tr>
		<tr><td$bg[4]>04: $A[4]</td><td$bg[9]>09: $A[9]</td><td$bg[14]>14: $A[14]</td><td$bg[19]>19: $A[19]</td></tr>
		<tr><td$bg[5]>05: $A[5]</td><td$bg[10]>10: $A[10]</td><td$bg[15]>15: $A[15]</td><td$bg[20]>20: $A[20]</td></tr>
		</table></center><br>";
		$co_robimy_txt = "zaladowana"; 
		};
		// koniec "pokazuje liste hasel jednorazowych w liscie"

		// zaklada blokade na liste hasel
	  if ($co_robimy == b)
		{
		$block = "UPDATE pass_list SET blokada=1 WHERE pid=$kogo_robimy";
		mysql_query($block);
		$co_robimy_txt = "<font color=red>zablokowany</font>"; 
		};
		// koniec "zaklada blokade na liste hasel"
		
		// odblokowuje liste hasel
	  if ($co_robimy == u)
		{
		$unblock = "UPDATE pass_list SET blokada=0 WHERE pid=$kogo_robimy";
		mysql_query($unblock);
		$co_robimy_txt = "<font color=green>odblokowany</font>"; 
		};
		// koniec "odblokowuje liste hasel"
		
		// kasuje liste hasel
	  if ($co_robimy == d)
		{
		$usuwanie = "DELETE FROM pass_list WHERE pid=$kogo_robimy";
		mysql_query($usuwanie);
		$co_robimy_txt = "<font color=red><b>skasowany</b></font>"; 
		}
		// koniec "kasuje liste hasel"
		
	  $status = "Lista hasel jednorazowych numer $kogo_robimy zostala $co_robimy_txt ";
	 } 
	else
		{
		echo "<center>";
		echo "Tworz listy hasel<br>
		<form method=post action=admin.php?o=pass_list>
		podaj ile list hasel chcesz wygenerowac<br><br>
		<input type=text name=ile size=5>  <input type=submit value=Stworz>
		</form>
		";
		include('pass_list_dodaj.inc');
		echo "</center>";
		};
	 // koniec warunkow przy zmianie statusu uzytkownika

echo "</td></tr></table><br><br></center>"; // koniec tabelki dla "akcji"
	
	
	// warunek do sortowania, jezeli get orderby dostal zmienna
	if ( $orderby > "")
	{ $order = "ORDER BY $orderby"; }
	else
	{ $order = "ORDER BY pass_list.pid"; }
	 ;
	// koniec

  $zapytanie = "SELECT pass_list.*, users.uid, users.imie, users.nazwisko, users.pid FROM `pass_list` left join `users` on pass_list.pid=users.pid $order";

  $lista = mysql_query($zapytanie);
  
  echo "<center><table border=1 bordercolor=black cellpadding='4' style='border-collapse: collapse'>
		<tr class=naglowek>
			<td width=3><a href=admin.php?o=pass_list&orderby=pass_list.pid>ID</a></td>
			<td>komu przydzielone [uid, imie, nazwisko]</td>
			<td><a href=admin.php?o=pass_list&orderby=used>Ostatnio uzywane haslo</a></td>
			<td width=30><a href=admin.php?o=pass_list&orderby=blokada>Status</a></td>
			<td width=30>Opcje</td>
		</tr>
			";
  
  
   while ($A = mysql_fetch_array($lista))
  {

	// warunek ktory pokazuje status listy hasel
	if ($A[blokada] == 1)
		{
		$blokada = "<font color=red>blokada</font>";
		$background = " bgcolor=#ff9f9f";
		}
	elseif ($A[blokada] == 0)
		{
		$blokada = "<font color=green>aktywne</font>";
		$background = " bgcolor=#ccff99";
		}
	// koniec warunku pokazujacego status

	// jezeli karta nie byla uzywana wpisuje nowa, sprawdza czy karta nie jest zuzyta
	if ($A[used] == 0)
		{
		$used = "<font color=green>nowa</font>";
		}
	elseif ($A[used] == 20)
		{
		$blokada = "<font color=blue>zuzyta</font>";
		$background = " bgcolor=#a8a8ff";
		$used = "<font color=green>zuzyta</font>";
		}
		else $used = $A[used];
	// koniec jezeli karta nie byla uzywana

	// jezeli karta nie jest przydzielona do uzytkownika
	if ($A[uid] == 0)
		{
		$uid = "<font color=grey>nie przydzielona</font>";
		}
		else $uid = $A[uid];
	// koniec jezeli karta nie jest przydzielona do uzytkownika


	// zmienna $A[0] oznacza pierwsze pole w ladowanej tabeli, w tym wypadku pid
	echo "<tr$background>
			  <td>$A[0]</td>
			  <td>$uid $A[imie] $A[nazwisko]</td>
			  <td align=center>$used</td>
			  <td>$blokada</td>
		<td bgcolor=#ffffcc>
		";
	if ($A[blokada] == 1 || $A[blokada] == 0 and $A[used] <> 20) // jezeli haslo nie jest zuzyte, wtedy mozna blokowac, odblokowywac i podgladac
		{
		print "
		<a href=admin.php?o=pass_list&akcja=v$A[0]>podglad</a><br>";
		
		if ($A[uid] == 0 and $A[blokada] == 0 ) // jezeli haslo nie jest przydzielone i nie jest zalozona na niego blokada, ani nie jest zurzyte, wtedy mozna je przydzielic
		echo "<a href=admin.php?o=pass_list&akcja=p$A[0]>przydziel</a><br>";
		
		if ( $A[blokada] == 0 )
		echo "<a href=admin.php?o=pass_list&akcja=b$A[0]>blokowanie</a><br>";
		if ( $A[blokada] == 1 )
		echo "<a href=admin.php?o=pass_list&akcja=u$A[0]>odblokowanie</a><br>";
		};
		print "
		<a href=admin.php?o=pass_list&akcja=d$A[0]>usuniecie</a>
		</td></tr>\r";
  
  }
  
  echo "</table></center>";


  mysql_close($db);

?>
