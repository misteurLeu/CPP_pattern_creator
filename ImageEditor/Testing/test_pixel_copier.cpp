#include "../../ImageEditor/pixelcolor.h"
#include <iostream>
#include <string>

class TestPixelsInit
{

    public:
        static std::string tupleToString(std::tuple<double, double, double> tuple)
        {
            double part1 = std::get<0>(tuple);
            double part2 = std::get<1>(tuple);
            double part3 = std::get<2>(tuple);

            return "( " + std::to_string(part1) + " , " + std::to_string(part2) + " , " + std::to_string(part3) + " )";
        }

        static int test(
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

            if (colorTested.getRGB() != targetRgb)
            {
                std::cerr << "RGB color not passed, " << TestPixelsInit::tupleToString(targetRgb) << " expected" << TestPixelsInit::tupleToString(colorTested.getRGB()) << " found" << std::endl;
                testFailed  = 1;
            }
            if (colorTested.getHSL() != targetHsl)
            {
                std::cerr << "RGB color not passed, " << TestPixelsInit::tupleToString(targetHsl) << " expected" << TestPixelsInit::tupleToString(colorTested.getHSL()) << " found" << std::endl;
                testFailed  = 1;
            }
            if (colorTested.getXYZ() != targetXyz)
            {
                std::cerr << "RGB color not passed, " << TestPixelsInit::tupleToString(targetXyz) << " expected" << TestPixelsInit::tupleToString(colorTested.getXYZ()) << " found" << std::endl;
                testFailed  = 1;
            }
            if (colorTested.getLab() != targetLab)
            {
                std::cerr << "RGB color not passed, " << TestPixelsInit::tupleToString(targetLab) << " expected" << TestPixelsInit::tupleToString(colorTested.getLab()) << " found" << std::endl;
                testFailed  = 1;
            }

            return testFailed;
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
        case 1:
            return TestPixelsInit::test(
                std::make_tuple(0, 0, 0),
                0,
                EColorType::RGB,

                std::make_tuple(0, 0, 0),
                std::make_tuple(0, 0, 0),
                std::make_tuple(0, 0, 0),
                std::make_tuple(0, 0, 0)
            );
        break;
        default:
            std::cerr << "Test #" << choice << "does not exists" << std::endl;
            return 1;
    }

    return 1;
}