<?php include("lib/naglowek.inc"); ?>

<script type="text/javascript" language="JavaScript">   
<!--

function Login_onsubmit() 
{
	if (document.Login.loginid.value == "")
	{
		document.Login.loginid.focus()
		alert("Pole 'Login' nie mo¿e byæ puste..");
		return false;
	}

	if (document.Login.passwd.value == "")
	{
		document.Login.passwd.focus()
		alert("Pole 'Haslo' nie mo¿e byæ puste..");
		return false;
	}
	return true;
}

-->
</script>

<table border="0" cellpadding="0" cellspacing="0" style="border-collapse: collapse" bordercolor="#111111" width="100%" id="AutoNumber1" height="100%">
  <tr>
    <td width="100%">
    <div align="center">
      <center>
      <table border="0" cellpadding="5" cellspacing="0" style="border-collapse: collapse" bordercolor="#111111" width="300" id="AutoNumber2">
        <tr>
          <td width="200%" colspan="2">
          <p align="center">Logowanie do systemu vaBank</td>
        </tr>
        <tr>
          <form Name="Login" method="POST" action="login_end.php" onsubmit="return Login_onsubmit()">
          <td width="100%">Login</td>
          <td width="100%">
            <input type="text" size="20" NAME="loginid" AUTOCOMPLETE="off"></p>
          </td>
        </tr>
        <tr>
          <td width="100%">Haslo</td>
          <td width="100%">
            <input type="password" size="20" NAME="passwd" AUTOCOMPLETE="off"></td>
        </tr>
        <tr>
          <td width="100%" colspan=2>
          <p align="center"><input NAME="Submit" type="submit" value="Loguj">  <input type="reset" value="Resetuj"></td>
          </form>
        </tr>
      </table>
      </center>
    </div>
    </td>
  </tr>
</table>

<script type="text/javascript" language="JavaScript">   
<!--
	document.Login.loginid.focus()
//-->

</script>

<?php include("lib/stopka.inc");?>

