# - Find json
# Find the native JSON headers and libraries.
#
#  JSON_INCLUDE_DIRS - where to find json/json.h, etc.
#  JSON_LIBRARIES    - List of libraries when using json.
#  JSON_FOUND        - True if json found.

#=============================================================================
# Copyright 2012 Gabriel Pickl.
#
# This software is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the License for more information.
#=============================================================================

# Look for the header file.
FIND_PATH(JANSSON_INCLUDE_DIR NAMES jansson.h)
MARK_AS_ADVANCED(JANSSON)

# Look for the library.
FIND_LIBRARY(JANSSON_LIBRARY NAMES 
    jansson
)
MARK_AS_ADVANCED(JANSSON_LIBRARY)

# handle the QUIETLY and REQUIRED arguments and set CURL_FOUND to TRUE if 
# all listed variables are TRUE
INCLUDE(/usr/share/cmake-2.8/Modules/FindPackageHandleStandardArgs.cmake)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(JANSSON DEFAULT_MSG JANSSON_LIBRARY JANSSON_INCLUDE_DIR)

IF(JANSSON_FOUND)
  SET(JANSSON_LIBRARIES ${JSON_LIBRARY})
  SET(JSANSON_INCLUDE_DIRS ${JSON_INCLUDE_DIR})
ENDIF(JANSSON_FOUND)
