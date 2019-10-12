#pragma once
#ifndef _messageStream_Header
#define _messageStream_Header

#include <autString.hxx>
#include <debugSwitch.hxx>

namespace AutLib
{

	class IOstream;
	class Ostream;
	class OSstream;
	class OStringStream;
	class dictionary;

	class messageStream
	{

	public:

		//- Severity flags
		enum errorSeverity
		{
			INFO,       // Debugging information in event of error
			WARNING,    // Warning of possible problem
			SERIOUS,    // A serious problem (data corruption?)
			FATAL       // Oh bugger!
		};

	protected:

		// Private data

		string title_;
		errorSeverity severity_;
		int maxErrors_;
		int errorCount_;

	public:

		// Debug switches

		static debug::debugSwitch level;

		//- Construct from components
		messageStream
		(
			const string& title,
			errorSeverity sev,
			const int maxErrors = 0
		);

		//- Construct from dictionary
		messageStream(const dictionary& dict);

		//- Return the title of this error type
		const string& title() const
		{
			return title_;
		}

		//- Return the maximum number of errors before program termination
		int maxErrors() const
		{
			return maxErrors_;
		}

		//- Return non-const access to the maximum number of errors before
		//  program termination to enable user to reset it
		int& maxErrors()
		{
			return maxErrors_;
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

		//- Convert to Ostream for << operations
		operator OSstream&();

		//- Explicitly convert to Ostream for << operations
		OSstream& operator()()
		{
			return operator OSstream&();
		}
	};

	// Global error declarations: defined in messageStream.C

	extern messageStream SeriousError;
	extern messageStream Warning;
	extern messageStream Info;

	// Convienient macros to add the file name and line number to the function name

#define SeriousErrorIn(fn) SeriousError(fn, __FILE__, __LINE__)
#define SeriousIOErrorIn(fn, ios) SeriousError(fn, __FILE__, __LINE__, ios)

#define WarningIn(fn) Warning(fn, __FILE__, __LINE__)
#define IOWarningIn(fn, ios) Warning(fn, __FILE__, __LINE__, ios)

#define InfoIn(fn) Info(fn, __FILE__, __LINE__)
#define IOInfoIn(fn, ios) Info(fn, __FILE__, __LINE__, ios)
}

#endif // !_messageStream_Header
