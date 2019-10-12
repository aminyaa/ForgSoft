#pragma once
#ifndef _Cad_EntityPrecision_Header
#define _Cad_EntityPrecision_Header

#include <Precision.hxx>
#include <error.hxx>
#include <OSstream.hxx>

namespace AutLib
{

	class Cad_EntityPrecision
	{

		/*Private Data*/

		Standard_Real thePrecision_;

	public:

		Cad_EntityPrecision()
			: thePrecision_(Precision::Confusion())
		{}

		Cad_EntityPrecision(const Standard_Real thePrec)
		{
			SetPrecision(thePrec);
		}

		Standard_Real Presicion() const
		{
			return thePrecision_;
		}

		Standard_Real& Presicion()
		{
			return thePrecision_;
		}

		void SetPrecision(const Standard_Real thePrec)
		{
			if (thePrec <= RealSmall())
			{
				FatalErrorIn("void SetPrecision(const Standard_Real thePrec)")
					<< "Invalid Precision: " << thePrecision_ << endl
					<< abort(FatalError);
			}

			thePrecision_ = thePrec;
		}
	};
}

#endif // !_Cad_EntityPrecision_Header