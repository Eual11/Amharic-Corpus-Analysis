set(EXECUTABLE_NAME "e")
CPMAddPackage(
    NAME matplotplusplus
    GITHUB_REPOSITORY alandefreitas/matplotplusplus
    GIT_TAG origin/master # or whatever tag you want
)
# ...
option(CPM_USE_LOCAL_PACKAGES "Try `find_package` before downloading dependencies" ON)
include_directories("${PROJECT_SOURCE_DIR}/include" $ENV{CPLUS_INCLUDE_PATH})
add_library(Tokenizer Tokenizer.cpp)
set_target_properties(Tokenizer PROPERTIES CXX_STANDARD 17)
add_executable(${EXECUTABLE_NAME} main.cpp)
target_link_libraries(${EXECUTABLE_NAME}     PRIVATE Tokenizer 
  PRIVATE matplot
  )
set_target_properties(${EXECUTABLE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
