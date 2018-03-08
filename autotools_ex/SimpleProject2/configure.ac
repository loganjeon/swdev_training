AC_INIT([simpleproject], [1.0])

AC_CONFIG_SRCDIR([src/simple_project2.c])
AC_CONFIG_SRCDIR([libfoo/libfoo.c])
AM_INIT_AUTOMAKE

AC_PROG_CC
AC_PROG_RANLIB

CFLAGS=
LDFLAGS=
LIBS=

AC_DEFUN([REQUIRE_LIB], [ { 
						AC_ARG_WITH([$1], AC_HELP_STRING([--with-$1=<path>], [Location where $4 is installed]), [], [with_$1=default])

						AS_IF( [test "x$with_$1" != xdefault],
						[
						 	LDFLAGS="$LDFLAGS -L${with_$1}/lib"
							CFLAGS="$CFLAGS -I$(with_$1)/include"
					    ])

						AC_CHECK_LIB($2,$3,[],
						[
						 	AC_MSG_ERROR([$4 was not found, try specifying --with-$1])
						])
						
}])


AC_OUTPUT(Makefile src/Makefile libfoo/Makefile)

