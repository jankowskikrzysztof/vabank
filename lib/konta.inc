<?php

echo "
<center><br><table border=1 style='border-collapse: collapse' cellpadding='10'>
<tr bgcolor=#ffffcc><td>"; // tabelka dla zmian akcji

include('config.inc');

  
  $db = mysql_connect("$mysql_address","$mysql_login","$mysql_passwd");

  if (! mysql_select_db("$mysql_db"))
    echo 'nie moge wybrac bazy Banku';


	
	if ($akcja > "")			// warunki przy akcji
		   {
			$kogo_robimy = substr($akcja,1);	
			$co_robimy = substr($akcja,0,1);


						/* spis akcji
												
							p = przydziel konto
							d = debet na konto
							b = blokady na konto
							u = odblokowuje konto
							d = kasuje konto
							t = tworzy nowe konta
							r = promocja
						*/

		  if ($co_robimy == p)		// opcja przydziel
			{
			include('konto_przydziel.inc');
			};

			
		  if ($co_robimy == k)		// opcja debetu
			{
			include('konto_debet.inc');
			};

	
			
		  if ($co_robimy == b) 		// zaklada blokade na konto
			{
			$block = "UPDATE konta SET blokada=1 WHERE aid=$kogo_robimy";
			mysql_query($block);
			$co_robimy_txt = "<font color=red>zablokowany</font>"; 
			};
			// koniec "zaklada blokade na konto"
			
	
		  if ($co_robimy == u) 		// odblokowuje konto
			{
			$unblock = "UPDATE konta SET blokada=0 WHERE aid=$kogo_robimy";
			mysql_query($unblock);
			$co_robimy_txt = "<font color=green>odblokowany</font>"; 
			};
			// koniec "odblokowuje konto"
			
			
		  if ($co_robimy == d)		// kasuje konto
			{
			$usuwanie = "DELETE FROM konta WHERE aid=$kogo_robimy";
			mysql_query($usuwanie);
			$co_robimy_txt = "<font color=red><b>skasowany</b></font>"; 
			};
			// koniec "kasuje konto"
	
		  if ($co_robimy == t) // tworzenie nowych pustych kont bankowych
			{
			include('konto_dodaj.inc');
			};

		  if ($co_robimy == r)		// promocja
			{
			include('konto_promocja.inc');
			};
			
			// koniec "tworzenie nowych pustych kont bankowych"
			
		$status = "Konto numer $kogo_robimy zostala $co_robimy_txt ";
		
		};
	if (!$akcja ) 					// jezeli brak akcji, wtedy menu
		{
		echo "dostepne opcje: [<a href=admin.php?o=konta&akcja=t>nowe konta bankowe</a>] [<a href=admin.php?o=konta&akcja=r>wyszukaj do promocji</a>]";
		};
	// koniec warunkow przy akcji
		
	
