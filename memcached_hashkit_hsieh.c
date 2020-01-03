#undef get16bits
#if (defined(__GNUC__) && defined(__i386__))
#define get16bits(d) (*((const uint16_t *) (d)))
#endif

#if !defined (get16bits)
#define get16bits(d) ((((uint32_t)(((const uint8_t *)(d))[1])) << 8)\
                      +(uint32_t)(((const uint8_t *)(d))[0]) )
#endif

/* {{{ string memcached_hashkit_hsieh( [ string $var ] )
 */
PHP_FUNCTION(memcached_hashkit_hsieh)
{
	char *var = NULL;
	size_t var_len;
    size_t i = 0;
    uint32_t hash = 0, tmp;
    int rem;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &var, &var_len) == FAILURE) {
		return;
	}

    if (var_len <= 0 || var == NULL)
        RETURN_LONG(0);

    rem = var_len & 3;
    var_len >>= 2;

    /* Main loop */
    for (;var_len > 0; var_len--)
    {
        hash  += get16bits (var);
        tmp    = (get16bits (var+2) << 11) ^ hash;
        hash   = (hash << 16) ^ tmp;
        var  += 2*sizeof (uint16_t);
        hash  += hash >> 11;
    }

    /* Handle end cases */
    switch (rem)
    {
    case 3: hash += get16bits (var);
          hash ^= hash << 16;
          hash ^= var[sizeof (uint16_t)] << 18;
          hash += hash >> 11;
          break;
    case 2: hash += get16bits (var);
          hash ^= hash << 11;
          hash += hash >> 17;
          break;
    case 1: hash += *var;
          hash ^= hash << 10;
          hash += hash >> 1;
    }

    /* Force "avalanching" of final 127 bits */
    hash ^= hash << 3;
    hash += hash >> 5;
    hash ^= hash << 4;
    hash += hash >> 17;
    hash ^= hash << 25;
    hash += hash >> 6;

    RETURN_LONG(hash);
}
/* }}}*/