#include "pixelcolor.h"
#include <algorithm>
#include <stdexcept>
#include <string>


PixelColor::PixelColor(std::tuple<double, double, double> color, double alpha, EColorType type)
{
    double color1 = std::get<0>(color);
    double color2 = std::get<1>(color);
    double color3 = std::get<2>(color);

    if (alpha < 0 || alpha > 1)
    {
        throw std::runtime_error("alpha out of range, should be between 0 and 1, " + std::to_string(alpha) + "found");
    }
    this->_a = alpha;
    switch (type)
    {
        case EColorType::RGB:
            this->_rgb = color;
            this->_hsl = PixelColor::RGBtoHSL((int)color1, (int)color2, (int)color3);
            this->_xyz = PixelColor::RGBtoXYZ((int)color1, (int)color2, (int)color3);
            this->_lab = PixelColor::RGBtoLab((int)color1, (int)color2, (int)color3);
            break;
        case EColorType::HSL:
            this->_rgb = PixelColor::HSLtoRGB(color1, color2, color3);
            this->_hsl = color;
            this->_xyz = PixelColor::HSLtoXYZ(color1, color2, color3);
            this->_lab = PixelColor::HSLtoLab(color1, color2, color3);
            break;
        case EColorType::XYZ:
            this->_rgb = PixelColor::XYZtoRGB(color1, color2, color3);
            this->_hsl = PixelColor::XYZtoHSL(color1, color2, color3);
            this->_xyz = color;
            this->_lab = PixelColor::XYZtoLab(color1, color2, color3);
            break;
        case EColorType::LAB:
            this->_rgb = PixelColor::LabtoRGB(color1, color2, color3);
            this->_hsl = PixelColor::LabtoHSL(color1, color2, color3);
            this->_xyz = PixelColor::LabtoXYZ(color1, color2, color3);
            this->_lab = color;
            break;
        default:
            throw std::runtime_error("color type" + colorsTypesNames[type] + "is not compatible with pixel color");
    }
}

// conversion methods
std::tuple<double, double, double> PixelColor::RGBtoHSL(int r, int g, int b)
{

    int x_max = std::max({r, g, b});
    int x_min = std::min({r, g, b});
    int chroma = x_max - x_min;
    double L = (x_max + x_min) * 0.5 / 255.0;

    double H = [chroma, r, g, b, x_max]{
        if (chroma == 0)
            return 0.0;
        if (x_max == r)
            return (double)(60.0 * (((g - b) / chroma) % 6));
        if (x_max == g)
            return (double)(60.0 * ((b - r) / chroma + 2));
        if (x_max == b)
            return (double)(60.0 * ((r - g) / chroma + 4));

        throw std::runtime_error("x_max does not match any of r, g or b values, it should never append");
    }();

    double S = (L == 0)? 0 : 1 - std::abs(2 * L - 1);
    return std::make_tuple(H, S, L);
}

std::tuple<int, int, int> PixelColor::HSLtoRGB(double h, double s, double l)
{
    double chroma = (1.0 - std::abs(2.0 * l - 1.0)) * s;
    double H = h / 60.0;
    double X = chroma * (1.0 - std::abs(fmod(H, 2.0) - 1.0));
    double m = l - chroma * 0.5;
    double r, g, b = 0;

    if (H <= 1.0)
    {
        r = chroma;
        g = X;
        b = 0;
    }
    else if (H <= 2.0)
    {
        r = X;
        g = chroma;
        b = 0;
    }
    else if (H <= 3.0)
    {
        r = 0;
        g = chroma;
        b = X;
    }
    else if (H <= 4.0)
    {
        r = 0;
        g = X;
        b = chroma;
    }
    else if (H <= 5.0)
    {
        r = X;
        g = 0;
        b = chroma;
    }
    else if (H <= 6.0)
    {
        r = chroma;
        g = 0;
        b = X;
    }
    else
    {
        throw std::runtime_error("h is bigger than 360");
    }

    r = (r + m) * 255;
    g = (g + m) * 255;
    b = (b + m) * 255;

    return std::make_tuple(r, g, b);
}

