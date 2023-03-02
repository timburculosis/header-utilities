cmake_minimum_required( VERSION 3.24 )
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/.cmake)
include( shacl_FetchContent )

#######################################################################
# Declare project dependencies
#######################################################################

shacl_FetchContent_Declare( catch-adapter
    GIT_REPOSITORY  ../../njoy/catch-adapter
    GIT_TAG         origin/master
    GIT_SHALLOW     TRUE
    )

shacl_FetchContent_Declare( Log
    GIT_REPOSITORY  ../../njoy/Log
    GIT_TAG         origin/master
    GIT_SHALLOW     TRUE
    )

#######################################################################
# Load dependencies
#######################################################################

shacl_FetchContent_MakeAvailable(
    Log
    )

if (${header-utilities_unit_tests})
    shacl_FetchContent_MakeAvailable(catch-adapter)
endif()

