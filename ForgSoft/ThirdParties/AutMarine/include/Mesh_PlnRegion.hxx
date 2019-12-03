#pragma once
#ifndef _Mesh_PlnRegion_Header
#define _Mesh_PlnRegion_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>
#include <OFstream.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	// Forward Declarations
	template<class CurveType, class SizeFun, class MetricFun>
	class Mesh_PlnCurve;

	template<class PlnCurve>
	class Mesh_PlnWire;

	template<class CurveType, class SizeFun, class MetricFun = void>
	class Mesh_PlnRegion
		: public Global_Indexed
		, public Global_Named
	{

	public:

		typedef Mesh_PlnCurve<CurveType, SizeFun, MetricFun>
			plnCurveType;

		typedef Mesh_PlnWire<plnCurveType> plnWireType;

		typedef std::shared_ptr<plnWireType > outer;
		typedef std::shared_ptr<std::vector<outer>> inner;
		typedef std::vector<std::shared_ptr<plnWireType>> wireList;

		typedef SizeFun sizeFun;
		typedef MetricFun metricFun;

	private:

		/*Private Data*/

		outer theOutter_;
		inner theInner_;

	public:

		Mesh_PlnRegion
		(
			const outer& theOuter,
			const inner& theInner = nullptr
		)
			: theOutter_(theOuter)
			, theInner_(theInner)
		{}

		Mesh_PlnRegion
		(
			const Standard_Integer theIndex,
			const word& theName,
			const outer& theOuter,
			const inner& theInner = nullptr
		)
			: Global_Indexed(theIndex)
			, Global_Named(theName)
			, theOutter_(theOuter)
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

		void ExportToPlt(OFstream& File) const;


		//- Static functions and operators

		template<class WireType>
		static std::shared_ptr<plnWireType> MakeMeshWire(const WireType& theWire);

	};
}

#endif // !_Mesh_PlnRegion_Header
