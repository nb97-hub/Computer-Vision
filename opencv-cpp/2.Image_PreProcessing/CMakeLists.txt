cmake_minimum_required(VERSION 3.10.0)
project(ImageFiltering)

# Set the OpenCV directory
set(OpenCV_DIR "C:/dev/libs/opencv/build/")

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Add executable target
add_executable(Smoothing smoothing.cpp)
add_executable(Morpho morpho.cpp)
add_executable(SAP salt_and_pepper.cpp)
add_executable(GN gaussian_noise.cpp)

# Link OpenCV libraries
target_link_libraries(Smoothing ${OpenCV_LIBS})
target_link_libraries(Morpho ${OpenCV_LIBS})
target_link_libraries(SAP ${OpenCV_LIBS})
target_link_libraries(GN ${OpenCV_LIBS})