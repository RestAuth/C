# - Find json
# Find the native JSON headers and libraries.
#
#  JSON_INCLUDE_DIRS - where to find json/json.h, etc.
#  JSON_LIBRARIES    - List of libraries when using json.
#  JSON_FOUND        - True if json found.

#=============================================================================
# Copyright 2012 Gabriel Pickl.
#
# Distributed under the OSI-approved BSD License (the "License");
#
# This software is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the License for more information.
#=============================================================================

# Look for the header file.
FIND_PATH(JSON_INCLUDE_DIR NAMES json/json.h)
MARK_AS_ADVANCED(JSON_INCLUDE_DIR)

# Look for the library.
FIND_LIBRARY(JSON_LIBRARY NAMES 
    json
)
MARK_AS_ADVANCED(JSON_LIBRARY)

# handle the QUIETLY and REQUIRED arguments and set CURL_FOUND to TRUE if 
# all listed variables are TRUE
INCLUDE(${CMAKE_CURRENT_LIST_DIR}/FindPackageHandleStandardArgs.cmake)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(JSON DEFAULT_MSG JSON_LIBRARY JSON_INCLUDE_DIR)

IF(JSON_FOUND)
  SET(JSON_LIBRARIES ${JSON_LIBRARY})
  SET(JSON_INCLUDE_DIRS ${JSON_INCLUDE_DIR})
ENDIF(JSON_FOUND)