#pragma once
#ifndef _CadRepair_ParaPlaneAR_System_Header
#define _CadRepair_ParaPlaneAR_System_Header

#include <Standard_TypeDef.hxx>
#include <word.hxx>

#include <memory>
#include <error.hxx>

namespace AutLib
{

	// Forward Declarations
	class CadRepair_ParaPlaneAR_Info;

	namespace cadRepairSys
	{

		extern std::shared_ptr<CadRepair_ParaPlaneAR_Info> gl_para_plane_ar_info;
	}

	class AR_ParaPlane_Failure
		: public error
	{

		/*Private Data*/

		Standard_Integer theIndex_;

		word theName_;

	public:

		AR_ParaPlane_Failure
		(
			const string& theTitle,
			const Standard_Integer theIndex,
			const word& theName
		)
			: error(theTitle)
			, theIndex_(theIndex)
			, theName_(theName)
		{}

		virtual ~AR_ParaPlane_Failure() throw()
		{}


		Standard_Integer Index() const
		{
			return theIndex_;
		}

		const word& Name() const
		{
			return theName_;
		}

		OSstream& operator()
			(
				const char* functionName,
				const char* sourceFileName,
				const int sourceFileLineNumber,
				const Standard_Integer theIndex,
				const word& theName
				);

		//- Exit : can be called for any error to exit program
		void exit(const int errNo = 1);

		//- Abort : used to stop code for fatal errors
		void abort();


		// Ostream operator

		friend Ostream& operator<<(Ostream&, const AR_ParaPlane_Failure&);
	};

	extern AR_ParaPlane_Failure FatalARParaPlaneError;

#define FatalArParaPlaneErrorIn(fn, indx, name) FatalARParaPlaneError(fn, __FILE__, __LINE__, indx, name)

	inline errorManipArg<AR_ParaPlane_Failure, int> exit(AR_ParaPlane_Failure& err, const int errNo = 1)
	{
		return errorManipArg<AR_ParaPlane_Failure, int>(&AR_ParaPlane_Failure::exit, err, errNo);
	}

	inline errorManip<AR_ParaPlane_Failure> abort(AR_ParaPlane_Failure& err)
	{
		return errorManip<AR_ParaPlane_Failure>(&AR_ParaPlane_Failure::abort, err);
	}
}

#endif // !_CadRepair_ParaPlaneAR_System_Header
