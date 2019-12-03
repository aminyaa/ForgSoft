#pragma once
#ifndef _Leg_Model_DuctNo1_Header
#define _Leg_Model_DuctNo1_Header

#include <Global_AccessMethod.hxx>
#include <Leg_Model_Duct.hxx>
#include <Leg_Model_SectionCtrlPts.hxx>
#include <Leg_DuctNo1_Profiles.hxx>
#include <Leg_Model_CtrlNet.hxx>
#include <Leg_Model_Surface.hxx>

namespace AutLib
{

	// Forward Declarations
	class Pnt2d;
	class Leg_DuctNo1_Parameters;

	struct Leg_DuctNo1_Profile;
	struct Leg_DuctNo1_Xparams;

	class Leg_Model_DuctNo1_Base
	{

		/*Private Data*/

		Standard_Boolean ApplySmoothing_;

	protected:

		Leg_Model_DuctNo1_Base()
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

	class Leg_Model_DuctNo1_Memory
		: public Leg_DuctNo1_Profile
		, public Leg_DuctNo1_Xparams
		, public Leg_Model_CtrlNet

	{

		/*Private Data*/

		Leg_Model::sectionCPtsList theSections_;
		

	protected:

		Leg_Model_DuctNo1_Memory()
		{}

		Leg_Model::sectionCPtsList& ChangeSections()
		{
			return theSections_;
		}

	public:

	};

	class Leg_Model_DuctNo1
		: public Leg_Model_DuctNo1_Memory
		, public Leg_Model_DuctNo1_Base
		, public Leg_Model_Duct
	{

		/*Private Data*/	

		std::shared_ptr<Leg_DuctNo1_Parameters> theParameters_;

		Leg_Model::geomSurface theGeometry_;

	protected:

		void AllocateMemory();

		/* Create Profiles */

		void CreateBredthProfile();

		void CreateDepthProfile();

		void CreateProfiles();

		/* Calculate parameters*/

		void CalcxXSections();

		void CalcxYSections();

		void CalcxZSections();

		void CalcxDepth();

		void CalcxUpperTightness();

		void CalcxLowerTightness();

		void CalcxSideSlope();

		void CalcxWidth();

		void CalcxParameters();

		/* Section Constructors*/

		std::shared_ptr<Leg_Model_SectionCtrlPts> 
			CreateSection(const Standard_Integer Section) const;

		void CreateSections();

		/*Setup hull*/

		void SetupControlNet();

		void SetupPatch();

		void MakeFace();

	public:

		//- Macros

		GLOBAL_ACCESS_SINGLE(std::shared_ptr<Leg_DuctNo1_Parameters>, Parameters)
	};
}

#endif // !_Leg_Model_DuctNo1_Header
