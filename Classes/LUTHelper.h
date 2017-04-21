#pragma once

#include "CppLUT.h"
#include <vector> // std::vector
#include <cmath> // std::sqrt std::pow 

class LUT;
class LUT1D;
class LUT3D;

// typedef NS_ENUM(NSInteger, LUT1DExtractionMethod); uh, yeah, wft?
typedef int LUT1DExtractionMethod;

/**
 * @brief      A namespace containing useful LUT functions
 */
namespace LUTHelper
{
	/**
	 * @brief      Remaps a value to a new contrast range
	 *
	 * @param[in]  value       The value
	 * @param[in]  currentMin  The minimum value of the current contrast range
	 * @param[in]  currentMax  The maximum value of the current contrast range
	 * @param[in]  finalMin    The minimum value of the final contrast range
	 * @param[in]  finalMax    The maximum value of the final contrast range
	 *
	 * @return     a double value in the new contrast range
	 */
	inline double contrastStretch(double value,
	                              double currentMin, double currentMax,
	                              double finalMin, double finalMax)
	{
		return (value - currentMin)*((finalMax-finalMin)/(currentMax-currentMin)) + finalMin;
	}

	/**
	 * @brief      Clamps a value to a given range
	 *
	 * @param[in]  value  The value to clamp
	 * @param[in]  min    The minimum possible value
	 * @param[in]  max    The maximum possible value
	 *
	 * @return     A double value in the given range
	 */
	inline double clamp(double value, double min, double max)
	{
		return (value > max) ? max : ((value < min) ? min : value);
	}

	/**
	 * @brief      Clamps a value to the range 0-1
	 *
	 * @param[in]  value  The value to be clamped
	 *
	 * @return     A double in the range 0-1 inclusive
	 */
	inline double clamp01(double value) { return clamp(value, 0, 1); }

	/**
	 * @brief      Clamps a value to the specified lower bound
	 *
	 * @param[in]  value       The value to clamp
	 * @param[in]  lowerBound  The lower bound to clamp to
	 *
	 * @return     { A clamped double value }
	 */
	inline double clampLowerBound(double value, double lowerBound)
	{
		return (value < lowerBound) ? lowerBound : value;
	}

	/**
	 * @brief      Clamps a value to the specified upper bound
	 *
	 * @param[in]  value       The value to clamp
	 * @param[in]  upperBound  The upper bound to clamp to
	 *
	 * @return     { A clamped double value }
	 */
	inline double clampUpperBound(double value, double upperBound)
	{
		return (value < upperBound) ? upperBound : value;
	}

	/**
	 * @brief      Converts an interger representation to a floating point value
	 *
	 * @param[in]  value     The value to be converted to floating point
	 * @param[in]  maxValue  The maximum value in the integer color space
	 *
	 * @return     A floating point value in the range 0 to 1 inclusive
	 */
	inline double remapInt01(int value, int maxValue) { return (double)value / maxValue; }

	/**
	 * @brief      Remap a value from a given input range to a given output
	 *             range
	 *
	 * @throws     std::domain_error  If the value does not fall in the input range
	 * @throws     std::domain_error  If inputLow is greater than inputHigh
	 * @throws     std::domain_error  If outputLow is greater than outputHigh
	 *
	 * @param[in]  value       The value to remap
	 * @param[in]  inputLow    The input range lower bound
	 * @param[in]  inputHigh   The input range higher bound
	 * @param[in]  outputLow   The output range lower bound
	 * @param[in]  outputHigh  The output range higher bound
	 *
	 * @return     A remapped value in the new output range
	 */
	double remap(double value, double inputLow, double inputHigh,
		                double outputLow, double outputHigh);

	/**
	 * @brief      Remap a value from a given input range to a given output
	 *             range
	 *
	 * @param[in]  value       The value to remap
	 * @param[in]  inputLow    The input range lower bound
	 * @param[in]  inputHigh   The input range higher bound
	 * @param[in]  outputLow   The output range lower bound
	 * @param[in]  outputHigh  The output range higher bound
	 *
	 * @return     A remapped value in the new output range
	 */
	inline double remapNoError(double value, double inputLow, double inputHigh,
		                       double outputLow, double outputHigh)
	{
		return outputLow + ((value - inputLow) * (outputHigh - outputLow)) / (inputHigh - inputLow);
	}

	/**
	 * @brief      Determine whether a value falls in a given range
	 *
	 * @param[in]  value      The value to test
	 * @param[in]  min        The minimum test value
	 * @param[in]  max        The maximum test value
	 * @param[in]  inclusive  Whether to include min and max in the range
	 *
	 * @return     True if the value falls out of the range
	 */
	inline bool outOfBounds(double value, double min, double max, bool inclusive)
	{
		return (inclusive ? (value < min || value > max) : (value <= min || value >= max));
	}
	/**
	 * @brief      Applies a liner interpolation
	 *
	 * @throws     std::domain_error  If the interpolated value is not in the range 0-1
	 *
	 * @param[in]  beginning  The beginning point of the range (0)
	 * @param[in]  end        The end point of the range (1)
	 * @param[in]  value01    The value to interpolate in the range 0-1
	 *
	 * @return     An interpolated floating point value
	 */
	double lerp1d(double beginning, double end, double value01);

