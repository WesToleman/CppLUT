#include "LUTHelper.h"
#include <cmath> // std::round
#include <typeinfo> // typeid
#include <exception> // std::domain_error
#include <cstdio> // std::sprintf

double LUTHelper::remap(double value, double inputLow, double inputHigh, double outputLow, double outputHigh)
{
	if(value < inputLow || value > inputHigh)
	{
		char msg[256];
		std::sprintf(msg, "Remap value out of bounds: Tried to remap out-of-bounds value (%f) with input constraints low:%f high:%f", value, inputLow, inputHigh);
		throw std::domain_error(msg);
	}
	if(inputLow > inputHigh)
	{
		char msg[256];
		std::sprintf(msg, "RemapInputsError: Inputs low:%f high:%f. low must be less than or equal to high", inputLow, inputHigh);
		throw std::domain_error(msg);
	}
	if(outputLow > outputHigh)
	{
		char msg[256];
		std::sprintf(msg, "RemapOutputsError: Outputs low:%f high:%f. low must be less than or equal to high", outputLow, outputHigh);
		throw std::domain_error(msg);
	}
	return remapNoError(value, inputLow, inputHigh, outputLow, outputHigh);
}

double LUTHelper::lerp1d(double beginning, double end, double value01)
{
	if (value01 < 0 || value01 > 1)
	{
		throw std::domain_error("Invalid Lerp: Value out of bounds");
	}
	double range = end - beginning;
	return (beginning + range * value01);
}

double LUTHelper::smootherstep(double beginning, double end, double percentage)
{
	if(percentage < 0 || percentage > 1)
	{
		throw std::domain_error("Invalid Smoothstep: Percentage out of bounds [0-1]");
	}
	percentage = remap(percentage, 0, 1, beginning, end);
	return percentage*percentage*percentage*(percentage*(percentage*6.0 - 15.0) + 10.0);
}

double LUTHelper::smoothstep(double beginning, double end, double percentage)
{
	if(percentage < 0 || percentage > 1)
	{
		throw std::domain_error("Invalid Smoothstep: Percentage out of bounds [0-1]");
	}
	percentage = remap(percentage, 0, 1, beginning, end);
	// Evaluate polynomial
	return percentage*percentage*(3 - 2*percentage);
}

std::vector<double> LUTHelper::indicesDoubleVector(double startValue, double endValue, int numIndices)
{
	std::vector<double> indices;
	double ratio = remap(1, 0, numIndices -1, startValue, endValue);
	for (int i = 0; i < numIndices; i++)
	{
		indices.push_back(clampUpperBound(i * ratio, endValue));
	}

	return indices;
}

std::vector<int> LUTHelper::indicesIntegerVector(int startValue, int endValue, int numIndices)
{
	std::vector<int> indices;
	double ratio = remap(1, 0, numIndices -1, startValue, endValue);
	for (int i = 0; i < numIndices; i++)
	{
		indices.push_back(std::round(i * ratio));
	}
	return indices;
}