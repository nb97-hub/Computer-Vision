cmake_minimum_required(VERSION 3.10.0)
project(Playground)

# Set the OpenCV directory
set(OpenCV_DIR "C:/dev/libs/opencv/build/")

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Add executable target
add_executable(ROI ROI.cpp)
add_executable(MAT Mat.cpp)

# Link OpenCV libraries
target_link_libraries(ROI ${OpenCV_LIBS})
target_link_libraries(MAT ${OpenCV_LIBS})