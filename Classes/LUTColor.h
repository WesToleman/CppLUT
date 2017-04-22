#pragma once

#include "CppLUT.h"

#include <vector>

#define LEGAL_LEVELS_MIN 0.06256109481 //64.0/1023.0
#define LEGAL_LEVELS_MAX 0.91886608015 //940.0/1023.0
#define EXTENDED_LEVELS_MIN 0.0 //0.00391006842 //4.0/1023.0
#define EXTENDED_LEVELS_MAX 1.0 //0.99608993157 //1019.0/1023.0

/**
 *  Used to represent the value of a channel for a `LUTColor`.
 */
typedef double LUTColorValue;

/**
 * Represents a color value on a 3D LUT lattice.
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
	// static std::vector<double> & rgbArray; Find a way to do this

	/**
	 *  Returns a new color with the given floating-point channel values.
	 *
	 *  @param r The value of the red channel of the color. Values should be between 0 and 1
	 *  @param g The value of the green channel of the color. Values should be between 0 and 1
	 *  @param b The value of the blue channel of the color. Values should be between 0 and 1
	 *
	 *  @return A new color.
	 */
	static LUTColor colorWithRGB(LUTColorValue r, LUTColorValue g, LUTColorValue b);

	static LUTColor colorWithZeroes();

	static LUTColor colorWithOnes();

	static LUTColor colorWithValue(double value);

	/**
	 * Returns a new color with the provided integer channel values and a bit
	 * depth of the color system. Values will be converted to floating-point.
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
	 * @return     A LUTColor.
	 */
	static LUTColor colorFromIntegersWithBitdepth(int bitdepth, int r, int g, int b);

	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  maxOutputValue  The maximum output value
	 * @param[in]  r               { parameter_description }
	 * @param[in]  g               { parameter_description }
	 * @param[in]  b               { parameter_description }
	 *
	 * @return     A LUTColor
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

	double luminanceRec709()const ;

	double luminanceUsingLuma(double lumaR, double lumaG, double lumaB) const;

	void constrastStretchWithMinMax(double currentMin, double currentMax, double finalMin, double finalMax);

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
	 * @brief      Remaps the color from an input contrast range to an output contrast range range
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
	 * Linearly interpolate between this and another color by a percentage amount.
	 *
	 * An `amount` of zero returns a color identical to this. An
	 * `amount` of 1 returns a color identical to `otherColor`. An `amount` of
	 * 0.5 represents a color halfway between this and `otherColor`.
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

	void contrastStretchWithMinMax(double currentMin, double currentMax, double finalMin, double finalMax);

	void multiplyByNumber(double number);

	void multiplyByColor(const LUTColor & offsetColor);

	void addColor(const LUTColor & offsetColor);

	void subtractColor(const LUTColor & offsetColor);

	void invertColorWithMinMax(double minimumValue, double maximumValue);

	void changeSaturation(double saturation, double lumaR, double lumaG, double lumaB);
};