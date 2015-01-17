#include "stdafx.h"
#include "AuthentificationError.h"


AuthentificationError::AuthentificationError()
	: std::runtime_error("Authentification Failed")
{
}


AuthentificationError::AuthentificationError(const std::string& details)
	: std::runtime_error("Authentification Failed: " + details)
{

}