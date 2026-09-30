cmake_minimum_required(VERSION 3.16)

project(Testing LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(testPixels test_pixel.cpp)
target_link_libraries(testPixels PRIVATE ImageEditor)

add_test(
    NAME RGBinitPixelBlack
    COMMAND testPixels 1
)
add_test(
    NAME RGBinitPixelRed
    COMMAND testPixels 2
)
add_test(
    NAME RGBinitPixelGreen
    COMMAND testPixels 3
)
add_test(
    NAME RGBinitPixelBlue
    COMMAND testPixels 4
)
add_test(
    NAME RGBinitPixelWhite
    COMMAND testPixels 5
)

add_test(
    NAME HSLinitPixelBlack
    COMMAND testPixels 6
)
add_test(
    NAME HSLinitPixelRed
    COMMAND testPixels 7
)
add_test(
    NAME HSLinitPixelGreen
    COMMAND testPixels 8
)
add_test(
    NAME HSLinitPixelBlue
    COMMAND testPixels 9
)
add_test(
    NAME HSLinitPixelWhite
    COMMAND testPixels 10
)

add_test(
    NAME XYZinitPixelBlack
    COMMAND testPixels 11
)
add_test(
    NAME XYZinitPixelRed
    COMMAND testPixels 12
)
add_test(
    NAME XYZinitPixelGreen
    COMMAND testPixels 13
)
add_test(
    NAME XYZinitPixelBlue
    COMMAND testPixels 14
)
add_test(
    NAME XYZinitPixelWhite
    COMMAND testPixels 15
)

add_test(
    NAME LABinitPixelBlack
    COMMAND testPixels 16
)
add_test(
    NAME LABinitPixelRed
    COMMAND testPixels 17
)
add_test(
    NAME LABinitPixelGreen
    COMMAND testPixels 18
)
add_test(
    NAME LABinitPixelBlue
    COMMAND testPixels 19
)
add_test(
    NAME LABinitPixelWhite
    COMMAND testPixels 20
)

add_test(
    NAME EqualOperatorEqual
    COMMAND testPixels 21
)
add_test(
    NAME EqualOperatorNotEqual
    COMMAND testPixels 22
)

add_test(
    NAME sumOperator
    COMMAND testPixels 23
)
add_test(
    NAME sumOperatorZero
    COMMAND testPixels 24
)
add_test(
    NAME sumOperatorOverflow
    COMMAND testPixels 25
)

add_test(
    NAME subOperator
    COMMAND testPixels 26
)
add_test(
    NAME subOperatorZero
    COMMAND testPixels 27
)
add_test(
    NAME subOperatorNeg
    COMMAND testPixels 28
)

add_test(
    NAME invertOperatorZero
    COMMAND testPixels 29
)
add_test(
    NAME InvertOperatorMax
    COMMAND testPixels 30
)
add_test(
    NAME invertOperator
    COMMAND testPixels 31
)

add_test(
    NAME ciede2000SameColor
    COMMAND testPixels 32
)
add_test(
    NAME ciede2000DiffColors
    COMMAND testPixels 33
)
add_test(
    NAME ciede2000DiffColors2
    COMMAND testPixels 34
)

add_executable(testImageEditor test_imageEditor.cpp)
target_link_libraries(testImageEditor PRIVATE ImageEditor)

add_custom_command(TARGET testImageEditor POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_CURRENT_SOURCE_DIR}/testImages"
            "${CMAKE_CURRENT_BINARY_DIR}/testImages"
)

add_test(
    NAME loadBlack
    COMMAND testImageEditor 1
)
add_test(
    NAME loadWhite
    COMMAND testImageEditor 2
)
add_test(
    NAME loadTransparent
    COMMAND testImageEditor 3
)
add_test(
    NAME loadMulticolor
    COMMAND testImageEditor 4
)