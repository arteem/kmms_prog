project(menu)

include_directories(${CMAKE_SOURCE_DIR}/projects/menu/src)

set(HEADERS
    src/menu.hpp
    src/menu_func.hpp
    src/menu_items.hpp
)

set(SOURCES
    main.cpp 
    src/menu_func.cpp
    src/menu_items.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES}) 
