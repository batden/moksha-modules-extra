dnl Process this file with autoconf to produce a configure script.

# get rid of that stupid cache mechanism
rm -f config.cache

AC_INIT([engage],[1.0.0],[moksha@bodhilinux.com])
AC_PREREQ([2.71])

AC_CANONICAL_BUILD
AC_CANONICAL_HOST

AM_INIT_AUTOMAKE(1.6)
AC_CONFIG_SRCDIR(configure.ac)
AC_CONFIG_HEADERS(config.h)

AC_SEARCH_LIBS([strerror],[cposix])
AC_PROG_CC

AC_CHECK_INCLUDES_DEFAULT
AC_PROG_EGREP

AC_C_CONST
AC_C___ATTRIBUTE__
AC_ENABLE_SHARED([])
LT_INIT

m4_ifdef([AM_GNU_GETTEXT_VERSION], [
AM_GNU_GETTEXT_VERSION([0.19])
])

m4_ifdef([AM_GNU_GETTEXT], [
AM_GNU_GETTEXT([external])
po_makefile_in=po/Makefile.in
AM_CONDITIONAL([HAVE_PO], [true])
],[
AM_CONDITIONAL([HAVE_PO], [false])
])
AC_SUBST(LTLIBINTL)

release=$(pkg-config --variable=release enlightenment)
MODULE_ARCH="$host_os-$host_cpu"
AC_SUBST(MODULE_ARCH)
AC_DEFINE_UNQUOTED(MODULE_ARCH, "$MODULE_ARCH", "Module architecture")

# Find edje_cc
PKG_CHECK_MODULES(EDJE, [edje >= 0.5.0])
AC_ARG_WITH(edje-cc,
  AS_HELP_STRING([--with-edje-cc=PATH],[specify a specific path to edje_cc]),
  [
    v=$withval;
    EDJE_CC=$v
  ],[
    EDJE_CC=$(pkg-config --variable=prefix edje)/bin/edje_cc
  ]
)
AC_SUBST(EDJE_CC)
AC_MSG_CHECKING([Which edje_cc to use])
AC_MSG_RESULT(${EDJE_CC})

PKG_CHECK_MODULES(E, [enlightenment])

datadir=$(pkg-config --variable=modules enlightenment)/${PACKAGE}
AC_ARG_ENABLE(homedir-install,
  AS_HELP_STRING([--enable-homedir-install], [Install module in homedir]),
  [ datadir="${HOME}/.e/e/modules/${PACKAGE}" ]
)

AC_CONFIG_FILES([
Makefile
data/Makefile
data/themes/Makefile
src/Makefile
module.desktop
$po_makefile_in
])
AC_CONFIG_COMMANDS([default],[
],[])
AC_OUTPUT

