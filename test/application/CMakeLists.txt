#=============================================================================
# ART test application - ART demo project
#
# Copyright 2005-2014 William Xiao
#
# Create: 2014-09-25, William Xiao
# Modify:
#=============================================================================

#-----------------------------------------------------------------------------
# Project Properties
#-----------------------------------------------------------------------------
set(TEST_ART_PROJECT_NAME "application")
project("${TEST_ART_PROJECT_NAME}")

SET( INCLUDE_DIRS
	${CMAKE_CURRENT_LIST_DIR}
)
message("current path: ${INCLUDE_DIRS}")

INCLUDE_DIRECTORIES( ${INCLUDE_DIRS} )

#SET( INCLUDE_FILES
#	ArtParallel.h
#)

SET( SOURCE_FILES
	main.cpp
)

#ADD_EXECUTABLE(${TEST_ART_PROJECT_NAME} ${INCLUDE_FILES} ${SOURCE_FILES}
ADD_EXECUTABLE(${TEST_ART_PROJECT_NAME} ${SOURCE_FILES})

LINK_DIRECTORIES(${BOOST_LIBRARYDIR})
target_link_libraries(${TEST_ART_PROJECT_NAME} ${Boost_LIBRARIES})
