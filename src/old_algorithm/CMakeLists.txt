#设置包含的目录
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/array
    ${PROJECT_SOURCE_DIR}/include/binarytree
    ${PROJECT_SOURCE_DIR}/include/dfs
    ${PROJECT_SOURCE_DIR}/include/dp
    ${PROJECT_SOURCE_DIR}/include/gmock
    ${PROJECT_SOURCE_DIR}/include/greedy
    ${PROJECT_SOURCE_DIR}/include/gtest
    ${PROJECT_SOURCE_DIR}/include/list
    ${PROJECT_SOURCE_DIR}/include/stack
    ${PROJECT_SOURCE_DIR}/include/heap
    ${PROJECT_SOURCE_DIR}/include/hashtable
    ${PROJECT_SOURCE_DIR}/include/string
    #${PROJECT_SOURCE_DIR}/include/uthash
    ${PROJECT_SOURCE_DIR}/include/utils
)
#设置链接库搜索目录
link_directories(
    ${PROJECT_SOURCE_DIR}/lib
)
#发现一个目录下所有的源代码文件并将列表存储在一个变量中。
aux_source_directory(${PROJECT_SOURCE_DIR}/src ALGORITHM_SRC)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/utils ALGORITHM_SRC_UTILS)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/binaryTree ALGORITHM_SRC_BINARY_TREE)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/dfs ALGORITHM_SRC_DFS)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/array ALGORITHM_SRC_ARRAY)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/dp ALGORITHM_SRC_DP)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/greedy ALGORITHM_SRC_GREEDY)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/list ALGORITHM_SRC_LIST)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/heap ALGORITHM_SRC_HEAP)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/hashtable ALGORITHM_SRC_HASHTABLE)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/stack ALGORITHM_SRC_STACK)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/string ALGORITHM_SRC_STRING)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/uthash ALGORITHM_SRC_UTHASH)
 
# 参数之间用空格分隔
add_definitions("-Wall -g")

#重新定义目标二进制可执行文件的存放位置
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#重新定义目标链接库文件的存放位置
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
#target_link_libraries里库文件的顺序符合gcc链接顺序的规则，即被依赖的库放在依赖它的库的后面


# 生成静态库
#add_library(common STATIC util.cpp) 
# 生成动态库或共享库
add_library(
    algorithm STATIC 
    ${ALGORITHM_SRC_UTILS}
    ${ALGORITHM_SRC_BINARY_TREE}
    ${ALGORITHM_SRC_DFS}
    ${ALGORITHM_SRC_ARRAY}
    ${ALGORITHM_SRC_DP}
    ${ALGORITHM_SRC_GREEDY}
    ${ALGORITHM_SRC_LIST}
    ${ALGORITHM_SRC_STACK}
    ${ALGORITHM_SRC_HEAP}
    ${ALGORITHM_SRC_HASHTABLE}
    ${ALGORITHM_SRC_STRING}
    ${ALGORITHM_SRC_UTHASH}
)
link_libraries(
    algorithm
)   
add_executable(${PROJECT_NAME} ${ALGORITHM_SRC} ) #生成可执行文件

#设置变量
#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)

#预定义变量
#PROJECT_SOURCE_DIR：工程的根目录
#PROJECT_BINARY_DIR：运行 cmake 命令的目录，通常是 ${PROJECT_SOURCE_DIR}/build
#PROJECT_NAME：返回通过 project 命令定义的项目名称
#CMAKE_CURRENT_SOURCE_DIR：当前处理的 CMakeLists.txt 所在的路径
#CMAKE_CURRENT_BINARY_DIR：target 编译目录
#CMAKE_CURRENT_LIST_DIR：CMakeLists.txt 的完整路径
#CMAKE_CURRENT_LIST_LINE：当前所在的行
#CMAKE_MODULE_PATH：定义自己的 cmake 模块所在的路径，SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)，然后可以用INCLUDE命令来调用自己的模块
#EXECUTABLE_OUTPUT_PATH：重新定义目标二进制可执行文件的存放位置
#LIBRARY_OUTPUT_PATH：重新定义目标链接库文件的存放位置

#使用环境变量
#$ENV{Name}

#系统信息
#­CMAKE_MAJOR_VERSION：cmake 主版本号，比如 3.4.1 中的 3
#­CMAKE_MINOR_VERSION：cmake 次版本号，比如 3.4.1 中的 4
#­CMAKE_PATCH_VERSION：cmake 补丁等级，比如 3.4.1 中的 1
#­CMAKE_SYSTEM：系统名称，比如 Linux-­2.6.22
#­CMAKE_SYSTEM_NAME：不包含版本的系统名，比如 Linux
#­CMAKE_SYSTEM_VERSION：系统版本，比如 2.6.22
#­CMAKE_SYSTEM_PROCESSOR：处理器名称，比如 i686
#­UNIX：在所有的类 UNIX 平台下该值为 TRUE，包括 OS X 和 cygwin
#­WIN32：在所有的 win32 平台下该值为 TRUE，包括 cygwin

#主要开关选项
#BUILD_STATIC_LIBS：这个开关用来控制默认的库编译方式，如果不进行设置，使用 add_library 又没有指定库类型的情况下，默认编译生成的库都是静态库。如果 set(BUILD_STATIC_LIBS ON) 后，默认生成的为动态库
#CMAKE_C_FLAGS：设置 C 编译选项，也可以通过指令 add_definitions() 添加
#CMAKE_CXX_FLAGS：设置 C++ 编译选项，也可以通过指令 add_definitions() 添加
#add_definitions(-DENABLE_DEBUG -DABC) # 参数之间用空格分隔
