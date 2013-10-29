
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

namespace Axxel;

class Acl
{

	protected _axxel;

	protected _name;

	public function __construct(<Axxel\Client> axxel, string! name)
	{
		let this->_axxel = axxel, this->_name = name;
	}

	public function addRole(string! name)
	{
		return this->_axxel->send("typeof axxel.getAcl('" . addslashes(this->_name) . "').addRole('" . addslashes(name) . "')=='object';");
	}

	public function isRole(string! name)
	{
		return this->_axxel->send("axxel.getAcl('" . addslashes(this->_name) . "').isRole('" . addslashes(name) . "');");
	}

	public function getRoles()
	{
		return this->_axxel->send("JSON.stringify(axxel.getAcl('" . addslashes(this->_name) . "').getRoles());");
	}

	public function addResource(string! name)
	{
		return this->_axxel->send("typeof axxel.getAcl('" . addslashes(this->_name) . "').addResource('" . addslashes(name) . "')=='object';");
	}

	public function isResource(string! name)
	{
		return this->_axxel->send("axxel.getAcl('" . addslashes(this->_name) . "').isResource('" . addslashes(name) . "');");
	}

	public function getResources()
	{
		return this->_axxel->send("JSON.stringify(axxel.getAcl('" . addslashes(this->_name) . "').getResources());");
	}

	public function allow(string! role, string! resource, action)
	{
		return this->_axxel->send("typeof axxel.getAcl('" .
			addslashes(this->_name) . "').allow('" .
			addslashes(role) . "', '" .
			addslashes(resource) . "', '" .
			addslashes(action) . "')=='object';");
	}

	public function isAllowed(string! role, string! resource, permissions) -> boolean
	{
		var name, roleName, resourceName, perms,
			status, permission;

		let name = addslashes(this->_name),
			roleName = addslashes(role),
			resourceName = addslashes(resource);

		if (is_array(permissions)) {
			let perms = [];
			for permission in permissions {
				let perms[] = "'" . addslashes(permission) . "'";
			}
			let status = this->_axxel->send("axxel.getAcl('" . name . "').allowed('" . roleName . "', '" . resourceName . "', [" . join(", ", perms) . "]);");
		} else {
			let status = this->_axxel->send("axxel.getAcl('" . name . "').allowed('" . roleName . "', '" . resourceName . "', '" . addslashes(permissions) . "');");
		}

		if status->status == "ok" {
			return (boolean) status->result;
		}

		return false;
	}

}