# NAME/CMakeLists.txt
# Created by Robin Rowe 2019-11-18
# License: MIT Open Source

cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(MileageMaster)
enable_testing()
file(STRINGS sources.cmake SOURCES)
add_library(${PROJECT_NAME}_lib ${SOURCES})
link_libraries(${PROJECT_NAME}_lib)
if(NOT WIN32 AND NOT APPLE)
	link_libraries(rt pthread)
endif(NOT WIN32 AND NOT APPLE)

option(UNISTD "Enable libunistd" false)
if(UNISTD)
	set(LIBUNISTD_PATH /code/libunistd)
	if(WIN32)
		include_directories(${LIBUNISTD_PATH}/unistd)
		link_directories(${LIBUNISTD_PATH}/build/unistd/Release)
		link_libraries(libunistd)
	endif(WIN32)
endif(UNISTD)

option(FLTK "Enable FLTK" true)
if(FLTK)
	set(FLTK_DIR /Code/fltk)
	include_directories(${FLTK_DIR} ${FLTK_DIR}/build)
	link_directories(${FLTK_DIR}/build/lib/Debug)
endif(FLTK)

add_executable(mileage_master mileage_master.cpp)
add_executable(test_UiInDash_${PROJECT_NAME} test/test_UiInDash.cpp)
add_test(test_UiInDash_${PROJECT_NAME} test_UiInDash)
add_executable(test_Vehicle_${PROJECT_NAME} test/test_Vehicle.cpp)
add_test(test_Vehicle_${PROJECT_NAME} test_Vehicle)
add_executable(test_Traffic_${PROJECT_NAME} test/test_Traffic.cpp)
add_test(test_Traffic_${PROJECT_NAME} test_Traffic)
add_executable(test_RouteMap_${PROJECT_NAME} test/test_RouteMap.cpp)
add_test(test_RouteMap_${PROJECT_NAME} test_RouteMap)
