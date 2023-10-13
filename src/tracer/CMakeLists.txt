add_library(tracer SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/factory/tuple_helpers.cpp
)

target_include_directories(tracer PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/factory
)

target_compile_features(tracer PRIVATE cxx_std_17)