dnl config.m4 for extension memcached_hashkit

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(memcached_hashkit, for memcached_hashkit support,
dnl Make sure that the comment is aligned:
dnl [  --with-memcached_hashkit             Include memcached_hashkit support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(memcached_hashkit, whether to enable memcached_hashkit support,
dnl Make sure that the comment is aligned:
[  --enable-memcached-hashkit          Enable memcached_hashkit support], no)

if test "$PHP_MEMCACHED_HASHKIT" != "no"; then
  dnl Write more examples of tests here...

  dnl # get library FOO build options from pkg-config output
  dnl AC_PATH_PROG(PKG_CONFIG, pkg-config, no)
  dnl AC_MSG_CHECKING(for libfoo)
  dnl if test -x "$PKG_CONFIG" && $PKG_CONFIG --exists foo; then
  dnl   if $PKG_CONFIG foo --atleast-version 1.2.3; then
  dnl     LIBFOO_CFLAGS=\`$PKG_CONFIG foo --cflags\`
  dnl     LIBFOO_LIBDIR=\`$PKG_CONFIG foo --libs\`
  dnl     LIBFOO_VERSON=\`$PKG_CONFIG foo --modversion\`
  dnl     AC_MSG_RESULT(from pkgconfig: version $LIBFOO_VERSON)
  dnl   else
  dnl     AC_MSG_ERROR(system libfoo is too old: version 1.2.3 required)
  dnl   fi
  dnl else
  dnl   AC_MSG_ERROR(pkg-config not found)
  dnl fi
  dnl PHP_EVAL_LIBLINE($LIBFOO_LIBDIR, MEMCACHED_HASHKIT_SHARED_LIBADD)
  dnl PHP_EVAL_INCLINE($LIBFOO_CFLAGS)

  dnl # --with-memcached_hashkit -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/memcached_hashkit.h"  # you most likely want to change this
  dnl if test -r $PHP_MEMCACHED_HASHKIT/$SEARCH_FOR; then # path given as parameter
  dnl   MEMCACHED_HASHKIT_DIR=$PHP_MEMCACHED_HASHKIT
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for memcached_hashkit files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       MEMCACHED_HASHKIT_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$MEMCACHED_HASHKIT_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the memcached_hashkit distribution])
  dnl fi

  dnl # --with-memcached_hashkit -> add include path
  dnl PHP_ADD_INCLUDE($MEMCACHED_HASHKIT_DIR/include)

  dnl # --with-memcached_hashkit -> check for lib and symbol presence
  dnl LIBNAME=MEMCACHED_HASHKIT # you may want to change this
  dnl LIBSYMBOL=MEMCACHED_HASHKIT # you most likely want to change this

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $MEMCACHED_HASHKIT_DIR/$PHP_LIBDIR, MEMCACHED_HASHKIT_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_MEMCACHED_HASHKITLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong memcached_hashkit lib version or lib not found])
  dnl ],[
  dnl   -L$MEMCACHED_HASHKIT_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(MEMCACHED_HASHKIT_SHARED_LIBADD)

  dnl # In case of no dependencies
  AC_DEFINE(HAVE_MEMCACHED_HASHKIT, 1, [ Have memcached_hashkit support ])

  PHP_NEW_EXTENSION(memcached_hashkit, memcached_hashkit.c, $ext_shared)
fi
