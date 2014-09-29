#=============================================================================
# Atelier - Cross Platform labs of Ray Tracer [ART]
#
# Copyright 2005-2014 William Xiao
#
# Create: 2014-09-25, William Xiao
# Modify:
#=============================================================================

cmake_minimum_required(VERSION 2.8.4 FATAL_ERROR)
if(POLICY CMP0025)
  cmake_policy(SET CMP0025 NEW)
endif()

#-----------------------------------------------------------------------------
# Project Properties
#-----------------------------------------------------------------------------
set(PROJECT_NAME "Atelier")
project("${PROJECT_NAME}")

SET (APPLICATION_NAME "${PROJECT_NAME}")
SET (APPLICATION_CODENAME "${PROJECT_NAME}")
SET (APPLICATION_COPYRIGHT_YEARS "2014")
SET (APPLICATION_VERSION_MAJOR 1)
SET (APPLICATION_VERSION_MINOR 0)
SET (APPLICATION_VERSION_PATCH 0)
SET (APPLICATION_VERSION_TYPE SNAPSHOT)
SET (APPLICATION_VERSION_STRING "${APPLICATION_VERSION_MAJOR}.${APPLICATION_VERSION_MINOR}.${APPLICATION_VERSION_PATCH}-${APPLICATION_VERSION_TYPE}")
SET (APPLICATION_VENDOR_ID "xx_com.Atelier")
SET (APPLICATION_VENDOR_NAME "Atelier")
SET (APPLICATION_VENDOR_URL "xx_Atelier.com")
SET (APPLICATION_ID "${APPLICATION_VENDOR_ID}.${PROJECT_NAME}")

#-----------------------------------------------------------------------------
# Compiler settings
#-----------------------------------------------------------------------------

# Set default compile flags for GCC
if(CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "GCC detected, adding compile flags")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98 -pedantic -Wall -Wextra")
	set(CMAKE_C_FLAGS   " -Wall -Wextra" )
else()
	set(CMAKE_C_FLAGS   " -Wall" )
	set(CMAKE_CXX_FLAGS " -Wall" )
endif()

# Set CMAKE_BUILD_TYPE to Release by default
if ( NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING
    "Choose the type of build, options are: Debug, Release, RelWithDebInfo, MinSizeRel." FORCE)
	message(" test debug type")
endif()
# message("build type: ${CMAKE_BUILD_TYPE}")

if(MSVC)
	set(CMAKE_CXX_FLAGS_DEBUG_INIT "/D_DEBUG /MTd /Zi /Ob0 /Od /RTC1")
	set(CMAKE_CXX_FLAGS_MINSIZEREL_INIT     "/MT /O1 /Ob1 /D NDEBUG")
	set(CMAKE_CXX_FLAGS_RELEASE_INIT        "/MT /O2 /Ob2 /D NDEBUG")
	set(CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT "/MT /Zi /O2 /Ob1 /D NDEBUG")
endif()

#-----------------------------------------------------------------------------
# # Search Paths
#-----------------------------------------------------------------------------
LIST (APPEND CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}")
LIST (APPEND CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/external")
set (ART_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(${ART_INCLUDE_DIR})

#-----------------------------------------------------------------------------
# Make VC happy and group all the binary outputs
#-----------------------------------------------------------------------------
if( MSVC )
	SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin )
	SET( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin )
	SET( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin )
endif( MSVC )
# message("${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

#-----------------------------------------------------------------------------
# Locate Project Prerequisites 
#-----------------------------------------------------------------------------

# Boost
set (BOOST_ROOT ${PROJECT_SOURCE_DIR}/external/boost_1_52/)
SET (BOOST_LIBRARYDIR ${PROJECT_SOURCE_DIR}/external/boost_1_52/lib/x86_vc100/debug)
SET (BOOST_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/external/boost_1_52/include)
SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} ${BOOST_INCLUDE_DIR})
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} ${BOOST_LIBRARYDIR})

set(ART_BOOST_COMPONENTS system filesystem)
set(Boost_USE_STATIC_LIBS NOT ${Boost_USE_STATIC_LIBS})

find_package(Boost 1.52 COMPONENTS ${ART_BOOST_COMPONENTS} REQUIRED)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${BOOST_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

# Google Test
# Allow unit tests to be disabled via command
# line or the CMake GUI.
OPTION( BUILD_UNIT_TESTS "Build unit tests." ON )

# Enable the CMake built in CTest system if unit tests are enabled.
IF( BUILD_UNIT_TESTS )
	ENABLE_TESTING()
	INCLUDE( external/CMakeLists.txt )
	# Find the threading package for this machine.
	FIND_PACKAGE( Threads )
ENDIF( BUILD_UNIT_TESTS )


#-----------------------------------------------------------------------------
# Add Build Targets
#-----------------------------------------------------------------------------
add_subdirectory(source/scene)
add_subdirectory(source/kernel)
add_subdirectory(source/engine)
add_subdirectory(source/utility)
add_subdirectory(test/application)
add_subdirectory(test/unit_test)


# END OF FILE



