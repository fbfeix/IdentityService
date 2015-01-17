      
#include "stdafx.h"
#include <IdentityService/PostgresAuthStrategy.h>
#include <IdentityService/Authentification.h>

BOOST_AUTO_TEST_CASE( postgres_auth_test )  
{
	PostgresAuthStrategy * strategy;
	Authentification auth;

	PGconn * con;

	
	con = PQconnectdb("host=localhost port=5433 dbname=credentials_tbl user=postgres password=password");

	if (PQstatus(con) != CONNECTION_OK)
	{
		throw std::string(PQerrorMessage(con));
	}

	strategy = new PostgresAuthStrategy(con, "max.mustermann@example.com", "example_pw");

	BOOST_CHECK_EQUAL(strategy->auth(), true);

	BOOST_CHECK_NO_THROW(auth.auth(strategy));

	PQfinish(con);
	
	//delete strategy;
}

