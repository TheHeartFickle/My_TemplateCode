# CMake的预定义变量

PROJECT_SOURCE_DIR：工程根目录；  

PROJECT_BINARY_DIR：运行cmake命令的目录。建议定义为${PROJECT_SOURCE_DIR}/build下。具体原因见后文外部编译部分；  

CMAKE_INCLUDE_PATH：环境变量，非cmake变量；  

CMAKE_LIBRARY_PATH：环境变量；  

CMAKE_CURRENT_SOURCE_DIR：当前处理的CMakeLists.txt文件所在路径；  

CMAKE_CURRENT_BINARY_DIR：target编译目录；
使用ADD_SURDIRECTORY指令可以更改该变量的值；  

SET(EXECUTABLE_OUTPUT_PATH < dir >) 指令不会对该变量有影响，但改变了最终目标文件的存储路径；  

CMAKE_CURRENT_LIST_FILE：输出调用该变量的CMakeLists.txt的完整路径；  

CMAKE_CURRENT_LIST_LINE：输出该变量所在的行；  

CMAKE_MODULE_PATH：定义自己的cmake模块所在路径；  

EXECUTABLE_OUTPUT_PATH：重新定义目标二进制可执行文件的存放位置；  

LIBRARY_OUTPUT_PATH：重新定义目标链接库文件的存放位置；  

PROJECT_NAME：返回由PROJECT指令定义的项目名称；  

CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS：用来控制IF...ELSE...语句的书写方式；  

# 系统信息预定义变量

CMAKE_MAJOR_VERSION cmake主版本号,如2.8.6中的2  

CMAKE_MINOR_VERSION cmake次版本号,如2.8.6中的8  

CMAKE_PATCH_VERSION cmake补丁等级,如2.8.6中的6  

CMAKE_SYSTEM 系统名称,例如Linux-2.6.22  

CMAKE_SYSTEM_NAME 不包含版本的系统名,如Linux  

CMAKE_SYSTEM_VERSION 系统版本,如2.6.22  

CMAKE_SYSTEM_PROCESSOR 处理器名称,如i686  

UNIX 在所有的类UNIX平台为TRUE,包括OS X和cygwin  

WIN32 在所有的win32平台为TRUE,包括cygwin

# 开关选项

BUILD_SHARED_LIBS 控制默认的库编译方式。
注：如果未进行设置,使用ADD_LIBRARY时又没有指定库类型,默认编译生成的库都是静态库。  

CMAKE_C_FLAGS 设置C编译选项  

CMAKE_CXX_FLAGS 设置C++编译选项  

# CMake常用语法

cmake_minimum_required (VERSION X.X) 说明CMake最低版本要求  

PROJECT(|name|)  定义了工程的名称  

PROJECT_BINARY_DIR = |projectname|_BINARY_DIR：二进制文件保存路径  项目构建期确定,无法更改

PROJECT_SOURCE_DIR = |projectname|_SOURCE_DIR：源代码路径  

# 将 ~(<dir_list> <variable>) 中 <dir_list> 的所有源文件存储进 <variable>

# aux_source_directory(./src SRCLIST)

# file(GLOB/GLOB_RECURSE 变量名 要搜索的文件路径和文件类型)

# file(GLOB SRCLIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

SET(VAR [VALUE] [CACHE TYPEDOCSTRING [FORCE]])
**ep:**
``
SET(SRC_LIST
    /*
        some src-cpp
    */
        )
``
``
ADD_EXECUTABLE(DEMO ${SRC_LIST})
``
**定义了该工程会生成一个名为DEMO的可执行文件，所依赖的源文件是变量SRC_LIST定义的源文件列表。**

**ADD_SUBDIRECTORY(source_dir [binary_dir] [EXCLUDE_FROM_ALL])**

source_dir：源文件路径；
[binary_dir]：中间二进制与目标二进制存放路径；
[EXECLUDE_FROM_ALL]：将这个目录从编译过程中排除；

**ADD_EXECUTABLE(exename srcname)**

exename：可执行文件名
srcname：生成该可执行文件的源文件

**ADD_LIBRARY(libname [SHARED|STATIC|MODULE] [EXCLUDE_FROM_ALL] source1 source2 ... sourceN)**  

libname：库文件名称；
[SHARED|STATIC|MODULE]：生成库文件类型（共享库/静态库）
[EXCLUDE_FROM_ALL]：表示该库不会被默认构建
source1, ..., sourceN：生成库所依赖的源文件  
