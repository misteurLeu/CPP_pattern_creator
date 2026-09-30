#include "../../ImageEditor/pixelcolor.h"
#include "../../ImageEditor/imageeditor.h"
#include <iostream>
#include <string>

class TestImageEditor
{

    public:

        static int TestloadImage(std::string imagePath, ImageEditor expected)
        {
            ImageEditor result = ImageEditor::LoadFromFile(imagePath);
            int testFailed  = 0;

            if (expected != result)
            {
                std::cerr << "Loading image test failed for image " << imagePath << std::endl;
                testFailed = 1;
            }

            return testFailed;
        }
};

int main(int argc, char* argv[])
{
    int choice = 1;
    int result = 0;
    ImageEditor *expected = NULL;
    std::vector<PixelColor> *pixels = NULL;


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
        case 1: // image black
            pixels = new std::vector<PixelColor>();
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 1, EColorType::RGB));

            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 1, EColorType::RGB));

            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 1, EColorType::RGB));

            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 1, EColorType::RGB));

            expected = new ImageEditor(*pixels, 4, 4);
            result = TestImageEditor::TestloadImage(
                "testImages\\Black.png",
                *expected
            );
        break;
        case 2: // image white
            pixels = new std::vector<PixelColor>();
            pixels->push_back(PixelColor(std::make_tuple(255, 255, 255), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(255, 255, 255), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(255, 255, 255), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(255, 255, 255), 1, EColorType::RGB));

            pixels->push_back(PixelColor(std::make_tuple(255, 255, 255), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(255, 255, 255), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(255, 255, 255), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(255, 255, 255), 1, EColorType::RGB));

            pixels->push_back(PixelColor(std::make_tuple(255, 255, 255), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(255, 255, 255), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(255, 255, 255), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(255, 255, 255), 1, EColorType::RGB));

            pixels->push_back(PixelColor(std::make_tuple(255, 255, 255), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(255, 255, 255), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(255, 255, 255), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(255, 255, 255), 1, EColorType::RGB));

            expected = new ImageEditor(*pixels, 4, 4);
            result = TestImageEditor::TestloadImage(
                "testImages/White.png",
                *expected
            );
        break;
        case 3: // image Transparent
            pixels = new std::vector<PixelColor>();
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 0, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 0, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 0, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 0, EColorType::RGB));

            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 0, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 0, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 0, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 0, EColorType::RGB));

            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 0, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 0, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 0, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 0, EColorType::RGB));

            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 0, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 0, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 0, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 0, EColorType::RGB));

            expected = new ImageEditor(*pixels, 4, 4);
            result = TestImageEditor::TestloadImage(
                "testImages/Transparent.png",
                *expected
            );
        break;
        case 4: // image Multicolor
            pixels = new std::vector<PixelColor>();
            pixels->push_back(PixelColor(std::make_tuple(255, 0, 0), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 255, 0), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 255), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 1, EColorType::RGB));

            pixels->push_back(PixelColor(std::make_tuple(255, 255, 255), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(255, 255, 0), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(255, 0, 255), 1, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 255, 255), 1, EColorType::RGB));

            pixels->push_back(PixelColor(std::make_tuple(255, 0, 0), 100.0/255.0, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 255, 0), 100.0/255.0, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 255), 100.0/255.0, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 0, 0), 100.0/255.0, EColorType::RGB));

            pixels->push_back(PixelColor(std::make_tuple(255, 255, 255), 100.0/255.0, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(255, 255, 0), 100.0/255.0, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(255, 0, 255), 100.0/255.0, EColorType::RGB));
            pixels->push_back(PixelColor(std::make_tuple(0, 255, 255), 100.0/255.0, EColorType::RGB));

            expected = new ImageEditor(*pixels, 4, 4);
            result = TestImageEditor::TestloadImage(
                "testImages/Multicolor.png",
                *expected
            );
        break;
        default:
            std::cerr << "Test #" << choice << " does not exists" << std::endl;
            result = 1;
    }
    if (pixels != NULL)
        delete pixels;
    if (expected != NULL)
        delete expected;
    return result;
}