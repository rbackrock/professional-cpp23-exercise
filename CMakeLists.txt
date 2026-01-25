cmake_minimum_required(VERSION 3.20)

# 设置项目名称和版本
project(ProfessionalCpp23Exercise VERSION 1.0)

# 设置C++标准为C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 查找src目录中的所有.cpp文件
file(GLOB_RECURSE SOURCES "src/*.cpp")

# 确保至少找到一个源文件
if(NOT SOURCES)
  message(FATAL_ERROR "No source files found in src directory!")
endif()

# 为每个源文件创建一个单独的可执行文件
foreach(SOURCE_FILE ${SOURCES})
  # 获取源文件的相对路径（相对于src目录）
  file(RELATIVE_PATH RELATIVE_PATH ${CMAKE_SOURCE_DIR}/src ${SOURCE_FILE})
  
  # 将路径中的目录分隔符替换为下划线，用作唯一标识符
  string(REPLACE "/" "_" UNIQUE_ID ${RELATIVE_PATH})
  string(REPLACE "\\" "_" UNIQUE_ID ${UNIQUE_ID})
  
  # 获取源文件名（不含路径和扩展名）
  get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)
  
  # 创建唯一的目标名称（包含目录信息）
  string(REPLACE ".cpp" "" TARGET_NAME ${UNIQUE_ID})
  
  # 创建可执行文件
  add_executable(${TARGET_NAME} ${SOURCE_FILE})
  
  # 设置可执行文件的输出目录
  get_filename_component(DIR_NAME ${RELATIVE_PATH} DIRECTORY)
  
  if(DIR_NAME)
    # 如果有目录结构，保持相同的目录结构
    set_target_properties(${TARGET_NAME} PROPERTIES
      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${DIR_NAME}
      LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${DIR_NAME}
      ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${DIR_NAME}
    )
  endif()
  
  # 如果有头文件目录，可以添加以下行
  # target_include_directories(${TARGET_NAME} PRIVATE "include")
endforeach()