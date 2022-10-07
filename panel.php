<?php
include('lib/naglowek_panel.inc');

	
print "
<center>
<font color=white>
Menu $A[imie]:
[<a class=menu href=panel.php?u=$u&o=konta>konta</a>] -
[<a class=menu href=index.html>wyloguj</a>]
</font>
</center>
</td>
</tr>
<tr>
<td colspan=2>

<table width=100%>
<tr>
<td>
";

/*	<h1>Witamy $A[imie]</h1>
	<br>Logowanie zakonczone sukcesem<br>
twoj $loginid jest	
*/

if ($o==konta)
 {
$status = "przegladanie kont bankowych";
include('lib/panel_konta.inc');
 }


print "
</td>
</tr>
</table>
";

include('lib/stopka.inc');	
?>