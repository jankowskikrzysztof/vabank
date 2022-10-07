<?

/*
include('config.inc');

$aid = 9;

  $db = mysql_connect("$mysql_address","$mysql_login","$mysql_passwd");

  if (! mysql_select_db("$mysql_db"))
    echo 'nie moge wybrac bazy Banku';
*/

$aid = $A[aid];

if ($aid > "")
	{
	$s_zapytanie = "SELECT SUM(kwota) FROM `operacje` WHERE aid=$aid and typ=0";
	$s_lista = mysql_query($s_zapytanie);
	$S = mysql_fetch_array($s_lista);
	
	$s_wplaty = $S[0];
	
	$s_zapytanie = "SELECT SUM(kwota) FROM `operacje` WHERE aid=$aid and typ=1";
	$s_lista = mysql_query($s_zapytanie);
	$S = mysql_fetch_array($s_lista);
	
	$s_wyplaty = $S[0];
	
	$saldo = $s_wplaty - $s_wyplaty;
	};


/*
echo "suma wplat dla $aid wynosi $s_wplaty<br>";
echo "suma wyplat dla $aid wynosi $s_wyplaty<br>";
echo "saldo dla $aid wynosi $saldo";
*/

// suma wplat

// SELECT SUM(kwota) FROM `operacje` WHERE typ=0 and aid=$aid



// suma wyplat
   

// SELECT SUM(kwota) FROM `operacje` WHERE typ=1 and aid=$aid


?>