#include "directory.h"

void createDirectory() {

#ifdef _WIN32
	system("if not exist database mkdir database");
	system("if not exist database\\busInformation mkdir database\\busInformation");
	system("if not exist database\\userInformation mkdir database\\userInformation");
	printf("done!");
#elif __linux__
	system("mkdir -p database/busInformation database/userInformation");
#endif

}

