#=============================================================================
# Atelier - Doxygen Settings
#
# Copyright 2005-2014 William Xiao
#
# Create: 2014-09-29, William Xiao
# Modify:
#=============================================================================

FIND_PACKAGE(Doxygen)

IF(DOXYGEN_FOUND)

	CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/DoxygenConfigure.in ${CMAKE_CURRENT_BINARY_DIR}/DoxygenConfigure @ONLY)
	
	ADD_CUSTOM_TARGET(doxygen
	    ALL
		${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/DoxygenConfigure
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		COMMENT "Generating API documentation with Doxygen" VERBATIM
	)
	
	SET_PROPERTY(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES doxygen)	
		
ENDIF(DOXYGEN_FOUND)
