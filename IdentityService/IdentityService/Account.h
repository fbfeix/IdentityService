#pragma once

#include <string>

class Account
{
public:
	Account();
	virtual ~Account();

	virtual std::string getName() const = 0;
};

