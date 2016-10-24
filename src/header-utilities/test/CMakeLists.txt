add_executable( header-utilities.test
                copy.test.cpp
                echoErroneousLine.test.cpp
                element_type.test.cpp
                is_container.test.cpp
                is_iterator.test.cpp
                is_shared_ptr.test.cpp
                is_smart_ptr.test.cpp
                is_unique_ptr.test.cpp
                iterator.test.cpp
                iterator_category.test.cpp
                slurpFileToMemory.test.cpp
                utility.test.cpp )
set( test_flags ${header-utilities_compiler_flags} )
separate_arguments( test_flags )
foreach( flag IN LISTS test_flags )
    target_compile_options( header-utilities.test PUBLIC ${flag} )
endforeach( flag )
set_target_properties( header-utilities.test PROPERTIES LINK_FLAGS "${header-utilities_compiler_flags}" )
target_link_libraries( header-utilities.test PUBLIC header-utilities )
file( GLOB resources "resources/*" ) 
file( COPY "${resources}" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}" ) 
add_test( NAME header-utilities COMMAND header-utilities.test ) 
