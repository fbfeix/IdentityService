#pragma once

#include <IdentityService/Account.h>
#include <IdentityService/AuthStrategy.h>

#ifdef IDENTITYSERVICE_EXPORTS
#define IDENTITYSERVICE_API __declspec(dllexport)
#else
#define IDENTITYSERVICE_API __declspec(dllimport)
#endif

class IDENTITYSERVICE_API Authentification
{
public:
	Authentification();
	virtual ~Authentification();

	Account* auth(AuthStrategy* strat);


};

