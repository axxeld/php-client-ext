
extern zend_class_entry *axxel_client_ce;

ZEPHIR_INIT_CLASS(Axxel_Client);

PHP_METHOD(Axxel_Client, __construct);
PHP_METHOD(Axxel_Client, getAcl);
PHP_METHOD(Axxel_Client, send);
PHP_METHOD(Axxel_Client, createAcl);
PHP_METHOD(Axxel_Client, isAcl);

ZEND_BEGIN_ARG_INFO_EX(arginfo_axxel_client___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, server)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_axxel_client_getacl, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, initialization)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_axxel_client_send, 0, 0, 1)
	ZEND_ARG_INFO(0, command)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_axxel_client_createacl, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_axxel_client_isacl, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(axxel_client_method_entry) {
	PHP_ME(Axxel_Client, __construct, arginfo_axxel_client___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Axxel_Client, getAcl, arginfo_axxel_client_getacl, ZEND_ACC_PUBLIC)
	PHP_ME(Axxel_Client, send, arginfo_axxel_client_send, ZEND_ACC_PUBLIC)
	PHP_ME(Axxel_Client, createAcl, arginfo_axxel_client_createacl, ZEND_ACC_PUBLIC)
	PHP_ME(Axxel_Client, isAcl, arginfo_axxel_client_isacl, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
