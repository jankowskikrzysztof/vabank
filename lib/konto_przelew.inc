<?php


echo "<center><table border=0 bordercolor=black cellpadding='4' style='border-collapse: collapse' bgcolor=white>";

if (!$przelew) // pierwsza strona przelewu
	
	/*
	
	nadawca = 	$nad=$u (users.uid=$nad)
				$nad_aid
				$nad_konto
	
	kwota = $kwota (operacje.kwota = [$kwota, operacje.typ=0] => $odb & [operacje.kwota = $kwota, operacje.typ=1] => $nad)
	
	odbiorca = $odb_konto (konta.numer)
			$odb = (konta.numer where $uid = $odb_konto)
	
	zdefiniowac ze $kwota > 0
	
	sprawdzanie salda i debetu u $nad przed wyslaniem
	
	$kogo_robimy = zmienna z numerem aid konta nadawcy = $nad_aid
	$co_robimy = zmienna z typem akcji - przelew
	
	*/
	
	{
	echo "
	<tr class=naglowek><td colspan=2>przelew, krok 1/3</td></tr>
	<form method=post action=panel.php?u=$u&o=konta&akcja=$akcja&przelew=1>
	<tr valign=top>
	<tr>
		<td>numer konta odbiorcy:</td>
		<td><input type=text name=odb_konto_nr size=10></td>
	</tr>
	<tr>
		<td>kwota przelewu:</td>
		<td><input type=text name=kwota size=10></td>
	</tr>
	<tr>
		<td colspan=2>
		<input type=hidden name=nad_aid value=$kogo_robimy>
		<input type=submit value=Dalej>
		</td>
	</form>
	</tr>
	";
	};


///////////////////////////////////////////////////////////////////////////////////////////////


if ( $przelew == 1 ) // druga strona przelewu
	{

	if ($kwota < 0 ) //sprawdza czy kwota podana jest kwota ujemna
		{
		echo "kwota przelewu <b>nie moze byc</b> kwota ujemna<br><br>";
		echo "<center><a href=javascript:history.back()> <-- POWROT</a></center>";
		exit;
		}

	// zapytanie pierwsze - o nadawce
	$zapytanie = "SELECT konta.*, users.uid, users.imie, users.nazwisko, users.pid FROM `konta`, `users` WHERE konta.aid=$nad_aid and konta.uid=users.uid";

	$lista = mysql_query($zapytanie);
	$A = mysql_fetch_array($lista);

	$nad = "$A[uid]";
	$nad_aid = $nad_aid;
	$nad_full = "$A[imie] $A[nazwisko]";
	$nad_konto_nr = "$A[numer]";
	$pid = "$A[pid]";

	include('saldo.inc'); //biblioteka dla salda, wynikiem jest zmienna $saldo i $s_wplaty i $s_wyplaty
	$spr = $saldo - $kwota + $A[debet];
	if ($spr < 0) // sprawdza czy sa dostepne srodki na koncie
		{
		echo "<b>brak</b> wystarczajacych srodkow do dokonania przelewu<br><br>";
		echo "<center><a href=javascript:history.back()> <-- POWROT</a></center>";
		exit;
		}

	// zapytanie drugie - o odbiorce
	$zapytanie = "SELECT konta.*, users.uid, users.imie, users.nazwisko FROM `konta`, `users` WHERE konta.numer=$odb_konto_nr and konta.uid=users.uid";

	$lista = mysql_query($zapytanie);
	$A = mysql_fetch_array($lista);

	$odb = "$A[uid]";
	$odb_aid = "$A[aid]";
	$odb_full = "$A[imie] $A[nazwisko]";
	$odb_konto_nr = "$A[numer]";

	$spr = $odb_konto_nr;

	if ($spr == "") // sprawdza czy istnieje podane konto odbiorcy
		{
		echo "podany numer konta bankowego jest <b>nieprawidlowy</b><br><br>";
		echo "<center><a href=javascript:history.back()> <-- POWROT</a></center>";
		exit;
		}
		
	if ($nad_konto_nr == $odb_konto_nr) // sprawdza czy podane konto nie jest takie jak nadawcy
		{
		echo "podany numer konta <b>jest taki sam</b> jak nadawcy<br><br>";
		echo "<center><a href=javascript:history.back()> <-- POWROT</a></center>";
		exit;
		}
	

	// zapytanie trzecie - o hasla jednorazowe
	$zapytanie = "SELECT * FROM pass_list WHERE pid=$pid";

	$lista = mysql_query($zapytanie);
	$A = mysql_fetch_array($lista);

	$used = $A[used];
	$spr = 20 - $used;
	if ($spr == 0) // sprawdza czy sa dostepne hasla jednorazowe na karcie
		{
		echo "<b>brak</b> hasel jednorazowych do wykorzystania<br>zamow nowa karte hasel jednorazowych<br><br>";
		echo "<center><a href=javascript:history.back()> <-- POWROT</a></center>";
		exit;
		}
	$pass_nr = $used +1;


	echo "
	<tr class=naglowek><td colspan=2>przelew, krok 2/3</td></tr>
	<form method=post action=panel.php?u=$u&o=konta&akcja=$akcja&przelew=2>
	<tr>
		<td>sprawdzam poprawnosc danych </td>
		<td></td>
	</tr>
	<tr>
		<td>nadawca:</td>
		<td><b>$nad_full</b></td>
	</tr>
	<tr>
		<td>konto nadawcy:</td>
		<td><b>$nad_konto_nr</b></td>
	</tr>
	<tr>
		<td>odbiorca:</td>
		<td><b>$odb_full</b></td>
	</tr>
	<tr>
		<td>konto odbiorcy:</td>
		<td><b>$odb_konto_nr</b></td>
	</tr>
	<tr>
		<td>kwota przelewu:</td>
		<td><b>$kwota</b></td>
	</tr>
	<tr>
		<td>wprowadz haslo jednorazowe<br>nr: $pass_nr z listy hasel nr: $pid</td>
		<td><input type=text name=pass_jest size=5></td>
	</tr>
	<tr>
		<td colspan=2>
		<input type=hidden name=kwota value=$kwota>
		<input type=hidden name=nad value=$nad>
		<input type=hidden name=nad_aid value=$nad_aid>
		<input type=hidden name=odb value=$odb>
		<input type=hidden name=odb_aid value=$odb_aid>
		<input type=hidden name=pid value=$pid>
		<input type=hidden name=pass_nr value=$pass_nr>
		<input type=submit value=Dalej>
		</form>
		</td>
	</tr>
	";
	};


