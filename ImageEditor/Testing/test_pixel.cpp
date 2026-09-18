#include "../../ImageEditor/pixelcolor.h"
#include <iostream>
#include <string>

class TestPixels
{

    public:
        static std::string tupleToString(std::tuple<double, double, double> tuple)
        {
            double part1 = std::get<0>(tuple);
            double part2 = std::get<1>(tuple);
            double part3 = std::get<2>(tuple);

            return "( " + std::to_string(part1) + " , " + std::to_string(part2) + " , " + std::to_string(part3) + " )";
        }

        static bool areTupleEqual(std::tuple<double, double, double> tuple1, std::tuple<double, double, double> tuple2, uint zeroTolerance = 6)
        {
            double tuple1Part1 = std::get<0>(tuple1);
            double tuple1Part2 = std::get<1>(tuple1);
            double tuple1Part3 = std::get<2>(tuple1);
            double tuple2Part1 = std::get<0>(tuple2);
            double tuple2Part2 = std::get<1>(tuple2);
            double tuple2Part3 = std::get<2>(tuple2);

            double tolerance = 1.0 / (10.0 * (double)zeroTolerance);

            if (std::abs(tuple2Part1 - tuple1Part1) > tolerance)
                return false;
            if (std::abs(tuple2Part2 - tuple1Part2) > tolerance)
                return false;
            if (std::abs(tuple2Part3 - tuple1Part3) > tolerance)
                return false;

            return true;
        }

        static int testInit(
            std::tuple<double, double, double>  colorIn,
            double alphaIn,
            EColorType typeIn,
            std::tuple<int, int, int> targetRgb,
            std::tuple<double, double, double> targetHsl,
            std::tuple<double, double, double> targetXyz,
            std::tuple<double, double, double> targetLab)
        {
            int testFailed  = 0;

            PixelColor colorTested = PixelColor(colorIn, alphaIn, typeIn);

            if (!TestPixels::areTupleEqual(colorTested.getRGB(), targetRgb))
            {
                std::cerr << "RGB color not passed " << TestPixels::tupleToString(targetRgb) << " was expected || " << colorTested.toString(EColorType::RGB) << " found" << std::endl;
                testFailed  = 1;
            }
            if (!TestPixels::areTupleEqual(colorTested.getHSL(), targetHsl))
            {
                std::cerr << "HSL color not passed " << TestPixels::tupleToString(targetHsl) << " was expected || " << colorTested.toString(EColorType::HSL) << " found" << std::endl;
                testFailed  = 1;
            }
            if (!TestPixels::areTupleEqual(colorTested.getXYZ(), targetXyz))
            {
                std::cerr << "XYZ color not passed " << TestPixels::tupleToString(targetXyz) << " was expected || " << colorTested.toString(EColorType::XYZ) << " found" << std::endl;
                testFailed  = 1;
            }
            if (!TestPixels::areTupleEqual(colorTested.getLab(), targetLab))
            {
                std::cerr << "Lab color not passed " << TestPixels::tupleToString(targetLab) << " was expected || " << colorTested.toString(EColorType::LAB) << " found" << std::endl;
                testFailed  = 1;
            }

            return testFailed;
        }

        static int testOperatorEqual(
            PixelColor color1,
            PixelColor color2,
            bool expected
        )
        {
            if ((color1 == color2) != expected)
            {
                std::cerr << "Equal operator test not passed for colors "<< color1.toString() << " and " << color2.toString() << ", should be " << ((expected)? "equal": "different");
                return 1;
            }
            return 0;
        }

        static int testOperatorSum(
            PixelColor color1,
            PixelColor color2,
            PixelColor expected
        )
        {
            PixelColor result = color1 + color2;

            if (result != expected)
            {
                std::cerr << "Sum operator test not passed for colors "<< color1.toString() << " and " << color2.toString() << " result is: " << result.toString() << " expected: "<< expected.toString();
                return 1;
            }
            return 0;
        }

        static int testOperatorSubstract(
            PixelColor color1,
            PixelColor color2,
            PixelColor expected
        )
        {
            PixelColor result = color1 - color2;

            if (result != expected)
            {
                std::cerr << "Substraction operator test not passed for colors "<< color1.toString() << " and " << color2.toString() << " result is: " << result.toString() << " expected: "<< expected.toString();
                return 1;
            }
            return 0;
        }

