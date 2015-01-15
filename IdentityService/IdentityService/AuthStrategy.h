#pragma once

#include <IdentityService/Account.h>



class AuthStrategy
{
public:
	virtual Account* auth() = 0;
};

