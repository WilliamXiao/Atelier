#=============================================================================
# Atelier - Cross Platform labs of Ray Tracer [ART]
#
# Copyright 2005-2014 William Xiao
#
# Create: 2014-09-25, William Xiao
# Modify:
#=============================================================================

cmake_minimum_required(VERSION 2.8.4 FATAL_ERROR)
IF(POLICY CMP0025)
  cmake_policy(SET CMP0025 NEW)
ENDIF()

#-----------------------------------------------------------------------------
# Project Properties
#-----------------------------------------------------------------------------
SET(PROJECT_NAME "Atelier")
PROJECT("${PROJECT_NAME}")

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
IF(CMAKE_COMPILER_IS_GNUCXX)
    MESSAGE(STATUS "GCC detected, adding compile flags")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98 -pedantic -Wall -Wextra")
	SET(CMAKE_C_FLAGS   " -Wall -Wextra" )
ELSE()
	#SET(CMAKE_C_FLAGS   " -Wall" )
	#SET(CMAKE_CXX_FLAGS " -Wall" )
ENDIF()

# Set CMAKE_BUILD_TYPE to Release by default
IF ( NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE "Debug" CACHE STRING
    "Choose the type of build, options are: Debug, Release, RelWithDebInfo, MinSizeRel." FORCE)
	message(" test debug type")
ENDIF()
MESSAGE("build type: ${CMAKE_BUILD_TYPE}")

IF(MSVC)
	SET(CMAKE_CXX_FLAGS_DEBUG_INIT "/D_DEBUG /MTD /ZI /OB0 /OD /RTC1")
	SET(CMAKE_CXX_FLAGS_MINSIZEREL_INIT     "/MT /O1 /OB1 /D NDEBUG")
	SET(CMAKE_CXX_FLAGS_RELEASE_INIT        "/MT /O2 /OB2 /D NDEBUG")
	SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT "/MT /ZI /O2 /OB1 /D NDEBUG")
ENDIF()

#specific compiler flags
IF((CMAKE_BUILD_TYPE MATCHES "Release") AND MSVC)
	ADD_DEFINITIONS(/arch:SSE2 /fp:fast /GS- /Gy)
ENDIF((CMAKE_BUILD_TYPE MATCHES "Release") AND MSVC)

#-----------------------------------------------------------------------------
# # Search Paths
#-----------------------------------------------------------------------------
LIST (APPEND CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}")
LIST (APPEND CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/external")
SET (ART_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
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
SET (BOOST_LIBRARY_DIR ${PROJECT_SOURCE_DIR}/external/boost_1_52/lib/x86_vc100)
SET (BOOST_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/external/boost_1_52/include)
INCLUDE_DIRECTORIES(${BOOST_INCLUDE_DIR})
MESSAGE("boos lib dir: ${BOOST_LIBRARY_DIR}")

SET(ART_BOOST_COMPONENTS system filesystem)

# Eigen
SET (ART_EIGEN_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/external/eigen_3_2_2)
INCLUDE_DIRECTORIES(${ART_EIGEN_INCLUDE_DIR} )

# FreeImage
SET(FREEIMAGE_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/external/FreeImage_3_13_1/include)
SET(FREEIMAGE_LIBRARY_DIR ${PROJECT_SOURCE_DIR}/external/FreeImage_3_13_1/lib/x86_vc100)
SET(FREEIMAGE_LIBRARY optimized FreeImage.lib debug FreeImaged.lib)

# common actions
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} 
	${BOOST_LIBRARY_DIR} 
	${FREEIMAGE_LIBRARY_DIR})

# Google Test
# Allow unit tests to be disabled via command
# line or the CMake GUI.
OPTION( BUILD_UNIT_TESTS "Build unit tests." ON )

# Enable the CMake built in CTest system if unit tests are enabled.
IF( BUILD_UNIT_TESTS )
	ENABLE_TESTING()
	INCLUDE( external/CMakeLists.txt )
	# Find the threading package for this machine.
	#FIND_PACKAGE( Threads )
ENDIF( BUILD_UNIT_TESTS )

# Doxygen
OPTION( BUILD_DOXYGEN "Build unit tests." ON )
IF( BUILD_DOXYGEN )
	ADD_SUBDIRECTORY(doc)
ENDIF( BUILD_DOXYGEN ) 

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



