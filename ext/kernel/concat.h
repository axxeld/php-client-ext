#define ZEPHIR_CONCAT_SVS(result, op1, op2, op3) \
	 zephir_concat_svs(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_SVS(result, op1, op2, op3) \
	 zephir_concat_svs(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_SVSVS(result, op1, op2, op3, op4, op5) \
	 zephir_concat_svsvs(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_SVSVS(result, op1, op2, op3, op4, op5) \
	 zephir_concat_svsvs(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_SVSVSVSVS(result, op1, op2, op3, op4, op5, op6, op7, op8, op9) \
	 zephir_concat_svsvsvsvs(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, op7, sizeof(op7)-1, op8, op9, sizeof(op9)-1, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_SVSVSVSVS(result, op1, op2, op3, op4, op5, op6, op7, op8, op9) \
	 zephir_concat_svsvsvsvs(&result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, op7, sizeof(op7)-1, op8, op9, sizeof(op9)-1, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_VS(result, op1, op2) \
	 zephir_concat_vs(&result, op1, op2, sizeof(op2)-1, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_VS(result, op1, op2) \
	 zephir_concat_vs(&result, op1, op2, sizeof(op2)-1, 1 TSRMLS_CC);

#define ZEPHIR_CONCAT_VSVS(result, op1, op2, op3, op4) \
	 zephir_concat_vsvs(&result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, 0 TSRMLS_CC);
#define ZEPHIR_SCONCAT_VSVS(result, op1, op2, op3, op4) \
	 zephir_concat_vsvs(&result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, 1 TSRMLS_CC);


void zephir_concat_svs(zval **result, const char *op1, zend_uint op1_len, zval *op2, const char *op3, zend_uint op3_len, int self_var TSRMLS_DC);
void zephir_concat_svsvs(zval **result, const char *op1, zend_uint op1_len, zval *op2, const char *op3, zend_uint op3_len, zval *op4, const char *op5, zend_uint op5_len, int self_var TSRMLS_DC);
void zephir_concat_svsvsvsvs(zval **result, const char *op1, zend_uint op1_len, zval *op2, const char *op3, zend_uint op3_len, zval *op4, const char *op5, zend_uint op5_len, zval *op6, const char *op7, zend_uint op7_len, zval *op8, const char *op9, zend_uint op9_len, int self_var TSRMLS_DC);
void zephir_concat_vs(zval **result, zval *op1, const char *op2, zend_uint op2_len, int self_var TSRMLS_DC);
void zephir_concat_vsvs(zval **result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, const char *op4, zend_uint op4_len, int self_var TSRMLS_DC);
