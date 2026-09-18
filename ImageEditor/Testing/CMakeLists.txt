cmake_minimum_required(VERSION 3.16)

project(Testing LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ImageEditorTests test_pixel.cpp
    test_pixel.cpp)

target_link_libraries(ImageEditorTests PRIVATE ImageEditor)

add_test(
    NAME RGBinitPixelBlack
    COMMAND ImageEditorTests 1
)
add_test(
    NAME RGBinitPixelRed
    COMMAND ImageEditorTests 2
)
add_test(
    NAME RGBinitPixelGreen
    COMMAND ImageEditorTests 3
)
add_test(
    NAME RGBinitPixelBlue
    COMMAND ImageEditorTests 4
)
add_test(
    NAME RGBinitPixelWhite
    COMMAND ImageEditorTests 5
)


add_test(
    NAME HSLinitPixelBlack
    COMMAND ImageEditorTests 6
)
add_test(
    NAME HSLinitPixelRed
    COMMAND ImageEditorTests 7
)
add_test(
    NAME HSLinitPixelGreen
    COMMAND ImageEditorTests 8
)
add_test(
    NAME HSLinitPixelBlue
    COMMAND ImageEditorTests 9
)
add_test(
    NAME HSLinitPixelWhite
    COMMAND ImageEditorTests 10
)

add_test(
    NAME XYZinitPixelBlack
    COMMAND ImageEditorTests 11
)
add_test(
    NAME XYZinitPixelRed
    COMMAND ImageEditorTests 12
)
add_test(
    NAME XYZinitPixelGreen
    COMMAND ImageEditorTests 13
)
add_test(
    NAME XYZinitPixelBlue
    COMMAND ImageEditorTests 14
)
add_test(
    NAME XYZinitPixelWhite
    COMMAND ImageEditorTests 15
)

add_test(
    NAME LABinitPixelBlack
    COMMAND ImageEditorTests 16
)
add_test(
    NAME LABinitPixelRed
    COMMAND ImageEditorTests 17
)
add_test(
    NAME LABinitPixelGreen
    COMMAND ImageEditorTests 18
)
add_test(
    NAME LABinitPixelBlue
    COMMAND ImageEditorTests 19
)
add_test(
    NAME LABinitPixelWhite
    COMMAND ImageEditorTests 20
)

add_test(
    NAME EqualOperatorEqual
    COMMAND ImageEditorTests 21
)
add_test(
    NAME EqualOperatorNotEqual
    COMMAND ImageEditorTests 22
)

add_test(
    NAME sumOperator
    COMMAND ImageEditorTests 23
)
add_test(
    NAME sumOperatorZero
    COMMAND ImageEditorTests 24
)
add_test(
    NAME sumOperatorOverflow
    COMMAND ImageEditorTests 25
)

add_test(
    NAME subOperator
    COMMAND ImageEditorTests 26
)
add_test(
    NAME subOperatorZero
    COMMAND ImageEditorTests 27
)
add_test(
    NAME subOperatorNeg
    COMMAND ImageEditorTests 28
)

add_test(
    NAME invertOperatorZero
    COMMAND ImageEditorTests 29
)
add_test(
    NAME InvertOperatorMax
    COMMAND ImageEditorTests 30
)
add_test(
    NAME invertOperator
    COMMAND ImageEditorTests 31
)

add_test(
    NAME initLoop
    COMMAND ImageEditorTests 32
)