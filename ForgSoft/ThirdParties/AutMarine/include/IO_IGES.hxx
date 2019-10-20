#pragma once
#ifndef _IO_IGES_Header
#define _IO_IGES_Header

#include <Global_Verbose.hxx>
#include <IO_Config.hxx>
#include <IO_Info.hxx>
#include <IO_Shape.hxx>

namespace AutLib
{
	class IO_IGES
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

		IO_IGES
		(
			const std::shared_ptr<FastDiscrete_Params>& theParams
		)
			: IO_Config(theParams)
		{}

		void ReadFile
		(
			const word& theFileName
		);
	};
}

#endif // !_IO_IGES_Header
