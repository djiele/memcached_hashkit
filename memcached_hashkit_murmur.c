/* {{{ string memcached_hashkit_murmur( [ string $var ] )
 */
PHP_FUNCTION(memcached_hashkit_murmur)
{
    const unsigned int m = 0x5bd1e995;
    const unsigned int r = 24;
	char *var = NULL;
	size_t var_len;
    uint32_t hash = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &var, &var_len) == FAILURE) {
		return;
	}

    if (var_len <= 0 || var == NULL)
    {
        RETURN_LONG(0);
    }

    {
        uint32_t seed= (0xdeadbeef * (uint32_t)var_len);
        unsigned int h = seed ^ (uint32_t)var_len;
        const unsigned char * data= (unsigned char *)var;
        
        while(var_len >= 4) {
            unsigned int k = *(unsigned int *)data;

            k *= m;
            k ^= k >> r;
            k *= m;

            h *= m;
            h ^= k;

            data += 4;
            var_len -= 4;
        }

        // Handle the last few bytes of the input array

        switch(var_len) {
            case 3: h ^= ((uint32_t)data[2]) << 16;
            case 2: h ^= ((uint32_t)data[1]) << 8;
            case 1: h ^= data[0];
                  h *= m;
            default: break;
        };

        /*
        Do a few final mixes of the hash to ensure the last few bytes are
        well-incorporated.
        */
        h ^= h >> 13;
        h *= m;
        h ^= h >> 15;
        
        RETURN_LONG(h);
    }

    RETURN_LONG(0);
}
/* }}}*/