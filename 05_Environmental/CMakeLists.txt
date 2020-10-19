cmake_minimum_required(VERSION 3.1)
project(hw5)

find_package(Curses REQUIRED)
find_library(PCRE2_LIBRARY pcre2-8)

if(CURSES_LIBRARY)
	message(STATUS "curses OK")
endif()

if(PCRE2_LIBRARY)
	message(STATUS "pcre2 OK")
endif()

option(WITHOUT_UTF "without_utf off" OFF)

add_executable(hw5 Window.c)
target_link_libraries(hw5 ${CURSES_LIBRARY} ${PCRE2_LIBRARY})

set(GENERATES hw5 CMakeCache.txt CMakeFiles cmake_install.cmake Makefile)
add_custom_target(allclean)
add_custom_command(
	TARGET    allclean
	COMMAND   rm -rf ${GENERATES}
)