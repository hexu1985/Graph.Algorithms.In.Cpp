INCLUDE(${CMAKE_CURRENT_SOURCE_DIR}/../alone.cmake)

FILE(GLOB src_files ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

FOREACH (src_file ${src_files})
    STRING(REGEX MATCH "[^/]+$" src_basename ${src_file})
    STRING(REPLACE ".cpp" "" exe_file ${src_basename})
    ADD_EXECUTABLE(${exe_file} ${src_file})
    TARGET_LINK_LIBRARIES(${exe_file} graph_algo)
ENDFOREACH()

