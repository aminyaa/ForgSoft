#pragma once
#ifndef _GModel_ParaWire_Header
#define _GModel_ParaWire_Header

#include <GModel_Entity.hxx>
#include <Entity2d_BoxFwd.hxx>
#include <OFstream.hxx>

#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class GModel_ParaCurve;

	class GModel_ParaWire
	{

		typedef std::vector<std::shared_ptr<GModel_ParaCurve>> curveList;

		/*Private Data*/

		std::shared_ptr<curveList> theCurves_;

	public:

		GModel_ParaWire(const std::shared_ptr<curveList>& theCurves);

		GModel_ParaWire(const Standard_Integer theIndex, const std::shared_ptr<curveList>& theCurves);

		GModel_ParaWire(const Standard_Integer theIndex, const word& theName, const std::shared_ptr<curveList>& theCurves);


		Standard_Integer NbCurves() const;

		const auto& Curves() const
		{
			return theCurves_;
		}

		Entity2d_Box CalcBoundingBox() const;

		//- IO functions and operators

		void ExportToPlt(OFstream& File) const;
	};
}

#endif // !_GModel_ParaWire_Header
