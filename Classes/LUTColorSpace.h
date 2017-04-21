#pragma once

#include "CppLUT.h"
#include "LUTColorSpaceWhitePoint.h"

#include <string> // std::string
#include <vector> //std::vector

class LUTColorTransferFunction;

/**
 * @brief      A colorspace in the CIE xy Chromacity color model. CIE RGB Colorpace.
 */
class LUTColorSpace {
private:

	/** @brief      The default white point for the color space */
	LUTColorSpaceWhitePoint defaultWhitePoint;

	/** @brief      The X coordinate for the red channel chromacity */
	double redChromaticityX;

	/** @brief      The Y coordinate for the red channel chromacity */
	double redChromaticityY;

	/** @brief      The X coordinate for the green channel chromacity */
	double greenChromaticityX;

	/** @brief      The Y coordinate for the green channel chromacity */
	double greenChromaticityY;

	/** @brief      The X coordinate for the blue channel chromacity */
	double blueChromaticityX;

	/** @brief      The Y coordinate for the blue channel chromacity */
	double blueChromaticityY;

	bool forcesNPM;

	double forwardFootlambertCompensation;

	/** @brief      The name of the color space */
	std::string name;

	/**
	 * @brief      Private constructor for a ColorSpace
	 *
	 * @param[in]  whitePoint                      The white point of the color space
	 * @param[in]  redChromaticityX                The red chromaticity X point 
	 * @param[in]  redChromaticityY                The red chromaticity Y point 
	 * @param[in]  greenChromaticityX              The green chromaticity X point 
	 * @param[in]  greenChromaticityY              The green chromaticity Y point 
	 * @param[in]  blueChromaticityX               The blue chromaticity X point 
	 * @param[in]  blueChromaticityY               The blue chromaticity Y point 
	 * @param[in]  forwardFootlambertCompensation  The forward footlambert compensation
	 * @param[in]  name                            The name of the colorspace
	 */
	LUTColorSpace(LUTColorSpaceWhitePoint whitePoint,
	              double redChromaticityX, double redChromaticityY,
	              double greenChromaticityX, double greenChromaticityY,
	              double blueChromaticityX, double blueChromaticityY,
	              double forwardFootlambertCompensation, const std::string & name);

public:

	/**
	 * @brief      Create a colorspace with the default white point
	 *
	 * @param[in]  whitePoint          The white point of the color space
	 * @param[in]  redChromaticityX    The red chromaticity X point
	 * @param[in]  redChromaticityY    The red chromaticity Y point
	 * @param[in]  greenChromaticityX  The green chromaticity X point
	 * @param[in]  greenChromaticityY  The green chromaticity Y point
	 * @param[in]  blueChromaticityX   The blue chromaticity X point
	 * @param[in]  blueChromaticityY   The blue chromaticity Y point
	 * @param[in]  name                The name of the colorspace
	 *
	 * @return     A colorspace
	 */
 	static LUTColorSpace withDefaultWhitePoint(const LUTColorSpaceWhitePoint & whitePoint,
	                                           double redChromaticityX, double redChromaticityY,
	                                           double greenChromaticityX, double greenChromaticityY,
	                                           double blueChromaticityX, double blueChromaticityY,
	                                           const std::string & name);
	
	/**
	 * @brief      Create a colorspace with the default white point
	 *
	 * @param[in]  whitePoint          The white point of the color space
	 * @param[in]  redChromaticityX    The red chromaticity X point
	 * @param[in]  redChromaticityY    The red chromaticity Y point
	 * @param[in]  greenChromaticityX  The green chromaticity X point
	 * @param[in]  greenChromaticityY  The green chromaticity Y point
	 * @param[in]  blueChromaticityX   The blue chromaticity X point
	 * @param[in]  blueChromaticityY   The blue chromaticity Y point
	 * @param[in]  forwardFootlambertCompensation  The forward footlambert compensation
	 * @param[in]  name                The name of the colorspace
	 *
	 * @return     A colorspace
	 */
	static LUTColorSpace withDefaultWhitePoint(const LUTColorSpaceWhitePoint & whitePoint,
	                                           double redChromaticityX, double redChromaticityY,
	                                           double greenChromaticityX, double greenChromaticityY,
	                                           double blueChromaticityX, double blueChromaticityY,
	                                           double flCompensation, const std::string & name);
/*
	static LUT3D convertLUT3D(const LUT3D & lut,
	                          const LUTColorSpace & sourceColorSpace,
	                          const LUTColorSpaceWhitePoint & sourceWhitePoint,
	                          const LUTColorSpace & destinationColorSpace,
	                          const LUTColorSpaceWhitePoint & destinationWhitePoint,
	                          bool useBradfordMatrix);

	static LUT3D convertColorTemperature(const LUT3D & lut,
	                                     const LUTColorSpace & sourceColorSpace,
	                                     const LUTColorTransferFunction & sourceTransferFunction,
	                                     const LUTColorSpaceWhitePoint & sourceColorTemperature,
	                                     const LUTColorSpaceWhitePoint & destinationColorTemperature);
*/
	/**
	 * @brief      Returns the vector of all known color spaces in the library
	 *
	 * @return     A vector of color spaces
	 */
	static std::vector<LUTColorSpace> knownColorSpaces();

	static LUTColorSpace rec709ColorSpace();
	static LUTColorSpace dciP3ColorSpace();
	static LUTColorSpace rec2020ColorSpace();
	static LUTColorSpace alexaWideGamutColorSpace();
	static LUTColorSpace sGamut3CineColorSpace();
	static LUTColorSpace sGamutColorSpace();
	static LUTColorSpace bmccColorSpace();
	static LUTColorSpace redColorColorSpace();
	static LUTColorSpace redColor2ColorSpace();
	static LUTColorSpace redColor3ColorSpace();
	static LUTColorSpace redColor4ColorSpace();
	static LUTColorSpace dragonColorColorSpace();
	static LUTColorSpace dragonColor2ColorSpace();
	static LUTColorSpace canonCinemaGamutColorSpace();
	static LUTColorSpace canonDCIP3PlusColorSpace();
	static LUTColorSpace vGamutColorSpace();
	static LUTColorSpace acesGamutColorSpace();
	// static LUTColorSpace dciXYZColorSpace();
	static LUTColorSpace xyzColorSpace();
	static LUTColorSpace adobeRGBColorSpace();
	static LUTColorSpace proPhotoRGBColorSpace();


}; // end class declaration LUTColorSpace