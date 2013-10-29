PHP_ARG_ENABLE(axxel, whether to enable axxel, [ --enable-axxel   Enable Axxel])

if test "$PHP_AXXEL" = "yes"; then
	AC_DEFINE(HAVE_AXXEL, 1, [Whether you have Axxel])
	axxel_sources="axxel.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/alternative/fcall.c kernel/file.c kernel/operators.c kernel/concat.c axxel/acl.c axxel/client.c axxel/exception.c"
	PHP_NEW_EXTENSION(axxel, $axxel_sources, $ext_shared)
fi
