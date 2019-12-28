#pragma once
#include <Global_Message.hxx>
#include <CadRepair_ParaPlaneAR_System.hxx>
#include <Cad_Tools.hxx>
namespace AutLib
{

	template<class SurfType>
	std::pair<Standard_Integer, Standard_Real> 
		CadRepair_ParaPlaneAR<SurfType>::CalcMaxAR
		(
			const SurfType & theSurface
		)
	{
		const auto& box = theSurface.BoundingBox();

		const auto& P0 = box.P0();
		const auto& P1 = box.P1();

		auto dx = P1.X() - P0.X();
		auto dy = P1.Y() - P0.Y();

		if (dy > dx)
		{
			auto p = std::make_pair(0, dy / dx);
			return std::move(p);
		}
		else
		{
			auto p = std::make_pair(1, dx / dy);
			return std::move(p);
		}
	}

	template<class SurfType>
	void CadRepair_ParaPlaneAR<SurfType>::Perform()
	{
		if (Info()->Verbose())
		{
			GET_MESSAGE << " @ void CadRepair_ParaPlaneAR<SurfType>::Perform()";
			SEND_INFO;
		}

		if (NOT Surface())
		{
			FatalErrorIn("void Perform()")
				<< "No surface has been loaded!" << endl
				<< abort(FatalError);
		}

		const auto ar = CalcMaxAR(*Surface());

		if (Info()->Verbose())
		{
			GET_MESSAGE << " - the surface is modified if it's AR be less than the criterion";
			SEND_INFO;

			GET_MESSAGE << "   criterion: " << Info()->AR();
			SEND_INFO;

			GET_MESSAGE << "   max. of the AR: " << ar.second;
			SEND_INFO;
		}

		if (ar.second <= Info()->AR())
		{
			if (Info()->Verbose())
			{
				GET_MESSAGE << "  *****the surface is received no modification****";
				SEND_INFO;
			}
			
			ChangeModified() = Surface();		
		}
		else
		{
			if (NOT Info()->ToApply())
			{
				GET_MESSAGE << "   *****AR modification is not permitted****";
				SEND_INFO;

				FatalArParaPlaneErrorIn("void CadRepair_ParaPlaneAR<SurfType>::Perform()", Surface()->Index(), Surface()->Name())
					<< "  AR modification is not permitted" << endl
					<< abort(FatalARParaPlaneError);
			}

			ChangeApplied() = Standard_True;

			if (ar.first)
			{
				ChangeModified() = Cad_Tools::template ReParameterization_vExpand(*Surface(), ar.second / Info()->AR());
			}
			else
			{
				ChangeModified() = Cad_Tools::template ReParameterization_uExpand(*Surface(), ar.second / Info()->AR());
			}
		}

		Change_IsDone() = Standard_True;
	}
}