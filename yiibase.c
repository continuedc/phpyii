/*
  +----------------------------------------------------------------------+
  | Yii Framework as PHP extension                                       |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Baoqiang Su  <zmrnet@qq.com>                                 |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "main/SAPI.h"

#include "php_yii.h"
#include "yiibase.h"

zend_class_entry *yiibase_ce;

/** {{{ ARG_INFO
 */
ZEND_BEGIN_ARG_INFO_EX(yiibase_getversion_arginfo, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yiibase_createwebapp_arginfo, 0, 0, 0)
    ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yiibase_createconsoleapp_arginfo, 0, 0, 0)
    ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yiibase_createapplication_arginfo, 0, 0, 0)
    ZEND_ARG_INFO(0, class)
    ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yiibase_app_arginfo, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yiibase_setapplication_arginfo, 0, 0, 0)
    ZEND_ARG_INFO(0, app)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yiibase_getframeworkpath_arginfo, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yiibase_createcomponent_arginfo, 0, 0, 0)
    ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yiibase_import_arginfo, 0, 0, 0)
    ZEND_ARG_INFO(0, alias)
    ZEND_ARG_INFO(0, forceInclude)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yiibase_getpathofalias_arginfo, 0, 0, 0)
    ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yiibase_setpathofalias_arginfo, 0, 0, 0)
    ZEND_ARG_INFO(0, alias)
    ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yiibase_autoload_arginfo, 0, 0, 1)
    ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yiibase_trace_arginfo, 0, 0, 1)
    ZEND_ARG_INFO(0, msg)
    ZEND_ARG_INFO(0, category)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yiibase_log_arginfo, 0, 0, 1)
    ZEND_ARG_INFO(0, msg)
    ZEND_ARG_INFO(0, level)
    ZEND_ARG_INFO(0, category)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yiibase_beginprofile_arginfo, 0, 0, 1)
    ZEND_ARG_INFO(0, token)
    ZEND_ARG_INFO(0, category)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yiibase_endprofile_arginfo, 0, 0, 0)
    ZEND_ARG_INFO(0, token)
    ZEND_ARG_INFO(0, category)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yiibase_getlogger_arginfo, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yiibase_setlogger_arginfo, 0, 0, 0)
    ZEND_ARG_INFO(0, logger)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yiibase_powered_arginfo, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yiibase_t_arginfo, 0, 0, 0)
    ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(yiibase_registerautoloader_arginfo, 0, 0, 0)
    ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()
/* }}} */

/** {{{ proto public static YiiBase::getVersion(void)
*/
PHP_METHOD(yiibase, getVersion) {
	 RETURN_STRING(YII_VERSION, 1);
}
/* }}} */

/** {{{ proto public static YiiBase::createWebApplication($config=null)
*/
PHP_METHOD(yiibase, createWebApplication) {
    RETURN_STRING(YII_VERSION, 1);
}
/* }}} */

/** {{{ proto public static YiiBase::createConsoleApplication($config=null)
*/
PHP_METHOD(yiibase, createConsoleApplication) {
  	char *path = "yiix.php";

  	zend_file_handle file_handle;
  	zend_op_array 	*op_array;
  	char realpath[MAXPATHLEN];

  	if (!VCWD_REALPATH(path, realpath)) {
  	//	return 0;
  	}

  	file_handle.type = ZEND_HANDLE_FILENAME;
  	file_handle.filename = path;
  	file_handle.opened_path = NULL;
  	file_handle.free_filename = 0;

  	zend_execute_scripts(ZEND_INCLUDE TSRMLS_CC, NULL, 1, &file_handle);

}
/* }}} */


/** {{{ proto public static YiiBase::createApplication($class,$config=null)
*/
PHP_METHOD(yiibase, createApplication) {
    RETURN_STRING(YII_VERSION, 1);
}
/* }}} */

/** {{{ proto public static YiiBase::app(void)
*/
PHP_METHOD(yiibase, app) {
    RETURN_STRING(YII_VERSION, 1);
}
/* }}} */

/** {{{ proto public static YiiBase::setApplication($app)
*/
PHP_METHOD(yiibase, setApplication) {
    RETURN_STRING(YII_VERSION, 1);
}
/* }}} */

/** {{{ proto public static YiiBase::getFrameworkPath(void)
*/
PHP_METHOD(yiibase, getFrameworkPath) {
    RETURN_STRING(YII_VERSION, 1);
}
/* }}} */

/** {{{ proto public static YiiBase::createComponent($config)
*/
PHP_METHOD(yiibase, createComponent) {
    RETURN_STRING(YII_VERSION, 1);
}
/* }}} */

/** {{{ proto public static YiiBase::import($alias,$forceInclude=false)
*/
PHP_METHOD(yiibase, import) {
    RETURN_STRING(YII_VERSION, 1);
}
/* }}} */

