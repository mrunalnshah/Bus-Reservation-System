# CMakeList.txt : CMake project for Bus-Reservation-System, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Bus-Reservation-System")

# Add source to this project's executable.
add_executable (Bus-Reservation-System "Bus-Reservation-System.c" "Bus-Reservation-System.h"  "src/directory.h" "src/directory.c" "src/login.h" "src/login.c" "src/clearScreen.c" "src/clearScreen.h" "src/interface.h" "src/interface.c" "src/functionality.h" "src/functionality.c" "src/time.h" "src/time.c" "src/design.h" "src/design.c" "src/key.c" "src/key.h" "src/errorHandling.h" "src/errorHandling.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Bus-Reservation-System PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
