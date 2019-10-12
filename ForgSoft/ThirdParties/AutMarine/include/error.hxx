#pragma once
#ifndef _error_Header
#define _error_Header

#include <messageStream.hxx>

namespace AutLib
{

	class error
		: public std::exception
		, public messageStream
	{

	protected:

		// Protected data

		string functionName_;
		string sourceFileName_;
		label sourceFileLineNumber_;

		bool abort_;

		bool throwExceptions_;
		OStringStream* messageStreamPtr_;

	public:

		//- Construct from title string
		error(const string& title);

		//- Construct from dictionary
		error(const dictionary& errDict);

		//- Construct as copy
		error(const error& err);

		virtual ~error() throw();

		string message() const;

		const string& functionName() const
		{
			return functionName_;
		}

		const string& sourceFileName() const
		{
			return sourceFileName_;
		}

		label sourceFileLineNumber() const
		{
			return sourceFileLineNumber_;
		}

		void throwExceptions()
		{
			throwExceptions_ = true;
		}

		void dontThrowExceptions()
		{
			throwExceptions_ = false;
		}

		//- Convert to Ostream
		//  Prints basic message and then returns Ostream for further info.
		OSstream& operator()
			(
				const char* functionName,
				const char* sourceFileName,
				const int sourceFileLineNumber = 0
				);

		OSstream& operator()
			(
				const string& functionName,
				const char* sourceFileName,
				const int sourceFileLineNumber = 0
				);

		//- Convert to Ostream
		//  Prints basic message and then returns Ostream for further info.
		operator OSstream&();

		//- Explicitly convert to Ostream for << operations
		OSstream& operator()()
		{
			return operator OSstream&();
		}

		//- Create and return a dictionary
		operator dictionary() const;


		//- Helper function to print a stack
		static void printStack(Ostream& os);

		//- Exit : can be called for any error to exit program. Prints stack
		//  before exiting.
		void exit(const int errNo = 1);

		//- Abort : used to stop code for fatal errors. Prints stack before
		//  exiting.
		void abort();


		// Ostream operator

		friend Ostream& operator<<(Ostream&, const error&);
	};

	class IOerror
		: public error
	{

		// Private data

		string ioFileName_;
		label ioStartLineNumber_;
		label ioEndLineNumber_;

	public:

		//- Construct from title string
		IOerror(const string& title);

		//- Construct from dictionary
		IOerror(const dictionary& errDict);

		virtual ~IOerror() throw();

		const string& ioFileName() const
		{
			return ioFileName_;
		}

		label ioStartLineNumber() const
		{
			return ioStartLineNumber_;
		}

		label ioEndLineNumber() const
		{
			return ioEndLineNumber_;
		}

		//- Convert to Ostream
		//  Prints basic message and then returns Ostream for further info.
		OSstream& operator()
			(
				const char* functionName,
				const char* sourceFileName,
				const int sourceFileLineNumber,
				const string& ioFileName,
				const label ioStartLineNumber = -1,
				const label ioEndLineNumber = -1
				);

		//- Convert to Ostream
		//  Prints basic message and then returns Ostream for further info.
		OSstream& operator()
			(
				const char* functionName,
				const char* sourceFileName,
				const int sourceFileLineNumber,
				const IOstream&
				);

		//- Convert to Ostream
		//  Prints basic message and then returns Ostream for further info.
		OSstream& operator()
			(
				const char* functionName,
				const char* sourceFileName,
				const int sourceFileLineNumber,
				const dictionary&
				);

		//- Create and return a dictionary
		operator dictionary() const;


		//- Exit : can be called for any error to exit program
		void exit(const int errNo = 1);

		//- Abort : used to stop code for fatal errors
		void abort();


		// Ostream operator

		friend Ostream& operator<<(Ostream&, const IOerror&);
	};

	class NonConvergency_Iteration_Failure
		: public error
	{

		/*Private Data*/

		label nbIterations_;

	public:

		NonConvergency_Iteration_Failure(const string& title)
			: error(title)
		{}

		virtual ~NonConvergency_Iteration_Failure() throw()
		{}

		label NbIterations() const
		{
			return nbIterations_;
		}

		void SetNbIterations(const label theNbIterations)
		{
			nbIterations_ = theNbIterations;
		}

		OSstream& operator()
			(
				const char* functionName,
				const char* sourceFileName,
				const int sourceFileLineNumber,
				const label nbIterations
				);

		//- Exit : can be called for any error to exit program
		void exit(const int errNo = 1);

		//- Abort : used to stop code for fatal errors
		void abort();


		// Ostream operator

		friend Ostream& operator<<(Ostream&, const NonConvergency_Iteration_Failure&);
	};

	// Global error declarations: defined in error.C

	extern error FatalError;
	extern IOerror FatalIOError;

	extern error ThrowException;

	extern NonConvergency_Iteration_Failure IterFail;

	// Convienient macros to add the file name and line number to the function name

#define FatalErrorIn(fn) FatalError(fn, __FILE__, __LINE__)
#define FatalIOErrorIn(fn, ios) FatalIOError(fn, __FILE__, __LINE__, ios)
#define IterFailedIn(fn, nbIters) IterFail(fn, __FILE__, __LINE__, nbIters)


#include <errorM.hxx>

	// Call for functions which are not currently implemented.
	// The functionName is printed and then abort is called.
#define notImplemented(fn) \
    FatalErrorIn(fn) << "Not implemented" << AutLib::abort(FatalError);
}

#include <NonConvergency_Iteration_Failure.hxx>
#include <errorManip.hxx>

#endif // !_error_Header