/** {{{ proto public static YiiBase::getPathOfAlias($alias)
*/
PHP_METHOD(yiibase, getPathOfAlias) {
    RETURN_STRING(YII_VERSION, 1);
}
/* }}} */

/** {{{ proto public static YiiBase::setPathOfAlias($alias,$path)
*/
PHP_METHOD(yiibase, setPathOfAlias) {
    RETURN_STRING(YII_VERSION, 1);
}
/* }}} */

/** {{{ proto public static YiiBase::autoload($className)
*/
PHP_METHOD(yiibase, autoload) {
    RETURN_STRING(YII_VERSION, 1);
}
/* }}} */

/** {{{ proto public static YiiBase::trace($msg,$category='application')
*/
PHP_METHOD(yiibase, trace) {
    RETURN_STRING(YII_VERSION, 1);
}
/* }}} */

/** {{{ proto public static YiiBase::log($msg,$level=CLogger::LEVEL_INFO,$category='application')
*/
PHP_METHOD(yiibase, log) {
    RETURN_STRING(YII_VERSION, 1);
}
/* }}} */

/** {{{ proto public static YiiBase::beginProfile($token,$category='application')
*/
PHP_METHOD(yiibase, beginProfile) {
    RETURN_STRING(YII_VERSION, 1);
}
/* }}} */

/** {{{ proto public static YiiBase::endProfile($token,$category='application')
*/
PHP_METHOD(yiibase, endProfile) {
    RETURN_STRING(YII_VERSION, 1);
}
/* }}} */

/** {{{ proto public static YiiBase::getLogger(void)
*/
PHP_METHOD(yiibase, getLogger) {
    RETURN_STRING(YII_VERSION, 1);
}
/* }}} */

/** {{{ proto public static YiiBase::setLogger($logger)
*/
PHP_METHOD(yiibase, setLogger) {
    RETURN_STRING(YII_VERSION, 1);
}
/* }}} */

/** {{{ proto public static YiiBase::powered()
*/
PHP_METHOD(yiibase, powered) {
    RETURN_STRING(YII_VERSION, 1);
}
/* }}} */

/** {{{ proto public static YiiBase::t($category,$message,$params=array(),$source=null,$language=null)
*/
PHP_METHOD(yiibase, t) {
    RETURN_STRING(YII_VERSION, 1);
}
/* }}} */

/** {{{ proto public static YiiBase::registerAutoloader($callback, $append=false)
*/
PHP_METHOD(yiibase, registerAutoloader) {
    RETURN_STRING(YII_VERSION, 1);
}
/* }}} */

/** {{{ yiibase_methods[]
*/
zend_function_entry yiibase_methods[] = {
  	PHP_ME(yiibase, getVersion, yiibase_getversion_arginfo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    PHP_ME(yiibase, createWebApplication, yiibase_createwebapp_arginfo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  	PHP_ME(yiibase, createConsoleApplication, yiibase_createconsoleapp_arginfo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    PHP_ME(yiibase, createApplication, yiibase_createapplication_arginfo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    PHP_ME(yiibase, app, yiibase_app_arginfo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    PHP_ME(yiibase, setApplication, yiibase_setapplication_arginfo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    PHP_ME(yiibase, getFrameworkPath, yiibase_getframeworkpath_arginfo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    PHP_ME(yiibase, createComponent, yiibase_createcomponent_arginfo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    PHP_ME(yiibase, import, yiibase_import_arginfo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    PHP_ME(yiibase, getPathOfAlias, yiibase_getpathofalias_arginfo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    PHP_ME(yiibase, setPathOfAlias, yiibase_setpathofalias_arginfo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    PHP_ME(yiibase, autoload, yiibase_autoload_arginfo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    PHP_ME(yiibase, trace, yiibase_trace_arginfo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    PHP_ME(yiibase, log, yiibase_log_arginfo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    PHP_ME(yiibase, beginProfile, yiibase_beginprofile_arginfo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    PHP_ME(yiibase, endProfile, yiibase_endprofile_arginfo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    PHP_ME(yiibase, getLogger, yiibase_getlogger_arginfo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    PHP_ME(yiibase, setLogger, yiibase_setlogger_arginfo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    PHP_ME(yiibase, powered, yiibase_powered_arginfo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    PHP_ME(yiibase, t, yiibase_t_arginfo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    PHP_ME(yiibase, registerAutoloader, yiibase_autoload_arginfo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  	{NULL, NULL, NULL}
};
/* }}} */

/** {{{ PHP_MINIT_FUNCTION
*/
PHP_MINIT_FUNCTION(yiibase) {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "YiiBase", yiibase_methods);
    yiibase_ce = zend_register_internal_class(&ce TSRMLS_CC);

    return SUCCESS;
}
/* }}} */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
