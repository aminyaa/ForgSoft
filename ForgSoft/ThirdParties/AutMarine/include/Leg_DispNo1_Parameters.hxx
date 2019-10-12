#pragma once
#ifndef _Leg_DispNo1_Parameters_Header
#define _Leg_DispNo1_Parameters_Header

#include <Global_AccessMethod.hxx>
#include <Leg_Model_Parameter.hxx>
#include <Leg_Model_ManipParams.hxx>

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class Leg_DispNo1_HullParams;

	class Leg_DispNo1_Dimensions
	{

		typedef Leg_Model_Parameter parameter;

		/*Private Data*/

		std::shared_ptr<parameter> theDraft_;
		std::shared_ptr<parameter> theTransomHeight_;

		std::shared_ptr<parameter> theDepthAtBow_;
		std::shared_ptr<parameter> theDepthAtTransom_;

		std::shared_ptr<parameter> theBeamOnDeck_;
		std::shared_ptr<parameter> theLengthOnDeck_;

		Standard_Integer theNbNetRows_;
		Standard_Integer theNbNetColumns_;

	protected:

		Leg_DispNo1_Dimensions()
		{}

	public:


		GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, Draft)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, TransomHeight)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, DepthAtBow)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, DepthAtTransom)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, BeamOnDeck)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, LengthOnDeck)

			GLOBAL_ACCESS_SINGLE(Standard_Integer, NbNetRows)
			GLOBAL_ACCESS_SINGLE(Standard_Integer, NbNetColumns)
	};


	class Leg_DispNo1_SectionParamsBase
	{

		typedef Leg_Model_Parameter parameter;

		/*Private Data*/

		std::shared_ptr<parameter> theTightness_;
		std::shared_ptr<parameter> theDeadrise_;
		std::shared_ptr<parameter> theSideSlope_;
		std::shared_ptr<parameter> theFlare_;


	protected:

		Leg_DispNo1_SectionParamsBase()
		{}

	public:

		GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, Tightness)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, Deadrise)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, SideSlope)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, Flare)
	};


	class Leg_DispNo1_AftSectionParams
		: public Leg_DispNo1_SectionParamsBase
	{

		friend class Leg_DispNo1_HullParams;

		/*Private Data*/

	protected:

		Leg_DispNo1_AftSectionParams()
		{}

	public:

	};


	class Leg_DispNo1_MidSectionParams
		: public Leg_DispNo1_SectionParamsBase
	{

		friend class Leg_DispNo1_HullParams;

		/*Private Data*/

	protected:

		Leg_DispNo1_MidSectionParams()
		{}

	public:


	};

	class Leg_DispNo1_FwdSectionParams
		: public Leg_DispNo1_SectionParamsBase
	{

		friend class Leg_DispNo1_HullParams;

		/*Private Data*/

	protected:

		Leg_DispNo1_FwdSectionParams()
		{}

	public:


	};


	class Leg_DispNo1_KeelParams
	{

		typedef Leg_Model_Parameter parameter;

		/*Private Data*/

		std::shared_ptr<parameter> thePosition_;
		std::shared_ptr<parameter> theRisePoint_;
		std::shared_ptr<parameter> theRiseSlope_;
		std::shared_ptr<parameter> theTransomSlope_;

	protected:

		Leg_DispNo1_KeelParams()
		{}

	public:

		GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, Position)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, RisePoint)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, RiseSlope)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, TransomSlope)

	};


	class Leg_DispNo1_StemParams
	{

		typedef Leg_Model_Parameter parameter;

		/*Private Data*/

		std::shared_ptr<parameter> theBowRounding_;
		std::shared_ptr<parameter> theStemRake_;
		std::shared_ptr<parameter> theForeFootShape_;

	protected:

		Leg_DispNo1_StemParams()
		{}

	public:

		GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, BowRounding)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, StemRake)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, ForeFootShape)
	};


	class Leg_DispNo1_TransomParams
	{

		typedef Leg_Model_Parameter parameter;

		/*Private Data*/

		std::shared_ptr<parameter> theRake_;
		std::shared_ptr<parameter> theWidth_;

	protected:

		Leg_DispNo1_TransomParams()
		{}

	public:

		GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, Rake)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, Width)
	};


	class Leg_DispNo1_HullParams
	{

		typedef Leg_Model_Parameter parameter;

		/*Private Data*/

		Leg_DispNo1_AftSectionParams theAftSection_;
		Leg_DispNo1_MidSectionParams theMidSection_;
		Leg_DispNo1_FwdSectionParams theFwdSection_;

		std::shared_ptr<parameter> theMaxAreaLocation_;
		std::shared_ptr<parameter> theFwdFullness_;
		std::shared_ptr<parameter> theAftFullness_;

	protected:

		Leg_DispNo1_HullParams()
		{}

	public:

		GLOBAL_ACCESS_SINGLE(Leg_DispNo1_AftSectionParams, AftSection)
			GLOBAL_ACCESS_SINGLE(Leg_DispNo1_MidSectionParams, MidSection)
			GLOBAL_ACCESS_SINGLE(Leg_DispNo1_FwdSectionParams, FwdSection)

			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, MaxAreaLocation)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, FwdFullness)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, AftFullness)
	};


	class Leg_DispNo1_Parameters
		: public Leg_DispNo1_Dimensions
		, public Leg_DispNo1_HullParams
		, public Leg_DispNo1_StemParams
		, public Leg_DispNo1_KeelParams
		, public Leg_DispNo1_TransomParams
	{

		/*Private Data*/

	public:

		Leg_DispNo1_Parameters()
		{}
	};
}

#endif // !_Leg_DispNo1_Parameters_Header
