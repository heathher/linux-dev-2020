AC_PREREQ([2.69])
AC_INIT([main], [1.0.0], [nikolaevaytalina@gmail.com])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_SRCDIR([main.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([libintl.h locale.h stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([realpath setlocale])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

define(DATE, `date`)dnl
define(MESSAGE, [\/\* COMMENT:: AC_PACKAGE_NAME, AC_PACKAGE_VERSION: DATE \*\/])dnl
sed -i -s "1 s/^\/\* COMMENT::.*\*\//MESSAGE/; t; 1 s/^/MESSAGE\n/;" *.{c,h}
