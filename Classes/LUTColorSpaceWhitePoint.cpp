#include "LUTColorSpaceWhitePoint.h"

#include <cmath> // std::pow

LUTColorSpaceWhitePoint::LUTColorSpaceWhitePoint(double whiteChromaticityX,
                                                 double whiteChromaticityY,
                                                 const std::string & name):
                                                 whiteChromaticityX(whiteChromaticityX),
                                                 whiteChromaticityY(whiteChromaticityY),
                                                 name(name)
{} 

std::vector<LUTColorSpaceWhitePoint> LUTColorSpaceWhitePoint::knownWhitePoints()
{
	return {
		d65WhitePoint(),
		d60WhitePoint(),
		d55WhitePoint(),
		d50WhitePoint(),
		dciWhitePoint(),
		xyzWhitePoint()
	};
}

std::vector<LUTColorSpaceWhitePoint> LUTColorSpaceWhitePoint::knownColorTemperatureWhitePoints()
{
	return {
		fromColorTemperature(2900, "Incandescent (2900K)"),
		fromColorTemperature(3200, "Tungsten (3200K)"),
		fromColorTemperature(4400, "Mixed (4400K)"),
		fromColorTemperature(5600, "Daylight (5600K)")
	};
}

//http://en.wikipedia.org/wiki/Planckian_locus#Approximation
LUTColorSpaceWhitePoint LUTColorSpaceWhitePoint::fromColorTemperature(double colorTemperature)
{
	std::string name = std::to_string((int) colorTemperature) + "K";
	return fromColorTemperature(colorTemperature, name);
}

LUTColorSpaceWhitePoint LUTColorSpaceWhitePoint::fromColorTemperature(double colorTemperature, const std::string & name)
{
	if (colorTemperature < 1667 || colorTemperature > 25000)
	{
		throw std::domain_error("Invalid Color Temperature Error: Color temperature must be in the range 1667k to 25000k");
	}

	//calculate x
	double xC;
	if (colorTemperature >= 1667 && colorTemperature <= 4000)
	{
		xC = -0.2661239*(std::pow(10, 9)/std::pow(colorTemperature, 3)) - 0.2343580*(std::pow(10, 6)/std::pow(colorTemperature, 2)) + 0.8776956*(std::pow(10, 3)/colorTemperature) + 0.179910;
	}
	else
	{
		//temp > 4000 and <= 25000
		xC = -3.0258469*(std::pow(10, 9)/std::pow(colorTemperature, 3)) + 2.1070379*(std::pow(10, 6)/std::pow(colorTemperature, 2)) + 0.2226347*(std::pow(10, 3)/colorTemperature) + 0.240390;
	}

	//calculate y
	double yC;

	if (colorTemperature >= 1667 && colorTemperature <= 2222)
	{
		yC = -1.1063814*std::pow(xC, 3) - 1.34811020*std::pow(xC, 2) + 2.18555832*xC - 0.20219683;
	}
	else if (colorTemperature > 2222 && colorTemperature <= 4000)
	{
		yC = -0.9549476*std::pow(xC, 3) - 1.37418593*std::pow(xC, 2) + 2.09137015*xC - 0.16748867;
	}
	else
	{
		//temp > 4000 and <= 25000
		yC = 3.0817580*std::pow(xC, 3) - 5.87338670*std::pow(xC, 2) + 3.75112997*xC - 0.37001483;
	}

	return LUTColorSpaceWhitePoint(xC, yC, name);
}

LUTColorSpaceWhitePoint LUTColorSpaceWhitePoint::d65WhitePoint()
{
	return LUTColorSpaceWhitePoint(0.31271 , 0.32902 , "D65");
}

LUTColorSpaceWhitePoint LUTColorSpaceWhitePoint::d60WhitePoint()
{
	return LUTColorSpaceWhitePoint(0.32168 , 0.33767 , "D60");
}

LUTColorSpaceWhitePoint LUTColorSpaceWhitePoint::d55WhitePoint()
{
	return LUTColorSpaceWhitePoint(0.33242 , 0.34743 , "D55");
}

LUTColorSpaceWhitePoint LUTColorSpaceWhitePoint::d50WhitePoint()
{
	return LUTColorSpaceWhitePoint(0.34567 , 0.35850 , "D50");
}

LUTColorSpaceWhitePoint LUTColorSpaceWhitePoint::dciWhitePoint()
{
	return LUTColorSpaceWhitePoint(.314 , .351 , "DCI White");
}

LUTColorSpaceWhitePoint LUTColorSpaceWhitePoint::xyzWhitePoint()
{
	return LUTColorSpaceWhitePoint(1.0/3.0 , 1.0/3.0 , "XYZ White");
}
