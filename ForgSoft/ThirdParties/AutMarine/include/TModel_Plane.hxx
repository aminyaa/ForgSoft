#pragma once
#ifndef _TModel_Plane_Header
#define _TModel_Plane_Header

#include <TModel_Entity.hxx>
#include <OFstream.hxx>

namespace AutLib
{

	// Forward Declarations
	class TModel_parWire;
	class TModel_Surface;
	class TModel_parCurve;

	class TModel_Plane
		: public TModel_Entity
	{

		typedef std::shared_ptr<TModel_parWire> wire_ptr;
		typedef std::vector<wire_ptr> wireList;

		typedef wire_ptr outer;
		typedef std::shared_ptr<wireList> inner;

		/*Private Data*/

		outer theOutter_;
		inner theInner_;

	public:

		typedef TModel_parWire parWireType;
		typedef TModel_parCurve parCurveType;

		TModel_Plane
		(
			const Standard_Integer theIndex,
			const word& theName,
			const outer& theOutter,
			const inner& theInner = nullptr
		)
			: TModel_Entity(theIndex, theName)
			, theOutter_(theOutter)
			, theInner_(theInner)
		{}

		TModel_Plane
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


		//- IO functions and operators

		void ExportToPlt(OFstream& File) const;


		//- Static functions and operators

		static std::shared_ptr<TModel_Plane>
			MakePlane(const TModel_Surface& theFace);
	};
}

#endif // !_TModel_Plane_Header
