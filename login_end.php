<?php
include("lib/config.inc");


$db = mysql_pconnect("$mysql_address","$mysql_login","$mysql_passwd");

  if (! mysql_select_db("$mysql_db"))
    echo 'nie moge wybrac bazy Banku';
 
   // jezeli loguje sie zwykly uzytkownik
   if ($loginid <> admin and $loginid <> operator)
	{
	$zapytanie = "SELECT * FROM users WHERE uid LIKE '".$loginid."'";
	$lista = mysql_query($zapytanie);
	$A = mysql_fetch_array($lista);

		// poprawne logowanie, uid sie zgadza, haslo sie zgadza, nie ma blokady konta
		if ($loginid  == $A[uid] and $passwd == $A[passwd] and $A[blokada] == 0)
			{ 
			mysql_query("INSERT INTO log VALUES (NULL,$A[uid],NULL,0)");
			$status = "logowanie zakonczone sukcesem";
			$u = $loginid ;
			include('panel.php'); 
			};
		// poprawne logowanie, uid sie zgadza, haslo sie zgadza, JEST blokada konta
		if ($loginid  == $A[uid] and $passwd == $A[passwd] and $A[blokada] == 1)
			{ 
			include("lib/naglowek.inc");
			echo "<h1>Podany uzytkownik jest <b>zablokowany</b> w systemie</h1>";
			echo "<p>Skontaktuj sie jak najszybciej z infolinia vaBank - '0800 vabank' (0800 822265 )<br>";
			echo "<br>Blad moze wystapic takze w momencie gdy uzytkownik nie zostal jeszcze zaktywowany przez operatora i nie zostal zakonczony proces rejestracji uzytkownika<br></p>";
			$status = "blad";
			include("lib/stopka.inc");
			};
		// niepoprawne logowanie, haslo sie nie zgadza lub uid
		if ($passwd <> $A[passwd])
			{ 
			include("lib/naglowek.inc");
			echo "<h1>Nie poprawne haslo lub login</h1>";
			echo "<p>Jezeli to problem, skontaktuj sie jak najszybciej z infolinia vaBank - '0800 vabank' (0800 822265 )<br>";
			echo "<br><a href=login.php>powrot do strony logowania</a></p>";
			$status = "blad";
			include("lib/stopka.inc");
			};
	 };
	// koniec "jezeli loguje sie zwykly uzytkownik"
	
	
	// jezeli loguje sie administrator lub operator
	if ($loginid == admin or $loginid == operator)
		{
		$zapytanie = "SELECT * FROM boss WHERE login LIKE '".$loginid."'";
		$lista = mysql_query($zapytanie);
		$A = mysql_fetch_array($lista);

		if ($loginid == admin and $passwd == $A[passwd] )
			{ 
			// mysql_query("INSERT INTO log VALUES (NULL,$A[bid],NULL,0)");
			$status = "pracownik banku zalogowany";
			include('admin.php'); 
			}
		elseif ($loginid == operator and $passwd == $A[passwd] )
			{ 
			// mysql_query("INSERT INTO log VALUES (NULL,$A[bid],NULL,0)");
			$status = "pracownik banku zalogowany";
			include('operator.php'); 
			}
		else { 
				include("lib/naglowek.inc");
				echo "<h1>Nieautoryzowana proba logowania pracownika banku</h1>";
				$status = "blad systemowy";
				include("lib/stopka.inc");
				 };
		};
				 
	// koniec "jezeli loguje sie administrator lub operator"

	
?>