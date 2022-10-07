<?php
echo "<center>";

if ($kogo_robimy > "" and !$ile )
	{
	echo "promocja dla $kogo_robimy";
	}
if ($ile > "" ) //musi poczekac do sald
	{
	echo "ponizej lista $ile najbogatszych kont do promocji<br><br>";
	
	//$zapytanie = "SELECT konta.*, users.uid, users.imie, users.nazwisko FROM `konta` left join `users` on konta.uid=users.uid $order";
	//$lista = mysql_query($zapytanie);

	echo "<center><table border=1 bordercolor=black cellpadding='4' style='border-collapse: collapse'>
		<tr class=naglowek>
			<td width=3><a href=admin.php?o=pass_list&orderby=pass_list.pid>ID</a></td>
			<td>komu przydzielone<br>[uid, imie, nazwisko]</td>
			<td><a href=admin.php?o=konta&orderby=numer>Numer konta</a></td>
			<td><a href=admin.php?o=konta&orderby=numer>Saldo</a></td>
			<td><a href=admin.php?o=konta&orderby=dataczas>Data<br>zalozenia</a></td>
			<td><a href=admin.php?o=konta&orderby=debet>Limit debetowy</a></td>
			<td width=30>Opcje</td>
		</tr>
			";

	/* while ($A = mysql_fetch_array($lista))  
		{
		
				// zamienia date z mysql na czytelna
				$rok = substr($A[dataczas], 0, 4);
				$miesiac = substr($A[dataczas], 5, 2);
				$dzien = substr($A[dataczas], 8, 2);
				$godzina = substr($A[dataczas], 11, 2);
				$minuta = substr($A[dataczas], 14, 2);
			// koniec zamiany daty z mysql
				
		
			if ($A[used] == 0)			// jezeli karta nie byla uzywana wpisuje nowa
				{
				$used = "<font color=green>nowa</font>";
				}
				else $used = $A[used];
			// koniec jezeli karta nie byla uzywana
		
			if ($A[uid] == 0)			// jezeli karta nie jest przydzielona do uzytkownika
				{
				$uid = "<font color=grey>nie przydzielona</font>";
				}
				else $uid = $A[uid];
			// koniec jezeli karta nie jest przydzielona do uzytkownika
		
		
										// zmienna $A[0] oznacza pierwsze pole w ladowanej tabeli, w tym wypadku aid
			echo "<tr$background>		
					  <td>$A[aid]</td>
					  <td>$uid<br>$A[imie]<br>$A[nazwisko]</td>
					  <td align=center>$A[numer]</td>
					  <td>$A[saldo]</td>
					  <td>$dzien-$miesiac-$rok<br>$godzina:$minuta</td>
					  <td align=right>$A[debet]</td>
					  <td>$blokada</td>
				<td bgcolor=#ffffcc>
				<a href=admin.php?o=konta&akcja=k$A[0]>debet</a><br>
				<a href=admin.php?o=konta&akcja=r$A[0]>promocja</a><br>
				</td></tr>\r";
		
		} // koniec while ($A = mysql_fetch_array($lista))    */
	
	echo "</table></center>";
	
	}
elseif (!$kogo_robimy)
	{	
	echo "wyszukiwanie do promocji<br>
	<form method=post action=admin.php?o=konta&akcja=r>
	wyszukaj <input type=text name=ile size=5> najbogatszych kont <br>
	<input type=submit value=Szukaj>
	</form>
	";
	}

echo "</center>";
?>

