#pragma once
#ifndef _Leg_Nihad2_Parameters_Header
#define _Leg_Nihad2_Parameters_Header

#include <Global_AccessMethod.hxx>
#include <Leg_Model_Parameter.hxx>
#include <Leg_Model_ManipParams.hxx>

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class Leg_Nihad2_HullParams;

	class Leg_Nihad2_Dimensions
	{

		typedef Leg_Model_Parameter parameter;

		/*Private Data*/

		std::shared_ptr<parameter> theTransomHeight_;

		std::shared_ptr<parameter> theDepthAtBow_;
		std::shared_ptr<parameter> theDepthAtTransom_;

		std::shared_ptr<parameter> theBeamOnDeck_;
		std::shared_ptr<parameter> theLengthOnDeck_;

		Standard_Integer theNbNetColumns_;

	protected:

		Leg_Nihad2_Dimensions();

	public:

		Standard_Integer NbNetRows() const
		{
			return 9;
		}

			
		GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, TransomHeight)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, DepthAtBow)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, DepthAtTransom)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, BeamOnDeck)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, LengthOnDeck)

			GLOBAL_ACCESS_SINGLE(Standard_Integer, NbNetColumns)

	};


	class Leg_Nihad2_SectionParamsBase
	{

		typedef Leg_Model_Parameter parameter;

		/*Private Data*/

		std::shared_ptr<parameter> theDeadrise_;
		std::shared_ptr<parameter> theSideSlope_;
		std::shared_ptr<parameter> theTrim_;
		std::shared_ptr<parameter> theTightness0_;
		std::shared_ptr<parameter> theTightness1_;

	protected:

		Leg_Nihad2_SectionParamsBase()
		{}

		Leg_Nihad2_SectionParamsBase
		(
			const std::shared_ptr<parameter>& theDeadrise,
			const std::shared_ptr<parameter>& theSideSlope,
			const std::shared_ptr<parameter>& theTrim,
			const std::shared_ptr<parameter>& theTightness0, 
			const std::shared_ptr<parameter>& theTightness1
		)
			: theDeadrise_(theDeadrise)
			, theSideSlope_(theSideSlope)
			, theTrim_(theTrim)
			, theTightness0_(theTightness0)
			, theTightness1_(theTightness1)
		{}

	public:

		GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, Deadrise)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, SideSlope)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, Trim)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, Tightness0)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, Tightness1)
	};

	class Leg_Nihad2_AftSectionParams
		: public Leg_Nihad2_SectionParamsBase
	{

		friend class Leg_Nihad2_HullParams;

		/*Private Data*/

	protected:

		Leg_Nihad2_AftSectionParams();

	public:


	};

	class Leg_Nihad2_MidSectionParams
		: public Leg_Nihad2_SectionParamsBase
	{

		friend class Leg_Nihad2_HullParams;

		/*Private Data*/

	protected:

		Leg_Nihad2_MidSectionParams();

	public:

	};

	class Leg_Nihad2_FwdSectionParams
		: public Leg_Nihad2_SectionParamsBase
	{

		friend class Leg_Nihad2_HullParams;

		/*Private Data*/

	protected:

		Leg_Nihad2_FwdSectionParams();

	public:

	};

	class Leg_Nihad2_KeelParams
	{

		typedef Leg_Model_Parameter parameter;

		/*Private Data*/

		std::shared_ptr<parameter> thePosition_;
		std::shared_ptr<parameter> theRisePoint_;
		std::shared_ptr<parameter> theRiseSlope_;
		std::shared_ptr<parameter> theTransomSlope_;

	protected:

		Leg_Nihad2_KeelParams();

	public:

		GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, Position)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, RisePoint)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, RiseSlope)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, TransomSlope)
	};

	class Leg_Nihad2_StemParams
	{

		typedef Leg_Model_Parameter parameter;

		/*Private Data*/

		std::shared_ptr<parameter> theBowRounding_;
		std::shared_ptr<parameter> theStemRake_;
		std::shared_ptr<parameter> theForeFootShape_;

	protected:

		Leg_Nihad2_StemParams();

	public:

		GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, BowRounding)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, StemRake)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, ForeFootShape)
	};

	class Leg_Nihad2_TransomParams
	{

		typedef Leg_Model_Parameter parameter;

		/*Private Data*/

		std::shared_ptr<parameter> theRake_;
		std::shared_ptr<parameter> theWidth_;

	protected:

		Leg_Nihad2_TransomParams();

	public:

		GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, Rake)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, Width)
	};

	class Leg_Nihad2_HullParams
	{

		typedef Leg_Model_Parameter parameter;

		/*Private Data*/

		Leg_Nihad2_AftSectionParams theAftSection_;
		Leg_Nihad2_MidSectionParams theMidSection_;
		Leg_Nihad2_FwdSectionParams theFwdSection_;

		std::shared_ptr<parameter> theMaxAreaLocation_;
		std::shared_ptr<parameter> theFwdFullness_;
		std::shared_ptr<parameter> theAftFullness_;
		std::shared_ptr<parameter> theExtrude_;

	protected:

		Leg_Nihad2_HullParams();

	public:

		GLOBAL_ACCESS_SINGLE(Leg_Nihad2_AftSectionParams, AftSection)
			GLOBAL_ACCESS_SINGLE(Leg_Nihad2_MidSectionParams, MidSection)
			GLOBAL_ACCESS_SINGLE(Leg_Nihad2_FwdSectionParams, FwdSection)

			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, MaxAreaLocation)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, FwdFullness)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, AftFullness)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, Extrude)
	};


	class Leg_Nihad2_Parameters
		: public Leg_Nihad2_Dimensions
		, public Leg_Nihad2_HullParams
		, public Leg_Nihad2_StemParams
		, public Leg_Nihad2_KeelParams
		, public Leg_Nihad2_TransomParams
	{

		/*Private Data*/

	public:

		Leg_Nihad2_Parameters()
		{}
	};
}

#endif // !_Leg_Nihad2_Parameters_Header
