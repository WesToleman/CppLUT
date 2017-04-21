#include "LUTColorSpace.h"
// #include "LUTColorTransferFunction.h"

LUTColorSpace::LUTColorSpace(LUTColorSpaceWhitePoint whitePoint,
                             double redChromaticityX, double redChromaticityY,
                             double greenChromaticityX, double greenChromaticityY,
                             double blueChromaticityX, double blueChromaticityY,
                             double forwardFootlambertCompensation, const std::string & name):
                             defaultWhitePoint(whitePoint),
                             redChromaticityX(redChromaticityX),
                             redChromaticityY(redChromaticityY),
                             greenChromaticityX(greenChromaticityX),
                             greenChromaticityY(greenChromaticityY),
                             blueChromaticityX(blueChromaticityX),
                             blueChromaticityY(blueChromaticityY),
                             forwardFootlambertCompensation(forwardFootlambertCompensation),
                             name(name)
{}

LUTColorSpace LUTColorSpace::withDefaultWhitePoint(const LUTColorSpaceWhitePoint & whitePoint,
                                                   double redChromaticityX, double redChromaticityY,
                                                   double greenChromaticityX, double greenChromaticityY,
                                                   double blueChromaticityX, double blueChromaticityY,
                                                   const std::string & name)
{
	return LUTColorSpace(whitePoint, redChromaticityX, redChromaticityY,
	                     greenChromaticityX, greenChromaticityY,
	                     blueChromaticityX, blueChromaticityY, 1.0, name);
}

LUTColorSpace LUTColorSpace::withDefaultWhitePoint(const LUTColorSpaceWhitePoint & whitePoint,
                                                   double redChromaticityX, double redChromaticityY,
                                                   double greenChromaticityX, double greenChromaticityY,
                                                   double blueChromaticityX, double blueChromaticityY,
                                                   double flCompensation, const std::string & name)
{
	return LUTColorSpace(whitePoint, redChromaticityX, redChromaticityY,
	                     greenChromaticityX, greenChromaticityY,
	                     blueChromaticityX, blueChromaticityY, flCompensation, name);
}

std::vector<LUTColorSpace> LUTColorSpace::knownColorSpaces()
{
	return {
		LUTColorSpace::rec709ColorSpace(),
		LUTColorSpace::dciP3ColorSpace(),
		LUTColorSpace::rec2020ColorSpace(),
		LUTColorSpace::alexaWideGamutColorSpace(),
		LUTColorSpace::sGamut3CineColorSpace(),
		LUTColorSpace::sGamutColorSpace(),
		LUTColorSpace::bmccColorSpace(),
		LUTColorSpace::redColorColorSpace(),
		LUTColorSpace::redColor2ColorSpace(),
		LUTColorSpace::redColor3ColorSpace(),
		LUTColorSpace::redColor4ColorSpace(),
		LUTColorSpace::dragonColorColorSpace(),
		LUTColorSpace::dragonColor2ColorSpace(),
		LUTColorSpace::canonCinemaGamutColorSpace(),
		LUTColorSpace::canonDCIP3PlusColorSpace(),
		LUTColorSpace::vGamutColorSpace(),
		LUTColorSpace::acesGamutColorSpace(),
		// LUTColorSpace::dciXYZColorSpace(),
		LUTColorSpace::xyzColorSpace(),
		LUTColorSpace::adobeRGBColorSpace(),
		LUTColorSpace::proPhotoRGBColorSpace()
	};
}

LUTColorSpace LUTColorSpace::rec709ColorSpace()
{
	return LUTColorSpace::withDefaultWhitePoint(LUTColorSpaceWhitePoint::d65WhitePoint(),
	                                            0.64, 0.33, 0.30, 0.60, 0.15, 0.06, "Rec. 709");
}

LUTColorSpace LUTColorSpace::canonDCIP3PlusColorSpace()
{
	return LUTColorSpace::withDefaultWhitePoint(LUTColorSpaceWhitePoint::dciWhitePoint(),
	                                            0.7400, 0.2700, 0.2200, 0.7800, 0.0900, -0.0900, "Canon DCI-P3+");
}

LUTColorSpace LUTColorSpace::canonCinemaGamutColorSpace()
{
	return LUTColorSpace::withDefaultWhitePoint(LUTColorSpaceWhitePoint::d65WhitePoint(),
	                                            0.7400, 0.2700, 0.1700, 1.1400, 0.0800, -0.1000, "Canon Cinema Gamut");
}

LUTColorSpace LUTColorSpace::bmccColorSpace()
{
	return LUTColorSpace::withDefaultWhitePoint(LUTColorSpaceWhitePoint::d65WhitePoint(),
	                                            0.901885370853, 0.249059467640, 0.280038809783,
	                                                         1.535129255560, 0.078873341398, -0.082629719848, "BMCC");
}

LUTColorSpace LUTColorSpace::redColorColorSpace()
{
	return LUTColorSpace::withDefaultWhitePoint(LUTColorSpaceWhitePoint::d65WhitePoint(),
	                                            0.682235759294, 0.320973856307, 0.295705729612,
	                                            0.613311106957, 0.134524597085, 0.034410956920, "REDcolor");
}

LUTColorSpace LUTColorSpace::redColor2ColorSpace()
{
	return LUTColorSpace::withDefaultWhitePoint(LUTColorSpaceWhitePoint::d65WhitePoint(),
	                                            0.858485322390, 0.316594954144, 0.292084791425,
	                                            0.667838655872, 0.097651412967, -0.026565653796, "REDcolor2");
}

