#pragma once
#ifndef _profilingPool_Header
#define _profilingPool_Header

#include <regIOobject.hxx>
#include <profilingStack.hxx>
#include <clockTime.hxx>

#include <map>

namespace AutLib
{

	class profilingInfo;

	class profilingPool
		: public regIOobject
	{
		// Private typedefs

		typedef std::multimap<AutLib::string, AutLib::profilingInfo*> mapType;
		typedef std::pair<AutLib::string, AutLib::profilingInfo*> mapValues;
		typedef mapType::iterator mapIterator;
		typedef mapType::const_iterator mapConstIterator;


		// Private data

		mapType allInfo_;

		profilingStack theStack_;

		clockTime globalTime_;

		const Time &owner_;

		// Private Member Functions

		//- Disallow default bitwise copy construct
		profilingPool(const profilingPool&) = delete;

		//- Disallow default bitwise assignment
		void operator=(const profilingPool&) = delete;


		// Static data members

		//- The only possible Pool-Object
		static profilingPool *thePool_;


		// Constructors

		//- Construct null
		profilingPool
		(
			const IOobject&,
			const Time&
		);


		//- Destructor
		~profilingPool();


		// Member functions

		mapType& map()
		{
			return allInfo_;
		}

		const mapType& map() const
		{
			return allInfo_;
		}

		profilingStack& stack()
		{
			return theStack_;
		}

		const profilingStack& stack() const
		{
			return theStack_;
		}

		const Time& owner() const
		{
			return owner_;
		}

	protected:

		static void initProfiling
		(
			const IOobject&,
			const Time&
		);

		static void stopProfiling(const Time&);

	public:

		static profilingInfo& getInfo(const string& name);

		static void remove(const profilingInfo& info);

		static void rememberTimer(const profilingInfo& info, clockTime& timer);

		virtual bool writeData(Ostream&) const;

		friend class Time;
	};
}

#endif // !_profilingPool_Header
