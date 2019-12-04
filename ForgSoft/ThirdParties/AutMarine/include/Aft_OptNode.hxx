#pragma once
#ifndef _Aft_OptNode_Header
#define _Aft_OptNode_Header

#include <Standard_TypeDef.hxx>
#include <Global_Done.hxx>
#include <Aft_OptNode_Calculator.hxx>

#include <memory>

namespace AutLib
{

	template
		<
		class FrontType,
		class SizeFun,
		class OptTraits = void,
		bool CorrAlg = false,
		class MetricFun = void,
		class AltrAlg = void
		>
		class Aft_OptNode
		: public Aft_OptNode_Calculator<FrontType, SizeFun, MetricFun>
	{

		typedef Aft_OptNode_Calculator<FrontType, SizeFun, MetricFun> base;
		typedef Aft_MetricPrcsr<FrontType, SizeFun, MetricFun>
			metricMap;
		typedef FrontType frontType;
		typedef MetricFun metricFun;
		typedef SizeFun sizeFun;

		typedef typename sizeFun::ptType Point;

		/*Private Data*/

	public:

		Aft_OptNode()
		{}

		void Perform() override;
	};

	template<class FrontType, class SizeFun>
	class Aft_OptNode<FrontType, SizeFun>
		: public Aft_OptNode_Calculator<FrontType, SizeFun, void>
	{

		typedef Aft_OptNode_Calculator<FrontType, SizeFun, void> base;
		typedef Aft_MetricPrcsr<FrontType, SizeFun, void>
			metricMap;
		typedef FrontType frontType;
		typedef SizeFun sizeFun;

		typedef typename sizeFun::ptType Point;

		/*Private Data*/


		//- private functions and operators

	public:

		Aft_OptNode()
		{}

		void Perform() override;
	};

	template<class FrontType, class SizeFun, class OptTraits>
	class Aft_OptNode<FrontType, SizeFun, OptTraits, true>
		: public Aft_OptNode_Calculator<FrontType, SizeFun, void>
	{

		typedef Aft_OptNode_Calculator<FrontType, SizeFun, void> base;
		typedef Aft_MetricPrcsr<FrontType, SizeFun, void>
			metricMap;
		typedef FrontType frontType;
		typedef SizeFun sizeFun;

		typedef typename sizeFun::ptType Point;

		/*Private Data*/


		//- private functions and operators

	public:

		Aft_OptNode()
		{}

		void Perform() override;
	};
}

#include <Aft_OptNodeI.hxx>

#endif // !_Mesh_AftOptNode_Header
