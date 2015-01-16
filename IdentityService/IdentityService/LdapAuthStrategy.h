#pragma once
#include <IdentityService/AuthStrategy.h>
#include <IdentityService/Account.h>
#include <IdentityService/LdapAccount.h>
#include <Winldap.h>
#include <iostream>

#ifdef IDENTITYSERVICE_EXPORTS
#define IDENTITYSERVICE_API __declspec(dllexport)
#else
#define IDENTITYSERVICE_API __declspec(dllimport)
#endif

class IDENTITYSERVICE_API LdapAuthStrategy :
	public AuthStrategy
{
public:
	LdapAuthStrategy(
		const std::string hostName,
		const unsigned int portNumber,
		const std::string& bindName,
		const std::string& bindPW,
		bool useSSL = true);
	LdapAuthStrategy(
		const std::string hostName,
		const unsigned int portNumber, 
		const std::string& bindName,
		const std::string& bindPW,
		const std::string& name,
		const std::string& pw,
		bool useSSL = true);

	void ChangeUser(
		const std::string& name,
		const std::string& pw);
	void ChangeBindUser(
		const std::string& bindName,
		const std::string& bindPW);

	virtual ~LdapAuthStrategy();

	bool auth();

	Account* getAccount();

private:
	void init();
	void close();

	std::string host_name_;
	unsigned int port_number_;
	bool use_ssl_ = true;
	LDAP * ldap_handler_;

};