std::tuple<double, double, double> PixelColor::RGBtoXYZ(int r, int g, int b)
{
    double red = (double)r / 255.0;
    double green = (double)g / 255.0;
    double blue = (double)b / 255.0;

    // gamma correction
    red = (red > 0.040448236277105097) ? std::pow((red + 0.055) / 1.055, 2.4): red / 12.92;
    green = (green > 0.040448236277105097) ? std::pow((green + 0.055) / 1.055, 2.4): green / 12.92;
    blue = (blue > 0.040448236277105097) ? std::pow((blue + 0.055) / 1.055, 2.4): blue / 12.92;

    // linear transformation using rgb to xyz matrix
	double x = red * 0.4124564390896921145 + green * 0.3575760776439090507 + blue * 0.1804374830853290341;
	double y = red * 0.2126728514056222474 + green * 0.7151521552878181013 + blue * 0.0721749933075596513;
	double z = red * 0.0193338955823293176 + green * 0.1191919550818385936 + blue * 0.9503040770337479886;

    return std::make_tuple(x,y,z);
}

std::tuple<int, int, int> PixelColor::XYZtoRGB(double X, double Y, double Z)
{
	// Applying linear transformation using the XYZ to RGB transformation matrix.
	double r = (X * 0.032404541621141049051 + Y * -0.015371385127977165753 + Z * -0.004985314095560160079) * 100.0;
	double g = (X * -0.009692660305051867686 + Y * 0.018760108454466942288 + Z * 0.00041556017530349983) * 100.0;
	double b = (X * 0.000556434309591145522 + Y * -0.002040259135167538416 + Z * 0.010572251882231790398) * 100.0;

	// Apply gamma correction
	r = (r >  0.003130668442500634)? 1.055 * std::pow(r, 1.0 / 2.4) - 0.055: 12.92 * r;
	g = (g >  0.003130668442500634)? 1.055 * std::pow(g, 1.0 / 2.4) - 0.055: 12.92 * g;
	b = (b >  0.003130668442500634)? 1.055 * std::pow(b, 1.0 / 2.4) - 0.055: 12.92 * b;

    return std::make_tuple(std::round(r * 255), std::round(g * 255), std::round(b * 255));
}

std::tuple<double, double, double> PixelColor::XYZtoLab(double X, double Y, double Z)
{
    double ref_x = 95.047;
    double ref_y = 100.0;
    double ref_z = 108.883;

    double x = (X * 100.0) / ref_x;
    double y = (Y * 100.0) / ref_y;
    double z = (Z * 100.0) / ref_z;

    x = (x > 216.0 / 24389.0) ? std::pow(x, 1.0 / 3.0): ((841.0 / 108.0) * x) + (4.0 / 29.0);
    y = (y > 216.0 / 24389.0) ? std::pow(y, 1.0 / 3.0): ((841.0 / 108.0) * y) + (4.0 / 29.0);
    z = (z > 216.0 / 24389.0) ? std::pow(z, 1.0 / 3.0): ((841.0 / 108.0) * z) + (4.0 / 29.0);

    double l = (116.0 * y) - 16.0;
    double a = 500.0 * (x - y);
    double b = 200.0 * (y - z);

    return std::make_tuple(l, a, b);
}

std::tuple<double, double, double> PixelColor::LabtoXYZ(double L, double a, double b)
{
	// Reference white point : D65 2° Standard observer
	double ref_x = 95.047;
	double ref_y = 100.000;
	double ref_z = 108.883;

	double y = (L + 16.0) / 116.0;
	double x = a / 500.0 + y;
	double z = y - b / 200.0;

	double x3 = x * x * x;
	double y3 = y * y * y;
	double z3 = z * z * z;

	x = (x3 > 216.0 / 24389.0 )? x3: (x - 4.0 / 29.0) / (841.0 / 108.0);
	y = (L > 8.0 )? y3: L / (24389.0 / 27.0);
	z = (z3 > 216.0 / 24389.0)? z3: (z - 4.0 / 29.0) / (841.0 / 108.0);

    return std::make_tuple(x * ref_x / 100.0, y * ref_y / 100.0, z * ref_z / 100.0);
}

std::tuple<double, double, double> PixelColor::RGBtoLab(int r, int g, int b)
{
    std::tuple<double, double, double> xyz = RGBtoXYZ(r, g, b);
    double x = std::get<0>(xyz);
    double y = std::get<1>(xyz);
    double z = std::get<2>(xyz);

    return PixelColor::XYZtoLab(x, y, z);
}

std::tuple<int, int, int> PixelColor::LabtoRGB(double L, double a, double B)
{
    std::tuple<double, double, double> xyz = PixelColor::LabtoXYZ(L, a, B);
    double x = std::get<0>(xyz);
    double y = std::get<1>(xyz);
    double z = std::get<2>(xyz);

    return PixelColor::XYZtoRGB(x, y, z);
}

