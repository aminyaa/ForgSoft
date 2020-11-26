#pragma once
#ifndef _CadIO_STEP_Header
#define _CadIO_STEP_Header

#include <Global_Verbose.hxx>
#include <CadIO_Info.hxx>
#include <CadIO_Shape.hxx>

namespace tnbLib
{

	class CadIO_STEP
		: public CadIO_Info
		, public CadIO_Shape
		, public Global_Verbose
	{

		/*Private Data*/

	public:

		CadIO_STEP()
		{}

		void ReadFile
		(
			const fileName& theName
		);
	};
}

#endif // !_CadIO_STEP_Header
