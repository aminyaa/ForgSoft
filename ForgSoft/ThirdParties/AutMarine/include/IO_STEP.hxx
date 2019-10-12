#pragma once
#ifndef _IO_STEP_Header
#define _IO_STEP_Header

#include <Global_Verbose.hxx>
#include <IO_Config.hxx>
#include <IO_Info.hxx>
#include <IO_Shape.hxx>

namespace AutLib
{

	class IO_STEP
		: public IO_Config
		, public IO_Info
		, public IO_Shape
		, public Global_Verbose
	{

		friend class boost::serialization::access;

		/*Private Data*/


		template<class Archive>
		void serialize(Archive& ar, const unsigned int version)
		{
			ar& boost::serialization::base_object<IO_Config>(*this);
			ar& boost::serialization::base_object<IO_Info>(*this);
			ar& boost::serialization::base_object<IO_Shape>(*this);
		}

		void doFixShape();

	public:

		IO_STEP
		(
			const std::shared_ptr<FastDiscrete_Params>& theParams
		)
			: IO_Config(theParams)
		{}

		void ReadFile
		(
			const word& theFileName
		);

		void ExportToPlt(OFstream& File) const;

	};
}

#endif // !_IO_STEP_Header
