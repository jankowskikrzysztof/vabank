<?php
include('lib/naglowek_panel.inc');
print "
<center>
<font color=white>
Administrator: 
 [ <a class=menu href=admin.php?o=users>klienci</a> ] -
[ <a class=menu href=admin.php?o=konta>konta bankowe</a> ] -
[ <a class=menu href=admin.php?o=log_view>lista zdarzen</a> ] -
[ <a class=menu href=admin.php?o=pass_list>hasla jednorazowe</a> ] -
[ <a class=menu href=admin.php?o=stats>statystyki</a> ] -
[ <a class=menu href=index.html>wyloguj</a> ]
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

if ($o==users)
{
$status = "przegladanie listy klientow";
include('lib/users.inc');
}

if ($o==konta)
{
$status = "przegladanie kont bankowych";
include('lib/konta.inc');
}

if ($o==log_view)
{
$status = "przegladanie listy zdarzen";
include('lib/log_view.inc');
}

if ($o==pass_list)
{
$status = "przegladanie list hasel jednorazowych";
include('lib/pass_list.inc');
}


if ($o==stats)
{
$status = "statystyki";
include('lib/stats.inc');
}

print "
</td>
</tr>
</table>
";
include('lib/stopka.inc');
?>