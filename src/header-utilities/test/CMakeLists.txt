
add_executable( header-utilities.test
                echoErroneousLine.test.cpp
                copy.test.cpp
                slurpFileToMemory.test.cpp
                dereference.test.cpp
                element_type.test.cpp
                iterator.test.cpp
                utility.test.cpp
                iterator_category.test.cpp )
target_compile_options( header-utilities.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${header-utilities_appended_flags} )
target_link_libraries( header-utilities.test PUBLIC header-utilities ) 
file( GLOB resources "resources/*" )
foreach( resource ${resources})
    file( COPY "${resource}" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}" )
endforeach()
add_test( NAME header-utilities COMMAND header-utilities.test )