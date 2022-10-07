<?php


		if ($przydziel == 1) //drugi krok przydzielania konta, potwierdzenie danych
		{


		$zapytanie = "SELECT konta.*, users.uid, users.imie, users.nazwisko FROM users, konta WHERE users.uid=$komu_debet and konta.aid=$kogo_robimy";
						
		$lista = mysql_query($zapytanie);
		$A = mysql_fetch_array($lista);
		
			echo "
				<form method=post action=admin.php?o=konta&akcja=$akcja&przydziel=2>
				chcesz przydzielic debet w wysokosci <b>$kwota_debet</b> dla konta o numerze ID: <b>$kogo_robimy</b><br>
				klientowi:<br>
				ID: <b>$A[uid]</b><br>
				Imie: <b>$A[imie]</b><br>
				Nazwisko: <b>$A[nazwisko]</b><br>
				<br>
				<input type=hidden name=kwota_debet value=$kwota_debet>  			
				<center><input type=submit value=Potwierdzam></center>
				</form>
				";
			
		}

		elseif ($przydziel == 2) //trzeci krok przydzielania konta, laczenie konta z uzytkownikiem w tabelach
		{
		$zapytanie = "UPDATE konta SET debet=$kwota_debet WHERE aid=$kogo_robimy";
		mysql_query($zapytanie);
		echo "debet <b>zostal</b> przydzielony<br>";
		}

		else //pierwszy krok przydzielania konta, wprowadzenie id usera
		{
		$zapytanie = "SELECT konta.*, users.uid, users.imie, users.nazwisko, users.pid FROM users, konta WHERE konta.uid=users.uid and konta.aid=$kogo_robimy";
	
	
	
		$lista = mysql_query($zapytanie);
		$A = mysql_fetch_array($lista);
		
		echo "<center><table border=0 bordercolor=black cellpadding='4' style='border-collapse: collapse' bgcolor=white>
		<tr class=naglowek><td> konto ID numer:</td><td> $kogo_robimy</td></tr>

		<tr><td>numer konta: 
		<br>limit debetowy:
		<br>
		<br>wlasciciel:
		<br>ID: 
		<br>Imie: 
		<br>Nazwisko: 
		</td>
		<td><b>$A[numer]<br>$A[debet]<br><br><br>$A[uid]<br>$A[imie]<br>$A[nazwisko]</b></td>
		</tr>
		</table>
		<br>
		<form method=post action=admin.php?o=konta&akcja=$akcja&przydziel=1>
		Kwote debetu jaka przydzielic dla konta<br><br>
		<input type=text name=kwota_debet size=5>
		<input type=hidden name=komu_debet value=$A[uid]>
		<input type=submit value=Przydziel>
		</form></center>
		";
		};
		
// $co_robimy_txt = "zaladowana"; 

?>