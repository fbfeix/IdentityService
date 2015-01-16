#pragma once
#include <IdentityService/Account.h>

#ifdef IDENTITYSERVICE_EXPORTS
#define IDENTITYSERVICE_API __declspec(dllexport)
#else
#define IDENTITYSERVICE_API __declspec(dllimport)
#endif

class IDENTITYSERVICE_API LdapAccount :
	public Account
{
public:
	LdapAccount();
	~LdapAccount();

	std::string getName() const;
};

