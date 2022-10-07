<?php
  
	if ($ile > 0 )
	{
	
	for($i=1;$ile >= $i; $i++)
		{
  
		$zapytanie = "SELECT pid FROM pass_list ORDER BY pid desc";

		$lista = mysql_query($zapytanie);
  
		$A = mysql_fetch_array($lista);
  
		$pass_1 = $A[pid] + 2 + 1;
		$pass_2 = $A[pid] + 2 + 2;
		$pass_3 = $A[pid] + 2 + 3;
		$pass_4 = $A[pid] + 2 + 4;
		$pass_5 = $A[pid] + 2 + 5;
		$pass_6 = $A[pid] + 2 + 6;
		$pass_7 = $A[pid] + 2 + 7;
		$pass_8 = $A[pid] + 2 + 8;
		$pass_9 = $A[pid] + 2 + 9;
		$pass_10 = $A[pid] + 2 + 10;
		$pass_11 = $A[pid] + 2 + 11;
		$pass_12 = $A[pid] + 2 + 12;
		$pass_13 = $A[pid] + 2 + 13;
		$pass_14 = $A[pid] + 2 + 14;
		$pass_15 = $A[pid] + 2 + 15;
		$pass_16 = $A[pid] + 2 + 16;
		$pass_17 = $A[pid] + 2 + 17;
		$pass_18 = $A[pid] + 2 + 18;
		$pass_19 = $A[pid] + 2 + 19;
		$pass_20 = $A[pid] + 2 + 20;

		$wrzutka = "INSERT INTO `pass_list` VALUES (NULL, $pass_1, $pass_2, $pass_3, $pass_4, $pass_5, $pass_6, $pass_7, $pass_8, $pass_9, $pass_10, $pass_11, $pass_12, $pass_13, $pass_14, $pass_15, $pass_16, $pass_17, $pass_18, $pass_19, $pass_20 ,0,0)" ;

		$wynik = mysql_query($wrzutka);

		};
		echo "<br><b>Status:</b> dodano $ile nowe(ych) list(y) hasel";
	};

?>