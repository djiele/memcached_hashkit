--TEST--
memcached_hashkit_test2() Basic test
--SKIPIF--
<?php
if (!extension_loaded('memcached_hashkit')) {
	echo 'skip';
}
?>
--FILE--
<?php
var_dump(memcached_hashkit_murmur('The quick brown fox jumps over the lazy dog'));
var_dump(memcached_hashkit_hsieh('The quick brown fox jumps over the lazy dog'));
?>
--EXPECT--
string(11) "Hello World"
string(9) "Hello PHP"
