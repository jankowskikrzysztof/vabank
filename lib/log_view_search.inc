<?php

echo "
	<center>
	<br>
	<table border=1 style='border-collapse: collapse' cellpadding='10'>
	<tr class=naglowek><td align=center>Wyszukiwanie zdarzen wg daty</td></tr>
	<tr>
	<td align=right>
	";

echo "
	<form method=post action=admin.php?o=log_view>
	[dzien]&nbsp;[miesiac]&nbsp;&nbsp;&nbsp;&nbsp;[rok]&nbsp;&nbsp;&nbsp;&nbsp;<br>
	Szukaj danych z data od: 
	<select size=1 name=oddzien>
	  "; 
	  if ($oddzien > "") echo "<option selected>$oddzien</option>"; 
	  echo "
	  <option>01</option>
	  <option>02</option>
	  <option>03</option>
	  <option>04</option>
	  <option>05</option>
	  <option>06</option>
	  <option>07</option>
	  <option>08</option>
	  <option>09</option>
	  <option>10</option>
	  <option>11</option>
	  <option>12</option>
	  <option>13</option>
	  <option>14</option>
	  <option>15</option>
	  <option>16</option>
	  <option>17</option>
	  <option>18</option>
	  <option>19</option>
	  <option>20</option>
	  <option>21</option>
	  <option>22</option>
	  <option>23</option>
	  <option>24</option>
	  <option>25</option>
	  <option>26</option>
	  <option>27</option>
	  <option>28</option>
	  <option>29</option>
	  <option>30</option>
	  <option>31</option>
	</select>
	
	<select size=1 name=odmiesiac>
	  "; 
	  if ($odmiesiac > "") echo "<option selected>$odmiesiac</option>"; 
	  echo "
	  <option>01</option>
	  <option>02</option>
	  <option>03</option>
	  <option>04</option>
	  <option>05</option>
	  <option>06</option>
	  <option>07</option>
	  <option>08</option>
	  <option>09</option>
	  <option>10</option>
	  <option>11</option>
	  <option>12</option>
	</select>
	
	<select size=1 name=odrok>
	  "; 
	  if ($odrok > "") echo "<option selected>$odrok</option>"; 
	  echo "
	  <option>2003</option>
	  <option>2004</option>
	  <option>2005</option>
	  <option>2006</option>
	  <option>2007</option>
	  <option>2008</option>
	</select>
	<br>do: <select size=1 name=dodzien>
	  "; 
	  if ($dodzien > "") echo "<option selected>$dodzien</option>"; 
	  echo "
	  <option>01</option>
	  <option>02</option>
	  <option>03</option>
	  <option>04</option>
	  <option>05</option>
	  <option>06</option>
	  <option>07</option>
	  <option>08</option>
	  <option>09</option>
	  <option>10</option>
	  <option>11</option>
	  <option>12</option>
	  <option>13</option>
	  <option>14</option>
	  <option>15</option>
	  <option>16</option>
	  <option>17</option>
	  <option>18</option>
	  <option>19</option>
	  <option>20</option>
	  <option>21</option>
	  <option>22</option>
	  <option>23</option>
	  <option>24</option>
	  <option>25</option>
	  <option>26</option>
	  <option>27</option>
	  <option>28</option>
	  <option>29</option>
	  <option>30</option>
	  <option>31</option>
	</select>
	
	<select size=1 name=domiesiac>
	  "; 
	  if ($domiesiac > "") echo "<option selected>$domiesiac</option>"; 
	  echo "
	  <option>01</option>
	  <option>02</option>
	  <option>03</option>
	  <option>04</option>
	  <option>05</option>
	  <option>06</option>
	  <option>07</option>
	  <option>08</option>
	  <option>09</option>
	  <option>10</option>
	  <option>11</option>
	  <option>12</option>
	</select>
	
	<select size=1 name=dorok>
	  "; 
	  if ($dorok > "") echo "<option selected>$dorok</option>"; 
	  echo "
	  <option>2003</option>
	  <option>2004</option>
	  <option>2005</option>
	  <option>2006</option>
	  <option>2007</option>
	  <option>2008</option>
	</select>
	<br><br><center><input type=submit value=Szukaj></center>
	</form>";

if ($odrok > "" and $odmiesiac > "")
{
$dodzien = $dodzien+1;
$search = "and log.dataczas>=$odrok$odmiesiac$oddzien and log.dataczas<=$dorok$domiesiac$dodzien";
}
else
$limit = "LIMIT 10";

echo "
	</td>
	</tr>
	</table>
	<br>
	</center>
	";

?>