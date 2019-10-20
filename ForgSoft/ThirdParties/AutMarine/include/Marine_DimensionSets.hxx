#pragma once
#ifndef _Marine_DimensionSets_Header
#define _Marine_DimensionSets_Header

#include <Marine_DimensionSet.hxx>

namespace AutLib
{

	namespace marineLib
	{

		extern const Marine_DimensionSet dimless;

		extern const Marine_DimensionSet dimMass;
		extern const Marine_DimensionSet dimLength;
		extern const Marine_DimensionSet dimTime;
		extern const Marine_DimensionSet dimTemperature;

		extern const Marine_DimensionSet dimArea;
		extern const Marine_DimensionSet dimVolume;
		extern const Marine_DimensionSet dimVol;

		extern const Marine_DimensionSet dimDensity;
		extern const Marine_DimensionSet dimForce;
		extern const Marine_DimensionSet dimEnergy;

		extern const Marine_DimensionSet dimVelocity;
		extern const Marine_DimensionSet dimAcceleration;
		extern const Marine_DimensionSet dimPressure;
		extern const Marine_DimensionSet dimGasConstant;
		extern const Marine_DimensionSet dimSpecificHeatCapacity;
		extern const Marine_DimensionSet dimThermalConductivity;
	}
}

#endif // !_Marine_DimensionSets_Header
