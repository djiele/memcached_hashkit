--TEST--
Check if memcached_hashkit is loaded
--SKIPIF--
<?php
if (!extension_loaded('memcached_hashkit')) {
	echo 'skip';
}
?>
--FILE--
<?php
echo 'The extension "memcached_hashkit" is available';
?>
--EXPECT--
The extension "memcached_hashkit" is available
