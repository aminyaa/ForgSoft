#pragma once
#include <Global_Message.hxx>
#include <CadAnalys_ApprxSurfMetric.hxx>
#include <CadRepair_NormalizeMetric_System.hxx>
#include <Cad_Tools.hxx>
namespace AutLib
{

	template<class SurfType>
	Standard_Real CadRepair_NormalizeMetric<SurfType>::CalcMaxCharLengthU
	(
		intgInfo & theInfo
	) const
	{
		Debug_Null_Pointer(Surface());
		Debug_Null_Pointer(Metric());

		const auto& b = Metric()->Domain();

		const auto& P0 = b.P0();
		const auto& P1 = b.P1();

		const auto vmin = P0.Y();
		const auto vmax = P1.Y();

		const auto umin = P0.X();
		const auto du = (P1.X() - P0.X()) / (Standard_Real)Info()->NbSegmentsU();
		auto maxLen = (Standard_Real)0;

		forThose(Index, 0, Info()->NbSegmentsU())
		{
			auto x = umin + Index * du;

			Pnt2d Q0(x, vmin);
			Pnt2d Q1(x, vmax);

			auto len = Cad_Tools::CharLength(*Surface(), Q0, Q1, theInfo);

			if (len > maxLen) maxLen = len;
		}
		return maxLen;
	}

	template<class SurfType>
	Standard_Real CadRepair_NormalizeMetric<SurfType>::CalcMaxCharLengthV
	(
		intgInfo & theInfo
	) const
	{
		Debug_Null_Pointer(Surface());
		Debug_Null_Pointer(Metric());

		const auto& b = Metric()->Domain();

		const auto& P0 = b.P0();
		const auto& P1 = b.P1();

		const auto umin = P0.X();
		const auto umax = P1.X();

		const auto vmin = P0.Y();
		const auto dv = (P1.Y() - P0.Y()) / (Standard_Real)Info()->NbSegmentsV();
		auto maxLen = (Standard_Real)0;

		forThose(Index, 0, Info()->NbSegmentsV())
		{
			auto x = vmin + Index * dv;

			Pnt2d Q0(umin, x);
			Pnt2d Q1(umax, x);

			auto len = Cad_Tools::CharLength(*Surface(), Q0, Q1, theInfo);

			if (len > maxLen) maxLen = len;
		}
		return maxLen;
	}

	template<class SurfType>
	void CadRepair_NormalizeMetric<SurfType>::Perform()
	{
		if (Info()->Verbose())
		{
			GET_MESSAGE << " @ void CadRepair_NormalizeMetric<SurfType>::Perform()";
			SEND_INFO;
		}

		if (NOT Surface())
		{
			FatalErrorIn("void CadRepair_NormalizeMetric<SurfType>::Perform()") << endl
				<< " no surface has been loaded!" << endl
				<< abort(FatalError);
		}

		if (NOT Metric())
		{
			FatalErrorIn("void CadRepair_NormalizeMetric<SurfType>::Perform()") << endl
				<< " no metric approximation has been loaded!" << endl
				<< abort(FatalError);
		}

		if (NOT Metric()->MaxDet())
		{
			FatalErrorIn("void CadRepair_NormalizeMetric<SurfType>::Perform()") << endl
				<< " Invalid Data: max det = 0" << endl
				<< abort(FatalError);
		}

		if (Info()->Verbose())
		{
			GET_MESSAGE << " - the normalizing metric algorithm is applied if the maximum determinant ";
			SEND_INFO;

			GET_MESSAGE << "   of the metric surface be bigger than the criterion";
			SEND_INFO;

			GET_MESSAGE << "   criterion: " << Info()->MaxDet();
			SEND_INFO;

			GET_MESSAGE << "   max. of the determinant: " << Metric()->MaxDet();
			SEND_INFO;
		}

		if (Metric()->MaxDet() < Info()->MaxDet())
		{
			if (Info()->Verbose())
			{
				GET_MESSAGE << "  *****the surface needs no metric normalization**** ";
				SEND_INFO;

				GET_MESSAGE << "   continue...";
				SEND_INFO;
			}

			ChangeNormalized() = Surface();
		}
		else
		{

			if (NOT Info()->ToApply())
			{
				GET_MESSAGE << "  *****Normalization has not been permitted*****";
				SEND_INFO;

				FatalMetricSurfErrorIn
				(
					"void CadRepair_NormalizeMetric<SurfType>::Perform()",
					Surface()->Index(), Surface()->Name()
				)
					<< "  Normalization has not been permitted" << endl
					<< abort(FatalMetricSurfError);
			}

			if (Info()->Verbose())
			{
				GET_MESSAGE << "   going to normalize the surface metric...";
				SEND_INFO;
			}

			Debug_Null_Pointer(Info()->IntgInfo());
			const auto maxLu = CalcMaxCharLengthU(*Info()->IntgInfo());
			const auto maxLv = CalcMaxCharLengthV(*Info()->IntgInfo());

			const auto& b = Metric()->Domain();

			const auto& P0 = b.P0();
			const auto& P1 = b.P1();

			const auto du = P1.X() - P0.X();
			const auto dv = P1.Y() - P0.Y();

			const auto scale = MAX(maxLu, maxLv) / MAX(du, dv);

			if (Info()->Verbose())
			{
				GET_MESSAGE << "  scale: " << scale;
				SEND_INFO;
			}

			ChangeNormalized() = Cad_Tools::template ReParameterization<SurfType>(*Surface(), scale);

			ChangeApplied() = Standard_True;

			if (Info()->Verbose())
			{
				GET_MESSAGE << "   *****the normalization is done successfully!*****";
				SEND_INFO;

				GET_MESSAGE << "   continue...";
				SEND_INFO;
			}
		}

		Change_IsDone() = Standard_True;
	}
}