/* memcached_hashkit extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_memcached_hashkit.h"
#include "memcached_hashkit_one_at_a_time.c"
#include "memcached_hashkit_murmur.c"
#include "memcached_hashkit_hsieh.c"
#include "memcached_hashkit_fnv.c"


/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(memcached_hashkit)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(memcached_hashkit)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(memcached_hashkit)
{
#if PHP_MAJOR_VERSION > 5 && defined(COMPILE_DL_MEMCACHED_HASHKIT) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(memcached_hashkit)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(memcached_hashkit)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "memcached_hashkit support", "enabled");
    php_info_print_table_row(2, "Version", PHP_MEMCACHED_HASHKIT_VERSION);
	php_info_print_table_end();
}
/* }}} */

/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO(arginfo_memcached_hashkit_one_at_a_time, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_memcached_hashkit_murmur, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_memcached_hashkit_hsieh, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_memcached_hashkit_fnv1_64, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_memcached_hashkit_fnv1a_64, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_memcached_hashkit_fnv1_32, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_memcached_hashkit_fnv1a_32, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ memcached_hashkit_functions[]
 */
static const zend_function_entry memcached_hashkit_functions[] = {
	PHP_FE(memcached_hashkit_one_at_a_time,		arginfo_memcached_hashkit_one_at_a_time)
	PHP_FE(memcached_hashkit_murmur,		    arginfo_memcached_hashkit_murmur)
	PHP_FE(memcached_hashkit_hsieh,		        arginfo_memcached_hashkit_hsieh)
	PHP_FE(memcached_hashkit_fnv1_64,		    arginfo_memcached_hashkit_fnv1_64)
	PHP_FE(memcached_hashkit_fnv1a_64,		    arginfo_memcached_hashkit_fnv1a_64)
	PHP_FE(memcached_hashkit_fnv1_32,		    arginfo_memcached_hashkit_fnv1_32)
	PHP_FE(memcached_hashkit_fnv1a_32,		    arginfo_memcached_hashkit_fnv1a_32)
	PHP_FE_END
};
/* }}} */

/* {{{ memcached_hashkit_module_entry
 */
zend_module_entry memcached_hashkit_module_entry = {
	STANDARD_MODULE_HEADER,
	"memcached_hashkit",					/* Extension name */
	memcached_hashkit_functions,			/* zend_function_entry */
	PHP_MINIT(memcached_hashkit),			/* PHP_MINIT - Module initialization */
	PHP_MSHUTDOWN(memcached_hashkit),		/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(memcached_hashkit),			/* PHP_RINIT - Request initialization */
	PHP_RSHUTDOWN(memcached_hashkit),		/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(memcached_hashkit),			/* PHP_MINFO - Module info */
	PHP_MEMCACHED_HASHKIT_VERSION,		    /* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_MEMCACHED_HASHKIT
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE();
# endif
ZEND_GET_MODULE(memcached_hashkit);
#endif

