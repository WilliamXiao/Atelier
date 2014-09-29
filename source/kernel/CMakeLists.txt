#=============================================================================
# Atelier kernel - key rendering algorithms are managed in this project
#
# Copyright 2005-2014 William Xiao
#
# Create: 2014-09-25, William Xiao
# Modify:
#=============================================================================

#-----------------------------------------------------------------------------
# Project Properties
#-----------------------------------------------------------------------------
set(KERNEL_PROJECT_NAME "kernel")
project("${KERNEL_PROJECT_NAME}")

SET( INCLUDE_DIRS
	${CMAKE_CURRENT_LIST_DIR}
)
message("current path: ${INCLUDE_DIRS}")

INCLUDE_DIRECTORIES( ${INCLUDE_DIRS} )

SET( INCLUDE_FILES
	Integrator.h
)

SET( SOURCE_FILES
	Integrator.cpp
)

ADD_LIBRARY(${KERNEL_PROJECT_NAME} SHARED ${INCLUDE_FILES} ${SOURCE_FILES})