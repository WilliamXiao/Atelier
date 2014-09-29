#=============================================================================
# Atelier engine - rendering infrastructure class are managed in this project
#
# Copyright 2005-2014 William Xiao
#
# Create: 2014-09-25, William Xiao
# Modify:
#=============================================================================

#-----------------------------------------------------------------------------
# Project Properties
#-----------------------------------------------------------------------------
set(ENGINE_PROJECT_NAME "engine")
project("${ENGINE_PROJECT_NAME}")

SET( INCLUDE_DIRS
	${CMAKE_CURRENT_LIST_DIR}
)
message("current path: ${INCLUDE_DIRS}")

INCLUDE_DIRECTORIES( ${INCLUDE_DIRS} )

SET( INCLUDE_FILES
	Parallel.h
)

SET( SOURCE_FILES
	Parallel.cpp
)

ADD_LIBRARY(${ENGINE_PROJECT_NAME} SHARED ${INCLUDE_FILES} ${SOURCE_FILES})