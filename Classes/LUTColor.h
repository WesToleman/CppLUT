#pragma once

#include "CppLUT.h"

#include <vector>

namespace CppLUT
{

#define LEGAL_LEVELS_MIN 0.06256109481 //64.0/1023.0
#define LEGAL_LEVELS_MAX 0.91886608015 //940.0/1023.0
#define EXTENDED_LEVELS_MIN 0.0 //0.00391006842 //4.0/1023.0
#define EXTENDED_LEVELS_MAX 1.0 //0.99608993157 //1019.0/1023.0

/**
 *  Used to represent the value of a channel for a `LUTColor`.
 */
typedef double LUTColorValue;

/**
 * @brief      Represents a color value on a 3D LUT lattice.
 */
class LUTColor
{
private:
	/**
	 *  The value of the red channel of the color. Values should be between 0 and 1
	 */
	LUTColorValue red;

	/**
	 *  The value of the green channel of the color. Values should be between 0 and 1
	 */
	LUTColorValue green;

	/**
	 *  The value of the blue channel of the color. Values should be between 0 and 1
	 */
	LUTColorValue blue;

	/**
	 * @brief      Creates a `LUTColor` with specified floating point RGB value
	 *
	 * @param[in]  r     The value of the red channel of the color. Values should be between 0 and 1
	 * @param[in]  g     The value of the green channel of the color. Values should be between 0 and 1
	 * @param[in]  b     The value of the blue channel of the color. Values should be between 0 and 1
	 */
	LUTColor(LUTColorValue r, LUTColorValue g, LUTColorValue b);


public:
	
	/**
	 * @brief      Gets the floating point color value for the red channel.
	 *
	 * @return     The value for the red channel.
	 */
	LUTColorValue getR() const { return red; }

	/**
	 * @brief      Gets the floating point color value for the green channel.
	 *
	 * @return     The value for the green channel.
	 */
	LUTColorValue getG() const { return green; }
	
	/**
	 * @brief      Gets the floating point color value for the blue channel.
	 *
	 * @return     The value for the blue channel.
	 */
	LUTColorValue getB() const { return blue; }

	// static std::vector<double> & rgbArray; Find a way to do this

	/**
	 * @brief      Creates a `LUTColor` with the given floating-point channel
	 *             values.
	 *
	 * @param      r     The value of the red channel of the color. Values
	 *                   should be between 0 and 1
	 * @param      g     The value of the green channel of the color. Values
	 *                   should be between 0 and 1
	 * @param      b     The value of the blue channel of the color. Values
	 *                   should be between 0 and 1
	 *
	 * @return     A `LUTColor`.
	 */
	static LUTColor colorWithRGB(LUTColorValue r, LUTColorValue g, LUTColorValue b);

	/**
	 * @brief      Creates a black `LUTColor` with 0 set for all the for the
	 *             floating-point channel values.
	 *
	 * @return     A black `LUTColor`.
	 */
	static LUTColor colorWithZeroes();

	/**
	 * @brief      Creates a while `LUTColor` with 1 set for all the for the
	 *             floating-point channel values.
	 *
	 * @return     A while `LUTColor`.
	 */
	static LUTColor colorWithOnes();

	/**
	 * @brief      Creates a color with the same given floating-point channel
	 *             value for every channel.
	 *
	 * @param      value  The value of the all channels of the color. Values
	 *                    should be between 0 and 1
	 *
	 * @return     A `LUTColor`.
	 */
	static LUTColor colorWithValue(double value);

	/**
	 * @brief      Creates a `LUTColor` with the provided integer channel values
	 *             and a bit depth of the color system. Values will be converted
	 *             to floating-point.
	 *
	 * @param      bitdepth  The bit depth of the color system represented by
	 *                       these integers.
	 * @param      r         The value of the red channel of the color in the
	 *                       color system.
	 * @param      g         The value of the green channel of the color in the
	 *                       color system.
	 * @param      b         The value of the blue channel of the color in the
	 *                       color system.
	 *
	 * @return     A `LUTColor`.
	 */
	static LUTColor colorFromIntegersWithBitdepth(int bitdepth, int r, int g, int b);

	/**
	 * @brief      Creates a `LUTColor` with the provided integer channel values
	 *             and maximum value of the color system. Values will be
	 *             converted to floating-point.
	 *
	 * @param      maxOutputValue  The maximum output value of the color system
	 * @param      r               The value of the red channel of the color in
	 *                             the color system.
	 * @param      g               The value of the green channel of the color
	 *                             in the color system.
	 * @param      b               The value of the blue channel of the color in
	 *                             the color system.
	 *
	 * @return     A `LUTColor`.
	 */
	static LUTColor colorFromIntegersWithMaxOutputValue(int maxOutputValue, int r, int g, int b);

	/**
	 * @brief      Determine the distance between this and another color point
	 *
	 * @param[in]  otherColor  The other color
	 *
	 * @return     A double distance
	 */
	double distanceToColor(const LUTColor & otherColor) const;

	/**
	 * @brief      Determine the luminance value of this color in the Rec709
	 *             color space
	 *
	 * @return     The luminance value of this color
	 */
	double luminanceRec709() const;
	
	/**
	 * @brief      Determine the luminance value of this color using custom luma
	 *             values for each channel
	 *
	 * @param[in]  lumaR  The luma value for the red channel
	 * @param[in]  lumaG  The luma value for the green channel
	 * @param[in]  lumaB  The luma value for the blue channel
	 *
	 * @return     The luminance value of this color
	 */
	double luminanceUsingLuma(double lumaR, double lumaG, double lumaB) const;

	/**
	 * @brief      Return the minimum channel value for the color
	 *
	 * @return     a double
	 */
	double minimumValue() const;

