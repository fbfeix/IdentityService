// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the IDENTITYSERVICE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// IDENTITYSERVICE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef IDENTITYSERVICE_EXPORTS
#define IDENTITYSERVICE_API __declspec(dllexport)
#else
#define IDENTITYSERVICE_API __declspec(dllimport)
#endif

// This class is exported from the IdentityService.dll
class IDENTITYSERVICE_API CIdentityService {
public:
	CIdentityService(void);
	// TODO: add your methods here.
};

extern IDENTITYSERVICE_API int nIdentityService;

IDENTITYSERVICE_API int fnIdentityService(void);
