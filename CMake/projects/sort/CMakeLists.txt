project(sort)

set(HEADERS
    src/generate.hpp
    src/io.hpp
    src/sortings.hpp
)

set(SOURCES
    main.cpp 
    src/generate.cpp
    src/io.cpp
    src/sortings.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES}) 

add_subdirectory(tests)