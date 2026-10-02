#include "imageeditor.h"
#include "SDL3_image/SDL_image.h"

#include <string>
#include <iostream>


ImageEditor::ImageEditor(std::vector<PixelColor> pixels, int w, int h)
{
    this->h = h;
    this->w = w;
    this->pixels = pixels;
}

ImageEditor::~ImageEditor()
{
    this->pixels.clear();
}

ImageEditor ImageEditor::LoadFromFile(std::string file_path){
    SDL_Surface * imageLoaded = IMG_Load(file_path.c_str());

    if (imageLoaded == NULL)
    {
        std::cerr << "Error loading image " << file_path << " return null value" << std::endl;
        throw "Error while loading image";
    }
    int w = imageLoaded->w;
    int h = imageLoaded->h;
    std::vector<PixelColor> pixels;
    pixels.reserve(w * h);

    std::cerr << "image loaded" << std::endl;
    if (w == 0 || h == 0)
        throw "Error while loading image, width or heigth are zero";

    if (imageLoaded->format == SDL_PIXELFORMAT_UNKNOWN)
        throw "Error while loading image sdl image end with an unknow pixel format";

    SDL_Surface * imageLoadedRGBA = SDL_ConvertSurface(imageLoaded, SDL_PIXELFORMAT_RGBA32);
    int pitch = imageLoadedRGBA->pitch;

    uint8_t* pixelsVal = static_cast<uint8_t*>(imageLoadedRGBA->pixels);

    std::cerr << "image datas w: " << w << " h: " << h << " pitch: " << pitch << std::endl;

    std::cerr << "max vector size :" << pixels.max_size();

    for (int i = 0; i < w * h; ++i)
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
        pixels.push_back(PixelColor(std::make_tuple(r, g, b), a, EColorType::RGB));
    }

    SDL_DestroySurface(imageLoaded);
    SDL_DestroySurface(imageLoadedRGBA);

    return ImageEditor(pixels, w, h);
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