#pragma once

#include <IdentityService/Account.h>

#ifdef IDENTITYSERVICE_EXPORTS
#define IDENTITYSERVICE_API __declspec(dllexport)
#else
#define IDENTITYSERVICE_API __declspec(dllimport)
#endif

class IDENTITYSERVICE_API AuthStrategy
{
public:
	virtual bool auth() = 0;

	virtual Account* getAccount() = 0;
};


