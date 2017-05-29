
add_executable( header-utilities.exponentialSearch.test exponentialSearch.test.cpp )
target_compile_options( header-utilities.exponentialSearch.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${header-utilities_appended_flags} )
target_link_libraries( header-utilities.exponentialSearch.test PUBLIC header-utilities ) 
add_test( NAME header-utilities.exponentialSearch COMMAND header-utilities.exponentialSearch.test )