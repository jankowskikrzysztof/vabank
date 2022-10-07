<?php


		if ($przydziel == 1) //drugi krok przydzielania konta, potwierdzenie danych
		{
		
		$zapytanie = "SELECT users.uid, users.imie, users.nazwisko FROM users, konta WHERE users.uid=$komu_uid";
		
		$lista = mysql_query($zapytanie);
		$A = mysql_fetch_array($lista);
		
			if ($A[uid] == "")
				{
				echo "<font color=red><b>Brak</b> uzytkownika o podanym ID w bazie</font>";
				}
				
			else
				{
				echo "
				<form method=post action=admin.php?o=konta&akcja=$akcja&przydziel=2>
				chcesz przydzielic konto o numerze ID: <b>$kogo_robimy</b><br>
				numer konta: <b>$konto_numer</b><br>
				limit debetowy: <b>$konto_debet</b><br>
				klientowi:<br>
				ID: <b>$A[uid]</b><br>
				Imie: <b>$A[imie]</b><br>
				Nazwisko: <b>$A[nazwisko]</b><br>
				<br>
				<input type=hidden name=komu_uid value=$komu_uid>  			
				<center><input type=submit value=Potwierdzam></center>
				</form>
				";
				}
		}

		elseif ($przydziel == 2) //trzeci krok przydzielania konta, laczenie konta z uzytkownikiem w tabelach
		{

		$zapytanie = "UPDATE konta SET uid=$komu_uid WHERE aid=$kogo_robimy";
		mysql_query($zapytanie);
		echo "konto <b>zostalo</b> przydzielone<br>";

		}

		else //pierwszy krok przydzielania konta, wprowadzenie id usera
		{
		$zapytanie = "SELECT * FROM konta WHERE aid=$kogo_robimy";
		$lista = mysql_query($zapytanie);
		$A = mysql_fetch_array($lista);
		
		echo "<center><table border=1 bordercolor=black cellpadding='4' style='border-collapse: collapse' bgcolor=white>
		<tr class=naglowek><td> konto numer: $kogo_robimy</td></tr>
		<tr><td>
		numer konta: <b>$A[numer]</b><br>
		limit debetowy: <b>$A[debet]</b><br>
		</table>
		<br>
		<form method=post action=admin.php?o=konta&akcja=$akcja&przydziel=1>
		podaj User ID uzytkownika ktoremu przydzielic to konto<br><br>
		<input type=text name=komu_uid size=5>
		<input type=hidden name=konto_numer value=$A[numer]>
		<input type=hidden name=konto_debet value=$A[debet]>
		<input type=submit value=Przydziel>
		</form></center>
		";
		};
		
// $co_robimy_txt = "zaladowana"; 

?>