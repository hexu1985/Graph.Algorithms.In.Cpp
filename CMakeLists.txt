project(GRAPH_ALGO)

INCLUDE(${PROJECT_SOURCE_DIR}/common.cmake)

include_directories(
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/include/helper
	${PROJECT_SOURCE_DIR}/test
)

#set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
add_subdirectory(chap01)
add_subdirectory(chap02)
add_subdirectory(chap03)
