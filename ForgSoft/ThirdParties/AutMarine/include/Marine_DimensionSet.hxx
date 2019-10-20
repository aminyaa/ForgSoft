#pragma once
#ifndef _Marine_DimensionSet_Header
#define _Marine_DimensionSet_Header

#include <Standard_TypeDef.hxx>
#include <Marine_DimensionedParamFwd.hxx>
#include <Istream.hxx>
#include <debug.hxx>

namespace AutLib
{

	class Marine_DimensionSet
	{

		/*Private Data*/

	public:

		enum
		{
			nbDimensions = 4
		};

		enum dimensionType
		{
			MASS,               // kilogram   kg
			LENGTH,             // metre      m
			TIME,               // second     s
			TEMPERATURE         // Kelvin     K
		};

		static const Standard_Real smallExponent;

	private:

		Standard_Real theExponents_[nbDimensions];

	public:

		// Declare name of the class and its debug switch
		static const char* typeName_() { return "Marine_RealParam"; }

		static const word typeName;
		static debug::debugSwitch debug;

		Marine_DimensionSet
		(
			const Standard_Real mass,
			const Standard_Real length,
			const Standard_Real time,
			const Standard_Real temperature
		);

		//- Construct from Istream
		Marine_DimensionSet(Istream&);

		Standard_Boolean DimensionLess() const;

		void Reset(const Marine_DimensionSet&);

		Standard_Real operator[](const dimensionType type) const
		{
			return theExponents_[type];
		}

		Standard_Real& operator[](const dimensionType type)
		{
			return theExponents_[type];
		}

		Standard_Boolean operator==(const Marine_DimensionSet&) const;
		Standard_Boolean operator!=(const Marine_DimensionSet&) const;
		Standard_Boolean operator=(const Marine_DimensionSet&) const;

		Standard_Boolean operator+=(const Marine_DimensionSet&) const;
		Standard_Boolean operator-=(const Marine_DimensionSet&) const;
		Standard_Boolean operator*=(const Marine_DimensionSet&);
		Standard_Boolean operator/=(const Marine_DimensionSet&);

		friend Marine_DimensionSet max(const Marine_DimensionSet&, const Marine_DimensionSet&);
		friend Marine_DimensionSet min(const Marine_DimensionSet&, const Marine_DimensionSet&);

		friend Marine_DimensionSet pow(const Marine_DimensionSet&, const Standard_Real);
		friend Marine_DimensionSet pow(const Marine_DimensionSet&, const marineLib::realParam&);
		friend Marine_DimensionSet pow(const marineLib::realParam&, const Marine_DimensionSet&);

		friend Marine_DimensionSet sqr(const Marine_DimensionSet&);
		friend Marine_DimensionSet pow3(const Marine_DimensionSet&);
		friend Marine_DimensionSet pow4(const Marine_DimensionSet&);
		friend Marine_DimensionSet pow5(const Marine_DimensionSet&);
		friend Marine_DimensionSet pow6(const Marine_DimensionSet&);

		friend Marine_DimensionSet sqrt(const Marine_DimensionSet&);
		friend Marine_DimensionSet magSqr(const Marine_DimensionSet&);
		friend Marine_DimensionSet mag(const Marine_DimensionSet&);
		friend Marine_DimensionSet sign(const Marine_DimensionSet&);
		friend Marine_DimensionSet pos(const Marine_DimensionSet&);
		friend Marine_DimensionSet neg(const Marine_DimensionSet&);
		friend Marine_DimensionSet inv(const Marine_DimensionSet&);
		friend Marine_DimensionSet hinv(const Marine_DimensionSet&);

		friend Marine_DimensionSet operator-(const Marine_DimensionSet&);

		friend Marine_DimensionSet operator+(const Marine_DimensionSet&, const Marine_DimensionSet&);

		friend Marine_DimensionSet operator-(const Marine_DimensionSet&, const Marine_DimensionSet&);

		friend Marine_DimensionSet operator*(const Marine_DimensionSet&, const Marine_DimensionSet&);

		friend Marine_DimensionSet operator/(const Marine_DimensionSet&, const Marine_DimensionSet&);

		// IOstream operators

		friend Ostream& operator<<(Ostream&, const Marine_DimensionSet&);
	};
}

#include <Marine_DimensionSets.hxx>

#endif // !_Marine_DimensionSet_Header
