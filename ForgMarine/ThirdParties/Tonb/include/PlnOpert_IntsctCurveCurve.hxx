#pragma once
#ifndef _PlnOpert_IntsctCurveCurve_Header
#define _PlnOpert_IntsctCurveCurve_Header

#include <Global_AccessMethod.hxx>
#include <Standard_TypeDef.hxx>
#include <Global_Done.hxx>

#include <memory>
#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class PlnOpert_IntsctCurveCurve_Info;
	class Pln_Curve;
	class PlnOpert_IntsctPair;

	class PlnOpert_IntsctCurveCurve
		: public Global_Done
	{

		typedef PlnOpert_IntsctCurveCurve_Info info;

		/*Private Data*/

		std::shared_ptr<Pln_Curve> theCurve0_;
		std::shared_ptr<Pln_Curve> theCurve1_;

		std::shared_ptr<info> theInfo_;

		std::vector<std::shared_ptr<PlnOpert_IntsctPair>> theEntities_;


		//- private functions
		std::vector<std::shared_ptr<PlnOpert_IntsctPair>>& ChangeEntities()
		{
			return theEntities_;
		}

	public:

		PlnOpert_IntsctCurveCurve(const std::shared_ptr<info>& theInfo)
			: theInfo_(theInfo)
		{}

		PlnOpert_IntsctCurveCurve
		(
			const std::shared_ptr<Pln_Curve>& theCurve0,
			const std::shared_ptr<Pln_Curve>& theCurve1,
			const std::shared_ptr<info>& theInfo
		)
			: theCurve0_(theCurve0)
			, theCurve1_(theCurve1)
			, theInfo_(theInfo)
		{}

		auto NbEntities() const
		{
			return (Standard_Integer)theEntities_.size();
		}

		auto HasIntersection() const
		{
			return (Standard_Boolean)theEntities_.size();
		}

		const auto& Curve0() const
		{
			return theCurve0_;
		}

		const auto& Curve1() const
		{
			return theCurve1_;
		}

		const auto& Info() const
		{
			return theInfo_;
		}

		const auto& Entities() const
		{
			return theEntities_;
		}

		void Perform();

		void LoadCurve0(const std::shared_ptr<Pln_Curve>& theCurve)
		{
			theCurve0_ = theCurve;
		}

		void LoadCurve1(const std::shared_ptr<Pln_Curve>& theCurve)
		{
			theCurve1_ = theCurve;
		}

		void OverrideInfo(const std::shared_ptr<info>& theInfo)
		{
			theInfo_ = theInfo;
		}

		//- Macros
		
	};
}

#endif // !_PlnOpert_IntsctCurveCurve_Header
