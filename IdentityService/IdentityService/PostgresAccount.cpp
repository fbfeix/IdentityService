#include "stdafx.h"
#include "PostgresAccount.h"


PostgresAccount::PostgresAccount()
{
}

PostgresAccount::PostgresAccount(
	const boost::uuids::uuid& id,
	const std::string& name,
	const std::string& email)
	: id_(id)
	, name_(name)
	, email_(email)
{

}

PostgresAccount::~PostgresAccount()
{
}

std::string PostgresAccount::getName() const
{
	return name_;
}

