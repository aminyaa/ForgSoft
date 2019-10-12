#pragma once
#ifndef _GModel_Plane_Header
#define _GModel_Plane_Header

#include <GModel_Entity.hxx>
#include <OFstream.hxx>

namespace AutLib
{

	// Forward Declarations
	class GModel_parWire;
	class GModel_Surface;
	class GModel_parCurve;

	class GModel_Plane
		: public GModel_Entity
	{

		typedef std::shared_ptr<GModel_parWire> wire_ptr;
		typedef std::vector<wire_ptr> wireList;

		typedef wire_ptr outer;
		typedef std::shared_ptr<wireList> inner;

		/*Private Data*/

		outer theOutter_;
		inner theInner_;

	public:

		GModel_Plane
		(
			const Standard_Integer theIndex,
			const word& theName,
			const outer& theOutter,
			const inner& theInner = nullptr
		)
			: GModel_Entity(theIndex, theName)
			, theOutter_(theOutter)
			, theInner_(theInner)
		{}

		GModel_Plane
		(
			const outer& theOutter,
			const inner& theInner = nullptr
		)
			: theOutter_(theOutter)
			, theInner_(theInner)
		{}

		Standard_Boolean HasHole() const
		{
			return (Standard_Boolean)theInner_;
		}

		Standard_Integer NbHoles() const
		{
			if (!HasHole()) return 0;
			return (Standard_Integer)theInner_->size();
		}

		const inner& Inner() const
		{
			return theInner_;
		}

		const outer& Outer() const
		{
			return theOutter_;
		}

		void RetrieveWiresTo(wireList& theWires) const;


		//- Io functions and operators

		void ExportToPlt(OFstream& File) const;


		//- Static functions and operators

		static std::shared_ptr<GModel_Plane>
			MakePlane(const GModel_Surface& theFace);
	};
}

#endif // !_GModel_Plane_Header
