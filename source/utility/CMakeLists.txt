#=============================================================================
# Atelier utility - rendering utilities are managed in this project
#
# Copyright 2005-2014 William Xiao
#
# Create: 2014-09-25, William Xiao
# Modify:
#=============================================================================

#-----------------------------------------------------------------------------
# Project Properties
#-----------------------------------------------------------------------------
set(UTILITY_PROJECT_NAME "utility")
project("${UTILITY_PROJECT_NAME}")

SET( INCLUDE_DIRS
	${CMAKE_CURRENT_LIST_DIR}
)
message("current path: ${INCLUDE_DIRS}")

INCLUDE_DIRECTORIES( ${INCLUDE_DIRS} )

SET( INCLUDE_FILES
	${ART_INCLUDE_DIR}/utility/common.h
	${ART_INCLUDE_DIR}/utility/Timer.h
	${ART_INCLUDE_DIR}/utility/Ray.h
	${ART_INCLUDE_DIR}/utility/math/Vector.h
	${ART_INCLUDE_DIR}/utility/math/Transform.h
)

SET( SOURCE_FILES
	Timer.cpp
	Vector.cpp
)
LINK_DIRECTORIES(${CMAKE_LIBRARY_PATH})
# STATIC or SHARED
ADD_LIBRARY(${UTILITY_PROJECT_NAME} STATIC ${INCLUDE_FILES} ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(${UTILITY_PROJECT_NAME} ${FREEIMAGE_LIBRARY})
TARGET_LINK_LIBRARIES(${UTILITY_PROJECT_NAME} ${BOOST_LIBRARIES})
