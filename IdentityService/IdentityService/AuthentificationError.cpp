#include "stdafx.h"
#include "AuthentificationError.h"


AuthentificationError::AuthentificationError()
	: std::runtime_error("Authentification Failed")
{
}
