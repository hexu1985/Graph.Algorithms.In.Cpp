INCLUDE(${CMAKE_CURRENT_SOURCE_DIR}/../common.cmake)

option(compile_alone_flag "set lib output path alone" OFF)

if(compile_alone_flag)
	if(DEFINED libgraph_algo_output_path)
		message(STATUS "libgraph_algo_output_path: ${libgraph_algo_output_path}")
		set(LIBRARY_OUTPUT_PATH ${libgraph_algo_output_path})
	else()
		set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
	endif()
endif()

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/../include
	${CMAKE_CURRENT_SOURCE_DIR}/../include/json11
	)

set(LIBGRAPH_ALGO_SRC 
	json11/json11.cpp
	)

#add_library(graph_algo SHARED ${LIBGRAPH_ALGO_SRC})
#set_target_properties(graph_algo PROPERTIES VERSION 1.2 SOVERSION 1)

add_library(graph_algo_static STATIC ${LIBGRAPH_ALGO_SRC})
set_target_properties(graph_algo_static PROPERTIES OUTPUT_NAME "graph_algo")

get_target_property(OUTPUT_VALUE graph_algo_static OUTPUT_NAME)
message(STATUS "This is the graph_algo_static OUTPUT_NAME: " ${OUTPUT_VALUE})

