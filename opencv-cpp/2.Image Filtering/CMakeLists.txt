cmake_minimum_required(VERSION 3.10.0)
project(ImageFiltering)

# Set the OpenCV directory
set(OpenCV_DIR "C:/dev/libs/opencv/build/")

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Add executable target
add_executable(${PROJECT_NAME} main.cpp)
add_executable(SAP salt_and_pepper.cpp)

# Link OpenCV libraries
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
target_link_libraries(SAP ${OpenCV_LIBS})