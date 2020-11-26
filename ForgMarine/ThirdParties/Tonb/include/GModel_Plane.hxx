#pragma once
#ifndef _GModel_Plane_Header
#define _GModel_Plane_Header

#include <GModel_Entity.hxx>
#include <OFstream.hxx>

#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class GModel_ParaWire;

	class GModel_Plane
	{

		typedef std::vector<std::shared_ptr<GModel_ParaWire>> wireList;
		typedef std::shared_ptr<GModel_ParaWire> outer;
		typedef std::shared_ptr<wireList> inner;

		/*Private Data*/

		outer theOuter_;
		inner theInner_;

	public:

		GModel_Plane(const outer& theOuter, const inner& theInner = nullptr);

		GModel_Plane(const Standard_Integer theIndex, const outer& theOuter, const inner& theInner = nullptr);

		GModel_Plane(const Standard_Integer theIndex, const word& theName, const outer& theOuter, const inner& theInner = nullptr);


		Standard_Boolean HasHole() const;

		Standard_Integer NbHoles() const;

		const auto& Inner() const
		{
			return theInner_;
		}

		const auto& Outer() const
		{
			return theOuter_;
		}


		//- Io functions and operators

		void ExportToPlt(OFstream& File) const;
	};
}

#endif // !_GModel_Plane_Header
