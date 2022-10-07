<?php

function check_email ($email)
	{ return (bolean) preg_match
	('/^[\w-]+(\.[\w-]+)*@([\w-]+\.)+[a-zA-Z]{2,6}$/',$string);
	}
	
?>