#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([btdownload], [0.1], [songchenglin92@gmail.com])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([btdownload/main.c])
LT_INIT

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([libdebug], [log_print])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([
                 Makefile
                 btdownload/Makefile
                 debug/Makefile
                 ])
AC_OUTPUT
