#pragma once
#ifndef _Leg_PropNo1_ChordForm_Header
#define _Leg_PropNo1_ChordForm_Header

#include <Global_AccessMethod.hxx>
#include <Leg_PropNo1_Form.hxx>
#include <Leg_Model_Parameter.hxx>

#include <memory>

namespace AutLib
{

	class Leg_PropNo1_ChordForm
		: public Leg_PropNo1_Form
	{

		typedef Leg_Model_Parameter parameter;

		/*Private Data*/

		std::shared_ptr<parameter> theRootChord_;
		std::shared_ptr<parameter> theTipChord_;

		std::shared_ptr<parameter> theMaxChord_;
		std::shared_ptr<parameter> theMaxChordLocation_;

		std::shared_ptr<parameter> theRootWeight_;
		std::shared_ptr<parameter> theTipWeight_;

	protected:

		void Defaults();

	public:

		Leg_PropNo1_ChordForm();

		GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, RootChord)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, TipChord)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, MaxChord)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, MaxChordLocation)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, RootWeight)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, TipWeight)
	};
}

#endif // !_Leg_PropNo1_ChordForm_Header
