#pragma once

#include <exception>
#include <stdexcept>

#ifdef IDENTITYSERVICE_EXPORTS
#define IDENTITYSERVICE_API __declspec(dllexport)
#else
#define IDENTITYSERVICE_API __declspec(dllimport)
#endif

class IDENTITYSERVICE_API AuthentificationError :
	//public boost::exception, 
	public std::runtime_error
{
public:
	AuthentificationError();
	AuthentificationError(const std::string& details);
};