        static int testOperatorInvert(
            PixelColor color,
            PixelColor expected
        )
        {
            PixelColor result = !color;

            if (result != expected)
            {
                std::cerr << "! operator test not passed for color "<< color.toString() << " result is: " << result.toString() << " expected: "<< expected.toString();
                return 1;
            }
            return 0;
        }

        static int testInitLoop(int pixelNumberToInit)
        {
            for (int i=0; i < pixelNumberToInit; i++)
            {
                PixelColor _plop = PixelColor(std::make_tuple(10,25,90), 0.67, EColorType::RGB);
            }
            return 0;
        }

        static int testCiede20(
            PixelColor color1,
            PixelColor color2,
            double expected
        )
        {
            return 0;
        }

        static int testCiede94(
            PixelColor color1,
            PixelColor color2,
            double expected
        )
        {
            return 0;
        }

        static int testEuclidian(
            PixelColor color1,
            PixelColor color2,
            bool weigthByAlpha,
            double expected
        )
        {
            return 0;
        }
};

int main(int argc, char* argv[])
{
    int choice = 1;

    std::cerr << "ImageEditorTests started" << std::endl;

    if (argc > 1)
    {
        if (std::sscanf(argv[1], "%d", &choice) != 1)
        {
            std::cerr << "Couldn't parse that input as a number" << std::endl;
            return -1;
        }
    }

    switch(choice)
    {
        case 1: //from rgb black
            return TestPixels::testInit(
                std::make_tuple(0, 0, 0),
                0,
                EColorType::RGB,

                std::make_tuple(0, 0, 0),
                std::make_tuple(0, 0, 0),
                std::make_tuple(0, 0, 0),
                std::make_tuple(0, 0, 0)
            );
        break;
        case 2: // from rgb red
            return TestPixels::testInit(
                std::make_tuple(255, 0, 0),
                0,
                EColorType::RGB,

                std::make_tuple(255, 0, 0),
                std::make_tuple(0, 1, 0.5),
                std::make_tuple(0.412456, 0.212673, 0.019334),
                std::make_tuple(53.24, 80.09, 67.2)
            );
        break;
        case 3: // from rgb green
            return TestPixels::testInit(
                std::make_tuple(0, 255, 0),
                0,
                EColorType::RGB,

                std::make_tuple(0, 255, 0),
                std::make_tuple(120, 1, 0.5),
                std::make_tuple(0.357576, 0.715152, 0.119192),
                std::make_tuple(87.73, -86.18, 83.18)
            );
        break;
        case 4: // from rgb blue
            return TestPixels::testInit(
                std::make_tuple(0, 0, 255),
                0,
                EColorType::RGB,

                std::make_tuple(0, 0, 255),
                std::make_tuple(240, 1, 0.5),
                std::make_tuple(0.180437, 0.072175, 0.950304),
                std::make_tuple(32.3, 79.19, -107.86)
            );
        case 5: // from rgb white
            return TestPixels::testInit(
                std::make_tuple(255, 255, 255),
                0,
                EColorType::RGB,

                std::make_tuple(255, 255, 255),
                std::make_tuple(0, 0, 1),
                std::make_tuple(0.950470, 1.0, 1.088830),
                std::make_tuple(100, 0, 0)
            );
        break;

        case 6: //from hsl black
            return TestPixels::testInit(
                std::make_tuple(0, 0, 0),
                0,
                EColorType::HSL,

                std::make_tuple(0, 0, 0),
                std::make_tuple(0, 0, 0),
                std::make_tuple(0, 0, 0),
                std::make_tuple(0, 0, 0)
            );
        break;
        case 7: // from hsl red
            return TestPixels::testInit(
                std::make_tuple(0, 1, 0.5),
                0,
                EColorType::HSL,

                std::make_tuple(255, 0, 0),
                std::make_tuple(0, 1, 0.5),
                std::make_tuple(0.412456, 0.212673, 0.019334),
                std::make_tuple(53.24, 80.09, 67.2)
            );
        break;
        case 8: // from hsl green
            return TestPixels::testInit(
                std::make_tuple(120, 1, 0.5),
                0,
                EColorType::HSL,

                std::make_tuple(0, 255, 0),
                std::make_tuple(120, 1, 0.5),
                std::make_tuple(0.357576, 0.715152, 0.119192),
                std::make_tuple(87.73, -86.18, 83.18)
            );
        break;
        case 9: // from hsl blue
            return TestPixels::testInit(
                std::make_tuple(240, 1, 0.5),
                0,
                EColorType::HSL,

                std::make_tuple(0, 0, 255),
                std::make_tuple(240, 1, 0.5),
                std::make_tuple(0.180437, 0.072175, 0.950304),
                std::make_tuple(32.3, 79.19, -107.86)
            );
        case 10: // from hsl white
            return TestPixels::testInit(
                std::make_tuple(0, 0, 1),
                0,
                EColorType::HSL,

                std::make_tuple(255, 255, 255),
                std::make_tuple(0, 0, 1),
                std::make_tuple(0.950470, 1.0, 1.088830),
                std::make_tuple(100, 0, 0)
            );
        break;

        case 11: //from xyz black
            return TestPixels::testInit(
                std::make_tuple(0, 0, 0),
                0,
                EColorType::XYZ,

                std::make_tuple(0, 0, 0),
                std::make_tuple(0, 0, 0),
                std::make_tuple(0, 0, 0),
                std::make_tuple(0, 0, 0)
            );
        break;
        case 12: // from XYZ red
            return TestPixels::testInit(
                std::make_tuple(0.412456, 0.212673, 0.019334),
                0,
                EColorType::XYZ,

                std::make_tuple(255, 0, 0),
                std::make_tuple(0, 1, 0.5),
                std::make_tuple(0.412456, 0.212673, 0.019334),
                std::make_tuple(53.24, 80.09, 67.2)
            );
        break;
        case 13: // from XYZ green
            return TestPixels::testInit(
                std::make_tuple(0.357576, 0.715152, 0.119192),
                0,
                EColorType::XYZ,

                std::make_tuple(0, 255, 0),
                std::make_tuple(120, 1, 0.5),
                std::make_tuple(0.357576, 0.715152, 0.119192),
                std::make_tuple(87.73, -86.18, 83.18)
            );
        break;
        case 14: // from XYZ blue
            return TestPixels::testInit(
                std::make_tuple(0.180437, 0.072175, 0.950304),
                0,
                EColorType::XYZ,

                std::make_tuple(0, 0, 255),
                std::make_tuple(240, 1, 0.5),
                std::make_tuple(0.180437, 0.072175, 0.950304),
                std::make_tuple(32.3, 79.19, -107.86)
            );
        case 15: // from XYZ white
            return TestPixels::testInit(
                std::make_tuple(0.950470, 1.0, 1.088830),
                0,
                EColorType::XYZ,

                std::make_tuple(255, 255, 255),
                std::make_tuple(0, 0, 1),
                std::make_tuple(0.950470, 1.0, 1.088830),
                std::make_tuple(100, 0, 0)
            );
        break;

        case 16: //from lab black
            return TestPixels::testInit(
                std::make_tuple(0, 0, 0),
                0,
                EColorType::LAB,

                std::make_tuple(0, 0, 0),
                std::make_tuple(0, 0, 0),
                std::make_tuple(0, 0, 0),
                std::make_tuple(0, 0, 0)
            );
        break;
        case 17: // from lab red
            return TestPixels::testInit(
                std::make_tuple(53.24, 80.09, 67.2),
                0,
                EColorType::LAB,

                std::make_tuple(255, 0, 0),
                std::make_tuple(0, 1, 0.5),
                std::make_tuple(0.412456, 0.212673, 0.019334),
                std::make_tuple(53.24, 80.09, 67.2)
            );
        break;
        case 18: // from lab green
            return TestPixels::testInit(
                std::make_tuple(87.73, -86.18, 83.18),
                0,
                EColorType::LAB,

                std::make_tuple(0, 255, 0),
                std::make_tuple(120, 1, 0.5),
                std::make_tuple(0.357576, 0.715152, 0.119192),
                std::make_tuple(87.73, -86.18, 83.18)
            );
        break;
        case 19: // from lab blue
            return TestPixels::testInit(
                std::make_tuple(32.3, 79.19, -107.86),
                0,
                EColorType::LAB,

                std::make_tuple(0, 0, 255),
                std::make_tuple(240, 1, 0.5),
                std::make_tuple(0.180437, 0.072175, 0.950304),
                std::make_tuple(32.3, 79.19, -107.86)
            );
        case 20: // from lab white
            return TestPixels::testInit(
                std::make_tuple(100, 0, 0),
                0,
                EColorType::LAB,

                std::make_tuple(255, 255, 255),
                std::make_tuple(0, 0, 1),
                std::make_tuple(0.950470, 1.0, 1.088830),
                std::make_tuple(100, 0, 0)
            );
        break;
        case 21:// Equal operator with equal pixel
            return TestPixels::testOperatorEqual(
                PixelColor(std::make_tuple(10,25,90), 0.7, EColorType::RGB),
                PixelColor(std::make_tuple(10,25,90), 0.7, EColorType::RGB),
                true
            );
        break;
        case 22:// Equal operator with not equal pixels
            return TestPixels::testOperatorEqual(PixelColor(std::make_tuple(10,25,90), 0.67, EColorType::RGB),
                PixelColor(std::make_tuple(0,0,0), 1, EColorType::RGB),
                false
            );
            break;
        case 23:// sum operator normal
            return TestPixels::testOperatorSum(
                PixelColor(std::make_tuple(10, 25, 90), 0.2, EColorType::RGB),
                PixelColor(std::make_tuple(5, 44, 120), 0.3, EColorType::RGB),
                PixelColor(std::make_tuple(15, 69, 210), 0.5, EColorType::RGB)
            );
        break;
        case 24:// sum operator zero
            return TestPixels::testOperatorSum(
                PixelColor(std::make_tuple(0, 0, 0), 0, EColorType::RGB),
                PixelColor(std::make_tuple(0, 0, 0), 0, EColorType::RGB),
                PixelColor(std::make_tuple(0, 0, 0), 0, EColorType::RGB)
            );
        break;
        case 25:// sum operator overflow
            return TestPixels::testOperatorSum(
                PixelColor(std::make_tuple(200, 260, 150), 1, EColorType::RGB),
                PixelColor(std::make_tuple(220, 50, 155), 1, EColorType::RGB),
                PixelColor(std::make_tuple(255, 255, 255), 1, EColorType::RGB)
            );
        break;
        case 26:// sub operator normal
            return TestPixels::testOperatorSubstract(
                PixelColor(std::make_tuple(200, 260, 150), 1, EColorType::RGB),
                PixelColor(std::make_tuple(50, 50, 50), 0.5, EColorType::RGB),
                PixelColor(std::make_tuple(150, 210, 100), 0.5, EColorType::RGB)
            );
        break;
        case 27:// sub operator zero
            return TestPixels::testOperatorSubstract(
                PixelColor(std::make_tuple(20, 50, 100), 0.63, EColorType::RGB),
                PixelColor(std::make_tuple(0, 0, 0), 0, EColorType::RGB),
                PixelColor(std::make_tuple(20, 50, 100), 0.63, EColorType::RGB)
            );
        break;
        case 28:// sub operator negative
            return TestPixels::testOperatorSubstract(
                PixelColor(std::make_tuple(200, 260, 150), 0.2, EColorType::RGB),
                PixelColor(std::make_tuple(220, 300, 155), 1, EColorType::RGB),
                PixelColor(std::make_tuple(0, 0, 0), 0, EColorType::RGB)
            );
        break;
        case 29:// ! operator 0, 0, 0
            return TestPixels::testOperatorInvert(
                PixelColor(std::make_tuple(0, 0, 0), 0.7, EColorType::RGB),
                PixelColor(std::make_tuple(255, 255, 255), 0.7, EColorType::RGB)
            );
        break;
        case 30:// ! operator 255,255,255
            return TestPixels::testOperatorInvert(
                PixelColor(std::make_tuple(255, 255, 255), 0.7, EColorType::RGB),
                PixelColor(std::make_tuple(0, 0, 0), 0.7, EColorType::RGB)
            );
        break;
        case 31:// ! operator intermediate
            return TestPixels::testOperatorInvert(
                PixelColor(std::make_tuple(47, 213, 2), 0.7, EColorType::RGB),
                PixelColor(std::make_tuple(208, 42, 253), 0.7, EColorType::RGB)
            );
        break;
        case 32:// init 720p image
            return TestPixels::testInitLoop(777600);
        break;

        default:
            std::cerr << "Test #" << choice << "does not exists" << std::endl;
            return 1;
    }

    return 1;
}