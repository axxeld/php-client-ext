
extern zend_class_entry *axxel_acl_ce;

ZEPHIR_INIT_CLASS(Axxel_Acl);

PHP_METHOD(Axxel_Acl, __construct);
PHP_METHOD(Axxel_Acl, addRole);
PHP_METHOD(Axxel_Acl, isRole);
PHP_METHOD(Axxel_Acl, getRoles);
PHP_METHOD(Axxel_Acl, addResource);
PHP_METHOD(Axxel_Acl, isResource);
PHP_METHOD(Axxel_Acl, getResources);
PHP_METHOD(Axxel_Acl, allow);
PHP_METHOD(Axxel_Acl, isAllowed);

ZEND_BEGIN_ARG_INFO_EX(arginfo_axxel_acl___construct, 0, 0, 2)
  ZEND_ARG_INFO(0, axxel)
  ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_axxel_acl_addrole, 0, 0, 1)
  ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_axxel_acl_isrole, 0, 0, 1)
  ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_axxel_acl_addresource, 0, 0, 1)
  ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_axxel_acl_isresource, 0, 0, 1)
  ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_axxel_acl_allow, 0, 0, 3)
  ZEND_ARG_INFO(0, role)
  ZEND_ARG_INFO(0, resource)
  ZEND_ARG_INFO(0, action)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_axxel_acl_isallowed, 0, 0, 3)
  ZEND_ARG_INFO(0, role)
  ZEND_ARG_INFO(0, resource)
  ZEND_ARG_INFO(0, permissions)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(axxel_acl_method_entry) {
	PHP_ME(Axxel_Acl, __construct, arginfo_axxel_acl___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Axxel_Acl, addRole, arginfo_axxel_acl_addrole, ZEND_ACC_PUBLIC)
	PHP_ME(Axxel_Acl, isRole, arginfo_axxel_acl_isrole, ZEND_ACC_PUBLIC)
	PHP_ME(Axxel_Acl, getRoles, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Axxel_Acl, addResource, arginfo_axxel_acl_addresource, ZEND_ACC_PUBLIC)
	PHP_ME(Axxel_Acl, isResource, arginfo_axxel_acl_isresource, ZEND_ACC_PUBLIC)
	PHP_ME(Axxel_Acl, getResources, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Axxel_Acl, allow, arginfo_axxel_acl_allow, ZEND_ACC_PUBLIC)
	PHP_ME(Axxel_Acl, isAllowed, arginfo_axxel_acl_isallowed, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
