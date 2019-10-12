#pragma once
#ifndef _Pnt3d_Header
#define _Pnt3d_Header

#include <gp_Pnt.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

namespace AutLib
{

	//Forward Declarations
	class Pnt3d;
	class OFstream;

	std::ostream& operator<<(std::ostream& os, const Pnt3d&);
	std::istream& operator>>(std::istream& is, Pnt3d&);

	Ostream& operator<<(Ostream& os, const Pnt3d&);
	Istream& operator>>(Istream& is, Pnt3d&);

	Pnt3d operator-(const Pnt3d& P1, const Pnt3d& P2);

	class Pnt3d
		: public gp_Pnt
	{

		friend class boost::serialization::access;

		/*Private Data*/

		template<class Archive>
		void serialize(Archive& ar, const unsigned int version) { ar& X(); ar& Y(); ar& Z(); }

	public:

		typedef Pnt3d ptType;

		//- Static members
		static const int nbCmpts;
		static const Pnt3d null;

		enum
		{
			dim = 3
		};

		// constructors

		Pnt3d()
		{}

		Pnt3d
		(
			const Standard_Real theX, 
			const Standard_Real theY,
			const Standard_Real theZ
		)
			: gp_Pnt(theX, theY, theZ)
		{}

		Pnt3d(const gp_XYZ& XYZ)
			: gp_Pnt(XYZ)
		{}

		Pnt3d(const gp_Pnt& Pt)
			: gp_Pnt(Pt)
		{}

		Pnt3d(std::istream& is)
		{
			is >> *this;
		}

		Pnt3d(Istream& is)
		{
			is >> *this;
		}

		Standard_Real X() const
		{
			return coord.X();
		}

		Standard_Real& X()
		{
			return coord.X();
		}

		Standard_Real Y() const
		{
			return coord.Y();
		}

		Standard_Real& Y()
		{
			return coord.Y();
		}

		Standard_Real Z() const
		{
			return coord.Z();
		}

		Standard_Real& Z()
		{
			return coord.Z();
		}

		Standard_Real TwoNorm() const
		{
			return sqrt(X()*X() + Y()*Y() + Z()*Z());
		}

		Standard_Real SquareTwoNorm() const
		{
			return X()*X() + Y()*Y() + Z()*Z();
		}

		Pnt3d& operator+=(const Pnt3d& theOther)
		{
			coord.X() += theOther.X();
			coord.Y() += theOther.Y();
			coord.Z() += theOther.Z();

			return *this;
		}

		Pnt3d& operator-=(const Pnt3d& theOther)
		{
			coord.X() -= theOther.X();
			coord.Y() -= theOther.Y();
			coord.Z() -= theOther.Z();

			return *this;
		}

		Pnt3d& operator*=(const Pnt3d& theOther)
		{
			coord.X() *= theOther.X();
			coord.Y() *= theOther.Y();
			coord.Z() *= theOther.Z();

			return *this;
		}

		Pnt3d& operator=(const Standard_Real Scalar)
		{
			coord.X() = Scalar;
			coord.Y() = Scalar;
			coord.Z() = Scalar;

			return *this;
		}

		Pnt3d& operator+=(const Standard_Real Scalar)
		{
			coord.X() += Scalar;
			coord.Y() += Scalar;
			coord.Z() += Scalar;

			return *this;
		}

		Pnt3d& operator-=(const Standard_Real Scalar)
		{
			coord.X() -= Scalar;
			coord.Y() -= Scalar;
			coord.Z() -= Scalar;

			return *this;
		}

		Pnt3d& operator*=(const Standard_Real Scalar)
		{
			coord.X() *= Scalar;
			coord.Y() *= Scalar;
			coord.Z() *= Scalar;

			return *this;
		}

		Pnt3d& operator/=(const Standard_Real Scalar)
		{
			coord.X() /= Scalar;
			coord.Y() /= Scalar;
			coord.Z() /= Scalar;

			return *this;
		}

		Pnt3d& operator+()
		{
			return *this;
		}

		Pnt3d operator-()
		{
			return Pnt3d() - *this;
		}

		Pnt3d Normalized() const
		{
			auto Copy = *this;
			Copy.Normalize();
			MOVE(Copy);
		}

		void Normalize()
		{
			Standard_Real d = TwoNorm();
			if (d <= gp::Resolution())
			{
				FatalErrorIn(FunctionSIG)
					<< " Length of the vector is too small : " << d
					<< abort(FatalError);
			}
			coord.X() /= d;
			coord.Y() /= d;
			coord.Z() /= d;
		}

		void Get
		(
			Standard_Real& theX,
			Standard_Real& theY,
			Standard_Real& theZ
		) const
		{
			theX = coord.X();
			theY = coord.Y();
			theZ = coord.Z();
		}

		//- IO functions and operators

		void Print(std::ostream& os = std::cout) const;

		void AddToPlt(OFstream& theFile) const;
	};
}

#include <Pnt3dI.hxx>

#endif // !_Pnt3d_Header
