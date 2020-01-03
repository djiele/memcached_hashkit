
/* FNV hash'es lifted from Dustin Sallings work */
static uint64_t FNV_64_INIT= UINT64_C(0xcbf29ce484222325);
static uint64_t FNV_64_PRIME= UINT64_C(0x100000001b3);
static uint32_t FNV_32_INIT= 2166136261UL;
static uint32_t FNV_32_PRIME= 16777619;

/* {{{ string memcached_hashkit_fnv1_64( [ string $var ] )
 */
PHP_FUNCTION(memcached_hashkit_fnv1_64)
{

	char *var = NULL;
	size_t var_len;
    size_t i = 0;
    uint64_t hash = FNV_64_INIT;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &var, &var_len) == FAILURE) {
		return;
	}

    if (var_len <= 0 || var == NULL)
        RETURN_LONG(0);

    for (i= 0; i < var_len; i++)
    {
        hash *= FNV_64_PRIME;
        hash ^= (uint64_t)var[i];
    }

    RETURN_LONG((uint32_t)hash);
}

/* {{{ string memcached_hashkit_fnv1a_64( [ string $var ] )
 */
PHP_FUNCTION(memcached_hashkit_fnv1a_64)
{
	char *var = NULL;
	size_t var_len;
    size_t i = 0;
    uint32_t hash = (uint32_t) FNV_64_INIT;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &var, &var_len) == FAILURE) {
		return;
	}

    if (var_len <= 0 || var == NULL)
        RETURN_LONG(0);

    for (i= 0; i < var_len; i++)
    {
        uint32_t val = (uint32_t)var[i];
        hash ^= val;
        hash *= (uint32_t) FNV_64_PRIME;
    }

    RETURN_LONG(hash);
}

/* {{{ string memcached_hashkit_fnv1_32( [ string $var ] )
 */
PHP_FUNCTION(memcached_hashkit_fnv1_32)
{
	char *var = NULL;
	size_t var_len;
    size_t i = 0;
    uint32_t hash = FNV_32_INIT;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &var, &var_len) == FAILURE) {
		return;
	}

    if (var_len <= 0 || var == NULL)
        RETURN_LONG(0);

    for (i= 0; i < var_len; i++)
    {
        uint32_t val= (uint32_t)var[i];
        hash *= FNV_32_PRIME;
        hash ^= val;
    }

    RETURN_LONG(hash);
}

/* {{{ string memcached_hashkit_fnv1a_32( [ string $var ] )
 */
PHP_FUNCTION(memcached_hashkit_fnv1a_32)
{
	char *var = NULL;
	size_t var_len;
    size_t i = 0;
    uint32_t hash = FNV_32_INIT;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &var, &var_len) == FAILURE) {
		return;
	}

    if (var_len <= 0 || var == NULL)
        RETURN_LONG(0);

    for (i= 0; i < var_len; i++)
    {
        uint32_t val= (uint32_t)var[i];
        hash ^= val;
        hash *= FNV_32_PRIME;
    }

    RETURN_LONG(hash);
}