<?php include("lib/naglowek.inc"); ?>

<table border="0" cellpadding="0" cellspacing="0" style="border-collapse: collapse" bordercolor="#111111" width="100%" id="AutoNumber1" height="100%">
  <tr>
    <td width="100%">
    <div align="center">
      <center>
      <table border="0" cellpadding="5" style="border-collapse: collapse" bordercolor="#111111" width="500" id="AutoNumber2">
        <tr>
          <td colspan="2">
          <p align="center">Dodawanie nowego klienta</td>
        </tr>
          <form action="jestem_nowy_end.php" method="post">
        <tr>
          <td>has³o</td>
          <td>
            <input type="text" name="passwd" size="20" value=<?php echo "$passwd" ?>><br>
            <?php if ($brak_passwd <> "") echo "$brak_passwd<br>" ?>[max 20 znakow]</td>
        </tr>
        <tr>
          <td colspan="2">&nbsp;</td>
        </tr>
        <tr>
          <td>imie</td>
          <td>
            <input type="text" name="imie" size="20" value=<?php echo "$imie" ?>>
            <?php if ($brak_imie <> "") echo "<br>$brak_imie" ?></td>
        </tr>
        <tr>
          <td>nazwisko</td>
          <td>
            <input type="text" name="nazwisko" size="20" value=<?php echo "$nazwisko" ?>>
            <?php if ($brak_nazwisko <> "") echo "<br>$brak_nazwisko" ?></td>
        </tr>
        <tr>
          <td>Plec</td>
          <td>
            <select name="plec" id="plec">
			<option value="m" <?php if ($plec == "m") echo "selected" ?>>Mezczyzna</option>
			<option value="k" <?php if ($plec == "k") echo "selected" ?>>Kobieta</option>
          </td>
        </tr>
        <tr>
          <td>Rok urodzenia</td>
          <td>
            <input type="text" name="wiek" size="20" value=<?php echo "$wiek" ?>>
            <?php if ($brak_wiek <> "") echo "<br>$brak_wiek" ?></td>
        </tr>
        <tr>
          <td>Adres: ulica i nr domu</td>
          <td>
            <input type="text" name="ulica_nr" size="20" value=<?php echo "$ulica_nr" ?>>
            <?php if ($brak_ulica_nr <> "") echo "<br>$brak_ulica_nr" ?></td>
        </tr>
        <tr>
          <td>kod i miasto</td>
          <td>
            <input type="text" name="kod_miasto" size="20" value=<?php echo "$kod_miasto" ?>>
            <?php if ($brak_kod_miasto <> "") echo "<br>$brak_kod_miasto" ?></td>
        </tr>
        <tr>
          <td>Numer telefonu</td>
          <td>
            <input type="text" name="telefon" size="20" value=<?php echo "$telefon" ?>>
            <?php if ($brak_telefon <> "") echo "<br>$brak_telefon" ?></td></td>
        </tr>
        <tr>
          <td>Email</td>
          <td>
            <input type="text" name="email" size="20" value=<?php echo "$email" ?>>
            <?php if ($brak_email <> "") echo "<br>$brak_email" ?></td>
        </tr>
        <tr>
          <td colspan="2">&nbsp;</td>
        </tr>
        <tr>
          <td colspan="2">
          <p align="center"><input type="submit" value="Dodaj"> <input type="reset" value="Wyczysc"></td>
        </tr>
        </form>
      </table>
      </center>
    </div>
    </td>
  </tr>
</table>

<?php include("lib/stopka.inc"); ?>