	/**
	 * @brief      Return the minimum channel value for the color
	 *
	 * @return     a double
	 */
	double maximumValue() const;
	
	/**
	 *  Clip the color channel values to the range 0 to 1.
	 */
	void clamp01();

	/**
	 * @brief      Clip the color channel values to the specified range.
	 *
	 * @param[in]  lowerBound  The lower boundary, values below this will be clipped
	 * @param[in]  upperBound  The upper boundary, values above this will be clipped
	 */
	void clampToBounds(double lowerBound, double upperBound);

	/**
	 * @brief      Clip the color channel values to the lower bound
	 *
	 * @param[in]  lowerBound  The lower boundary, values below this will be clipped
	 */
	void clampToLowerBound(double lowerBound);
	
	/**
	 * @brief      Clip the color channel values to the upper bound
	 *
	 * @param[in]  upperBound  The upper boundary, values above this will be clipped
	 */
	void clampToUpperBound(double upperBound);
	/**
	 * @brief      Remaps the color from an input contrast range to an output contrast range
	 *
	 * @param[in]  inputLow    The input range low point
	 * @param[in]  inputHigh   The input range high point
	 * @param[in]  outputLow   The output range low point
	 * @param[in]  outputHigh  The output range high point
	 * @param[in]  bounded     Wether to check the bounds
     */
	void remapContrast(double inputLow, double inputHigh, double outputLow, double outputHigh, bool bounded);

	/**
	 * @brief      Remaps a color from an input contrast range to an output
	 *             contrast range specified by two color points
	 *
	 * @param[in]  inputLowColor    The input range low color point
	 * @param[in]  inputHighColor   The input range high color point
	 * @param[in]  outputLowColor   The output range low color point
	 * @param[in]  outputHighColor  The output range high color point
	 * @param[in]  bounded          The bounded Whether calls with an error !!!
	 */
	void remapBetweenColors(const LUTColor & inputLowColor, const LUTColor & inputHighColor,
	                        const LUTColor & outputLowColor, const LUTColor & outputHighColor,
	                        bool bounded);

	/**
	 * @brief      Linearly interpolate between this and another color by a
	 *             percentage amount.
	 *
	 *             An `amount` of zero returns a color identical to this. An
	 *             `amount` of 1 returns a color identical to `otherColor`. An
	 *             `amount` of 0.5 represents a color halfway between this and
	 *             `otherColor`.
	 *
	 * @param      otherColor  The destination color of the interpolation.
	 * @param      amount      The percentage distance between the two colors,
	 */
	void lerpTo(const LUTColor & otherColor, double amount);
	
	/**
	 * @brief      Apply ASC CDL slope, offset and power
	 * @see        http://en.wikipedia.org/wiki/ASC_CDL
	 *
	 * @param[in]  redSlope     The red slope
	 * @param[in]  redOffset    The red offset
	 * @param[in]  redPower     The red power
	 * @param[in]  greenSlope   The green slope
	 * @param[in]  greenOffset  The green offset
	 * @param[in]  greenPower   The green power
	 * @param[in]  blueSlope    The blue slope
	 * @param[in]  blueOffset   The blue offset
	 * @param[in]  bluePower    The blue power
	 */
	void applySlopeOffsetPower(double redSlope, double redOffset, double redPower,
	                           double greenSlope, double greenOffset, double greenPower,
	                           double blueSlope, double blueOffset, double bluePower);

	/**
	 * @brief      Converts the color from one contrast range to another
	 *
	 * @param[in]  currentMin  The minimum value of current contrast range
	 * @param[in]  currentMax  The maximum value of current contrast range
	 * @param[in]  finalMin    The minimum value of final contrast range
	 * @param[in]  finalMax    The maximum value of final contrast range
	 */
	void contrastStretchWithRange(double currentMin, double currentMax, double finalMin, double finalMax);

	void invertColorWithRange(double minimumValue, double maximumValue);

	/**
	 * @brief      Changes the saturation of the color
	 *
	 * @param[in]  saturation  The new saturation value
	 * @param[in]  lumaR       The luma value for the red channel
	 * @param[in]  lumaG       The luma value for the green channel
	 * @param[in]  lumaB       The luma value for the blue channel
	 */
	void changeSaturation(double saturation, double lumaR, double lumaG, double lumaB);

	/**
	 * @brief      Multiplies the channels of the color by a number
	 *
	 * @param[in]  number  The number to multiply the `LUTColor` by
	 *
	 * @return     The color with multiplied channels
	 */
	LUTColor & operator*=(double number);

	/**
	 * @brief      Multiplies the channels of the color with the channels of
	 *             another color
	 *
	 * @param[in]  offsetColor  The color to multiply with
	 *
	 * @return     A color
	 */
	LUTColor & operator*=(const LUTColor & offsetColor);

	/**
	 * @brief      Adds the channels of another color to the color
	 *
	 * @param[in]  offsetColor  The color to add
	 *
	 * @return     A color
	 */
	LUTColor & operator+=(const LUTColor & offsetColor);

	/**
	 * @brief      Subtracts the channels of another color from the color
	 *
	 * @param[in]  offsetColor  The color to subtract
	 *
	 * @return     A color
	 */
	LUTColor & operator-=(const LUTColor & offsetColor);
};

inline LUTColor operator*(LUTColor l, double number)
{
	l *= number;
	return l;
}

inline LUTColor operator*(double number, LUTColor l)
{
	return l * number;
}

inline LUTColor operator*(LUTColor l, const LUTColor & r)
{
	l *= r;
	return l;
}

inline LUTColor operator+(LUTColor l, const LUTColor & r)
{
	l += r;
	return l;
}

inline LUTColor operator-(LUTColor l, const LUTColor & r)
{
	l -= r;
	return l;
} 

}
