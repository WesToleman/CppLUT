
#include <vector> // std::vector
#include <string> //std::string

/**
 * @brief      Class for the white point of a `LUTColorSpace`
 */
class LUTColorSpaceWhitePoint
{
public:

	/**
	 * @brief      Create a LUTColorSpaceWhitePoint with X & Y chromacity points
	 *
	 * @param[in]  whiteChromaticityX  The white chromaticity X coordinate
	 * @param[in]  whiteChromaticityY  The white chromaticity Y coordinate
	 * @param[in]  name                The name of the whitepoint
	 *
	 * @return     A `LUTColorSpaceWhitePoint`
	 */
	static LUTColorSpaceWhitePoint withWhiteChromaticity(double whiteChromaticityX,
	                                                     double whiteChromaticityY,
	                                                     const std::string & name);

	/**
	 * @brief      Get a vector of all known color space white points
	 *
	 * @return     A  `vector` of `LUTColorSpaceWhitePoint`s 
	 */
	static std::vector<LUTColorSpaceWhitePoint> knownWhitePoints();

	/**
	 * @brief      Get a vector of all known color temperature white points
	 *
	 * @return     A  `vector` of `LUTColorSpaceWhitePoint`s
	 * @todo Fix case for values <1667 and >25000
	 */
	static std::vector<LUTColorSpaceWhitePoint> knownColorTemperatureWhitePoints();

	/**
	 * @brief      Creates a `LUTColorSpaceWhitePoint` using a color temperature
	 * @discussion An approximation of Planckian Locus
	 * @see        http://en.wikipedia.org/wiki/Planckian_locus#Approximation
	 *
	 * @param[in]  colorTemperature  The color temperature in kelvin
	 *
	 * @return     A `LUTColorSpaceWhitePoint`
	 */
	 static LUTColorSpaceWhitePoint fromColorTemperature(double colorTemperature);

	/**
	 * @brief      Creates a `LUTColorSpaceWhitePoint` using a color temperature
	 *             with a custom name
	 *
	 * @param[in]  colorTemperature  The color temperature in kelvin
	 * @param[in]  name              A custom name for the white point
	 *
	 * @return     A `LUTColorSpaceWhitePoint` with a custom name
	 */
	static LUTColorSpaceWhitePoint fromColorTemperature(double colorTemperature, const std::string & name);

	static LUTColorSpaceWhitePoint d65WhitePoint();

	static LUTColorSpaceWhitePoint d60WhitePoint();

	static LUTColorSpaceWhitePoint d55WhitePoint();

	static LUTColorSpaceWhitePoint d50WhitePoint();

	static LUTColorSpaceWhitePoint dciWhitePoint();

	static LUTColorSpaceWhitePoint xyzWhitePoint();
	

private:
	/**
	 * The white chromaticity X coordinate
	 */
	double whiteChromaticityX;
	/**
	 * The white chromaticity Y coordinate
	 */
	double whiteChromaticityY;
	/**
	 * The name of the whitepoint
	 */
	std::string name;

	/**
	 * @brief      Private constructor
	 *
	 * @param[in]  whiteChromaticityX  The white chromaticity X coordinate
	 * @param[in]  whiteChromaticityY  The white chromaticity Y coordinate
	 * @param[in]  name                The name of the whitepoint
	 */
	LUTColorSpaceWhitePoint(double whiteChromaticityX,
	                        double whiteChromaticityY,
	                        const std::string & name);

};