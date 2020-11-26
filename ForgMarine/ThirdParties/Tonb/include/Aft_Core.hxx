#pragma once
#ifndef _Aft_Core_Header
#define _Aft_Core_Header

#include <Aft_Core_Base.hxx>

#include <memory>
#include <vector>

namespace tnbLib
{

	template
		<
		class OptNodeAlg, class SizeFun, 
		class FrontInfo, class FrontData,
		class MetricFun = void
		>
	class Aft_Core
		: public Aft_Core_Base
		<
		OptNodeAlg, FrontInfo,
		FrontData, SizeFun,
		MetricFun
		>
	{

	public:

		typedef Aft_Core_Base
			<
			OptNodeAlg, FrontInfo,
			FrontData, SizeFun,
			MetricFun
			>
			base;

		typedef typename base::nodeType nodeType;
		typedef typename base::frontType frontType;
		typedef typename base::elementType elementType;

		typedef typename nodeType::ptType Point;

		typedef Mesh_GlobalData<typename FrontInfo::elementType> 
			globalData;
		typedef FrontInfo frontInfo;
		typedef FrontData frontData;

		typedef Aft_MetricPrcsr<frontType, SizeFun, MetricFun> 
			metricMap;

		/*Private Data*/

	protected:

		void RetrieveLocalFrontNodes
		(
			std::vector<std::shared_ptr<nodeType>>& theLocals,
			std::vector<std::shared_ptr<nodeType>>& theSearching
		) const;

		void ModifyLocalFront
		(
			const Standard_Real theFactor
		);

		void UpdateFront();

	public:

		Aft_Core()
		{}

		Aft_Core
		(
			const std::shared_ptr<metricMap>& theSizeMap,
			const std::shared_ptr<OptNodeAlg>& theCoordCalculator
		)
			: base(theSizeMap, theCoordCalculator)
		{}
	};

	template
		<
		class OptNodeAlg, class SizeFun,
		class FrontInfo, class FrontData
		>
	class Aft_Core
		<
		OptNodeAlg, SizeFun,
		FrontInfo, FrontData,
		void
		>
		: public Aft_Core_Base
		<
		OptNodeAlg, FrontInfo,
		FrontData, SizeFun,
		void
		>
	{

	public:

		typedef Aft_Core_Base
			<
			OptNodeAlg, FrontInfo,
			FrontData, SizeFun,
			void
			>
			base;

		typedef typename base::nodeType nodeType;
		typedef typename base::frontType frontType;
		typedef typename base::elementType elementType;

		typedef typename nodeType::ptType Point;

		typedef Mesh_GlobalData<typename FrontInfo::elementType> 
			globalData;
		typedef FrontInfo frontInfo;
		typedef FrontData frontData;

		typedef Aft_MetricPrcsr<frontType, SizeFun, void> 
			metricMap;

		/*Private Data*/

	protected:

		void RetrieveLocalFrontNodes
		(
			std::vector<std::shared_ptr<nodeType>>& theLocals,
			std::vector<std::shared_ptr<nodeType>>& theSearching
		) const;

		void ModifyLocalFront
		(
			const Standard_Real theFactor
		);

		void UpdateFront();

	public:

		Aft_Core()
		{}

		Aft_Core
		(
			const std::shared_ptr<metricMap>& theSizeMap,
			const std::shared_ptr<OptNodeAlg>& theCoordCalculator
		)
			: base(theSizeMap, theCoordCalculator)
		{}
	};

}

#include <Aft_CoreI.hxx>

#endif // !_Aft_Core_Header