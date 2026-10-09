#ifndef IMAGEEDITOR_H
#define IMAGEEDITOR_H

#include <string>
#include <vector>
#include <set>
#include <map>

#include "pixelcolor.h"
#include "ImageEditor_global.h"


class IMAGEEDITOR_EXPORT ImageEditor
{
    public:
        ImageEditor() = delete;
        ImageEditor(std::vector<PixelColor> pixels, int w, int h);
        ImageEditor(std::string file_path);
        ~ImageEditor();
        bool operator==(ImageEditor &other);

    private:
        std::vector<PixelColor> pixels;
        std::map<PixelColor, std::vector<int>> pixelsByColor;
        std::set<PixelColor> Palette;
        int w = 0;
        int h = 0;
};

#endif // IMAGEEDITOR_H
