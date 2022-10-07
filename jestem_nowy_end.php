<?php 


// $imie = $HTTP_POST_VARS['imie'];
// $nazwisko = $HTTP_POST_VARS['nazwisko'];
// $ulica_nr = $HTTP_POST_VARS['ulica_nr'];
// $kod_miast = $HTTP_POST_VARS['kod_miasto'];
// $plec = $HTTP_POST_VARS['plec'];
// $wiek = $HTTP_POST_VARS['wiek'];
// $telefon = $HTTP_POST_VARS['telefon'];
// $emaik  = $HTTP_POST_VARS['email'];
// $pesel = $HTTP_POST_VARS['pesel'];


if (!$passwd)
	{
	$brak_passwd = "<font color=red>pole haslo musi byc wypelnione</font>";
	}

if (!$imie)
	{
	$brak_imie = "<font color=red>musisz podac imie</font>";
	}

if (!$nazwisko)
	{
	$brak_nazwisko = "<font color=red>musisz podac nazwisko</font>";
	}
	
if (!$ulica_nr)
	{
	$brak_ulica_nr = "<font color=red>musisz podac prawidlowy adres</font>";
	}

if (!$kod_miasto)
	{
	$brak_kod_miasto = "<font color=red>musisz podac kod pocztowy i miasto</font>";
	}
	
if (!$wiek)
	{
	$brak_wiek = "<font color=red>musisz podac wiek</font>";
	}

if (!$telefon)
	{
	$brak_telefon = "<font color=red>musisz podac telefon</font>";
	}

if (!$email)
	{
	$brak_email = "<font color=red>musisz podac email</font>";
	}

if (!$passwd || !$imie || !$nazwisko || !$ulica_nr || !$kod_miasto || !$plec || !$wiek || !$telefon || !$email)
	{
	include('jestem_nowy.php');
	exit;
	}



include("lib/naglowek.inc");
include("lib/config.inc");

echo "<h1>Witamy $imie w naszym banku</h1>
<p>Przeszedles pomyslnie proces rejestracji.<br>
Zapamietaj haslo ktore podales w formularzu, jest ono bardzo wazne, gdyz bedziesz sie nim poslugiwal w czasie obslugi swojego konta bankowego</p>
<p>Login, liste hasel jednorazowych, oraz mozliwosc logowania sie do systemu otrzymasz po pozytywnym zweryfikowaniu wszystkich danych przez operatora</p>
<p>zostaniesz o tym poinformowany</p>
<p>Milego dnia!<br>
zyczy zespol vaBank</p>
";

$db = mysql_pconnect("$mysql_address","$mysql_login","$mysql_passwd");

  if (!$db)
  { echo 'Blad: Polaczenie z baza danych nie powiodlo sie'; exit; }
  
  mysql_select_db("$mysql_db");
   
   $zapytanie = "INSERT INTO users VALUES (NULL, '".$passwd."', '".$imie."', '".$nazwisko."', '".$ulica_nr."', '".$kod_miasto."', '".$plec."', '".$wiek."', '".$telefon."', '".$email."',CURRENT_TIMESTAMP(),0,1 ) ";
//   echo $zapytanie;
   $wynik = mysql_query($zapytanie);
   
   if ($wynik)
//	echo mysql_affected_rows() .' user dodany ';

include("lib/stopka.inc");
?>	
