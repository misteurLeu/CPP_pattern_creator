#ifndef PIXELCOLOR_H
#define PIXELCOLOR_H

#include <tuple>
#include <string>

#include "ImageEditor_global.h"

enum EColorType
{
    RGB,
    HSL,
    XYZ,
    LAB
};
const std::string colorsTypesNames[] = {"RGB", "HSL", "XYZ", "LAB"};


class IMAGEEDITOR_EXPORT PixelColor
{
    private:
        double _a; // between 0 and 1
        std::tuple<int, int, int> _rgb;
        std::tuple<double, double, double> _hsl;
        std::tuple<double, double, double> _xyz;
        std::tuple<double, double, double> _lab;

        /*
         * color: 3 component tuple in rgb, hsl, xyz or lab
         * alpha: alpha component of the color
         * type: the type of color
        */

    public:
        PixelColor(std::tuple<double, double, double> color, double alpha, EColorType type);

    // conversion methods
        static std::tuple<double, double, double>RGBtoHSL(int r, int g, int b);
        static std::tuple<int, int, int>HSLtoRGB(double h, double s, double l);
        static std::tuple<double, double, double>RGBtoXYZ(int r, int g, int b);
        static std::tuple<int, int, int>XYZtoRGB(double X, double Y, double Z);
        static std::tuple<double, double, double>XYZtoLab(double X, double Y, double Z);
        static std::tuple<double, double, double>LabtoXYZ(double L, double a, double b);
        static std::tuple<double, double, double>RGBtoLab(int r, int g, int b);
        static std::tuple<int, int, int>LabtoRGB(double L, double a, double B);
        static std::tuple<double, double, double>HSLtoXYZ(double h, double s, double l);
        static std::tuple<double, double, double>XYZtoHSL(double x, double y, double z);
        static std::tuple<double, double, double>HSLtoLab(double h, double s, double l);
        static std::tuple<double, double, double>LabtoHSL(double L, double a, double b);
    // export
        std::tuple<int, int, int> getRGB();
        std::tuple<double, double, double> getHSL();
        std::tuple<double, double, double> getXYZ();
        std::tuple<double, double, double> getLab();
        std::string toString(EColorType color = EColorType::RGB);

    //operators
        bool operator==(PixelColor &other);
        PixelColor operator+(PixelColor &other);
        PixelColor operator-(PixelColor &other);
        PixelColor operator!();

    // distance functions
        double ciede2000(PixelColor &other);
        double ciede94(PixelColor &other);
        double euclidian(PixelColor &other, bool WeigthByAlpha = false);
};

#endif // PIXELCOLOR_H
