#######################################################################
# Setup
#######################################################################

message( STATUS "Adding header-utilities unit testing" )

add_library( header-utilities_testing INTERFACE )
target_link_libraries( header-utilities_testing INTERFACE header-utilities )

target_link_libraries(header-utilities_testing INTERFACE catch-adapter)

#######################################################################
# Unit testing directories
#######################################################################

add_subdirectory( src/header-utilities/Require/test )
add_subdirectory( src/header-utilities/exponentialSearch/test )
add_subdirectory( src/header-utilities/is_container/test )
add_subdirectory( src/header-utilities/is_iterator/test )
add_subdirectory( src/header-utilities/is_range/test )
add_subdirectory( src/header-utilities/is_shared_ptr/test )
add_subdirectory( src/header-utilities/is_unique_ptr/test )
add_subdirectory( src/header-utilities/test )
add_subdirectory( src/header-utilities/value_t/test )