echo "</td></tr></table><br><br></center>"; // koniec tabelki dla "akcji"	
	
	
	if ( $orderby > "")			// warunek do sortowania, jezeli get orderby dostal zmienna
	{ $order = "ORDER BY $orderby"; }
	else
	{ $order = "ORDER BY konta.aid"; }
	 ;
	// koniec

  $zapytanie = "SELECT konta.*, users.uid, users.imie, users.nazwisko FROM `konta` left join `users` on konta.uid=users.uid $order";

  $lista = mysql_query($zapytanie);
  
  
  echo "<center><table border=1 bordercolor=black cellpadding='4' style='border-collapse: collapse'>
		<tr class=naglowek>
			<td width=3><a href=admin.php?o=pass_list&orderby=pass_list.pid>ID</a></td>
			<td>komu przydzielone<br>[uid, imie, nazwisko]</td>
			<td><a href=admin.php?o=konta&orderby=numer>Numer konta</a></td>
			<td>Saldo</td>
			<td><a href=admin.php?o=konta&orderby=debet>Limit debetowy</a></td>
			<td><a href=admin.php?o=konta&orderby=dataczas>Data<br>zalozenia</a></td>
			<td width=30><a href=admin.php?o=konta&orderby=blokada>Status</a></td>
			<td width=30>Opcje</td>
		</tr>
			";
  
  
   while ($A = mysql_fetch_array($lista))
		{
		
			// zamienia date z mysql na czytelna
				$rok = substr($A[dataczas], 0, 4);
				$miesiac = substr($A[dataczas], 5, 2);
				$dzien = substr($A[dataczas], 8, 2);
				$godzina = substr($A[dataczas], 11, 2);
				$minuta = substr($A[dataczas], 14, 2);
			// koniec zamiany daty z mysql
		
		
		
			if ($A[blokada] == 1)		// warunek ktory pokazuje status konta
				{
				$blokada = "<font color=red>blokada</font>";
				$background = " bgcolor=#ff9f9f";
				}
			elseif ($A[blokada] == 0)
				{
				$blokada = "<font color=green>aktywne</font>";
				$background = " bgcolor=#ccff99";
				}
			elseif ($A[blokada] == 2)
				{
				$blokada = "<font color=blue>zuzyta</font>";
				$background = " bgcolor=#a8a8ff";
				}
			// koniec warunku pokazujacego status
		
		
			if ($A[used] == 0)			// jezeli konto nie bylo uzywana wpisuje nowe
				{
				$used = "<font color=green>nowe</font>";
				}
				else $used = $A[used];
			// koniec jezeli konto nie byla uzywane
		
			if ($A[uid] == 0)			// jezeli konto nie jest przydzielone do uzytkownika
				{
				$uid = "<font color=grey>nie przydzielone</font>";
				}
				else $uid = $A[uid];
			// koniec jezeli konto nie jest przydzielone do uzytkownika


			include('saldo.inc'); //biblioteka dla sadla, wynikiem jest zmienna $saldo i $s_wplaty i $s_wyplaty

		
		
							// zmienna $A[0] oznacza pierwsze pole w ladowanej tabeli, w tym wypadku aid
													
			echo "<tr$background>		
					  <td>$A[aid]</td>
					  <td>$uid<br>$A[imie]<br>$A[nazwisko]</td>
					  <td align=center>$A[numer]</td>
					  <td align=right>$saldo</td>
					  <td align=right>$A[debet]</td>
					  <td>$dzien-$miesiac-$rok<br>$godzina:$minuta</td>					  
					  <td>$blokada</td>
				<td bgcolor=#ffffcc>
				";
			if ($A[blokada] == 1 || $A[blokada] == 0 ) // jezeli haslo nie jest zurzyte, wtedy mozna blokowac, odblokowywac i podgladac
				{

				// print "<a href=admin.php?o=konta&akcja=v$A[0]>podglad</a><br>"; //moze sie przydac pozniej koncie, przy przegladaniu histori
				
				if ($A[uid] == 0 and $A[blokada] == 0 ) // jezeli haslo nie jest przydzielone i nie jest zalozona na niego blokada, ani nie jest zurzyte, wtedy mozna je przydzielic
				echo "<a href=admin.php?o=konta&akcja=p$A[0]>przydziel</a><br>";
		
				if ($A[uid] <> 0 and $A[blokada] == 0 ) // jezeli konto jest niezablokowane i przydzielone, mozna ustanowic debet i promocje
				{
				echo "<a href=admin.php?o=konta&akcja=k$A[0]>debet</a><br>";
				echo "<a href=admin.php?o=konta&akcja=r$A[0]>promocja</a><br>";
				};
				
				if ($A[blokada] == 0 )
				echo "<a href=admin.php?o=konta&akcja=b$A[0]>blokowanie</a><br>";
				if ($A[blokada] == 1 )
				echo "<a href=admin.php?o=konta&akcja=u$A[0]>odblokowanie</a><br>";
				};
				print "
				<a href=admin.php?o=konta&akcja=d$A[0]>usuniecie</a>
				</td></tr>\r";	
	  
		} // koniec while ($A = mysql_fetch_array($lista))
  
  echo "</table></center>";


  mysql_close($db);

?>