<?php

echo "<center>";
echo "Tworzenie nowych pustych kont bankowych<br>
	<form method=post action=admin.php?o=konta&akcja=t>
	podaj ile nowych kont chcesz wygenerowac<br><br>
	<input type=text name=ile size=5>  <input type=submit value=Stworz>
	</form>
	";

  
	if ($ile > 0 )
	{
	
	for($i=1;$ile >= $i; $i++)
		{
  
		$zapytanie = "SELECT aid FROM konta ORDER BY aid desc";

		$lista = mysql_query($zapytanie);
  
		$A = mysql_fetch_array($lista);
  
		$numer = $A[aid] + 2 + 1;

		$wrzutka = "INSERT INTO `konta` VALUES (NULL,$numer,0,CURRENT_TIMESTAMP(),0,0)" ;

		$wynik = mysql_query($wrzutka);

		};
		echo "<br><b>Status:</b> dodano $ile nowych kont bankowych";
	};

echo "</center>";

?>