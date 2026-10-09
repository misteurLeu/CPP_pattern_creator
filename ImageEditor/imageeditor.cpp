#include "imageeditor.h"
#include "SDL3_image/SDL_image.h"

#include <string>
#include <iostream>
#include <vector>


ImageEditor::ImageEditor(std::vector<PixelColor> pixels, int w, int h)
{
    this->h = h;
    this->w = w;
    this->pixels = pixels;
    for (int i = 0; i < this->pixels.size(); i++)
    {
        if (!this->Palette.contains(this->pixels[i]))
            this->pixelsByColor[this->pixels[i]] = std::vector<int>();
        this->pixelsByColor[this->pixels[i]].push_back(i);
        this->Palette.insert(this->pixels[i]);
    }
}

ImageEditor::ImageEditor(std::string file_path){
    SDL_Surface * imageLoaded = IMG_Load(file_path.c_str());

    if (imageLoaded == NULL)
    {
        std::cerr << "Error loading image " << file_path << " return null value" << std::endl;
        throw "Error while loading image";
    }
    this->w = imageLoaded->w;
    this->h = imageLoaded->h;
    this->pixels.reserve(w * h);

    std::cerr << "image loaded" << std::endl;
    if (w == 0 || h == 0)
        throw "Error while loading image, width or heigth are zero";

    if (imageLoaded->format == SDL_PIXELFORMAT_UNKNOWN)
        throw "Error while loading image sdl image end with an unknow pixel format";

    SDL_Surface * imageLoadedRGBA = SDL_ConvertSurface(imageLoaded, SDL_PIXELFORMAT_RGBA32);
    int pitch = imageLoadedRGBA->pitch;

    uint8_t* pixelsVal = static_cast<uint8_t*>(imageLoadedRGBA->pixels);

    for (int i = 0; i < w * pitch; ++i)
    {
        int y = i / w;
        int x = i % w;
        int pixelPos = y * pitch + x * 4;

        int r, g, b = 0;
        double a = 0;
        r = (int)(pixelsVal[pixelPos]);
        g = (int)(pixelsVal[pixelPos + 1]);
        b = (int)(pixelsVal[pixelPos + 2]);
        a = (double)(pixelsVal[pixelPos + 3]) / 255.0;
        PixelColor new_pixel = PixelColor(std::make_tuple(r, g, b), a, EColorType::RGB);
        this->pixels.push_back(new_pixel);
        if (!this->Palette.contains(new_pixel))
            this->pixelsByColor[new_pixel] = std::vector<int>();
        this->pixelsByColor[new_pixel].push_back(i);
        this->Palette.insert(new_pixel);
    }

    SDL_DestroySurface(imageLoaded);
    SDL_DestroySurface(imageLoadedRGBA);
}

ImageEditor::~ImageEditor()
{
    this->pixels.clear();
}

// that function can be very costly for huge images
bool ImageEditor::operator==(ImageEditor &other)
{
    if (this->w != other.w || this->h != other.h)
        return false;
    for (int i = 0; i < w * h; i++)
    {
        if (this->pixels[i] != other.pixels[i])
            return false;
    }
    return true;
}