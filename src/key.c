#include "key.h"

void pressAnyKey() {
#ifdef _WIN32
	getch();
#elif __linux__
  // i dont have any alterantive for now.
#endif
}