///////////////////////////////////////////////////////////////////////////////////////////////


if ( $przelew == 2 ) // trzecia strona przelewu
	{

	// zapytanie pierwsze - o hasla jednorazowe
	$zapytanie = "SELECT * FROM pass_list WHERE pid=$pid";

	$lista = mysql_query($zapytanie);
	$A = mysql_fetch_array($lista);

	if($pass_nr <>$A[used] + 1) //sprawdza czy numer hasla podanego w czesc 2/3 jest taki sam jak poprawny
		{
		echo "<b>blad</b> proba wlamania<br><br>";
		echo "<center><a href=javascript:history.back()> <-- POWROT</a></center>";
		exit;
		}
	if($pass_jest <>$A[$pass_nr])
		{
		echo "<b>niepoprawne</b> haslo jednorazowe<br><br>";
		echo "<center><a href=javascript:history.back()> <-- POWROT</a></center>";
		exit;
		}

	// zapytanie drugie - wykorzystanie jednego hasla jednorazowego
	$zapytanie = "UPDATE pass_list SET used=$pass_nr WHERE pid=$pid";
	mysql_query($zapytanie);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// zapytanie trzecie - odjecie kwoty z konta nadawcy
	$zapytanie = "INSERT INTO `operacje` (`oid`, `aid`, `kwota`, `typ`) VALUES (NULL, $nad_aid, $kwota, 1)";
	
	mysql_query($zapytanie);

	// zapytanie czwarte - szukaj oid
	$zapytanie = "SELECT * FROM operacje WHERE aid=$nad_aid and kwota=$kwota and typ=1";
	$lista = mysql_query($zapytanie);
	$A = mysql_fetch_array($lista);
	$oid_a = $A[oid];
	
	// zapytanie piate - loguj przelew
	$zapytanie = "INSERT INTO `log` (`sid`, `uid`, `dataczas`, `oid`) VALUES (NULL,$nad, NULL,$oid_a)";
	mysql_query($zapytanie);

///////////////

	// zapytanie szoste - dodanie kwoty do konta odbiorcy
	$zapytanie = "INSERT INTO `operacje` (`oid`, `aid`, `kwota`, `typ`) VALUES (NULL, $odb_aid, $kwota, 0)";
	mysql_query($zapytanie);

	// zapytanie siodme - szukaj oid
	$zapytanie = "SELECT * FROM operacje WHERE aid=$odb_aid and kwota=$kwota and typ=0";
	$lista = mysql_query($zapytanie);
	$A = mysql_fetch_array($lista);
	$oid_b = $A[oid];
	
	// zapytanie osme - loguj przelew
	$zapytanie = "INSERT INTO `log` (`sid`, `uid`, `dataczas`, `oid`) VALUES (NULL,$odb, NULL,$oid_b)";
	mysql_query($zapytanie);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	echo "
	<tr class=naglowek><td colspan=2>przelew, krok 3/3</td></tr>
	<tr>
		<td colspan=>przelew zostal wykonany<td>
	</tr>
	<tr>
		<td>numer operacji:</td>
		<td><b>$oid_a/$oid_b</b></td>
	</tr>
	";
	};

echo "</table></center><br>";

?>