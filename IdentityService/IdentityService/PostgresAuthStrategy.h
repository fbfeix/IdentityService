#pragma once
#include <IdentityService/AuthStrategy.h>
#include <IdentityService/Account.h>
#include <IdentityService/PostgresAccount.h>
#include <IdentityService/AuthentificationError.h>
#include <iostream>
#include <libpq-fe.h>
#include <boost/shared_ptr.hpp>
#include <boost/uuid/string_generator.hpp>

#ifdef IDENTITYSERVICE_EXPORTS
#define IDENTITYSERVICE_API __declspec(dllexport)
#else
#define IDENTITYSERVICE_API __declspec(dllimport)
#endif

class IDENTITYSERVICE_API PostgresAuthStrategy :
	public AuthStrategy
{
public:
	PostgresAuthStrategy(PGconn* con,
		const std::string& email,
		const std::string& password);
	~PostgresAuthStrategy();

	bool auth();

	Account* getAccount();

private:
	PGconn* con_;

	std::string email_;
	std::string password_;

	Account* account_;
};

