<?PHP		
		if ($zmiana > "")
		{
		$zapytanie = "UPDATE `users` SET `passwd`='".$passwd."', `imie`='".$imie."', `nazwisko`='".$nazwisko."', `ulica_nr`='".$ulica_nr."', `kod_miasto`='".$kod_miasto."', `plec`='".$plec."', `wiek`='".$wiek."', `telefon`='".$telefon."', `email`='".$email."' WHERE `uid`='".$zmiana."'";
		mysql_query($zapytanie);
		$co_robimy_txt = "dane zmienione"; 
		}
		else
		$co_robimy_txt = "zaladowany"; 
		
		$ladowanie = "SELECT * FROM users WHERE uid=$kogo_robimy";
		$lista = mysql_query($ladowanie);
		$A = mysql_fetch_array($lista);

		echo "
		<table border=0 cellpadding='4' bordercolor=black style='border-collapse: collapse' width='100%'>
		<tr class=naglowek align=center>
 		 <td>UID</td>
		 <td>Haslo</td>
		 <td>Imie</td>
		 <td>Nazwisko</td>
		 <td>Ulica i nr</td>
		 <td>Kod i Miasto</td>
		 <td>Plec</td>
		 <td>Wiek</td>
		 <td>Telefon</td>
		 <td>Email</td>
		</tr>
		<form action='admin.php?o=users&akcja=".$akcja."&zmiana=".$A[uid]."' method='post'>
		<tr bgcolor=#ffffcc align=center>
		 <td>$A[uid]</td>
		 <td><input type='text' name='passwd' size='8' value='".$A[passwd]."'></td>
		 <td><input type='text' name='imie' size='15' value='".$A[imie]."'></td>
		 <td><input type='text' name='nazwisko' size='15' value='".$A[nazwisko]."'></td>
		 <td><input type='text' name='ulica_nr' size='20' value='".$A[ulica_nr]."'></td>
		 <td><input type='text' name='kod_miasto' size='20' value='".$A[kod_miasto]."'></td>
		 <td><select name='plec' id='plec'>
			<option value=k"; if ($A[plec] == "k") echo " selected"; echo ">Kobieta</option>
			<option value=m"; if ($A[plec] == "m") echo " selected"; echo ">Mezczyzna</option>
		 <td><input type='text' name='wiek' size='3' value='".$A[wiek]."'></td>
		 <td><input type='text' name='telefon' size='12' value='".$A[telefon]."'></td>
		 <td><input type='text' name='email' size='15' value='".$A[email]."'></td>
		</tr>
		<tr>
		 <td colspan=8><b>Status:</b> $co_robimy_txt</td>
		 <td colspan=2 bgcolor=#cccccc><p align=center><input type=submit value=Zmien></td>
		</tr>
		</form>
		</table><br><br>
		";

?>
