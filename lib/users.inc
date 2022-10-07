<?PHP
include('config.inc');

  
  $db = mysql_connect("$mysql_address","$mysql_login","$mysql_passwd");

  if (! mysql_select_db("$mysql_db"))
    echo 'nie moge wybrac bazy Banku';

	// warunki przy zmianie statusu uzytkownika
	if ($akcja > "")
	 {
	$kogo_robimy = substr($akcja,1);	
	$co_robimy = substr($akcja,0,1);
	  if ($co_robimy == e)
		{
		include('users_edit.inc'); //laduje modul zmiany danych uzytkownika z pliku
		};
	  if ($co_robimy == b)
		{
		$block = "UPDATE users SET blokada=1 WHERE uid=$kogo_robimy";
		mysql_query($block);
		$co_robimy_txt = "<font color=red>zablokowany</font>"; 
		};
	  if ($co_robimy == u)
		{
		$unblock = "UPDATE users SET blokada=0 WHERE uid=$kogo_robimy";
		mysql_query($unblock);
		$co_robimy_txt = "<font color=green>odblokowany</font>"; 
		};
	  if ($co_robimy == d)
		{
		$usuwanie = "DELETE FROM users WHERE uid=$kogo_robimy";
		mysql_query($usuwanie);
		$co_robimy_txt = "<font color=red><b>skasowany</b></font>"; 
		};
	

    
	
	   $status = "uzytkownik z ID $kogo_robimy zostal $co_robimy_txt <br><br>";
	 } 
	 // koniec warunkow przy zmianie statusu uzytkownika
	
	
	// warunek do sortowania, jezeli get orderby dostal zmienna
	if ( $orderby > "")
	{ $order = "ORDER BY $orderby"; } ;
	// koniec

  $zapytanie = "SELECT * FROM users $order";

  $lista = mysql_query($zapytanie);
  
  echo "<table border=1 bordercolor=#e2e2e2 cellpadding='4' style='border-collapse: collapse' width='100%'>" ;
  echo "<tr class=naglowek><td width=3><a href=admin.php?o=users&orderby=uid>ID</a></td>
							<td><a href=admin.php?o=users&orderby=passwd>Haslo</a></td>
							<td><a href=admin.php?o=users&orderby=imie>Imie</a><br><a href=admin.php?o=users&orderby=nazwisko>nazwisko</a></td>
							<td><a href=admin.php?o=users&orderby=ulica_nr>Ulica i nr domu</a></td>
							<td><a href=admin.php?o=users&orderby=kod_miasto>Kod i Miasto</a></td>
							<td><a href=admin.php?o=users&orderby=plec>P³eæ</a></td>
							<td><a href=admin.php?o=users&orderby=wiek>Wiek</a></td>
							<td><a href=admin.php?o=users&orderby=telefon>Telefon kontaktowy</a></td>
							<td><a href=admin.php?o=users&orderby=email>Email</a></td>
							<td><a href=admin.php?o=users&orderby=pid>Aktywna lista hasel</a></td>
							<td width=40><a href=admin.php?o=users&orderby=dataczas>Data utworzenia</a></td>
							<td><a href=admin.php?o=users&orderby=blokada>Status</a></td><td>Opcje</td></tr>";
  
  
   while ($A = mysql_fetch_array($lista))
  {

	// warunek ktory pokazuje status uzytkownika
	if ($A[blokada] == 1)
		{
		$blokada = "<font color=red>blokada</font>";
		$background = " bgcolor=#ff9f9f";
		}
		else 
		{
		$blokada = "<font color=green>aktywne</font>";
		$background = " bgcolor=white";
		}
	// koniec warunku pokazujacego status

	// jezeli nie ma przydzielonej listy hasel to wpisuje w kolumne "brak"
	if ($A[pid]==0)
		{ 
		$pid = '<font color=grey>brak</font>'; 
		}
		else $pid = $A[pid];
	// koniec "jezeli nie ma przydzielonej listy hasel to wpisuje w kolumne "brak""

  echo "<tr$background><td>$A[uid]</td><td>$A[passwd]</td><td>$A[imie]<br>$A[nazwisko]</td><td>$A[ulica_nr]</td><td>$A[kod_miasto]</td><td>$A[plec]</td><td>$A[wiek]</td><td>$A[telefon]</td><td><a href=mailto:$A[email]>$A[email]</a></td><td>$pid</td><td>$A[dataczas]</td><td>$blokada</td>
		<td bgcolor=#ffffcc>
		<a href=admin.php?o=users&akcja=e$A[uid]>edycja</a><br>";
		if ($A[blokada] == 0)
		echo "<a href=admin.php?o=users&akcja=b$A[uid]>blokowanie</a><br>";
		if ($A[blokada] == 1)
		echo "<a href=admin.php?o=users&akcja=u$A[uid]>odblokowanie</a><br>";
		echo "<a href=admin.php?o=users&akcja=d$A[uid]>usuniecie</a>
		</td></tr>\r";
  
  }
  
  echo "</table>"   ;
  mysql_close($db);

?>
