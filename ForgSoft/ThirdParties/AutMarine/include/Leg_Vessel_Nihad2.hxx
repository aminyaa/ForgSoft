#pragma once
#ifndef _Leg_Vessel_Nihad2_Header
#define _Leg_Vessel_Nihad2_Header

#include <Leg_Model_Entity.hxx>
#include <Leg_Model_CtrlNet.hxx>
#include <Leg_Nihad2_Profiles.hxx>
#include <Leg_Nihad2_Parameters.hxx>
#include <Leg_Model_Displacement.hxx>
#include <Leg_Model_Surface.hxx>
#include <Leg_Model_SectionCtrlPts.hxx>

namespace AutLib
{

	class Leg_Nihad2_Base
	{

		/*Private Data*/

		Standard_Boolean ApplySmoothing_;

	protected:

		Leg_Nihad2_Base()
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


	class Leg_Nihad2_Memory
		: public Leg_Nihad2_Profile
		, public Leg_Nihad2_Xparams
		, public Leg_Model_CtrlNet
	{

		/*Private Data*/

	protected:

		Leg_Nihad2_Memory()
		{}

	public:

	};


	class Leg_Nihad2_HullPatch
		: public Leg_Model_Displacement
		, public Leg_Nihad2_Parameters
		, public Leg_Nihad2_Base
		, public Leg_Nihad2_Memory
	{

		typedef Leg_Model_Displacement entity;
		typedef Leg_Nihad2_Parameters params;
		typedef Leg_Nihad2_Base base;
		typedef Leg_Nihad2_Memory memory;


		/*Private Data*/

		Leg_Model::geomSurface theHull_;


		//- Private functions and operators


		void AllocateMemory();


		//- Create profiles

		void CreateDeckProfile();


		//- Calculate parameters

		void CalcxXSections();

		void CalcxYSections();

		void CalcxZSections();

		void CalcxDepthSections();

		void CalcxDeadRise();

		void CalcxSideSlope();

		void CalcxTightness0();

		void CalcxTightness1();

		void CalcxTrim();

		void CalcxRake();

		void CalcXSheer();

		void CalcxParameters();


		//- Apply parameters

		void ApplyRake();

		void ApplyForeFootShape();

		void ApplyBowSmoothness();

		void ApplyParameters();

		void ApplyRake
		(
			Leg_Model_CorneredSectionCtrlPts& theSection,
			const Standard_Real theRake
		);


		//- Section constructors

		std::shared_ptr<Leg_Model_SectionCtrlPts> CreateRawSection
		(
			const Standard_Integer Section,
			const Standard_Real theTrimm,
			const Standard_Real theTightness1,
			const Standard_Real theTightness2
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

		Leg_Nihad2_HullPatch()
		{}


		void Perform();


		const Leg_Model::geomSurface& Patch() const
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

		const Leg_Nihad2_Dimensions& Dimensions() const
		{
			return *this;
		}

		Leg_Nihad2_Dimensions& Dimensions()
		{
			return *this;
		}

		const Leg_Nihad2_Xparams& Xparams() const
		{
			return *this;
		}
	};
}

#endif // !_Leg_Vessel_Nihad2_Header
