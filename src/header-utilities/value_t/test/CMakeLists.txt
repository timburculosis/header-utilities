
add_executable( header-utilities.value_t.test value_t.test.cpp )
target_compile_options( header-utilities.value_t.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${header-utilities_appended_flags} )
target_link_libraries( header-utilities.value_t.test PUBLIC header-utilities_testing ) 
add_test( NAME header-utilities.value_t COMMAND header-utilities.value_t.test )
