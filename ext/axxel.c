
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include "php_ext.h"
#include "axxel.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"

zend_class_entry *axxel_acl_ce;
zend_class_entry *axxel_client_ce;
zend_class_entry *axxel_exception_ce;

ZEND_DECLARE_MODULE_GLOBALS(axxel)

PHP_MINIT_FUNCTION(axxel){

	ZEPHIR_INIT(Axxel_Acl);
	ZEPHIR_INIT(Axxel_Client);
	ZEPHIR_INIT(Axxel_Exception);
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(axxel){

	assert(ZEPHIR_GLOBAL(function_cache) == NULL);
	//assert(ZEPHIR_GLOBAL(orm).parser_cache == NULL);
	//assert(ZEPHIR_GLOBAL(orm).ast_cache == NULL);

	return SUCCESS;
}
#endif

static PHP_RINIT_FUNCTION(axxel){

	php_zephir_init_globals(ZEPHIR_VGLOBAL TSRMLS_CC);
	//axxel_init_interned_strings(TSRMLS_C);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(axxel){

	if (ZEPHIR_GLOBAL(start_memory) != NULL) {
		zephir_clean_restore_stack(TSRMLS_C);
	}

	if (ZEPHIR_GLOBAL(function_cache) != NULL) {
		zend_hash_destroy(ZEPHIR_GLOBAL(function_cache));
		FREE_HASHTABLE(ZEPHIR_GLOBAL(function_cache));
		ZEPHIR_GLOBAL(function_cache) = NULL;
	}

	return SUCCESS;
}

static PHP_MINFO_FUNCTION(axxel)
{
	php_info_print_table_start();
	php_info_print_table_row(2, "Version", PHP_AXXEL_VERSION);
	php_info_print_table_end();
}

static PHP_GINIT_FUNCTION(axxel)
{
	zephir_memory_entry *start;

	php_zephir_init_globals(axxel_globals TSRMLS_CC);

	/* Start Memory Frame */
	start = (zephir_memory_entry *) pecalloc(1, sizeof(zephir_memory_entry), 1);
	start->addresses       = pecalloc(24, sizeof(zval*), 1);
	start->capacity        = 24;
	start->hash_addresses  = pecalloc(8, sizeof(zval*), 1);
	start->hash_capacity   = 8;

	axxel_globals->start_memory = start;

	/* Global Constants */
	ALLOC_PERMANENT_ZVAL(axxel_globals->global_false);
	INIT_PZVAL(axxel_globals->global_false);
	ZVAL_FALSE(axxel_globals->global_false);
	Z_ADDREF_P(axxel_globals->global_false);

	ALLOC_PERMANENT_ZVAL(axxel_globals->global_true);
	INIT_PZVAL(axxel_globals->global_true);
	ZVAL_TRUE(axxel_globals->global_true);
	Z_ADDREF_P(axxel_globals->global_true);

	ALLOC_PERMANENT_ZVAL(axxel_globals->global_null);
	INIT_PZVAL(axxel_globals->global_null);
	ZVAL_NULL(axxel_globals->global_null);
	Z_ADDREF_P(axxel_globals->global_null);
}

static PHP_GSHUTDOWN_FUNCTION(axxel)
{
	assert(axxel_globals->start_memory != NULL);

	pefree(axxel_globals->start_memory->hash_addresses, 1);
	pefree(axxel_globals->start_memory->addresses, 1);
	pefree(axxel_globals->start_memory, 1);
	axxel_globals->start_memory = NULL;
}

zend_module_entry axxel_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_AXXEL_EXTNAME,
	NULL,
	PHP_MINIT(axxel),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(axxel),
#else
	NULL,
#endif
	PHP_RINIT(axxel),
	PHP_RSHUTDOWN(axxel),
	PHP_MINFO(axxel),
	PHP_AXXEL_VERSION,
	ZEND_MODULE_GLOBALS(axxel),
	PHP_GINIT(axxel),
	PHP_GSHUTDOWN(axxel),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_AXXEL
ZEND_GET_MODULE(axxel)
#endif
