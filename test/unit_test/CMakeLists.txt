#=============================================================================
# ART unit test applications
#
# Copyright 2005-2014 William Xiao
#
# Create: 2014-09-25, William Xiao
# Modify:
#=============================================================================

#-----------------------------------------------------------------------------
# Project Properties
#-----------------------------------------------------------------------------
set(TEST_ART_PROJECT_NAME "unit_test")
project("${TEST_ART_PROJECT_NAME}")

SET( INCLUDE_DIRS
	${CMAKE_CURRENT_LIST_DIR}
)
message("current path: ${INCLUDE_DIRS}")

INCLUDE_DIRECTORIES( ${INCLUDE_DIRS} )

SET( INCLUDE_FILES
	testAll.hpp
	testTimer.hpp
	testVector.hpp
)

SET( SOURCE_FILES
	unit_test_main.cpp
)

LINK_DIRECTORIES(${CMAKE_LIBRARY_PATH})
# Make a unit test holder for the Math library.
IF( BUILD_UNIT_TESTS )
	# Add the gmock include directories.
	INCLUDE_DIRECTORIES( ${GMOCK_INCLUDE_DIRS} )

	ADD_EXECUTABLE( ${TEST_ART_PROJECT_NAME}
		${INCLUDE_FILES}
		${SOURCE_FILES}
	)
	TARGET_LINK_LIBRARIES( ${TEST_ART_PROJECT_NAME}
		${Boost_LIBRARIES}
		gmock
		${CMAKE_THREAD_LIBS_INIT}
		utility
	)

	ADD_TEST( NAME
		${TEST_ART_PROJECT_NAME}
		COMMAND
		${TEST_ART_PROJECT_NAME}
	)
ENDIF( BUILD_UNIT_TESTS )