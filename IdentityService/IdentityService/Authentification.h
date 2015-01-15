#pragma once

#include <IdentityService/Account.h>
#include <IdentityService/AuthStrategy.h>

class Authentification
{
public:
	Authentification();
	virtual ~Authentification();

	Account* auth(AuthStrategy* strat);
};

