option(compile_alone_flag "This is a option for compile_alone_flag" OFF)

if(compile_alone_flag)

	include(${CMAKE_CURRENT_SOURCE_DIR}/../common.cmake)

	include_directories(
		${CMAKE_CURRENT_SOURCE_DIR}/../include
		${CMAKE_CURRENT_SOURCE_DIR}/../include/json11
		)

	link_directories(
		${CMAKE_CURRENT_SOURCE_DIR}/../lib
		)

endif()


