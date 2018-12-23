cmake_minimum_required (VERSION 3.2)

set (TRAVIS_BUILD_NUMBER $ENV{TRAVIS_BUILD_NUMBER})

if ("${TRAVIS_BUILD_NUMBER}" STREQUAL "")
	set (TRAVIS_BUILD_NUMBER "1")
endif ("${TRAVIS_BUILD_NUMBER}" STREQUAL "")

project (helloworld VERSION 0.0.${TRAVIS_BUILD_NUMBER})

configure_file (version.h.in ${CMAKE_SOURCE_DIR}/version.h)

add_executable (helloworld helloworld.cpp)

set_target_properties (helloworld PROPERTIES
	CXX_STANDARD 17
	CXX_EXTENSIONS OFF
	CXX_STANDARD_REQUIRED ON
	COMPILE_OPTIONS "-pedantic;-Wall;-Wextra"
)

install (TARGETS helloworld RUNTIME DESTINATION bin)

set (CMAKE_VERBOSE_MAKEFILE ON)

set (CPACK_GENERATOR DEB)

set (CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set (CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

include (CPack)

# enable_testing()

# add_test (test test)
