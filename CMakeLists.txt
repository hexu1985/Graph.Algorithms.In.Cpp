project(GRAPH_ALGO)

INCLUDE(${PROJECT_SOURCE_DIR}/common.cmake)

include_directories(
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/include/helper
	${PROJECT_SOURCE_DIR}/test
)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

link_directories(
	${PROJECT_BINARY_DIR}/lib
	)

#set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
add_subdirectory(src)
add_subdirectory(chap01)
add_subdirectory(chap01_2)
add_subdirectory(chap02)
add_subdirectory(chap03)
