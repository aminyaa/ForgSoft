#pragma once
/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | foam-extend: Open Source CFD
   \\    /   O peration     | Version:     4.0
	\\  /    A nd           | Web:         http://www.foam-extend.org
	 \\/     M anipulation  | For copyright notice see file Copyright
-------------------------------------------------------------------------------
License
	This file is part of foam-extend.

	foam-extend is free software: you can redistribute it and/or modify it
	under the terms of the GNU General Public License as published by the
	Free Software Foundation, either version 3 of the License, or (at your
	option) any later version.

	foam-extend is distributed in the hope that it will be useful, but
	WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with foam-extend.  If not, see <http://www.gnu.org/licenses/>.

Class
	tnbLib::profilingPool

Description
	Collects all the data for profiling

SourceFiles
	profilingPool.C

\*---------------------------------------------------------------------------*/
#ifndef _profilingPool_Header
#define _profilingPool_Header

#include <regIOobject.hxx>
#include <clockTime.hxx>

#include <profilingInfo.hxx>
#include <profilingStack.hxx>

#include <map>

namespace tnbLib
{

	// Forward declaration of classes
// class Istream;
	class Ostream;

	// // Forward declaration of friend functions and operators
	// Istream& operator>>(Istream&, profilingPool&);
	// Ostream& operator<<(Ostream&, const profilingPool&);


	/*---------------------------------------------------------------------------*\
							   Class profilingPool Declaration
	\*---------------------------------------------------------------------------*/

	class profilingPool
		: public regIOobject
	{
		// Private typedefs

		typedef std::multimap<tnbLib::string, tnbLib::profilingInfo*> mapType;
		typedef std::pair<tnbLib::string, tnbLib::profilingInfo*> mapValues;
		typedef mapType::iterator mapIterator;
		typedef mapType::const_iterator mapConstIterator;


		// Private data

		mapType allInfo_;

		profilingStack theStack_;

		clockTime globalTime_;

		const Time &owner_;

		// Private Member Functions

			//- Disallow default bitwise copy construct
		profilingPool(const profilingPool&);

		//- Disallow default bitwise assignment
		void operator=(const profilingPool&);


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


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#endif // !_profilingPool_Header
