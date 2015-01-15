#pragma once

#include <exception>
#include <stdexcept>

class AuthentificationError :
	//public boost::exception, 
	public std::runtime_error
{
public:
	AuthentificationError();
};

