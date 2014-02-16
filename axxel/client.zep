
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

class Client
{

	private _socket;

	private _server;

	private _port;

	public function __construct(string server="127.0.0.1", port=1589)
	{
		let this->_server = server,
			this->_port = port;
	}

	public function getAcl(string! name, initialization=null) -> <Acl>
	{
		var acl;

		let acl = new Acl(this, name);
		if is_callable(initialization)  {
			if !this->isAcl(name) {
				call_user_func_array(name, [initialization]);
			}
		}
		return acl;
	}

	public function send(string! command)
	{
		var socket, errorNumber, errorString, data;

		let socket = this->_socket,
			errorNumber = null,
			errorString = null;

		if !socket {
			let socket = pfsockopen(this->_server, this->_port, errorNumber, errorString, 1),
				this->_socket = socket;
		}

		if !socket {
			throw new Exception(errorString . " (" . errorNumber . ")");
		}

		let data = null;

		fwrite(socket, command . "\n");
		while !feof(socket) {
			let data = fgets(socket, 128);
			if ends_with(data, "\n") {
				break;
			}
		}

		return json_decode(data);
	}

	public function createAcl(string! name) -> <Axxel\Acl>
	{
		var status;

		let status = this->send("var a = axxel.createAcl('" . addslashes(name) . "'); typeof a == 'object';");
		return new Acl(this, name);
	}

	public function isAcl(string! name) -> boolean
	{
		var status;

		let status = this->send("axxel.isAcl('" . addslashes(name) . "')");
		if status->status == "ok" {
			return (boolean) status->result;
		}
		return false;
	}

}
