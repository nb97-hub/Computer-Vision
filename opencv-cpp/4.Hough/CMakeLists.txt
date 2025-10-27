cmake_minimum_required(VERSION 3.10.0)
project(Hough)

# Set the OpenCV directory
set(OpenCV_DIR "C:/dev/libs/opencv/build/")
set(OPENCV_LOG_LEVEL OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Add executable target
add_executable(Hough hough.cpp)

# Link OpenCV libraries
target_link_libraries(Hough ${OpenCV_LIBS})