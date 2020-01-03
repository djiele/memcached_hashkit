/* memcached_hashkit extension for PHP */

#ifndef PHP_MEMCACHED_HASHKIT_H
# define PHP_MEMCACHED_HASHKIT_H

# ifndef uint32_t
#  include <stdint.h>
# endif

extern zend_module_entry memcached_hashkit_module_entry;
# define phpext_memcached_hashkit_ptr &memcached_hashkit_module_entry

# define PHP_MEMCACHED_HASHKIT_VERSION "0.1.0"

#ifdef PHP_WIN32
#   define PHP_MEMCACHED_HASHKIT_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#   define PHP_MEMCACHED_HASHKIT_API __attribute__ ((visibility("default")))
#else
#   define PHP_MEMCACHED_HASHKIT_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

/* {{{ PHP_FUNCTION declarations */
PHP_MINIT_FUNCTION(memcached_hashkit);
PHP_MSHUTDOWN_FUNCTION(memcached_hashkit);
PHP_RINIT_FUNCTION(memcached_hashkit);
PHP_RSHUTDOWN_FUNCTION(memcached_hashkit);
PHP_MINFO_FUNCTION(memcached_hashkit);
PHP_FUNCTION(memcached_hashkit_one_at_a_time);
PHP_FUNCTION(memcached_hashkit_murmur);
PHP_FUNCTION(memcached_hashkit_hsieh);
PHP_FUNCTION(memcached_hashkit_fnv1_64);
PHP_FUNCTION(memcached_hashkit_fnv1a_64);
PHP_FUNCTION(memcached_hashkit_fnv1_32);
PHP_FUNCTION(memcached_hashkit_fnv1a_32);
/* }}} */

# if defined(ZTS) && defined(COMPILE_DL_MEMCACHED_HASHKIT)
ZEND_TSRMLS_CACHE_EXTERN();
# endif


#ifdef ZTS
#define MEMCACHED_HASHKIT_G(v) TSRMG(memcached_hashkit_globals_id, zend_memcached_hashkit_globals *, v)
#else
#define MEMCACHED_HASHKIT_G(v) (memcached_hashkit_globals.v)
#endif

#endif	/* PHP_MEMCACHED_HASHKIT_H */