std::tuple<double, double, double> PixelColor::HSLtoXYZ(double h, double s, double l)
{
    std::tuple<int, int, int> rgb = PixelColor::HSLtoRGB(h, s, l);
    int r = std::get<0>(rgb);
    int g = std::get<1>(rgb);
    int b = std::get<2>(rgb);

    return PixelColor::RGBtoXYZ(r, g, b);
}

std::tuple<double, double, double> PixelColor::XYZtoHSL(double x, double y, double z)
{
    std::tuple<int, int, int> rgb = PixelColor::XYZtoRGB(x, y, z);
    int r = std::get<0>(rgb);
    int g = std::get<1>(rgb);
    int b = std::get<2>(rgb);

    return PixelColor::RGBtoHSL(r, g, b);
}

std::tuple<double, double, double> PixelColor::HSLtoLab(double h, double s, double l)
{
    std::tuple<int, int, int> rgb = PixelColor::HSLtoRGB(h, s, l);
    int r = std::get<0>(rgb);
    int g = std::get<1>(rgb);
    int b = std::get<2>(rgb);

    return PixelColor::RGBtoLab(r, g, b);
}

std::tuple<double, double, double> PixelColor::LabtoHSL(double L, double a, double B)
{
    std::tuple<double, double, double> xyz = PixelColor::LabtoXYZ(L, a, B);
    double x = std::get<0>(xyz);
    double y = std::get<1>(xyz);
    double z = std::get<2>(xyz);

    return PixelColor::XYZtoHSL(x, y, z);
}


// export
std::tuple<int, int, int> PixelColor::getRGB() { return (this->_rgb); }
std::tuple<double, double, double> PixelColor::getHSL() { return (this->_hsl); }
std::tuple<double, double, double> PixelColor::getXYZ() { return (this->_xyz); }
std::tuple<double, double, double> PixelColor::getLab() { return (this->_lab); }
std::string PixelColor::toString(EColorType color)
{
    std::tuple<double, double, double> tuple;
    switch (color)
    {
        case EColorType::RGB:
            tuple = this->_rgb;
        break;
        case EColorType::HSL:
            tuple = this->_hsl;
        break;
        case EColorType::XYZ:
            tuple = this->_xyz;
        break;
        case EColorType::LAB:
            tuple = this->_lab;
        break;
    }

    double part1 = std::get<0>(tuple);
    double part2 = std::get<1>(tuple);
    double part3 = std::get<2>(tuple);

    return "( " + std::to_string(part1) + " , " + std::to_string(part2) + " , " + std::to_string(part3) +  " , " + std::to_string(this->_a) + " )";

}

//operators
bool PixelColor::operator==(PixelColor &other)
{
    return (this->_rgb == other._rgb && this->_a == other._a);
}

PixelColor PixelColor::operator+(PixelColor &other)
{
    int r1 = std::get<0>(this->_rgb);
    int g1 = std::get<1>(this->_rgb);
    int b1 = std::get<2>(this->_rgb);

    int r2 = std::get<0>(other._rgb);
    int g2 = std::get<1>(other._rgb);
    int b2 = std::get<2>(other._rgb);

    int r = std::min(r1+r2, 255);
    int g = std::min(g1+g2, 255);
    int b = std::min(b1+b2, 255);

    double alpha = std::min(this->_a + other._a, 1.0);

    return PixelColor(std::make_tuple(r, g, b), alpha, EColorType::RGB);
}

PixelColor PixelColor::operator-(PixelColor &other)
{
    int r1 = std::get<0>(this->_rgb);
    int g1 = std::get<1>(this->_rgb);
    int b1 = std::get<2>(this->_rgb);

    int r2 = std::get<0>(other._rgb);
    int g2 = std::get<1>(other._rgb);
    int b2 = std::get<2>(other._rgb);

    int r = std::max(r1 - r2, 0);
    int g = std::max(g1 - g2, 0);
    int b = std::max(b1 - b2, 0);

    double alpha = std::max(this->_a - other._a, 0.0);

    return PixelColor(std::make_tuple(r, g, b), alpha, EColorType::RGB);
}

PixelColor PixelColor::operator!()
{
    int r = std::max(255 - std::get<0>(this->_rgb), 0);
    int g = std::max(255 - std::get<1>(this->_rgb), 0);
    int b = std::max(255 - std::get<2>(this->_rgb), 0);

    return PixelColor(std::make_tuple(r, g, b), this->_a, EColorType::RGB);
}

// distance functions
double ciede2000(PixelColor &other){return 0.0;}
double ciede94(PixelColor &other){return 0.0;}
double euclidian(PixelColor &other, bool weightByAlpha){return 0.0;}
