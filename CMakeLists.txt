# 3.5之后 cmake_minimum_required(VERSION X.X)改为 ~(VERSION <min>...<max>)
cmake_minimum_required(VERSION 3.0...3.7)

# 设置构建模式 VSCode把下面这行注释掉用插件
# set(CMAKE_BUILD_TYPE "Release")

PROJECT(demo VERSION 0.1.0)

# 设置编译器路径
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

# 声明语言标准
# set(CMAKE_C_STANDARD 11)
# set(CMAKE_CXX_STANDARD 11)

# UTF-8的源代码以GBK编码编译
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -fexec-charset=GBK")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

# 根据构建模式 Debug/Release 设置构建路径
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(BUILD_DIR ${PROJECT_SOURCE_DIR}/make/debug)
else()
    set(BUILD_DIR ${PROJECT_SOURCE_DIR}/make/release)
endif()

#链接库输出路径
set(LIBRARY_OUTPUT_PATH ${BUILD_DIR})
# 生成库文件
set(LIBRARY_LIST
    ${PROJECT_SOURCE_DIR}/src/base.cpp
    )
add_library(base SHARED ${LIBRARY_LIST})
# 链接库文件
link_directories(LIBRARY_OUTPUT_PATH)

# 图标链接
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    # message("This script is running on Windows.")
    set(ICON_PATH ${PROJECT_SOURCE_DIR}/resource/icon)
    if(NOT EXISTS ${ICON_PATH}/icon.o)
        execute_process(
            # 如果调用powershell cmd /c 改为 powershell -Command
            COMMAND cmd /c windres -i ${ICON_PATH}/windres.rc -o ${ICON_PATH}/icon.o
            RESULT_VARIABLE result
        )
        if(result EQUAL 0)
            message("========Icon generation for compilation success.========")
        else()
            message("========Icon generation for compilation failed.========")
        endif()
    endif()
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message("Linux用户要什么图标")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    message("macOS懒得做")
else()
    message("这个系统不认识")
endif()

# 可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${BUILD_DIR})
# 生成可执行文件
set(EXEDIR 
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${ICON_PATH}/icon.o
)
add_executable(main ${EXEDIR})

# 链接库文件
target_link_libraries(main base)

# 指定头文件路径
file(GLOB HEADLIST ${PROJECT_SOURCE_DIR}/include/*.h)
include_directories(HEADLIST)

# add_custom_command(
#     TARGET test
#     POST_BUILD
#     WORKING_DIRECTORY ${BUILD_DIR}
#     COMMAND del *.dll.a
#     ) 