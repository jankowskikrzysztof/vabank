<?php


		if ($przydziel == 1) //drugi krok przydzielania hasel, potwierdzenie danych
		{
		$zapytanie = "SELECT users.uid, users.imie, users.nazwisko, users.pid FROM users WHERE uid=$komu_uid";
		$lista = mysql_query($zapytanie);
		$A = mysql_fetch_array($lista);
		
			if ($A[uid] == "")
				{
				echo "<font color=red><b>Brak</b> uzytkownika o podanym ID w bazie</font>";
				}
				
			elseif ($A[pid] > 0)
				{
				echo "Uzytkownik o podanym ID ma juz liste hasel przydzielona";
				}
				
			else
				{
				echo "
				<form method=post action=admin.php?o=pass_list&akcja=$akcja&przydziel=2>
				chcesz przydzielic liste hasel numer: <b>$kogo_robimy</b><br>
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

		elseif ($przydziel == 2) //trzeci krok przydzielania hasel, laczenie hasel z uzytkownikiem w tabelach
		{

		$zapytanie = "UPDATE users SET pid=$kogo_robimy WHERE uid=$komu_uid";
		mysql_query($zapytanie);
		echo "lista hasel <b>zostala</b> przydzielona<br>";

		}

		else //pierwszy krok przydzielania hasel, wprowadzenie id usera
		{
		$zapytanie = "SELECT * FROM pass_list WHERE pid=$kogo_robimy";
		$lista = mysql_query($zapytanie);
		$A = mysql_fetch_array($lista);
		
		echo "<center><table border=1 bordercolor=black cellpadding='4' style='border-collapse: collapse' bgcolor=white>
		<tr class=naglowek><td colspan=4> lista hasel numer: $kogo_robimy</td></tr>
		<tr><td>01: $A[1]</td><td>06: $A[6]</td><td>11: $A[11]</td><td>16: $A[16]</td>
		<tr><td>02: $A[2]</td><td>07: $A[7]</td><td>12: $A[12]</td><td>17: $A[17]</td></tr>
		<tr><td>03: $A[3]</td><td>08: $A[8]</td><td>13: $A[13]</td><td>18: $A[18]</td></tr>
		<tr><td>04: $A[4]</td><td>09: $A[9]</td><td>14: $A[14]</td><td>19: $A[19]</td></tr>
		<tr><td>05: $A[5]</td><td>10: $A[10]</td><td>15: $A[15]</td><td>20: $A[20]</td></tr>
		</table>
		<br>
		<form method=post action=admin.php?o=pass_list&akcja=$akcja&przydziel=1>
		podaj User ID uzytkownika ktoremu przydzielic ten plik hasel<br><br>
		<input type=text name=komu_uid size=5>  <input type=submit value=Przydziel>
		</form></center>
		";
		};
		
// $co_robimy_txt = "zaladowana"; 

?>