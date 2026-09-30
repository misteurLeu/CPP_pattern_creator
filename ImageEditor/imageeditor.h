#ifndef IMAGEEDITOR_H
#define IMAGEEDITOR_H

#include <string>
#include <vector>

#include "pixelcolor.h"
#include "ImageEditor_global.h"


class IMAGEEDITOR_EXPORT ImageEditor
{
    public:
        ImageEditor(std::vector<PixelColor> pixels, int w, int h);
        ~ImageEditor();
        bool operator==(ImageEditor &other);

        static ImageEditor LoadFromFile(std::string file_path);

    private:
        std::vector<PixelColor> pixels;
        int w = 0;
        int h = 0;
};

#endif // IMAGEEDITOR_H
