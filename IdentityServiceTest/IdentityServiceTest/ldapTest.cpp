      
#include "stdafx.h"
#include <IdentityService/LdapAuthStrategy.h>


BOOST_AUTO_TEST_CASE( ldapTest )  
{
	LdapAuthStrategy * strat;

	BOOST_REQUIRE(strat = new LdapAuthStrategy("localhost", 636, "bindUser", "bindPW"));

	delete strat;
}

