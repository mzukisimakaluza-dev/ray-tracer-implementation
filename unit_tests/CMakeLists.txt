add_executable(unit_tests
    ${CMAKE_CURRENT_SOURCE_DIR}/test_tuples.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_link_libraries(unit_tests tracer)

target_include_directories(unit_tests PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/tracer
)

target_compile_features(unit_tests PRIVATE cxx_std_17)