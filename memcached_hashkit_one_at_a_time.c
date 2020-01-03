/* {{{ string memcached_hashkit_one_at_a_time( [ string $var ] )
 */
PHP_FUNCTION(memcached_hashkit_one_at_a_time) 
{
	char *var = NULL;
	size_t var_len = 0;
    size_t i = 0;
    uint32_t hash = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &var, &var_len) == FAILURE) {
		return;
	}

    if (var_len <= 0 || var == NULL)
        RETURN_LONG(0);

    while (i != var_len) {
        hash += var[i++];
        hash += hash << 10;
        hash ^= hash >> 6;
    }
    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
    RETURN_LONG(hash);
}
/* }}}*/