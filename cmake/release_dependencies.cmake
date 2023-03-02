cmake_minimum_required( VERSION 3.24 )
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/.cmake)
include( shacl_FetchContent )

#######################################################################
# Declare project dependencies
#######################################################################

shacl_FetchContent_Declare( catch-adapter
    GIT_REPOSITORY  ../../njoy/catch-adapter
    GIT_TAG         fb84b82ebf7a4789aa43cea560680cf745c6ee4f
    )

shacl_FetchContent_Declare( Log
    GIT_REPOSITORY  ../../njoy/Log
    GIT_TAG         9f70f9428219dc245b72042a284dac18e33bc946
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

