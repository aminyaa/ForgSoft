#pragma once
#ifndef _UnitSystem_Header
#define _UnitSystem_Header

#include <Standard_TypeDef.hxx>
#include <scalar.hxx>

/* A macro to define a function which convert a unit*/
#define CONVERT_UNIT(Unit)																			\
	inline scalar ConvertUnit(const UnitSystem_##Unit From, const UnitSystem_##Unit To)				\
	{																								\
		return ConvertorTables::##Unit[From][To];													\
	}

#define UNIT_EXPONENTS(UnitName, Exp0, Exp1, Exp2, Exp3, Exp4, Exp5, Exp6, Ang)			\
	struct UnitName##UnitExps															\
	{																					\
		static constexpr int MASS = Exp0;												\
		static constexpr int LENGTH = Exp1;												\
		static constexpr int TIME = Exp2;												\
		static constexpr int TEMPERATURE = Exp3;										\
		static constexpr int MOLES = Exp4;												\
		static constexpr int CURRENT = Exp5;											\
		static constexpr int LUMINOUS_INTENSITY = Exp6;									\
		static constexpr bool ANGLE = Ang;												\
	};

namespace AutLib
{

	enum UnitSystem
	{

		UnitSystem_SI = 0,
		UnitSystem_Imperial
	};

	enum UnitSystem_Length
	{
		UnitSystem_Length_m = 0,
		UnitSystem_Length_cm,
		UnitSystem_Length_ft,
		UnitSystem_Length_in,
		UnitSystem_Length_km,
		UnitSystem_Length_mi,
		UnitSystem_Length_mm,
		UnitSystem_Length_um,
		UnitSystem_Length_yd
	};

	string toString(const UnitSystem_Length);

	enum UnitSystem_Mass
	{
		UnitSystem_Mass_kg = 0,
		UnitSystem_Mass_tonne,
		UnitSystem_Mass_g,
		UnitSystem_Mass_mg,
		UnitSystem_Mass_usTonne,
		UnitSystem_Mass_ImperialTonne,
		UnitSystem_Mass_lb,
		UnitSystem_Mass_oz
	};

	string toString(const UnitSystem_Mass);

	enum UnitSystem_Pressure
	{
		UnitSystem_Pressure_atm = 0,
		UnitSystem_Pressure_bar,
		UnitSystem_Pressure_Pa,
		UnitSystem_Pressure_MPa,
		UnitSystem_Pressure_GPa,
		UnitSystem_Pressure_psi
	};

	string toString(const UnitSystem_Pressure);

	enum UnitSystem_Velocity
	{
		UnitSystem_Velocity_mPerSec = 0,
		UnitSystem_Velocity_kmPerHour,
		UnitSystem_Velocity_ftPerSec,
		UnitSystem_Velocity_mph,
		UnitSystem_Velocity_kt,  // Knot (UK)
		UnitSystem_Velocity_kn   // Knots
	};

	string toString(const UnitSystem_Velocity);

	enum UnitSystem_Acceleration
	{
		UnitSystem_Acceleration_mPerSecPerSec = 0,
		UnitSystem_Acceleration_ftPerSecPerSec
	};

	string toString(const UnitSystem_Acceleration);

	enum UnitSystem_Density
	{
		UnitSystem_Density_kgPerMeterQubic = 0,
		UnitSystem_Density_lbPerFtQubic,
		UnitSystem_Density_lbPerInchQubic,
		UnitSystem_Density_SlugPerFtQubic
	};

	string toString(const UnitSystem_Density);

	enum UnitSystem_Power
	{
		UnitSystem_Power_W = 0,
		UnitSystem_Power_kW,
		UnitSystem_Power_MW,
		UnitSystem_Power_ftlbPerSec,
		UnitSystem_Power_ftlbPerMin,
		UnitSystem_Power_hp
	};

	string toString(const UnitSystem_Power);

	enum UnitSystem_Temperature
	{
		UnitSystem_Temperature_C = 0,
		UnitSystem_Temperature_F,
		UnitSystem_Temperature_K,
		UnitSystem_Temperature_R
	};

	string toString(const UnitSystem_Temperature);

	enum UnitSystem_Force
	{
		UnitSystem_Force_N = 0,
		UnitSystem_Force_kN,
		UnitSystem_Force_dyn,
		UnitSystem_Force_gf,
		UnitSystem_Force_kgf,
		UnitSystem_Force_tf,
		UnitSystem_Force_lbf,
		UnitSystem_Force_lbftPerSecPerSec
	};

	string toString(const UnitSystem_Force);

	enum UnitSystem_Angle
	{
		UnitSystem_Angle_deg = 0,
		UnitSystem_Angle_rad,
		UnitSystem_Angle_grad
	};

	string toString(const UnitSystem_Angle);

	enum UnitSystem_DynViscosity
	{
		UnitSystem_DynViscosity_PaSec = 0,
		UnitSystem_DynViscosity_NSecPerSquareMeter,
		UnitSystem_DynViscosity_gPerCmPerSec,
		UnitSystem_DynViscosity_slugPerFtPerSec,
		UnitSystem_DynViscosity_lbPerFtPerSec
	};	

	string toString(const UnitSystem_DynViscosity);

	enum UnitSystem_KinViscosity
	{
		UnitSystem_KinViscosity_squareMeterPerSec = 0,
		UnitSystem_KinViscosity_squareFtPerSec
	};

	string toString(const UnitSystem_KinViscosity);

	enum UnitSystem_DimenLess
	{
		UnitSystem_DimenLess_None = 0
	};
	
	template<int Mass, int Length, int Time, int Temp, int Moles, int Current, int Lum_int, bool Angle = false>
	struct UnitType{};

	template<> struct UnitType<0, 1, 0, 0, 0, 0, 0> { typedef UnitSystem_Length type; };
	template<> struct UnitType<1, 0, 0, 0, 0, 0, 0> { typedef UnitSystem_Mass type; };
	template<> struct UnitType<1, -3, 0, 0, 0, 0, 0> { typedef UnitSystem_Density type; };
	template<> struct UnitType<1, 1, -2, 0, 0, 0, 0> { typedef UnitSystem_Force type; };

	template<> struct UnitType<0, 1, -1, 0, 0, 0, 0> { typedef UnitSystem_Velocity type; };
	template<> struct UnitType<0, 1, -2, 0, 0, 0, 0> { typedef UnitSystem_Acceleration type; };
	template<> struct UnitType<1, -1, -2, 0, 0, 0, 0> { typedef UnitSystem_Pressure type; };

	template<> struct UnitType<1, -1, -1, 0, 0, 0, 0> { typedef UnitSystem_DynViscosity type; };
	template<> struct UnitType<0, 2, -1, 0, 0, 0, 0> { typedef UnitSystem_KinViscosity type; };

	//template<> struct UnitType<0, 0, 0, 0, 0, 0, 0> { typedef UnitSystem_DimenLess type; };
	template<> struct UnitType<0, 0, 0, 0, 0, 0, 0, true> { typedef UnitSystem_Angle type; };



	struct ConvertorTables
	{
		static const scalar Length[9][9];
		static const scalar Mass[8][8];
		static const scalar Pressure[6][6];
		static const scalar Velocity[6][6];
		static const scalar Acceleration[2][2];
		static const scalar Density[4][4];
		static const scalar Power[5][5];
		//static const scalar Temperature[4][4];
		static const scalar Force[8][8];
		static const scalar Angle[3][3];
		static const scalar DynViscosity[5][5];
		static const scalar KinViscosity[2][2];
	};

	namespace Convertor
	{
		template<int From, int To>
		struct Length {};


		template<> struct Length<0, 0> { static const scalar value; };
		template<> struct Length<0, 1> { static const scalar value; };
		template<> struct Length<0, 2> { static const scalar value; };
		template<> struct Length<0, 3> { static const scalar value; };
		template<> struct Length<0, 4> { static const scalar value; };
		template<> struct Length<0, 5> { static const scalar value; };
		template<> struct Length<0, 6> { static const scalar value; };
		template<> struct Length<0, 7> { static const scalar value; };
		template<> struct Length<0, 8> { static const scalar value; };

		template<> struct Length<1, 0> { static const scalar value; };
		template<> struct Length<1, 1> { static const scalar value; };
		template<> struct Length<1, 2> { static const scalar value; };
		template<> struct Length<1, 3> { static const scalar value; };
		template<> struct Length<1, 4> { static const scalar value; };
		template<> struct Length<1, 5> { static const scalar value; };
		template<> struct Length<1, 6> { static const scalar value; };
		template<> struct Length<1, 7> { static const scalar value; };
		template<> struct Length<1, 8> { static const scalar value; };

		template<> struct Length<2, 0> { static const scalar value; };
		template<> struct Length<2, 1> { static const scalar value; };
		template<> struct Length<2, 2> { static const scalar value; };
		template<> struct Length<2, 3> { static const scalar value; };
		template<> struct Length<2, 4> { static const scalar value; };
		template<> struct Length<2, 5> { static const scalar value; };
		template<> struct Length<2, 6> { static const scalar value; };
		template<> struct Length<2, 7> { static const scalar value; };
		template<> struct Length<2, 8> { static const scalar value; };

		template<> struct Length<3, 0> { static const scalar value; };
		template<> struct Length<3, 1> { static const scalar value; };
		template<> struct Length<3, 2> { static const scalar value; };
		template<> struct Length<3, 3> { static const scalar value; };
		template<> struct Length<3, 4> { static const scalar value; };
		template<> struct Length<3, 5> { static const scalar value; };
		template<> struct Length<3, 6> { static const scalar value; };
		template<> struct Length<3, 7> { static const scalar value; };
		template<> struct Length<3, 8> { static const scalar value; };

		template<> struct Length<4, 0> { static const scalar value; };
		template<> struct Length<4, 1> { static const scalar value; };
		template<> struct Length<4, 2> { static const scalar value; };
		template<> struct Length<4, 3> { static const scalar value; };
		template<> struct Length<4, 4> { static const scalar value; };
		template<> struct Length<4, 5> { static const scalar value; };
		template<> struct Length<4, 6> { static const scalar value; };
		template<> struct Length<4, 7> { static const scalar value; };
		template<> struct Length<4, 8> { static const scalar value; };

		template<> struct Length<5, 0> { static const scalar value; };
		template<> struct Length<5, 1> { static const scalar value; };
		template<> struct Length<5, 2> { static const scalar value; };
		template<> struct Length<5, 3> { static const scalar value; };
		template<> struct Length<5, 4> { static const scalar value; };
		template<> struct Length<5, 5> { static const scalar value; };
		template<> struct Length<5, 6> { static const scalar value; };
		template<> struct Length<5, 7> { static const scalar value; };
		template<> struct Length<5, 8> { static const scalar value; };

		template<> struct Length<6, 0> { static const scalar value; };
		template<> struct Length<6, 1> { static const scalar value; };
		template<> struct Length<6, 2> { static const scalar value; };
		template<> struct Length<6, 3> { static const scalar value; };
		template<> struct Length<6, 4> { static const scalar value; };
		template<> struct Length<6, 5> { static const scalar value; };
		template<> struct Length<6, 6> { static const scalar value; };
		template<> struct Length<6, 7> { static const scalar value; };
		template<> struct Length<6, 8> { static const scalar value; };

		template<> struct Length<7, 0> { static const scalar value; };
		template<> struct Length<7, 1> { static const scalar value; };
		template<> struct Length<7, 2> { static const scalar value; };
		template<> struct Length<7, 3> { static const scalar value; };
		template<> struct Length<7, 4> { static const scalar value; };
		template<> struct Length<7, 5> { static const scalar value; };
		template<> struct Length<7, 6> { static const scalar value; };
		template<> struct Length<7, 7> { static const scalar value; };
		template<> struct Length<7, 8> { static const scalar value; };

		template<> struct Length<8, 0> { static const scalar value; };
		template<> struct Length<8, 1> { static const scalar value; };
		template<> struct Length<8, 2> { static const scalar value; };
		template<> struct Length<8, 3> { static const scalar value; };
		template<> struct Length<8, 4> { static const scalar value; };
		template<> struct Length<8, 5> { static const scalar value; };
		template<> struct Length<8, 6> { static const scalar value; };
		template<> struct Length<8, 7> { static const scalar value; };
		template<> struct Length<8, 8> { static const scalar value; };


		template<int From, int To>
		struct Mass {};

		template<> struct Mass<0, 0> { static const scalar value; };
		template<> struct Mass<0, 1> { static const scalar value; };
		template<> struct Mass<0, 2> { static const scalar value; };
		template<> struct Mass<0, 3> { static const scalar value; };
		template<> struct Mass<0, 4> { static const scalar value; };
		template<> struct Mass<0, 5> { static const scalar value; };
		template<> struct Mass<0, 6> { static const scalar value; };
		template<> struct Mass<0, 7> { static const scalar value; };

		template<> struct Mass<1, 0> { static const scalar value; };
		template<> struct Mass<1, 1> { static const scalar value; };
		template<> struct Mass<1, 2> { static const scalar value; };
		template<> struct Mass<1, 3> { static const scalar value; };
		template<> struct Mass<1, 4> { static const scalar value; };
		template<> struct Mass<1, 5> { static const scalar value; };
		template<> struct Mass<1, 6> { static const scalar value; };
		template<> struct Mass<1, 7> { static const scalar value; };

		template<> struct Mass<2, 0> { static const scalar value; };
		template<> struct Mass<2, 1> { static const scalar value; };
		template<> struct Mass<2, 2> { static const scalar value; };
		template<> struct Mass<2, 3> { static const scalar value; };
		template<> struct Mass<2, 4> { static const scalar value; };
		template<> struct Mass<2, 5> { static const scalar value; };
		template<> struct Mass<2, 6> { static const scalar value; };
		template<> struct Mass<2, 7> { static const scalar value; };

		template<> struct Mass<3, 0> { static const scalar value; };
		template<> struct Mass<3, 1> { static const scalar value; };
		template<> struct Mass<3, 2> { static const scalar value; };
		template<> struct Mass<3, 3> { static const scalar value; };
		template<> struct Mass<3, 4> { static const scalar value; };
		template<> struct Mass<3, 5> { static const scalar value; };
		template<> struct Mass<3, 6> { static const scalar value; };
		template<> struct Mass<3, 7> { static const scalar value; };

		template<> struct Mass<4, 0> { static const scalar value; };
		template<> struct Mass<4, 1> { static const scalar value; };
		template<> struct Mass<4, 2> { static const scalar value; };
		template<> struct Mass<4, 3> { static const scalar value; };
		template<> struct Mass<4, 4> { static const scalar value; };
		template<> struct Mass<4, 5> { static const scalar value; };
		template<> struct Mass<4, 6> { static const scalar value; };
		template<> struct Mass<4, 7> { static const scalar value; };

		template<> struct Mass<5, 0> { static const scalar value; };
		template<> struct Mass<5, 1> { static const scalar value; };
		template<> struct Mass<5, 2> { static const scalar value; };
		template<> struct Mass<5, 3> { static const scalar value; };
		template<> struct Mass<5, 4> { static const scalar value; };
		template<> struct Mass<5, 5> { static const scalar value; };
		template<> struct Mass<5, 6> { static const scalar value; };
		template<> struct Mass<5, 7> { static const scalar value; };

		template<> struct Mass<6, 0> { static const scalar value; };
		template<> struct Mass<6, 1> { static const scalar value; };
		template<> struct Mass<6, 2> { static const scalar value; };
		template<> struct Mass<6, 3> { static const scalar value; };
		template<> struct Mass<6, 4> { static const scalar value; };
		template<> struct Mass<6, 5> { static const scalar value; };
		template<> struct Mass<6, 6> { static const scalar value; };
		template<> struct Mass<6, 7> { static const scalar value; };

		template<> struct Mass<7, 0> { static const scalar value; };
		template<> struct Mass<7, 1> { static const scalar value; };
		template<> struct Mass<7, 2> { static const scalar value; };
		template<> struct Mass<7, 3> { static const scalar value; };
		template<> struct Mass<7, 4> { static const scalar value; };
		template<> struct Mass<7, 5> { static const scalar value; };
		template<> struct Mass<7, 6> { static const scalar value; };
		template<> struct Mass<7, 7> { static const scalar value; };


		template<int From, int To>
		struct Pressure {};

		template<> struct Pressure<0, 0> { static const scalar value; };
		template<> struct Pressure<0, 1> { static const scalar value; };
		template<> struct Pressure<0, 2> { static const scalar value; };
		template<> struct Pressure<0, 3> { static const scalar value; };
		template<> struct Pressure<0, 4> { static const scalar value; };
		template<> struct Pressure<0, 5> { static const scalar value; };

		template<> struct Pressure<1, 0> { static const scalar value; };
		template<> struct Pressure<1, 1> { static const scalar value; };
		template<> struct Pressure<1, 2> { static const scalar value; };
		template<> struct Pressure<1, 3> { static const scalar value; };
		template<> struct Pressure<1, 4> { static const scalar value; };
		template<> struct Pressure<1, 5> { static const scalar value; };

		template<> struct Pressure<2, 0> { static const scalar value; };
		template<> struct Pressure<2, 1> { static const scalar value; };
		template<> struct Pressure<2, 2> { static const scalar value; };
		template<> struct Pressure<2, 3> { static const scalar value; };
		template<> struct Pressure<2, 4> { static const scalar value; };
		template<> struct Pressure<2, 5> { static const scalar value; };

		template<> struct Pressure<3, 0> { static const scalar value; };
		template<> struct Pressure<3, 1> { static const scalar value; };
		template<> struct Pressure<3, 2> { static const scalar value; };
		template<> struct Pressure<3, 3> { static const scalar value; };
		template<> struct Pressure<3, 4> { static const scalar value; };
		template<> struct Pressure<3, 5> { static const scalar value; };

		template<> struct Pressure<4, 0> { static const scalar value; };
		template<> struct Pressure<4, 1> { static const scalar value; };
		template<> struct Pressure<4, 2> { static const scalar value; };
		template<> struct Pressure<4, 3> { static const scalar value; };
		template<> struct Pressure<4, 4> { static const scalar value; };
		template<> struct Pressure<4, 5> { static const scalar value; };

		template<> struct Pressure<5, 0> { static const scalar value; };
		template<> struct Pressure<5, 1> { static const scalar value; };
		template<> struct Pressure<5, 2> { static const scalar value; };
		template<> struct Pressure<5, 3> { static const scalar value; };
		template<> struct Pressure<5, 4> { static const scalar value; };
		template<> struct Pressure<5, 5> { static const scalar value; };


		template<int From, int To>
		struct Velocity {};

		template<> struct Velocity<0, 0> { static const scalar value; };
		template<> struct Velocity<0, 1> { static const scalar value; };
		template<> struct Velocity<0, 2> { static const scalar value; };
		template<> struct Velocity<0, 3> { static const scalar value; };
		template<> struct Velocity<0, 4> { static const scalar value; };
		template<> struct Velocity<0, 5> { static const scalar value; };


		template<> struct Velocity<1, 0> { static const scalar value; };
		template<> struct Velocity<1, 1> { static const scalar value; };
		template<> struct Velocity<1, 2> { static const scalar value; };
		template<> struct Velocity<1, 3> { static const scalar value; };
		template<> struct Velocity<1, 4> { static const scalar value; };
		template<> struct Velocity<1, 5> { static const scalar value; };

		template<> struct Velocity<2, 0> { static const scalar value; };
		template<> struct Velocity<2, 1> { static const scalar value; };
		template<> struct Velocity<2, 2> { static const scalar value; };
		template<> struct Velocity<2, 3> { static const scalar value; };
		template<> struct Velocity<2, 4> { static const scalar value; };
		template<> struct Velocity<2, 5> { static const scalar value; };

		template<> struct Velocity<3, 0> { static const scalar value; };
		template<> struct Velocity<3, 1> { static const scalar value; };
		template<> struct Velocity<3, 2> { static const scalar value; };
		template<> struct Velocity<3, 3> { static const scalar value; };
		template<> struct Velocity<3, 4> { static const scalar value; };
		template<> struct Velocity<3, 5> { static const scalar value; };

		template<> struct Velocity<4, 0> { static const scalar value; };
		template<> struct Velocity<4, 1> { static const scalar value; };
		template<> struct Velocity<4, 2> { static const scalar value; };
		template<> struct Velocity<4, 3> { static const scalar value; };
		template<> struct Velocity<4, 4> { static const scalar value; };
		template<> struct Velocity<4, 5> { static const scalar value; };

		template<> struct Velocity<5, 0> { static const scalar value; };
		template<> struct Velocity<5, 1> { static const scalar value; };
		template<> struct Velocity<5, 2> { static const scalar value; };
		template<> struct Velocity<5, 3> { static const scalar value; };
		template<> struct Velocity<5, 4> { static const scalar value; };
		template<> struct Velocity<5, 5> { static const scalar value; };


		template<int From, int To>
		struct Acceleration {};

		template<> struct Acceleration<0, 0> { static const scalar value; };
		template<> struct Acceleration<0, 1> { static const scalar value; };

		template<> struct Acceleration<1, 0> { static const scalar value; };
		template<> struct Acceleration<1, 1> { static const scalar value; };


		template<int From, int To>
		struct Density {};

		template<> struct Density<0, 0> { static const scalar value; };
		template<> struct Density<0, 1> { static const scalar value; };
		template<> struct Density<0, 2> { static const scalar value; };
		template<> struct Density<0, 3> { static const scalar value; };

		template<> struct Density<1, 0> { static const scalar value; };
		template<> struct Density<1, 1> { static const scalar value; };
		template<> struct Density<1, 2> { static const scalar value; };
		template<> struct Density<1, 3> { static const scalar value; };

		template<> struct Density<2, 0> { static const scalar value; };
		template<> struct Density<2, 1> { static const scalar value; };
		template<> struct Density<2, 2> { static const scalar value; };
		template<> struct Density<2, 3> { static const scalar value; };

		template<> struct Density<3, 0> { static const scalar value; };
		template<> struct Density<3, 1> { static const scalar value; };
		template<> struct Density<3, 2> { static const scalar value; };
		template<> struct Density<3, 3> { static const scalar value; };


		template<int From, int To>
		struct Power {};

		template<> struct Power<0, 0> { static const scalar value; };
		template<> struct Power<0, 1> { static const scalar value; };
		template<> struct Power<0, 2> { static const scalar value; };
		template<> struct Power<0, 3> { static const scalar value; };
		template<> struct Power<0, 4> { static const scalar value; };
		template<> struct Power<0, 5> { static const scalar value; };

		template<> struct Power<1, 0> { static const scalar value; };
		template<> struct Power<1, 1> { static const scalar value; };
		template<> struct Power<1, 2> { static const scalar value; };
		template<> struct Power<1, 3> { static const scalar value; };
		template<> struct Power<1, 4> { static const scalar value; };
		template<> struct Power<1, 5> { static const scalar value; };

		template<> struct Power<2, 0> { static const scalar value; };
		template<> struct Power<2, 1> { static const scalar value; };
		template<> struct Power<2, 2> { static const scalar value; };
		template<> struct Power<2, 3> { static const scalar value; };
		template<> struct Power<2, 4> { static const scalar value; };
		template<> struct Power<2, 5> { static const scalar value; };

		template<> struct Power<3, 0> { static const scalar value; };
		template<> struct Power<3, 1> { static const scalar value; };
		template<> struct Power<3, 2> { static const scalar value; };
		template<> struct Power<3, 3> { static const scalar value; };
		template<> struct Power<3, 4> { static const scalar value; };
		template<> struct Power<3, 5> { static const scalar value; };

		template<> struct Power<4, 0> { static const scalar value; };
		template<> struct Power<4, 1> { static const scalar value; };
		template<> struct Power<4, 2> { static const scalar value; };
		template<> struct Power<4, 3> { static const scalar value; };
		template<> struct Power<4, 4> { static const scalar value; };
		template<> struct Power<4, 5> { static const scalar value; };

		template<> struct Power<5, 0> { static const scalar value; };
		template<> struct Power<5, 1> { static const scalar value; };
		template<> struct Power<5, 2> { static const scalar value; };
		template<> struct Power<5, 3> { static const scalar value; };
		template<> struct Power<5, 4> { static const scalar value; };
		template<> struct Power<5, 5> { static const scalar value; };


		template<int From, int To>
		struct Force {};

		template<> struct Force<0, 0> { static const scalar value; };
		template<> struct Force<0, 1> { static const scalar value; };
		template<> struct Force<0, 2> { static const scalar value; };
		template<> struct Force<0, 3> { static const scalar value; };
		template<> struct Force<0, 4> { static const scalar value; };
		template<> struct Force<0, 5> { static const scalar value; };
		template<> struct Force<0, 6> { static const scalar value; };
		template<> struct Force<0, 7> { static const scalar value; };

		template<> struct Force<1, 0> { static const scalar value; };
		template<> struct Force<1, 1> { static const scalar value; };
		template<> struct Force<1, 2> { static const scalar value; };
		template<> struct Force<1, 3> { static const scalar value; };
		template<> struct Force<1, 4> { static const scalar value; };
		template<> struct Force<1, 5> { static const scalar value; };
		template<> struct Force<1, 6> { static const scalar value; };
		template<> struct Force<1, 7> { static const scalar value; };

		template<> struct Force<2, 0> { static const scalar value; };
		template<> struct Force<2, 1> { static const scalar value; };
		template<> struct Force<2, 2> { static const scalar value; };
		template<> struct Force<2, 3> { static const scalar value; };
		template<> struct Force<2, 4> { static const scalar value; };
		template<> struct Force<2, 5> { static const scalar value; };
		template<> struct Force<2, 6> { static const scalar value; };
		template<> struct Force<2, 7> { static const scalar value; };

		template<> struct Force<3, 0> { static const scalar value; };
		template<> struct Force<3, 1> { static const scalar value; };
		template<> struct Force<3, 2> { static const scalar value; };
		template<> struct Force<3, 3> { static const scalar value; };
		template<> struct Force<3, 4> { static const scalar value; };
		template<> struct Force<3, 5> { static const scalar value; };
		template<> struct Force<3, 6> { static const scalar value; };
		template<> struct Force<3, 7> { static const scalar value; };

		template<> struct Force<4, 0> { static const scalar value; };
		template<> struct Force<4, 1> { static const scalar value; };
		template<> struct Force<4, 2> { static const scalar value; };
		template<> struct Force<4, 3> { static const scalar value; };
		template<> struct Force<4, 4> { static const scalar value; };
		template<> struct Force<4, 5> { static const scalar value; };
		template<> struct Force<4, 6> { static const scalar value; };
		template<> struct Force<4, 7> { static const scalar value; };

		template<> struct Force<5, 0> { static const scalar value; };
		template<> struct Force<5, 1> { static const scalar value; };
		template<> struct Force<5, 2> { static const scalar value; };
		template<> struct Force<5, 3> { static const scalar value; };
		template<> struct Force<5, 4> { static const scalar value; };
		template<> struct Force<5, 5> { static const scalar value; };
		template<> struct Force<5, 6> { static const scalar value; };
		template<> struct Force<5, 7> { static const scalar value; };

		template<> struct Force<6, 0> { static const scalar value; };
		template<> struct Force<6, 1> { static const scalar value; };
		template<> struct Force<6, 2> { static const scalar value; };
		template<> struct Force<6, 3> { static const scalar value; };
		template<> struct Force<6, 4> { static const scalar value; };
		template<> struct Force<6, 5> { static const scalar value; };
		template<> struct Force<6, 6> { static const scalar value; };
		template<> struct Force<6, 7> { static const scalar value; };

		template<> struct Force<7, 0> { static const scalar value; };
		template<> struct Force<7, 1> { static const scalar value; };
		template<> struct Force<7, 2> { static const scalar value; };
		template<> struct Force<7, 3> { static const scalar value; };
		template<> struct Force<7, 4> { static const scalar value; };
		template<> struct Force<7, 5> { static const scalar value; };
		template<> struct Force<7, 6> { static const scalar value; };
		template<> struct Force<7, 7> { static const scalar value; };


		template<int From, int To>
		struct Angle {};

		template<> struct Angle<0, 0> { static const scalar value; };
		template<> struct Angle<0, 1> { static const scalar value; };
		template<> struct Angle<0, 2> { static const scalar value; };

		template<> struct Angle<1, 0> { static const scalar value; };
		template<> struct Angle<1, 1> { static const scalar value; };
		template<> struct Angle<1, 2> { static const scalar value; };

		template<> struct Angle<2, 0> { static const scalar value; };
		template<> struct Angle<2, 1> { static const scalar value; };
		template<> struct Angle<2, 2> { static const scalar value; };


		template<int From, int To>
		struct DynViscosity {};
		
		template<> struct DynViscosity<0, 0> { static const scalar value; };
		template<> struct DynViscosity<0, 1> { static const scalar value; };
		template<> struct DynViscosity<0, 2> { static const scalar value; };
		template<> struct DynViscosity<0, 3> { static const scalar value; };
		template<> struct DynViscosity<0, 4> { static const scalar value; };

		template<> struct DynViscosity<1, 0> { static const scalar value; };
		template<> struct DynViscosity<1, 1> { static const scalar value; };
		template<> struct DynViscosity<1, 2> { static const scalar value; };
		template<> struct DynViscosity<1, 3> { static const scalar value; };
		template<> struct DynViscosity<1, 4> { static const scalar value; };

		template<> struct DynViscosity<2, 0> { static const scalar value; };
		template<> struct DynViscosity<2, 1> { static const scalar value; };
		template<> struct DynViscosity<2, 2> { static const scalar value; };
		template<> struct DynViscosity<2, 3> { static const scalar value; };
		template<> struct DynViscosity<2, 4> { static const scalar value; };

		template<> struct DynViscosity<3, 0> { static const scalar value; };
		template<> struct DynViscosity<3, 1> { static const scalar value; };
		template<> struct DynViscosity<3, 2> { static const scalar value; };
		template<> struct DynViscosity<3, 3> { static const scalar value; };
		template<> struct DynViscosity<3, 4> { static const scalar value; };

		template<> struct DynViscosity<4, 0> { static const scalar value; };
		template<> struct DynViscosity<4, 1> { static const scalar value; };
		template<> struct DynViscosity<4, 2> { static const scalar value; };
		template<> struct DynViscosity<4, 3> { static const scalar value; };
		template<> struct DynViscosity<4, 4> { static const scalar value; };


		template<int From, int To>
		struct KinViscosity {};

		template<> struct KinViscosity<0, 0> { static const scalar value; };
		template<> struct KinViscosity<0, 1> { static const scalar value; };

		template<> struct KinViscosity<1, 0> { static const scalar value; };
		template<> struct KinViscosity<1, 1> { static const scalar value; };
	}

	CONVERT_UNIT(Length)
		CONVERT_UNIT(Mass)
		CONVERT_UNIT(Pressure)
		CONVERT_UNIT(Velocity)
		CONVERT_UNIT(Acceleration)
		CONVERT_UNIT(Density)
		CONVERT_UNIT(Power)
		CONVERT_UNIT(Force)
		CONVERT_UNIT(Angle)
		CONVERT_UNIT(DynViscosity)
		CONVERT_UNIT(KinViscosity)


	UNIT_EXPONENTS(Mass, 1, 0, 0, 0, 0, 0, 0, false);
	UNIT_EXPONENTS(Length, 0, 1, 0, 0, 0, 0, 0, false);
	UNIT_EXPONENTS(Pressure, 1, -1, -2, 0, 0, 0, 0, false);
	UNIT_EXPONENTS(Velocity, 0, 1, -1, 0, 0, 0, 0, false);
	UNIT_EXPONENTS(Acceleration, 0, 1, -2, 0, 0, 0, 0, false);
	UNIT_EXPONENTS(Density, 1, -3, 0, 0, 0, 0, 0, false);
	UNIT_EXPONENTS(Power, 1, 2, -3, 0, 0, 0, 0, false);
	UNIT_EXPONENTS(Force, 1, 1, -2, 0, 0, 0, 0, false);
	UNIT_EXPONENTS(Angle, 0, 0, 0, 0, 0, 0, 0, true);
	UNIT_EXPONENTS(DynViscosity, 1, -1, -1, 0, 0, 0, 0, false);
	UNIT_EXPONENTS(KinViscosity, 0, 2, -1, 0, 0, 0, 0, false);
	UNIT_EXPONENTS(Null, 0, 0, 0, 0, 0, 0, 0, false);
}

#undef CONVERT_UNIT
#undef UNIT_EXPONENTS

#endif // !_UnitSystem_Header
