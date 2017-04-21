#include "LUTColor.h"
#include "LUTHelper.h"

#include <cmath> //std::isfinite
#include <algorithm> //std::min std::max

LUTColor::LUTColor(LUTColorValue r, LUTColorValue g, LUTColorValue b):
                   red(!std::isfinite(r) ? 0 : r),
                   green(!std::isfinite(g) ? 0 : g),
                   blue(!std::isfinite(b) ? 0 : b)
{}

LUTColorValue LUTColor::getRed() const
{
	return red;
}
LUTColorValue LUTColor::getGreen() const
{
	return green;
}
LUTColorValue LUTColor::getBlue() const
{
	return blue;
}

LUTColor LUTColor::colorWithRGB(LUTColorValue r, LUTColorValue g, LUTColorValue b)
{
	return LUTColor(r, g, b);
}

LUTColor LUTColor::colorWithZeroes()
{
	return colorWithValue(0);
}
LUTColor LUTColor::colorWithOnes()
{
	return colorWithValue(1);
}
LUTColor LUTColor::colorWithValue(double value)
{
	return LUTColor(value, value, value);
}

LUTColor LUTColor::colorFromIntegersWithBitdepth(int bitdepth, int r, int g, int b)
{
	unsigned maxBits = LUTHelper::maxIntegerFromBitdepth(bitdepth);
	return LUTColor::colorWithRGB(LUTHelper::remapInt01(r, maxBits),
		                          LUTHelper::remapInt01(g, maxBits),
		                          LUTHelper::remapInt01(b, maxBits));
}

LUTColor LUTColor::colorFromIntegersWithMaxOutputValue(int maxOutputValue, int r, int g, int b)
{
	return LUTColor::colorWithRGB(LUTHelper::remapInt01(r, maxOutputValue),
		                          LUTHelper::remapInt01(g, maxOutputValue),
	                              LUTHelper::remapInt01(b, maxOutputValue));
}

double LUTColor::minimumValue() const
{
	return std::min(std::min(red, green), blue);
}
double LUTColor::maximumValue() const
{
	return std::max(std::max(red, green), blue);
}

void LUTColor::clamp01()
{
	red = LUTHelper::clamp01(red);
	green = LUTHelper::clamp01(green);
	blue = LUTHelper::clamp01(blue);
}

void LUTColor::clampToBounds(double lowerBound, double upperBound)
{
	red = LUTHelper::clamp(red, lowerBound, upperBound);
	green = LUTHelper::clamp(green, lowerBound, upperBound);
	blue = LUTHelper::clamp(blue, lowerBound, upperBound);
}

void LUTColor::clampToLowerBound(double lowerBound)
{
	red = LUTHelper::clampLowerBound(red, lowerBound);
	green = LUTHelper::clampLowerBound(green, lowerBound);
	blue = LUTHelper::clampLowerBound(blue, lowerBound);
}

void LUTColor::clampToUpperBound(double upperBound)
{
	red = LUTHelper::clampUpperBound(red, upperBound);
	green = LUTHelper::clampUpperBound(green, upperBound);
	blue = LUTHelper::clampUpperBound(blue, upperBound);
}

void LUTColor::remapContrast(double inputLow, double inputHigh, double outputLow, double outputHigh, bool bounded)
{
	if (!bounded)
	{
		red = LUTHelper::remapNoError(red, inputLow, inputHigh, outputLow, outputHigh);
		green = LUTHelper::remapNoError(green, inputLow, inputHigh, outputLow, outputHigh);
		blue = LUTHelper::remapNoError(blue, inputLow, inputHigh, outputLow, outputHigh);
	}
	else
	{
		red = LUTHelper::remap(red, inputLow, inputHigh, outputLow, outputHigh);
		green = LUTHelper::remap(green, inputLow, inputHigh, outputLow, outputHigh);
		blue = LUTHelper::remap(blue, inputLow, inputHigh, outputLow, outputHigh);
	}
}

