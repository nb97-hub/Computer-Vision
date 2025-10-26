cmake_minimum_required(VERSION 3.10.0)
project(OpenCVExample)

# Set the OpenCV directory
set(OpenCV_DIR "C:/dev/libs/opencv/build/")
set(OPENCV_LOG_LEVEL OFF)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Add executable target
add_executable(${PROJECT_NAME} main.cpp)

# Link OpenCV libraries
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})