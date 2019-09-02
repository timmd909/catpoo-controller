AC_INIT([catpoo_controller], [0.1], [tim@tim-doerzbacher.com])
AM_INIT_AUTOMAKE([-Wall foreign])

AC_CONFIG_HEADERS([config.h])

dnl Switch to a C++ compiler, and check if it works.
AC_LANG(C++)
AC_PROG_CC
AC_PROG_CXX

dnl Check for requirements
AC_CHECK_HEADERS([wiringPi.h], [], [AC_MSG_ERROR([Unable to find wiringPi header])])

dnl Process Makefile.in to create Makefile
AC_CONFIG_FILES([
  Makefile
  src/Makefile
])

AC_OUTPUT