LUTColorSpace LUTColorSpace::redColor3ColorSpace()
{
	return LUTColorSpace::withDefaultWhitePoint(LUTColorSpaceWhitePoint::d65WhitePoint(),
	                                            0.682450885401, 0.320302618634, 0.291813306036,
	                                            0.672642663443, 0.109533374066, -0.006916855752, "REDcolor3");
}

LUTColorSpace LUTColorSpace::redColor4ColorSpace()
{
	return LUTColorSpace::withDefaultWhitePoint(LUTColorSpaceWhitePoint::d65WhitePoint(),
	                                            0.682432347, 0.320314427, 0.291815909,
	                                            0.672638769, 0.144290202, 0.050547336, "REDcolor4");
}

LUTColorSpace LUTColorSpace::dragonColorColorSpace()
{
	return LUTColorSpace::withDefaultWhitePoint(LUTColorSpaceWhitePoint::d65WhitePoint(),
	                                            0.733696621349, 0.319213119879, 0.290807268864,
	                                            0.689667987865, 0.083009416684, -0.050780628080, "DRAGONcolor");
}

LUTColorSpace LUTColorSpace::dragonColor2ColorSpace()
{
	return LUTColorSpace::withDefaultWhitePoint(LUTColorSpaceWhitePoint::d65WhitePoint(),
	                                            0.733671536367, 0.319227712042, 0.290804815281,
	                                            0.689668775507, 0.143989704285, 0.050047743857, "DRAGONcolor2");
}

LUTColorSpace LUTColorSpace::proPhotoRGBColorSpace()
{
	return LUTColorSpace::withDefaultWhitePoint(LUTColorSpaceWhitePoint::d65WhitePoint(),
	                                            0.7347, 0.2653, 0.1596, 0.8404, 0.0366, 0.0001, "ProPhoto RGB");
}

LUTColorSpace LUTColorSpace::adobeRGBColorSpace()
{
	return LUTColorSpace::withDefaultWhitePoint(LUTColorSpaceWhitePoint::d65WhitePoint(),
	                                            0.64, 0.33, 0.21, 0.71, 0.15, 0.06, "Adobe RGB");
}

LUTColorSpace LUTColorSpace::dciP3ColorSpace()
{
	return LUTColorSpace::withDefaultWhitePoint(LUTColorSpaceWhitePoint::dciWhitePoint(),
	                                            0.680, 0.320, 0.265, 0.69, 0.15, 0.06, "DCI-P3");
}

LUTColorSpace LUTColorSpace::rec2020ColorSpace()
{
	return LUTColorSpace::withDefaultWhitePoint(LUTColorSpaceWhitePoint::d65WhitePoint(),
	                                            0.708, 0.292, 0.170, 0.797, 0.131, 0.046, "Rec. 2020");

}

LUTColorSpace LUTColorSpace::alexaWideGamutColorSpace()
{
	return LUTColorSpace::withDefaultWhitePoint(LUTColorSpaceWhitePoint::d65WhitePoint(),
	                                            0.6840, 0.3130, 0.2210, 0.8480, 0.0861, -0.1020, "Alexa Wide Gamut");
}

LUTColorSpace LUTColorSpace::sGamut3CineColorSpace()
{
	return LUTColorSpace::withDefaultWhitePoint(LUTColorSpaceWhitePoint::d65WhitePoint(),
	                                            0.76600, 0.27500, 0.22500, 0.80000, 0.08900, -0.08700, "S-Gamut3.Cine");
}

LUTColorSpace LUTColorSpace::sGamutColorSpace()
{
	return LUTColorSpace::withDefaultWhitePoint(LUTColorSpaceWhitePoint::d65WhitePoint(),
	                                            0.73000, 0.28000, 0.14000, 0.85500, 0.10000, -0.05000, "S-Gamut/S-Gamut3");
}

LUTColorSpace LUTColorSpace::vGamutColorSpace()
{
	return LUTColorSpace::withDefaultWhitePoint(LUTColorSpaceWhitePoint::d65WhitePoint(),
	                                            0.730, 0.280, 0.165, 0.840, 0.100, -0.030, "V-Gamut");
}

LUTColorSpace LUTColorSpace::acesGamutColorSpace()
{
	return LUTColorSpace::withDefaultWhitePoint(LUTColorSpaceWhitePoint::d60WhitePoint(),
	                                            0.73470, 0.26530, 0.00000, 1.00000, 0.00010, -0.07700, "ACES Gamut");
}
/*
LUTColorSpace LUTColorSpace::dciXYZColorSpace()
{
	return LUTColorSpace::withNPM(GLKMatrix3MakeWithRows(GLKVector3Make(1.0, 0.0, 0.0),
	                                                     GLKVector3Make(0.0, 1.0, 0.0),
	                                                     GLKVector3Make(0.0, 0.0, 1.0))
	                              0.916555, "DCI-XYZ");
}
*/
LUTColorSpace LUTColorSpace::xyzColorSpace()
{
	return LUTColorSpace::withDefaultWhitePoint(LUTColorSpaceWhitePoint::xyzWhitePoint(),
	                                            1, 0, 0, 1, 0, 0, 0.916555, "CIE-XYZ");
}
