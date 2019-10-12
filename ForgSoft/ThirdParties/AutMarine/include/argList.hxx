#pragma once
#ifndef _argList_Header
#define _argList_Header

#include <sigFpe.hxx>
#include <sigInt.hxx>
#include <sigQuit.hxx>
#include <sigSegv.hxx>

#include <stringList.hxx>
#include <parRun.hxx>
#include <IStringStream.hxx>

namespace AutLib
{

	class argList
	{
		// Private data
		static bool bannerEnabled;

		stringList args_;
		HashTable<string> options_;

		word executable_;
		fileName rootPath_;
		fileName globalCase_;
		fileName case_;

		ParRunControl parRunControl_;

		// Signal handlers
		sigFpe sigFpe_;
		sigInt sigInt_;
		sigQuit sigQuit_;
		sigSegv sigSegv_;


		// Private member functions

		void getRootCase();

		//- Transcribe argv into internal args_
		//  return true if any "(" ... ")" sequences were captured
		bool regroupArgv(int& argc, char**& argv);


	public:

		// Static data members

		//- A list of valid (mandatory) arguments
		static SLList<string> validArgs;

		//- A list of valid options
		static HashTable<string> validOptions;

		//- A list of valid parallel options
		static HashTable<string> validParOptions;

		//- Name of the application-specific dictionary
		static word appDictName_;

		//! @cond ignoreDocumentation
		class initValidTables
		{
		public:

			initValidTables();
		};
		//! @endcond ignoreDocumentation


		// Constructors

		//- Construct from argc and argv
		//  checking the arguments and options as requested
		argList
		(
			int& argc,
			char**& argv,
			bool checkArgs = true,
			bool checkOpts = true
		);


		// Destructor

		virtual ~argList();


		// Member functions

		// Access

		//- Name of executable
		const word& executable() const
		{
			return executable_;
		}

		//- Return root path
		const fileName& rootPath() const
		{
			return rootPath_;
		}

		//- Return case name
		const fileName& globalCaseName() const
		{
			return globalCase_;
		}

		//- Return case name (parallel run) or global case (serial run)
		const fileName& caseName() const
		{
			return case_;
		}

		//- Return the path
		fileName path() const
		{
			return rootPath() / caseName();
		}

		//- Return arguments
		const stringList& args() const
		{
			return args_;
		}

		//- Return additionl arguments,
		//  i.e. those additional to the executable itself
		stringList::subList additionalArgs() const;

		//- Return options
		const HashTable<string>& options() const
		{
			return options_;
		}

		//- Return the argument string associated with the named option
		const string& option(const word& opt) const
		{
			return options_.operator[](opt);
		}

		//- Return true if the named option is found
		bool optionFound(const word& opt) const
		{
			return options_.found(opt);
		}

		//- Return an IStringStream to the named option
		IStringStream optionLookup(const word& opt) const
		{
			return IStringStream(option(opt));
		}

		//- Read a value from the named option
		template<class T>
		T optionRead(const word& opt) const
		{
			T val;
			optionLookup(opt)() >> val;
			return val;
		}

		//- Read a value from the named option if present.
		//  Return true if the named option was found.
		template<class T>
		bool optionReadIfPresent(const word& opt, T& val) const
		{
			if (optionFound(opt))
			{
				optionLookup(opt)() >> val;
				return true;
			}
			else
			{
				return false;
			}
		}

		//- Read a List of values from the named option
		template<class T>
		List<T> optionReadList(const word& opt) const
		{
			return readList<T>(optionLookup(opt)());
		}

		//- Return appDictName_
		const word appDictName() const
		{
			return appDictName_;
		}

		// Edit

		//- Disable emitting the banner information
		static void noBanner();

		//- Remove the parallel options
		static void noParallel();


		// Print

		//- Print usage
		void printUsage() const;

		//- Display documentation in browser
		//  Optionally display the application source code
		void displayDoc(bool source = false) const;


		// Check

		//- Check argument list
		bool check(bool checkArgs = true, bool checkOpts = true) const;

		//- Check root path and case path
		bool checkRootCase() const;

	};
}

#endif // !_argList_Header
