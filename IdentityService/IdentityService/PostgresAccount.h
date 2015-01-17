#pragma once
#include <IdentityService/Account.h>
#include <boost/uuid/uuid.hpp>

#ifdef IDENTITYSERVICE_EXPORTS
#define IDENTITYSERVICE_API __declspec(dllexport)
#else
#define IDENTITYSERVICE_API __declspec(dllimport)
#endif



class PostgresAuthStrategy;



class IDENTITYSERVICE_API PostgresAccount :
	public Account
{
	friend class PostgresAuthStrategy;
public:
	PostgresAccount();
	~PostgresAccount();

	std::string getName() const;

private:
	PostgresAccount(
		const boost::uuids::uuid& id,
		const std::string& name,
		const std::string& email);

	boost::uuids::uuid id_;

	std::string name_;
	std::string email_;
};

