
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
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
ZEPHIR_INIT_CLASS(Axxel_Client) {

	ZEPHIR_REGISTER_CLASS(Axxel, Client, axxel, client, axxel_client_method_entry, 0);

	zend_declare_property_null(axxel_client_ce, SL("_socket"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(axxel_client_ce, SL("_server"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(axxel_client_ce, SL("_port"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Axxel_Client, __construct) {

	zval *server_param = NULL, *port = NULL;
	zval *server = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &server_param, &port);

	if (!server_param) {
		ZEPHIR_INIT_VAR(server);
		ZVAL_STRING(server, "127.0.0.1", 1);
	} else {
		zephir_get_strval(server, server_param);
	}
	if (!port) {
		ZEPHIR_INIT_VAR(port);
		ZVAL_LONG(port, 1589);
	}


	zephir_update_property_this(this_ptr, SL("_server"), server TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_port"), port TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Axxel_Client, getAcl) {

	zval *name_param = NULL, *initialization = NULL, *acl, *_0, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &initialization);

		if (Z_TYPE_P(name_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		name = name_param;

	if (!initialization) {
		initialization = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(acl);
	object_init_ex(acl, axxel_acl_ce);
	zephir_call_method_p2_noret(acl, "__construct", this_ptr, name);
	if (zephir_is_callable(initialization TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_method_p1(_0, this_ptr, "isacl", name);
		if (!(zephir_is_true(_0))) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_array_fast_append(_1, initialization);
			zephir_call_func_p2_noret("call_user_func_array", name, _1);
		}
	}
	RETURN_CCTOR(acl);

}

PHP_METHOD(Axxel_Client, send) {

	zval *command_param = NULL, *socket, *errorNumber, *errorString, *data = NULL, *_0, *_1, *_2 = NULL, *_3 = NULL, _4 = zval_used_for_init;
	zval *command = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &command_param);

		if (Z_TYPE_P(command_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'command' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		command = command_param;



	ZEPHIR_OBS_VAR(socket);
	zephir_read_property_this(&socket, this_ptr, SL("_socket"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(errorNumber);
	ZVAL_NULL(errorNumber);
	ZEPHIR_INIT_VAR(errorString);
	ZVAL_NULL(errorString);
	if (!(zephir_is_true(socket))) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_server"), PH_NOISY_CC);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_port"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_LONG(_2, 1);
		Z_SET_ISREF_P(errorNumber);
		ZEPHIR_INIT_BNVAR(socket);
		zephir_call_func_p5(socket, "pfsockopen", _0, _1, errorNumber, errorString, _2);
		zephir_update_property_this(this_ptr, SL("_socket"), socket TSRMLS_CC);
	}
	if (!(zephir_is_true(socket))) {
		ZEPHIR_INIT_NVAR(_2);
		object_init_ex(_2, axxel_exception_ce);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_VSVS(_3, errorString, " (", errorNumber, ")");
		zephir_call_method_p1_noret(_2, "__construct", _3);
		zephir_throw_exception(_2 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(data);
	ZVAL_NULL(data);
	ZEPHIR_INIT_LNVAR(_3);
	ZEPHIR_CONCAT_VS(_3, command, "\n");
	zephir_call_func_p2_noret("fwrite", socket, _3);
	while (1) {
		ZEPHIR_INIT_NVAR(_2);
		zephir_call_func_p1(_2, "feof", socket);
		if (!(!(zephir_is_true(_2)))) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 128);
		ZEPHIR_INIT_NVAR(data);
		zephir_call_func_p2(data, "fgets", socket, &_4);
		if (zephir_end_with_str(data, SL("\n"))) {
			break;
		}
	}
	zephir_call_func_p1(return_value, "json_decode", data);
	RETURN_MM();

}

PHP_METHOD(Axxel_Client, createAcl) {

	zval *name_param = NULL, *status, *_0, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		if (Z_TYPE_P(name_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		name = name_param;



	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "addslashes", name);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVS(_1, "var a = axxel.createAcl('", _0, "'); typeof a == 'object';");
	ZEPHIR_INIT_VAR(status);
	zephir_call_method_p1(status, this_ptr, "send", _1);
	object_init_ex(return_value, axxel_acl_ce);
	zephir_call_method_p2_noret(return_value, "__construct", this_ptr, name);
	RETURN_MM();

}

PHP_METHOD(Axxel_Client, isAcl) {

	zval *name_param = NULL, *status, *_0, *_1, *_2, *_3;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		if (Z_TYPE_P(name_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		name = name_param;



	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "addslashes", name);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVS(_1, "axxel.isAcl('", _0, "')");
	ZEPHIR_INIT_VAR(status);
	zephir_call_method_p1(status, this_ptr, "send", _1);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, status, SL("status"), PH_NOISY_CC);
	if (ZEPHIR_IS_STRING(_2, "ok")) {
		ZEPHIR_OBS_VAR(_3);
		zephir_read_property(&_3, status, SL("result"), PH_NOISY_CC);
		RETURN_MM_BOOL(zephir_get_boolval(_3));
	}
	RETURN_MM_BOOL(0);

}