void LUTColor::remapBetweenColors(const LUTColor &  inputLowColor, const LUTColor & inputHighColor,
                                  const LUTColor & outputLowColor, const LUTColor & outputHighColor,
                                  bool bounded)
{
	if (!bounded)
	{
		red = LUTHelper::remapNoError(red, inputLowColor.getRed(), inputHighColor.getRed(),
		                              outputLowColor.getRed(), outputHighColor.getRed());
		green = LUTHelper::remapNoError(green, inputLowColor.getGreen(), inputHighColor.getGreen(),
		                                outputLowColor.getGreen(), outputHighColor.getGreen());
		blue = LUTHelper::remapNoError(blue, inputLowColor.getBlue(), inputHighColor.getBlue(),
		                               outputLowColor.getBlue(), outputHighColor.getBlue());
	}
	else
	{
		red = LUTHelper::remap(red, inputLowColor.getRed(), inputHighColor.getRed(),
		                       outputLowColor.getRed(), outputHighColor.getRed());
		green = LUTHelper::remap(green, inputLowColor.getGreen(), inputHighColor.getGreen(),
		                         outputLowColor.getGreen(), outputHighColor.getGreen());
		blue = LUTHelper::remap(blue, inputLowColor.getBlue(), inputHighColor.getBlue(),
		                        outputLowColor.getBlue(), outputHighColor.getBlue());
	}
}

void LUTColor::lerpTo(const LUTColor & otherColor, double amount)
{
	red = LUTHelper::lerp1d(red, otherColor.getRed(), amount);
	green = LUTHelper::lerp1d(green, otherColor.getGreen(), amount);
	blue = LUTHelper::lerp1d(blue, otherColor.getBlue(), amount);
}

//thanks http://en.wikipedia.org/wiki/ASC_CDL
void LUTColor::applySlopeOffsetPower(double redSlope, double redOffset, double redPower,
                                     double greenSlope, double greenOffset, double greenPower,
                                     double blueSlope, double blueOffset, double bluePower)
{
	redSlope = LUTHelper::clampLowerBound(redSlope, 0);
	redPower = LUTHelper::clampLowerBound(redPower, 0);
	greenSlope = LUTHelper::clampLowerBound(greenSlope, 0);
	greenPower = LUTHelper::clampLowerBound(greenPower, 0);
	blueSlope = LUTHelper::clampLowerBound(blueSlope, 0);
	bluePower = LUTHelper::clampLowerBound(bluePower, 0);

	red = std::pow(red*redSlope + redOffset, redPower);
	green = std::pow(green*greenSlope + greenOffset, greenPower);
	blue = std::pow(blue*blueSlope + blueOffset, bluePower);
}

double LUTColor::distanceToColor(const LUTColor & otherColor) const
{
    return std::sqrt(std::pow(red - otherColor.getRed(), 2)
                     + std::pow(green - otherColor.getGreen(), 2)
                     + std::pow(blue - otherColor.getBlue(), 2));
}

double LUTColor::luminanceRec709() const
{
	return luminanceUsingLuma(0.2126, 0.7152, 0.0722);
}

double LUTColor::luminanceUsingLuma(double lumaR, double lumaG, double lumaB) const
{
	return (red*lumaR + green*lumaB + blue*lumaB);
}


void LUTColor::contrastStretchWithMinMax(double currentMin, double currentMax, double finalMin, double finalMax)
{
	red = LUTHelper::contrastStretch(red, currentMin, currentMax, finalMin, finalMax);
	green = LUTHelper::contrastStretch(green, currentMin, currentMax, finalMin, finalMax);
	blue = LUTHelper::contrastStretch(blue, currentMin, currentMax, finalMin, finalMax);
}

void LUTColor::multiplyByNumber(double number)
{
	red *= number;
	green *= number;
	blue *= number;
}

void LUTColor::multiplyByColor(const LUTColor & offsetColor)
{
	red *= offsetColor.getRed();
	green *= offsetColor.getGreen();
	blue *= offsetColor.getBlue();
}

void LUTColor::addColor(const LUTColor & offsetColor)
{
	red += offsetColor.getRed();
	green += offsetColor.getGreen();
	blue += offsetColor.getBlue();
}

void LUTColor::subtractColor(const LUTColor & offsetColor)
{
	red -= offsetColor.getRed();
	green -= offsetColor.getGreen();
	blue -= offsetColor.getBlue();
}

void LUTColor::invertColorWithMinMax(double minimumValue, double maximumValue)
{
	double distance = std::abs(maximumValue-minimumValue);
	red = distance - red;
	green = distance - green;
	blue = distance - blue;
}

void LUTColor::changeSaturation(double saturation, double lumaR, double lumaG, double lumaB)
{
	double luma = red * lumaR + green * lumaG + blue * lumaB;
	red = luma + saturation * (red - luma);
	green = luma + saturation * (green - luma);
	blue = luma + saturation * (blue - luma);
}