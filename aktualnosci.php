<?php
include('lib/naglowek.inc');
include('lib/kursy.inc');
include('lib/config.inc');


$db = mysql_connect("$mysql_address","$mysql_login","$mysql_passwd");

  if (! mysql_select_db("$mysql_db"))
    echo 'nie moge wybrac bazy Banku';
$klientow = "SELECT COUNT(`uid`) FROM `users`" ;
$klientow = mysql_query($klientow);
$klientow = mysql_fetch_array($klientow); 


echo "aktualny kurs dolara wynosi: $usd";
echo "<br>aktualny kurs euro wynosi: $eur";
echo "<br>aktualny kurs funta wynosi: $gbp";

echo "<br>w banku jest juz ".$klientow[0]." zarejestrowanych klientow";


  mysql_close($db);
include('lib/stopka.inc');
?>
