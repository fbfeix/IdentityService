#pragma once

#include <string>

#ifdef IDENTITYSERVICE_EXPORTS
#define IDENTITYSERVICE_API __declspec(dllexport)
#else
#define IDENTITYSERVICE_API __declspec(dllimport)
#endif

class IDENTITYSERVICE_API Account
{
public:
	Account();
	virtual ~Account();

	virtual std::string getName() const = 0;
};

