#pragma once
namespace AutLib
{

	template<class FrontType, class SizeFun, class InfoAlg, class AnalyAlg, class CorrtAlg>
	void Mesh_AftOptNode_Calculator<FrontType, SizeFun, InfoAlg, void, AnalyAlg, CorrtAlg>::Perform()
	{
		auto IntP = std::make_shared<AnalyAlg>(ElementSize(), Front());
		IntP->Perform();

		Debug_If_Condition_Message
		(
			NOT IntP->IsDone(),
			"the Mesh2d_OptNodeAnIso_Analytical algorithm has not been performed");
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
	}
}