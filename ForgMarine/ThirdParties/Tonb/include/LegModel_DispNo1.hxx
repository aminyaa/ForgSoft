#pragma once
#ifndef _LegModel_DispNo1_Header
#define _LegModel_DispNo1_Header

#include <LegModel_Displacement.hxx>
#include <LegModel_CtrlNet.hxx>
#include <LegModel_DispNo1_Parameters.hxx>
#include <LegModel_DispNo1_Profiles.hxx>
#include <LegModel_Displacement.hxx>
#include <LegModel_Surface.hxx>
#include <LegModel_SectionCtrlPts.hxx>

namespace tnbLib
{


	class LegModel_DispNo1_Memory
		: public LegModel_DispNo1_Profile
		, public LegModel_DispNo1_Xparams
		, public LegModel_CtrlNet
	{

		/*Private Data*/

	protected:

		LegModel_DispNo1_Memory()
		{}

	public:


	};

	class LegModel_DispNo1_HullPatch
		: public LegModel_Displacement
		, public LegModel_DispNo1_Parameters
		, public LegModel_DispNo1_Memory
	{

		typedef LegModel_Displacement entity;
		typedef LegModel_DispNo1_Parameters params;
		typedef LegModel_DispNo1_Memory memory;

		/*Private Data*/

		legModel::geomSurface theHull_;

	protected:

		void AllocateMemory();


		//- Create profiles

		void CreateDeckProfile();

		void CreateFlareProfile
		(
			const Standard_Integer theSection
		);

		void CreateFlareProfile();


		//- Calculate parameters

		void CalcxXSections();

		void CalcxYSections();

		void CalcxZSections();

		void CalcxDepthSections();

		void CalcxDeadRise();

		void CalcxFlare();

		void CalcxSideSlope();

		void CalcxTightness();

		void CalcxRake();

		void CalcXSheer();

		void CalcxParameters();


		//- Apply parameters

		void ApplyTightness();

		void ApplyFlare();

		void ApplyRake();

		void ApplyForeFootShape();

		void ApplyBowSmoothness();

		void ApplyParameters();

		void ApplyTightness
		(
			LegModel_CorneredSectionCtrlPts& theSection,
			const Standard_Real theTightness
		);

		void ApplyFlare
		(
			Standard_Integer theSection
		);

		void ApplyRake
		(
			LegModel_CorneredSectionCtrlPts& theSection,
			const Standard_Real theRake
		);


		//- Section constructors

		std::shared_ptr<LegModel_SectionCtrlPts> CreateRawSection
		(
			const Standard_Integer Section,
			const Standard_Integer nbWidth,
			const Standard_Integer nbHeight
		);

		std::shared_ptr<LegModel_SectionCtrlPts> CreateRawStem() const;

		std::shared_ptr<LegModel_SectionCtrlPts> CreateRawStemPaired();

		void CreateRawSections();


		//- Setup hull

		void SetupControlNet();

		void SetupPatch();

		void SetSection
		(
			const Standard_Integer Index,
			const std::shared_ptr<LegModel_SectionCtrlPts>& Section
		)
		{
			xSection[Index] = Section;
		}

		void SetControlPoint
		(
			const Standard_Integer I,
			const Standard_Integer J,
			const Pnt3d& Coord
		)
		{
			CtrlNet->SetValue(I + 1, J + 1, Coord);
		}

	protected:

		virtual void MakeFace();

	public:

		void Perform();

		void PerformToPreview() override;

		const legModel::geomSurface& Patch() const
		{
			return theHull_;
		}

		const params& Parameters() const
		{
			return *this;
		}

		params& Parameters()
		{
			return *this;
		}

		const LegModel_DispNo1_Dimensions& Dimensions() const
		{
			return *this;
		}

		LegModel_DispNo1_Dimensions& Dimensions()
		{
			return *this;
		}

		const LegModel_DispNo1_Xparams& Xparams() const
		{
			return *this;
		}
	};

	class LegModel_DispNo1
		: public LegModel_DispNo1_HullPatch
	{

		/*Private Data*/

	protected:

		void MakeFace() override;

	public:

		LegModel_DispNo1()
		{}

		void PerformToPreview() override;
	};
}

#endif // !_LegModel_DispNo1_Header
