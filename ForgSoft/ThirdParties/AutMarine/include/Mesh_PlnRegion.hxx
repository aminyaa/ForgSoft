#pragma once
#ifndef _Mesh_PlnRegion_Header
#define _Mesh_PlnRegion_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>
#include <OFstream.hxx>
#include <Mesh_PlnRegion_Traits.hxx>

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

		typedef typename Mesh_PlnRegion_Traits<CurveType>::plnType 
			plnType;

		typedef Mesh_PlnWire<plnCurveType> plnWireType;

		typedef std::shared_ptr<plnWireType > outer;
		typedef std::shared_ptr<std::vector<outer>> inner;
		typedef std::vector<std::shared_ptr<plnWireType>> wireList;

		typedef SizeFun sizeFun;
		typedef MetricFun metricFun;

	private:

		/*Private Data*/

		std::shared_ptr<plnType> thePlane_;

		outer theOutter_;
		inner theInner_;

	public:

		Mesh_PlnRegion
		(
			const std::shared_ptr<plnType>& thePlane,
			const outer& theOuter,
			const inner& theInner = nullptr
		)
			: thePlane_(thePlane)
			, theOutter_(theOuter)
			, theInner_(theInner)
		{}

		Mesh_PlnRegion
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<plnType>& thePlane,
			const outer& theOuter,
			const inner& theInner = nullptr
		)
			: Global_Indexed(theIndex)
			, Global_Named(theName)
			, thePlane_(thePlane)
			, theOutter_(theOuter)
			, theInner_(theInner)
		{}

		const std::shared_ptr<plnType>& Plane() const
		{
			return thePlane_;
		}

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
		static std::shared_ptr<plnWireType>
			MakeMeshWire
			(
				const WireType& theWire
			);

		static std::shared_ptr<Mesh_PlnRegion> 
			MakePlane
			(
				const std::shared_ptr<plnType>& thePlane
			);

	};
}

#include <Mesh_PlnRegionI.hxx>

#endif // !_Mesh_PlnRegion_Header