	/**
	 * @brief      Applies smootherstep interpolation for a point at a specified
	 *             percentage of a range
	 * 
	 * @throws      std::domain_error { exception_description }
	 *
	 * @param[in]  beginning   The beginning of the range
	 * @param[in]  end         The end of the range
	 * @param[in]  percentage  The percentage position of the point in the range
	 *
	 * @return     An intepolated floating point value
	 */
	double smootherstep(double beginning, double end, double percentage);

	/**
	 * @brief      Applies smoothstep interpolation for a point at a specified
	 *             percentage of a range
	 *
	 * @throws      std::domain_error { exception_description }
	 *
	 * @param[in]  beginning   The beginning of the range
	 * @param[in]  end         The end of the range
	 * @param[in]  percentage  The percentage position of the point in the range
	 *
	 * @return     An intepolated floating point value
	 */
	double smoothstep(double beginning, double end, double percentage);

	/**
	 * @brief      Determines the distance between two XYZ points
	 *
	 * @param[in]  x1    The x co-ordinate for point 1
	 * @param[in]  y1    The y co-ordinate for point 1
	 * @param[in]  z1    The z co-ordinate for point 1
	 * @param[in]  x2    The x co-ordinate for point 2
	 * @param[in]  y2    The y co-ordinate for point 2
	 * @param[in]  z2    The z co-ordinate for point 2
	 *
	 * @return     { The length of the vector between the two points }
	 */
	inline float distancecalc(float x1, float y1, float z1, float x2, float y2, float z2)
	{
		float dx = x2 - x1;
		float dy = y2 - y1;
		float dz = z2 - z1;
		return std::sqrt((float)(dx * dx + dy * dy + dz * dz));
	}

	/**
	 * @brief      Generate a number of indices in a range
	 *
	 * @param[in]  startValue  The start value
	 * @param[in]  endValue    The end value
	 * @param[in]  numIndices  The number indices to generate
	 *
	 * @return     A vector of doubles
	 */
	std::vector<double> indicesDoubleVector(double startValue, double endValue, int numIndices);
	
	std::vector<int> indicesIntegerVector(int startValue, int endValue, int numIndices);

	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  value         The value
	 * @param[in]  nearestValue  The nearest value
	 *
	 * @return     { description_of_the_return_value }
	 */
	inline double roundValueToNearest(double value, double nearestValue)
	{
		int multiplier = std::floor(value / nearestValue);
		return multiplier* nearestValue;
	}

	/**
	 * @brief      Determine the maximum integer value for the given bit depth
	 *
	 * @param[in]  bitdepth  The bitdepth
	 *
	 * @return     The maximum value in the bit depth
	 */
	inline int maxIntegerFromBitdepth(int bitdepth) { return std::pow(2, bitdepth) - 1; }

	/**
	 * Runs the passed function cubeSize ^ 3 times, iterating over each point on a
	 * cube of edge length `cubeSize`.
	 *
	 * @param[in]  cubeSize  The cube size
	 * @param[in]  funcp     A pointer to the function to be run 
	 */
	//	inline void LUT3DConcurrentLoop(int cubeSize, void (*funcp)(int r, int g, int b));


	/**
	 * Runs the passed function size times, iterating over each index
	 *
	 * @param[in]  size   The number of points to iterate over
	 * @param[in]  funcp  A pointer to the function to be run
	 */
	//	inline void LUT1DLoop(int size, void (*funcp)(int index));

	// inline void LUTConcurrentRectLoop(int width, int height, void (*funcp)(int x, int y));

	// NSArray* arrayWithEmptyElementsRemoved(NSArray *array);
	// NSArray* arrayWithComponentsSeperatedByWhitespaceWithEmptyElementsRemoved(NSString *string);
	// NSArray* arrayWithComponentsSeperatedByNewlineWithEmptyElementsRemoved(NSString *string);
	// NSArray* arrayWithComponentsSeperatedByNewlineAndWhitespaceWithEmptyElementsRemoved(NSString *string);
	// NSString* substringBetweenTwoStrings(NSString *originString, NSString *firstString, NSString *secondString);

	// NSInteger findFirstLUTLineInLines(NSArray *lines, NSString *seperator, int numValues, int startLine);
	// NSInteger findFirstLUTLineInLinesWithWhitespaceSeparators(NSArray *lines, int numValues, int startLine);

	// NSNumberFormatter* sharedNumberFormatter();
	// NSCharacterSet* sharedInvertedNumericCharacterSet();
	// bool stringIsValidNumber(NSString *string);
};

	// CGSize CGSizeProportionallyScaled(CGSize currentSize, CGSize targetSize);

	// M13OrderedDictionary* M13OrderedDictionaryFromOrderedArrayWithDictionaries(NSArray *array);
	// NSDictionary *NSDictionaryFromM13OrderedDictionary(M13OrderedDictionary *stupidDict);