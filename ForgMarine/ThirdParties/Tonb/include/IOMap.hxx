#pragma once
#ifndef _IOMap_Header
#define _IOMap_Header

#include <Map.hxx>
#include <regIOobject.hxx>

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						   Class IOMap Declaration
\*---------------------------------------------------------------------------*/

	template<class T>
	class IOMap
		: public regIOobject
		, public Map<T>
	{

	public:

		//- Runtime type information
		TypeName("Map");


		// Constructors

			//- Construct from IOobject
		IOMap(const IOobject&);

		//- Construct from IOobject and size of Map
		IOMap(const IOobject&, const label);

		//- Construct from IOobject and a Map
		IOMap(const IOobject&, const Map<T>&);

		//- Construct by transferring the Map contents
		IOMap(const IOobject&, const Xfer<Map<T>>&);


		// Destructor

		virtual ~IOMap();


		// Member functions

		bool writeData(Ostream&) const;


		// Member operators

			//- Assignment of other IOMap's entries to this IOMap
		void operator=(const IOMap<T>&);

		//- Assignment of other Map's entries to this IOMap
		void operator=(const Map<T>&);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#include <IOMapI.hxx>

#ifdef NoRepository
#   include <IOMap.cxx>
#endif

#endif // !_IOMap_Header
