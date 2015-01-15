// IdentityService.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "IdentityService.h"


// This is an example of an exported variable
IDENTITYSERVICE_API int nIdentityService=0;

// This is an example of an exported function.
IDENTITYSERVICE_API int fnIdentityService(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see IdentityService.h for the class definition
CIdentityService::CIdentityService()
{
	return;
}
