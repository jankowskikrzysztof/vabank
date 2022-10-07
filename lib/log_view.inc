<?php

include('config.inc');

include('log_view_search.inc');


$db = mysql_connect("$mysql_address","$mysql_login","$mysql_passwd");

if (! mysql_select_db("$mysql_db"))
    echo 'nie moge wybrac bazy Banku';
	
if ( $orderby > "") // warunek do sortowania, jezeli get orderby dostal zmienna
		{ 
		$order = "ORDER BY $orderby desc"; 
		} 
		else $order = "ORDER BY sid desc"; // jezeli brak orderby wtedy wg sid
	
$zapytanie = "SELECT log.sid, users.imie, users.nazwisko, log.uid, log.dataczas, log.oid FROM `log`,`users` WHERE users.uid = log.uid $search $order $limit";

$lista = mysql_query($zapytanie);

echo "<center><table border=1 bordercolor=black cellpadding='4' style='border-collapse: collapse'>" ;
echo "<tr class=naglowek align=center>
			<td width=3 rowspan=2><a href=admin.php?o=log_view&orderby=sid>SID</a></td>
			
			<td rowspan=2><a href=admin.php?o=log_view&orderby=imie>Kto</a></td>
			<td rowspan=2><a href=admin.php?o=log_view&orderby=uid>User<br>ID</a></td>
			<td rowspan=2><a href=admin.php?o=log_view&orderby=dataczas>Data<br>godzina</a></td>
			<td colspan=2>Operacja</td>
			<td rowspan=2>Nr Konta<br>Bankowego</td>
			</tr>
			<tr class=naglowek align=center><td><a href=admin.php?o=log_view&orderby=oid>nazwa</a></td><td>id</td>
			</tr>\r";
    
while ($A = mysql_fetch_array($lista))
	  {
	
		// warunek ktory pokazuje typ zdarzenia
		if ($A[oid] == 0)
			{
			$rodzaj = "<font color=blue>logowanie</font>";
			$kwota = "";
			$B[numer] = "";
			}
			else 
			{
			$zapytanie2 = "SELECT operacje.*, konta.numer FROM `operacje`,`konta` WHERE operacje.oid=$A[oid] and operacje.aid=konta.aid";
			$lista2 = mysql_query($zapytanie2);
			$B = mysql_fetch_array($lista2);
				if($B[typ] == 0)
				$rodzaj = "<font color=green>wplata</font>";
				if($B[typ] == 1)
				$rodzaj = "<font color=red>wyplata</font>";
			$kwota = " - $B[kwota]";
			}
		// koniec warunku pokazujacego status
		
		if ($A[pid]==0)
			{ 
			$pid = 'brak'; 
			};
	
		echo "<tr><td>$A[sid]</td><td>$A[imie] $A[nazwisko]</td><td>$A[uid]</td><td>$A[dataczas]</td><td>$rodzaj$kwota</td><td>$A[oid]</td><td>$B[numer]</td>
			</tr>\r";
	  
		}
  

echo "</table></center>"   ;
mysql_close($db);
?>
