
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"


/**
 *
 * Axxel - Acl memory caching
 *
 * Copyright (c) 2013 Axxel Team
 *
 * Use and distribution licensed under the MIT license.
 * See the LICENSE file for full text.
 *
 * Authors: Andres Gutierrez <andres@phalconphp.com>
 */
ZEPHIR_INIT_CLASS(Axxel_Acl) {

	ZEPHIR_REGISTER_CLASS(Axxel, Acl, axxel, acl, axxel_acl_method_entry, 0);

	zend_declare_property_null(axxel_acl_ce, SL("_axxel"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(axxel_acl_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Axxel_Acl, __construct) {

	zval *name = NULL;
	zval *axxel, *name_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &axxel, &name_param);

		if (Z_TYPE_P(name_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		name = name_param;



	zephir_update_property_this(this_ptr, SL("_axxel"), axxel TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Axxel_Acl, addRole) {

	zval *name_param = NULL, *_0, *_1, *_2, *_3, *_4;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		if (Z_TYPE_P(name_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		name = name_param;



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_axxel"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p1(_2, "addslashes", _1);
	ZEPHIR_INIT_VAR(_3);
	zephir_call_func_p1(_3, "addslashes", name);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SVSVS(_4, "typeof axxel.getAcl('", _2, "').addRole('", _3, "')=='object';");
	zephir_call_method_p1(return_value, _0, "send", _4);
	RETURN_MM();

}

PHP_METHOD(Axxel_Acl, isRole) {

	zval *name_param = NULL, *_0, *_1, *_2, *_3, *_4;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		if (Z_TYPE_P(name_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		name = name_param;



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_axxel"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p1(_2, "addslashes", _1);
	ZEPHIR_INIT_VAR(_3);
	zephir_call_func_p1(_3, "addslashes", name);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SVSVS(_4, "axxel.getAcl('", _2, "').isRole('", _3, "');");
	zephir_call_method_p1(return_value, _0, "send", _4);
	RETURN_MM();

}

PHP_METHOD(Axxel_Acl, getRoles) {

	zval *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_axxel"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p1(_2, "addslashes", _1);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVS(_3, "JSON.stringify(axxel.getAcl('", _2, "').getRoles());");
	zephir_call_method_p1(return_value, _0, "send", _3);
	RETURN_MM();

}

PHP_METHOD(Axxel_Acl, addResource) {

	zval *name_param = NULL, *_0, *_1, *_2, *_3, *_4;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		if (Z_TYPE_P(name_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		name = name_param;



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_axxel"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p1(_2, "addslashes", _1);
	ZEPHIR_INIT_VAR(_3);
	zephir_call_func_p1(_3, "addslashes", name);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SVSVS(_4, "typeof axxel.getAcl('", _2, "').addResource('", _3, "')=='object';");
	zephir_call_method_p1(return_value, _0, "send", _4);
	RETURN_MM();

}

PHP_METHOD(Axxel_Acl, isResource) {

	zval *name_param = NULL, *_0, *_1, *_2, *_3, *_4;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		if (Z_TYPE_P(name_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		name = name_param;



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_axxel"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p1(_2, "addslashes", _1);
	ZEPHIR_INIT_VAR(_3);
	zephir_call_func_p1(_3, "addslashes", name);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SVSVS(_4, "axxel.getAcl('", _2, "').isResource('", _3, "');");
	zephir_call_method_p1(return_value, _0, "send", _4);
	RETURN_MM();

}

PHP_METHOD(Axxel_Acl, getResources) {

	zval *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_axxel"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p1(_2, "addslashes", _1);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVS(_3, "JSON.stringify(axxel.getAcl('", _2, "').getResources());");
	zephir_call_method_p1(return_value, _0, "send", _3);
	RETURN_MM();

}

PHP_METHOD(Axxel_Acl, allow) {

	zval *role_param = NULL, *resource_param = NULL, *action, *_0, *_1, *_2, *_3, *_4, *_5, *_6;
	zval *role = NULL, *resource = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &role_param, &resource_param, &action);

		if (Z_TYPE_P(role_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'role' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		role = role_param;

		if (Z_TYPE_P(resource_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'resource' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		resource = resource_param;



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_axxel"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p1(_2, "addslashes", _1);
	ZEPHIR_INIT_VAR(_3);
	zephir_call_func_p1(_3, "addslashes", role);
	ZEPHIR_INIT_VAR(_4);
	zephir_call_func_p1(_4, "addslashes", resource);
	ZEPHIR_INIT_VAR(_5);
	zephir_call_func_p1(_5, "addslashes", action);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_SVSVSVSVS(_6, "typeof axxel.getAcl('", _2, "').allow('", _3, "', '", _4, "', '", _5, "')=='object';");
	zephir_call_method_p1(return_value, _0, "send", _6);
	RETURN_MM();

}

PHP_METHOD(Axxel_Acl, isAllowed) {

	HashTable *_3;
	HashPosition _2;
	zval *role_param = NULL, *resource_param = NULL, *permissions, *name, *roleName, *resourceName, *perms, *status, *permission = NULL, *_0, *_1, **_4, *_5 = NULL, *_6 = NULL, *_7, *_8, *_9, *_10, *_11;
	zval *role = NULL, *resource = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &role_param, &resource_param, &permissions);

		if (Z_TYPE_P(role_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'role' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		role = role_param;

		if (Z_TYPE_P(resource_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'resource' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		resource = resource_param;



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(name);
	zephir_call_func_p1(name, "addslashes", _0);
	ZEPHIR_INIT_VAR(roleName);
	zephir_call_func_p1(roleName, "addslashes", role);
	ZEPHIR_INIT_VAR(resourceName);
	zephir_call_func_p1(resourceName, "addslashes", resource);
	ZEPHIR_INIT_VAR(status);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p1(_1, "is_array", permissions);
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_VAR(perms);
		array_init(perms);
		zephir_is_iterable(permissions, &_3, &_2, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
			; zend_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HVALUE(permission, _4);
			ZEPHIR_INIT_NVAR(_5);
			zephir_call_func_p1(_5, "addslashes", permission);
			ZEPHIR_INIT_LNVAR(_6);
			ZEPHIR_CONCAT_SVS(_6, "'", _5, "'");
			zephir_array_append(&perms, _6, PH_SEPARATE);
		}
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_axxel"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_5);
		zephir_fast_join_str(_5, SL(", "), perms TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_6);
		ZEPHIR_CONCAT_SVSVSVSVS(_6, "axxel.getAcl('", name, "').allowed('", roleName, "', '", resourceName, "', [", _5, "]);");
		zephir_call_method_p1(status, _7, "send", _6);
	} else {
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_axxel"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_8);
		zephir_call_func_p1(_8, "addslashes", permissions);
		ZEPHIR_INIT_VAR(_9);
		ZEPHIR_CONCAT_SVSVSVSVS(_9, "axxel.getAcl('", name, "').allowed('", roleName, "', '", resourceName, "', '", _8, "');");
		zephir_call_method_p1(status, _7, "send", _9);
	}
	ZEPHIR_OBS_VAR(_10);
	zephir_read_property(&_10, status, SL("status"), PH_NOISY_CC);
	if (ZEPHIR_IS_STRING(_10, "ok")) {
		ZEPHIR_OBS_VAR(_11);
		zephir_read_property(&_11, status, SL("result"), PH_NOISY_CC);
		RETURN_MM_BOOL(zephir_get_boolval(_11));
	}
	RETURN_MM_BOOL(0);

}

