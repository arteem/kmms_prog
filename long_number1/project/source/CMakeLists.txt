
add_library(long_number_lib
    long_number.cpp
    long_number.hpp
)


target_include_directories(long_number_lib
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)


target_compile_features(long_number_lib PUBLIC cxx_std_17)