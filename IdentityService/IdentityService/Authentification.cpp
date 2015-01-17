#include "stdafx.h"

#include <IdentityService/AuthentificationError.h>
#include <IdentityService/Authentification.h>



Authentification::Authentification()
{
}



Authentification::~Authentification()
{
}

Account* Authentification::auth(AuthStrategy* strat)
{
	if (strat)
	{
		if (strat->auth())
			return strat->getAccount();		
	}

	throw AuthentificationError();

}


