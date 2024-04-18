set(EXECUTABLE_NAME "e")
CPMAddPackage(
    NAME matplotplusplus
    GITHUB_REPOSITORY alandefreitas/matplotplusplus
    GIT_TAG origin/master # or whatever tag you want
)
# ...
include_directories("${PROJECT_SOURCE_DIR}/include" $ENV{CPLUS_INCLUDE_PATH})
option(CPM_USE_LOCAL_PACKAGES "Try `find_package` before downloading dependencies" ON)
add_executable(${EXECUTABLE_NAME} main.cpp)
target_link_libraries(${EXECUTABLE_NAME} PUBLIC matplot)

set_target_properties(${EXECUTABLE_NAME} PROPERTIES CXX_STANDARD 17)
set_target_properties(${EXECUTABLE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
