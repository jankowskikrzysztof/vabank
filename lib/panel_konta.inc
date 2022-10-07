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
												
							p = przelew
									d = debet na konto
									b = blokady na konto
									u = odblokowuje konto
									d = kasuje konto
									t = tworzy nowe konta
									r = promocja
							z = zamykanie konta
						*/

		  if ($co_robimy == p)		// przelew
			{
			include('konto_przelew.inc');
			};
			
		  if ($co_robimy == z)		// zamykanie konta
			{
			$usuwanie = "DELETE FROM konta WHERE aid=$kogo_robimy";
			mysql_query($usuwanie);
			$co_robimy_txt = "<font color=red><b>skasowany</b></font>"; 
			}; // koniec "zamykanie konta"
			
			}
			
	if (!$akcja ) 					// jezeli brak akcji, wtedy menu
		{
		echo "Lista kont bankowych";
		// echo "dostepne opcje: [] []";
		};
	// koniec warunkow przy akcji
		
	
echo "</td></tr></table><br><br></center>"; // koniec tabelki dla "akcji"	


	if ( $orderby > "")			// warunek do sortowania, jezeli get orderby dostal zmienna
	{ $order = "ORDER BY $orderby"; }
	else
	{ $order = "ORDER BY konta.aid"; }
	 ;
	// koniec


  $zapytanie = "SELECT konta.*, users.uid, users.imie, users.nazwisko FROM `konta`, `users` WHERE konta.uid=$u and konta.uid=users.uid $order";

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
			// koniec warunku pokazujacego status
		


			include('saldo.inc'); //biblioteka dla sadla, wynikiem jest zmienna $saldo i $s_wplaty i $s_wyplaty

		
		
							// zmienna $A[0] oznacza pierwsze pole w ladowanej tabeli, w tym wypadku aid
													
			echo "<tr$background>		
					  <td>$A[aid]</td>
					  <td>$A[uid], $A[imie],<br>$A[nazwisko]</td>
					  <td align=center>$A[numer]</td>
					  <td align=right>$saldo</td>
					  <td align=right>$A[debet]</td>
					  <td>$dzien-$miesiac-$rok<br>$godzina:$minuta</td>					  
					  <td>$blokada</td>
				<td bgcolor=#ffffcc>
				";

				// print "<a href=admin.php?o=konta&akcja=v$A[0]>podglad</a><br>"; //moze sie przydac pozniej koncie, przy przegladaniu histori
						
				if ($A[blokada] == 0 ) // jezeli konto jest niezablokowane mozna wykonac przelew
				{
				echo "<a href=panel.php?u=$u&o=konta&akcja=p$A[0]>przelew</a><br>";
				};
				
				print "
				<a href=panel.php?u=$u&o=konta&akcja=z$A[0]>zamkniecie</a>
				</td></tr>\r";	
	  
		} // koniec while ($A = mysql_fetch_array($lista))

  echo "</table></center>";


  mysql_close($db);

?>