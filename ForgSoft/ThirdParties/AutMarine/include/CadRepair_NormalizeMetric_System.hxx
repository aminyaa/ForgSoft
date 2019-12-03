#pragma once
#ifndef _CadRepair_NormalizeMetric_System_Header
#define _CadRepair_NormalizeMetric_System_Header

#include <Standard_TypeDef.hxx>
#include <word.hxx>

#include <memory>
#include <error.hxx>

namespace AutLib
{

	// Forward Declarations
	class Numeric_AdaptIntegrationInfo;

	namespace cadRepairSys
	{

		extern std::shared_ptr<Numeric_AdaptIntegrationInfo> normalize_metric_intg_info;

		void InitRunTime();
	}

	class Metric_Surface_Failure
		: public error
	{

		/*Private Data*/

		Standard_Integer theIndex_;

		word theName_;

	public:

		Metric_Surface_Failure
		(
			const string& theTitle,
			const Standard_Integer theIndex,
			const word& theName
		)
			: error(theTitle)
			, theIndex_(theIndex)
			, theName_(theName)
		{}

		virtual ~Metric_Surface_Failure() throw()
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

		friend Ostream& operator<<(Ostream&, const Metric_Surface_Failure&);
	};


	extern Metric_Surface_Failure FatalMetricSurfError;
	

#define FatalMetricSurfErrorIn(fn, indx, name) FatalMetricSurfError(fn, __FILE__, __LINE__, indx, name)


	inline errorManipArg<Metric_Surface_Failure, int> exit(Metric_Surface_Failure& err, const int errNo = 1)
	{
		return errorManipArg<Metric_Surface_Failure, int>(&Metric_Surface_Failure::exit, err, errNo);
	}

	inline errorManip<Metric_Surface_Failure> abort(Metric_Surface_Failure& err)
	{
		return errorManip<Metric_Surface_Failure>(&Metric_Surface_Failure::abort, err);
	}

	
}

#endif // !_CadRepair_NormalizeMetric_System_Header
