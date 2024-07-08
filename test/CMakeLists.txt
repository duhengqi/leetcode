#设置包含的目录
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/gtest
)
#重新定义目标链接库文件的存放位置
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#重新定义目标二进制可执行文件的存放位置
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

message(STATUS "Project dir ${PROJECT_SOURCE_DIR}")
#设置链接库搜索目录
link_directories(
    ${PROJECT_SOURCE_DIR}/lib
)

#发现一个目录下所有的源代码文件并将列表存储在一个变量中。
aux_source_directory(${PROJECT_SOURCE_DIR}/test LEETCODE_TEST)
#生成可执行文件
#target_link_libraries里库文件的顺序符合gcc链接顺序的规则，即被依赖的库放在依赖它的库的后面
link_libraries(gtest)
add_executable(test_leetcode ${LEETCODE_TEST})
target_link_libraries(
    test_leetcode
    gtest
)

#add_test(name test COMMAND test_leetcode)

