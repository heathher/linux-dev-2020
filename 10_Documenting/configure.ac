AC_PREREQ([2.69])
AC_INIT([main], [1.0.0], [nikolaevaytalina@gmail.com])
AM_INIT_AUTOMAKE([foreign])
DX_INIT_DOXYGEN(main)
AC_CONFIG_SRCDIR([main.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PATH_PROG([HELP2MAN], [help2man])

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([libintl.h locale.h stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([realpath setlocale])

AC_CONFIG_FILES([Makefile Doxyfile])
AC_OUTPUT
