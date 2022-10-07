<?php

include('kursy.inc');
include('config.inc');


echo "<center><h1>statystyki</h1><br>";

$db = mysql_connect("$mysql_address","$mysql_login","$mysql_passwd");

  if (! mysql_select_db("$mysql_db"))
    echo 'nie moge wybrac bazy Banku';

$klientow = "SELECT COUNT(`uid`) FROM `users`" ;
$klientow = mysql_query($klientow);
$klientow = mysql_fetch_array($klientow); 

$db = mysql_connect("$mysql_address","$mysql_login","$mysql_passwd");

  if (! mysql_select_db("$mysql_db"))
    echo 'nie moge wybrac bazy Banku';

	$s_zapytanie = "SELECT SUM(kwota) FROM `operacje` WHERE typ=0";
	$s_lista = mysql_query($s_zapytanie);
	$S = mysql_fetch_array($s_lista);
	
	$s_wplaty = $S[0];
	
	$s_zapytanie = "SELECT SUM(kwota) FROM `operacje` WHERE typ=1";
	$s_lista = mysql_query($s_zapytanie);
	$S = mysql_fetch_array($s_lista);
	
	$s_wyplaty = $S[0];
	
	$saldo = $s_wplaty - $s_wyplaty;



echo "aktualny kurs dolara wynosi: <b>$usd</b>";
echo "<br>aktualny kurs euro wynosi: <b>$eur</b>";
echo "<br>aktualny kurs funta wynosi: <b>$gbp</b>";

echo "<br><br>w banku jest juz <b>".$klientow[0]."</b> zarejestrowanych klientow";
echo "<br><br>Aktywa zgromadzone w banku wynosza:<b> $saldo zl</b></center>";


  mysql_close($db);

?>