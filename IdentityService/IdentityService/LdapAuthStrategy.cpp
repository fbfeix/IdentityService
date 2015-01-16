#include "stdafx.h"
#include "LdapAuthStrategy.h"




LdapAuthStrategy::LdapAuthStrategy(
	const std::string hostName,
	const unsigned int portNumber,
	const std::string& bindName,
	const std::string& bindPW,
	bool useSSL)
	: host_name_(hostName)
	, port_number_(portNumber)
	, use_ssl_(useSSL)
{
	init();
}

LdapAuthStrategy::LdapAuthStrategy(
	const std::string hostName,
	const unsigned int portNumber,
	const std::string& bindName,
	const std::string& bindPW,
	const std::string& name,
	const std::string& pw,
	bool useSSL)
	: host_name_(hostName)
	, port_number_(portNumber)
	, use_ssl_(useSSL)
{
	init();
}


void LdapAuthStrategy::ChangeUser(
	const std::string& name,
	const std::string& pw)
{

}

void LdapAuthStrategy::ChangeBindUser(
	const std::string& bindName,
	const std::string& bindPW)
{

}


LdapAuthStrategy::~LdapAuthStrategy()
{
	close();
}


bool LdapAuthStrategy::auth()
{
	return false;
}


Account* LdapAuthStrategy::getAccount()
{
	return new LdapAccount();
}


void LdapAuthStrategy::init()
{

	wchar_t *p = new wchar_t[host_name_.size()];

	for (std::string::size_type i = 0; i < host_name_.size(); ++i)
	{
		p[i] = host_name_[i];
	}



	// also available with Domain Controller 
	// see:
	// http://msdn.microsoft.com/en-us/library/aa366996(v=vs.85).aspx
	// http://msdn.microsoft.com/en-us/library/ms675983(v=vs.85).aspx
	if (false == use_ssl_) {
		ldap_handler_ = ldap_init(p, port_number_);
	}
	else
	{
		ldap_handler_ = ldap_sslinit(p, port_number_, 1);
	}

	if (ldap_handler_ == NULL)
		std::cout << "oh fuck" << std::endl;

	std::cout << LdapGetLastError() << std::endl;

	if (ldap_connect(ldap_handler_, NULL) == LDAP_SUCCESS)
	{
		std::cout << "yeah" << std::endl;
	}
	else
		std::cout << "ohhhh" << std::endl;

}

void LdapAuthStrategy::close()
{
	if (ldap_handler_)
	{
		delete ldap_handler_;
	}
}
