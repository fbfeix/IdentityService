#include "stdafx.h"
#include "PostgresAuthStrategy.h"


PostgresAuthStrategy::PostgresAuthStrategy(PGconn* con,
	const std::string& email,
	const std::string& password)
	: email_(email)
	, password_(password)
{
	con_ = con;
}


PostgresAuthStrategy::~PostgresAuthStrategy()
{

}


bool PostgresAuthStrategy::auth()
{
	std::string sql("select id, email, name, password from credentials_tbl where email='");
	sql.append(email_);
	sql.append("' and password='");
	sql.append(password_);
	sql.append("';");

	std::cout << sql << std::endl;

	PGresult * res = PQexec(con_, sql.c_str());

	ExecStatusType s = PQresultStatus(res);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)
	{
		PQclear(res);
		throw AuthentificationError(PQerrorMessage(con_));
	}

	if (PQntuples(res) == 1)
	{
		std::string id = PQgetvalue(res, 0, 0);
		boost::uuids::string_generator sgen;
		
		account_ = new PostgresAccount(sgen(id), 
			PQgetvalue(res, 0, 1), 
			PQgetvalue(res, 0, 2));
		
		



		PQclear(res);
		return true;
	}
	
	


	PQclear(res);
	return false;
}


Account* PostgresAuthStrategy::getAccount()
{
	return account_;
}