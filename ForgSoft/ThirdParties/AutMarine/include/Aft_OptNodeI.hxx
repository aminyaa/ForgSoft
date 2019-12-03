#pragma once
#include <Aft_OptNode_Analytical.hxx>
#include <Aft_OptNode_Corrector.hxx>
namespace AutLib
{

	/*template<class FrontType, class SizeFun, class InfoAlg, class AnalyAlg, class CorrtAlg>
	void Aft_OptNode<FrontType, SizeFun, InfoAlg, void, AnalyAlg, CorrtAlg>::Perform()
	{
		auto IntP = std::make_shared<AnalyAlg>(ElementSize(), Front());
		IntP->Perform();

		Debug_If_Condition_Message
		(
			NOT IntP->IsDone(),
			"the Aft2d_OptNodeAnIso_Analytical algorithm has not been performed");
		const auto& P0 = IntP->Coord();

		auto Crt = 
			std::make_shared<CorrtAlg>
			(
				ElementSize(), 
				Front(), 
				P0, MetricMap(), Info()->CorrectorInfo());

		Crt->Perform();
		Debug_If_Condition_Message
		(
			NOT Crt->IsDone(),
			"the Corrector algorithm has not been performed");

		ChangeCoord() = Crt->Coord();
		ChangeAnalytical() = IntP;
		ChangeCorrector() = Crt;
	}*/

	/*template<class FrontType, class SizeFun>
	void Aft_OptNode<FrontType, SizeFun>::Perform()
	{
		auto IntP = 
			std::make_shared<Aft_OptNode_Analytical<FrontType, void>>(base::ElementSize(), base::Front());
		Debug_Null_Pointer(IntP);

		IntP->Perform();

		Debug_If_Condition_Message
		(
			NOT IntP->IsDone(),
			"the Aft2d_OptNodeAnIso_Analytical algorithm has not been performed");

		base::ChangeCoord() = IntP->Coord();
		base::Change_IsConverged() = Standard_True;

		Change_IsDone() = Standard_True;
	}*/

	template<class FrontType, class SizeFun, class OptTraits>
	void Aft_OptNode<FrontType, SizeFun, OptTraits, true>::Perform()
	{
		auto IntP =
			std::make_shared<Aft_OptNode_Analytical<FrontType, void>>(base::ElementSize(), base::Front());
		Debug_Null_Pointer(IntP);

		IntP->Perform();

		Debug_If_Condition_Message
		(
			NOT IntP->IsDone(),
			"the Aft2d_OptNodeAnIso_Analytical algorithm has not been performed");

		auto crt = 
			std::make_shared
			<
			Aft_OptNode_Corrector<(int)OptTraits::correctType,
			FrontType, typename OptTraits::infoType, SizeFun>>(*base::MetricMap(), base::Front(),IntP->Coord(), base::ElementSize());

		Debug_Null_Pointer(crt);

		crt->Perform();
		Debug_If_Condition_Message
		(
			NOT crt->IsDone(),
			"the Corrector algorithm has not been performed");

		base::ChangeCoord() = crt->Coord();
		base::Change_IsConverged() = crt->IsConverged();
	}
}