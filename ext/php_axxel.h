
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_AXXEL_H
#define PHP_AXXEL_H 1

#include "kernel/globals.h"

#define PHP_AXXEL_NAME    "axxel"
#define PHP_AXXEL_VERSION "0.0.1"
#define PHP_AXXEL_EXTNAME "axxel"



ZEND_BEGIN_MODULE_GLOBALS(axxel)

	/* Memory */
	zephir_memory_entry *start_memory;
	zephir_memory_entry *active_memory;

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/* Function cache */
	HashTable *function_cache;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(axxel)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(axxel)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(axxel_globals_id, zend_axxel_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (axxel_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_axxel_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(axxel_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(axxel_globals)
#endif

#define zephir_globals axxel_globals
#define zend_zephir_globals zend_axxel_globals

extern zend_module_entry axxel_module_entry;
#define phpext_axxel_ptr &axxel_module_entry

#endif
