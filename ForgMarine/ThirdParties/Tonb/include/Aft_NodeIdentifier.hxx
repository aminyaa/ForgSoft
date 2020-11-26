#pragma once
#ifndef _Aft_NodeIdentifier_Header
#define _Aft_NodeIdentifier_Header

#include <Global_AccessMethod.hxx>
#include <Standard_TypeDef.hxx>
#include <Entity2d_Metric1.hxx>
#include <Pnt3d.hxx>
#include <Aft_NodeType.hxx>

namespace tnbLib
{

	template<Aft_NodeType NType = Aft_NodeType_Iso>
	class Aft_NodeIdentifier
	{

		/*Private Data*/

		Standard_Real theRadius_;
		Standard_Real theMaxL_;

		Standard_Boolean IsOnCavity_;

	public:

		Aft_NodeIdentifier()
			: theRadius_(0)
			, theMaxL_(0)
			, IsOnCavity_(Standard_False)
		{}


		Standard_Boolean CavityStatus() const
		{
			return IsOnCavity_;
		}

		void SetCavityStatus(const Standard_Boolean status)
		{
			IsOnCavity_ = status;
		}

		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Radius)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, MaxL)
	};


	template<>
	class Aft_NodeIdentifier<Aft_NodeType_AnIso>
		: public Aft_NodeIdentifier<Aft_NodeType_Iso>
	{

		/*Private Data*/

		Entity2d_Metric1 theMetric_;

	public:

		typedef Entity2d_Metric1 metricType;

		Aft_NodeIdentifier()
		{}

		GLOBAL_ACCESS_SINGLE(Entity2d_Metric1, Metric)
	};


	template<>
	class Aft_NodeIdentifier<Aft_NodeType_Surface>
		: public Aft_NodeIdentifier<Aft_NodeType_AnIso>
	{

		/*Private Data*/

		Pnt3d theCoord3D_;

	public:

		Aft_NodeIdentifier()
		{}

		GLOBAL_ACCESS_SINGLE(Pnt3d, Coord3D)
	};
}

#endif // !_Aft_NodeIdentifier_Header