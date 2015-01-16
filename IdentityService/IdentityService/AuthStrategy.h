#pragma once

#include <IdentityService/Account.h>



class AuthStrategy
{
public:
	virtual bool auth() = 0;

	virtual Account* getAccount() = 0;
};


