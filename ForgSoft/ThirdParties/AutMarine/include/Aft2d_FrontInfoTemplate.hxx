#pragma once
#ifndef _Aft2d_FrontInfoTemplate_Header
#define _Aft2d_FrontInfoTemplate_Header

#define RESET_FRONT_INFO
#include <Aft_FrontInfo.hxx>
#include <Mesh_Counters.hxx>
#include <Mesh_TypeTraits.hxx>
#include <error.hxx>
#include <OSstream.hxx>

//#include "Aft2d_FrontTraits.hxx"
//#include "Aft2d_FrontInfoAdaptor.hxx"

namespace AutLib
{

	template<class FrontTraits, class FrontAdaptor>
	class Aft2d_FrontInfoTemplate
		: public Aft_FrontInfo<FrontAdaptor>
		, public Mesh2d_FrontCounter
	{

	public:

		typedef typename FrontTraits::nodeType nodeType;
		typedef typename FrontTraits::edgeType egdeType;
		typedef typename FrontTraits::edgeType frontType;
		typedef typename FrontTraits::elementType elementType;

		typedef Aft_FrontInfo<FrontAdaptor> frontInfo;

	private:

		template< bool cond, typename U >
		using resolvedType = typename std::enable_if< cond, U >::type;

		/*Private Data*/

	protected:

		static void AttachToMeshNodes(const std::shared_ptr<elementType>& theElement);

		static void AttachToMeshNodes(const std::shared_ptr<frontType>& theEdge);

		static void AttachToFrontNodes(const std::shared_ptr<frontType>& theEdge);

		static void AttachToFronts(const std::shared_ptr<frontType>& theEdge);


		//	static void deAttachFromMesh(const std::shared_ptr<elementType>& theElement);

		static void deAttachFromMesh(const std::shared_ptr<frontType>& theEdge);

		static void deAttachFromFront(const std::shared_ptr<frontType>& theEdge);

		void SetPairedEdges();

		/*template<class SizeMap>
		void UpdateEdges(const SizeMap& theSizeMap);*/

		template<class U = void, class SizeMap>
		typename std::enable_if<is_isoType<typename SizeMap::frontType>::value, U>::type
			UpdateEdges(const SizeMap& theSizeMap)
		{
			Debug_Null_Pointer(frontInfo::CurrentFront());
			const auto& current = *frontInfo::CurrentFront();

			if (frontInfo::IsPairedEdge0())
			{
				frontInfo::SetCreatedEdge0(nullptr);

				// remove the old coincident face from the GF
				deAttachFromFront(frontInfo::PairedEdge0());

				// remove cavity face
				if (frontInfo::PairedEdge0()->IsOnCavity())
					frontInfo::PairedEdge0()->RemoveEntityAsCavity();
			}
			else
			{
				EdgeCounter()++;

				const auto& P1 = frontInfo::ValidNode()->Coord();
				const auto& P2 = current.Node1()->Coord();

				frontInfo::SetCreatedEdge0(std::make_shared<frontType>(EdgeCounter()));
				auto& edge = *frontInfo::CreatedEdge0();

				edge.SetCharLength(theSizeMap.CalcDistance(P1, P2));
				edge.SetCentre(theSizeMap.CalcCentreOf(P1, P2));
				edge.SetNode0(frontInfo::ValidNode());
				edge.SetNode1(current.Node1());

				Debug_If_Condition(frontInfo::ValidNode() == current.Node1());

				AttachToFrontNodes(frontInfo::CreatedEdge0());
				AttachToMeshNodes(frontInfo::CreatedEdge0());
			}

			if (frontInfo::IsPairedEdge1())
			{
				frontInfo::SetCreatedEdge1(nullptr);

				// remove the old coincident face from the GF
				deAttachFromFront(frontInfo::PairedEdge1());

				// remove cavity face
				if (frontInfo::PairedEdge1()->IsOnCavity())
					frontInfo::PairedEdge1()->RemoveEntityAsCavity();
			}
			else
			{
				EdgeCounter()++;

				const auto& P1 = current.Node0()->Coord();
				const auto& P2 = frontInfo::ValidNode()->Coord();

				frontInfo::SetCreatedEdge1(std::make_shared<frontType>(EdgeCounter()));
				auto& edge = *frontInfo::CreatedEdge1();

				edge.SetCharLength(theSizeMap.CalcDistance(P1, P2));
				edge.SetCentre(theSizeMap.CalcCentreOf(P1, P2));
				edge.SetNode0(current.Node0());
				edge.SetNode1(frontInfo::ValidNode());

				Debug_If_Condition(frontInfo::ValidNode() == current.Node0());

				AttachToFrontNodes(frontInfo::CreatedEdge1());
				AttachToMeshNodes(frontInfo::CreatedEdge1());
			}
		}

		template<class U = void, class SizeMap>
		typename std::enable_if<is_anisoType<typename SizeMap::frontType>::value, U>::type
			UpdateEdges(const SizeMap& theSizeMap)
		{
			Debug_Null_Pointer(frontInfo::CurrentFront());
			const auto& current = *frontInfo::CurrentFront();

			if (frontInfo::IsPairedEdge0())
			{
				frontInfo::SetCreatedEdge0(nullptr);

				// remove the old coincident face from the GF
				deAttachFromFront(frontInfo::PairedEdge0());

				// remove cavity face
				if (frontInfo::PairedEdge0()->IsOnCavity())
					frontInfo::PairedEdge0()->RemoveEntityAsCavity();
			}
			else
			{
				EdgeCounter()++;

				const auto& P1 = frontInfo::ValidNode()->Coord();
				const auto& P2 = current.Node1()->Coord();

				frontInfo::SetCreatedEdge0(std::make_shared<frontType>(EdgeCounter()));
				auto& edge = *frontInfo::CreatedEdge0();

				edge.SetCharLength(theSizeMap.CalcDistance(P1, P2));
				edge.SetCentre(theSizeMap.CalcCentreOf(P1, P2));
				edge.SetNode0(frontInfo::ValidNode());
				edge.SetNode1(current.Node1());
				edge.SetEffectiveMetric(theSizeMap.CalcEffectiveMetric(P1, P2));

				Debug_If_Condition(frontInfo::ValidNode() == current.Node1());

				AttachToFrontNodes(frontInfo::CreatedEdge0());
				AttachToMeshNodes(frontInfo::CreatedEdge0());
			}

			if (frontInfo::IsPairedEdge1())
			{
				frontInfo::SetCreatedEdge1(nullptr);

				// remove the old coincident face from the GF
				deAttachFromFront(frontInfo::PairedEdge1());

				// remove cavity face
				if (frontInfo::PairedEdge1()->IsOnCavity())
					frontInfo::PairedEdge1()->RemoveEntityAsCavity();
			}
			else
			{
				EdgeCounter()++;

				const auto& P1 = current.Node0()->Coord();
				const auto& P2 = frontInfo::ValidNode()->Coord();

				frontInfo::SetCreatedEdge1(std::make_shared<frontType>(EdgeCounter()));
				auto& edge = *frontInfo::CreatedEdge1();

				edge.SetCharLength(theSizeMap.CalcDistance(P1, P2));
				edge.SetCentre(theSizeMap.CalcCentreOf(P1, P2));
				edge.SetNode0(current.Node0());
				edge.SetNode1(frontInfo::ValidNode());
				edge.SetEffectiveMetric(theSizeMap.CalcEffectiveMetric(P1, P2));

				Debug_If_Condition(frontInfo::ValidNode() == current.Node0());

				AttachToFrontNodes(frontInfo::CreatedEdge1());
				AttachToMeshNodes(frontInfo::CreatedEdge1());
			}
		}

		//template<>
		//void UpdateEdges<SizeMap2d>(const SizeMap2d& theSizeMap)
		//{
		//	Debug_Null_Pointer(CurrentFront());
		//	const auto& current = *CurrentFront();

		//	if (IsPairedEdge0())
		//	{
		//		SetCreatedEdge0(nullptr);

		//		// remove the old coincident face from the GF
		//		deAttachFromFront(PairedEdge0());

		//		// remove cavity face
		//		if (PairedEdge0()->IsOnCavity())
		//			PairedEdge0()->RemoveEntityAsCavity();
		//	}
		//	else
		//	{
		//		EdgeCounter()++;

		//		const auto& P1 = ValidNode()->Coord();
		//		const auto& P2 = current.Node1()->Coord();

		//		SetCreatedEdge0(std::make_shared<frontType>(EdgeCounter()));
		//		auto& edge = *CreatedEdge0();

		//		edge.SetCharLength(theSizeMap.CalcDistance(P1, P2));
		//		edge.SetCentre(theSizeMap.CalcCentreOf(P1, P2));
		//		edge.SetNode0(ValidNode());
		//		edge.SetNode1(current.Node1());

		//		AttachToFrontNodes(CreatedEdge0());
		//		AttachToMeshNodes(CreatedEdge0());
		//	}

		//	if (IsPairedEdge1())
		//	{
		//		SetCreatedEdge1(nullptr);

		//		// remove the old coincident face from the GF
		//		deAttachFromFront(PairedEdge1());

		//		// remove cavity face
		//		if (PairedEdge1()->IsOnCavity())
		//			PairedEdge1()->RemoveEntityAsCavity();
		//	}
		//	else
		//	{
		//		EdgeCounter()++;

		//		const auto& P1 = current.Node0()->Coord();
		//		const auto& P2 = ValidNode()->Coord();

		//		SetCreatedEdge1(std::make_shared<frontType>(EdgeCounter()));
		//		auto& edge = *CreatedEdge1();

		//		edge.SetCharLength(theSizeMap.CalcDistance(P1, P2));
		//		edge.SetCentre(theSizeMap.CalcCentreOf(P1, P2));
		//		edge.SetNode0(current.Node0());
		//		edge.SetNode1(ValidNode());

		//		AttachToFrontNodes(CreatedEdge1());
		//		AttachToMeshNodes(CreatedEdge1());
		//	}
		//}

	public:

		Aft2d_FrontInfoTemplate()
		{}

		void SetPaires()
		{
			SetPairedEdges();
		}

		template<class SizeMap>
		void UpdatePaires(const SizeMap& theSizeMap)
		{
			UpdateEdges(theSizeMap);
		}

		void CreateElement();

		void UpdateElement();

	};
}

#include <Aft2d_FrontInfoTemplateI.hxx>

#endif // !_Aft2d_FrontInfoTemplate_Header