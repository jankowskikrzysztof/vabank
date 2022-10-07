<?php
// skrypt wyciaga dolara i euro ze strony NBP //

$f = @fopen("http://www.nbp.pl/Kursy/KursyA.html", "r");
if ($f) {
  while(!feof($f)) $strona.= fread($f,1024); fclose($f);
  $strona = preg_replace("/\r/", " ", $strona);
  $strona = preg_replace("/\n/", " ", $strona);

  preg_match("<xml\/(.*?).xml>", $strona, $xml);

	$f1 = @fopen("http://www.nbp.pl/Kursy/$xml[0]", "r");

	if ($f1) {
	  while(!feof($f1)) $strona1.= fread($f1,1024); fclose($f1);
		  $strona1 = preg_replace("/\r/", " ", $strona1);
		  $strona1 = preg_replace("/\n/", " ", $strona1);	

			preg_match("/<kod_waluty>USD<\/kod_waluty>        <kurs_sredni>(.*?)<\/kurs_sredni>/", $strona1, $usd);
			$usd = substr($usd[0], -20, -16);
			global $usd;
			$usd = substr($usd, 0, 1 ).".".substr($usd, 2,3);

			preg_match("/<kod_waluty>EUR<\/kod_waluty>        <kurs_sredni>(.*?)<\/kurs_sredni>/", $strona1, $eur);
			$eur = substr($eur[0], -20, -16);
			global $eur;
			$eur = substr($eur, 0, 1 ).".".substr($eur, 2,3);
			
			preg_match("/<kod_waluty>GBP<\/kod_waluty>        <kurs_sredni>(.*?)<\/kurs_sredni>/", $strona1, $gbp);
			$gbp = substr($gbp[0], -20, -16);
			global $gbp;
			$gbp = substr($gbp, 0, 1 ).".".substr($gbp, 2,3);


	}
}
// echo "<br>kurs dol $usd i kurs eur $eur <br>";

?>