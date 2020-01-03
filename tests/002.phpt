--TEST--
memcached_hashkit_test1() Basic test
--SKIPIF--
<?php
if (!extension_loaded('memcached_hashkit')) {
	echo 'skip';
}
?>
--FILE--
<?php
$ret = memcached_hashkit_one_at_a_time('The quick brown fox jumps over the lazy dog');

var_dump($ret);
?>
--EXPECT--
The extension memcached_hashkit is loaded and working!
NULL
