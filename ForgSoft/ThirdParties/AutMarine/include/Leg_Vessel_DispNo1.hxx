#pragma once
#ifndef _Leg_Vessel_DispNo1_Header
#define _Leg_Vessel_DispNo1_Header

#include <Leg_Model_Entity.hxx>
#include <Leg_Model_CtrlNet.hxx>
#include <Leg_DispNo1_Profiles.hxx>
#include <Leg_DispNo1_Parameters.hxx>
#include <Leg_Model_Displacement.hxx>
#include <Leg_Model_Surface.hxx>
#include <Leg_Model_SectionCtrlPts.hxx>

namespace AutLib
{

	class Leg_DispNo1_Base
	{

		/*Private Data*/

		Standard_Boolean ApplySmoothing_;

	protected:

		Leg_DispNo1_Base()
			: ApplySmoothing_(Standard_True)
		{}

	public:

		Standard_Boolean ApplySmoothing() const
		{
			return ApplySmoothing_;
		}

		Standard_Boolean& ChangeApplySmoothing()
		{
			return ApplySmoothing_;
		}
	};

	class Leg_DispNo1_Memory
		: public Leg_DispNo1_Profile
		, public Leg_DispNo1_Xparams
		, public Leg_Model_CtrlNet
	{

		/*Private Data*/

	protected:

		Leg_DispNo1_Memory()
		{}

	public:


	};


	class Leg_DispNo1_HullPatch
		: public Leg_Model_Displacement
		, public Leg_DispNo1_Parameters
		, public Leg_DispNo1_Base
		, public Leg_DispNo1_Memory
	{

		typedef Leg_Model_Displacement entity;
		typedef Leg_DispNo1_Parameters params;
		typedef Leg_DispNo1_Base base;
		typedef Leg_DispNo1_Memory memory;


		/*Private Data*/

		Leg_Model::geomSurface theHull_;


		//- Private functions and operators


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
			Leg_Model_CorneredSectionCtrlPts& theSection,
			const Standard_Real theTightness
		);

		void ApplyFlare
		(
			Standard_Integer theSection
		);

		void ApplyRake
		(
			Leg_Model_CorneredSectionCtrlPts& theSection,
			const Standard_Real theRake
		);


		//- Section constructors

		std::shared_ptr<Leg_Model_SectionCtrlPts> CreateRawSection
		(
			const Standard_Integer Section,
			const Standard_Integer nbWidth,
			const Standard_Integer nbHeight
		);

		std::shared_ptr<Leg_Model_SectionCtrlPts> CreateRawStem() const;

		std::shared_ptr<Leg_Model_SectionCtrlPts> CreateRawStemPaired();

		void CreateRawSections();


		//- Setup hull

		void SetupControlNet();

		void SetupPatch();

		void SetSection
		(
			const Standard_Integer Index,
			const std::shared_ptr<Leg_Model_SectionCtrlPts>& Section
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

		Leg_DispNo1_HullPatch()
		{}


	};
}

#endif // !_Leg_Vessel_DispNo1_Header
