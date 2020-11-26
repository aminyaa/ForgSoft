#pragma once
#ifndef _LegModel_CtrlNet_Header
#define _LegModel_CtrlNet_Header

#include <LegModel_SectionCtrlPts.hxx>

namespace tnbLib
{

	struct LegModel_CtrlNet
	{
		std::shared_ptr<legModel::ctrlNet> CtrlNet;
	};

	struct LegModel_WeightNet
	{
		std::shared_ptr<legModel::weightNet> WeightNet;
	};
}

#endif // !_LegModel_CtrlNet_Header
