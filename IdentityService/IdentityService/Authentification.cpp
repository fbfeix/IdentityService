#include "stdafx.h"
#include "Authentification.h"


Authentification::Authentification()
{
}


Authentification::~Authentification()
{
}

Account* Authentification::auth(AuthStrategy* strat)
{
	if (strat)
		return strat->auth();
}