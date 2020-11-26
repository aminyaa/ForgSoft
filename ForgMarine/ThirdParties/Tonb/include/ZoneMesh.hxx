#pragma once
#ifndef _ZoneMesh_Header
#define _ZoneMesh_Header

#include <List.hxx>
#include <regIOobject.hxx>
#include <HashSet.hxx>
#include <pointFieldFwd.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	// Forward declaration of friend functions and operators
	template<class T>
	class Map;

	template<class ZoneType, class MeshType> class ZoneMesh;

	template<class ZoneType, class MeshType>
	Ostream& operator<<(Ostream&, const ZoneMesh<ZoneType, MeshType>&);

	/*---------------------------------------------------------------------------*\
							   Class ZoneMesh Declaration
	\*---------------------------------------------------------------------------*/

	template<class ZoneType, class MeshType>
	class ZoneMesh
		:
		public PtrList<ZoneType>,
		public regIOobject
	{
		// Private data

			//- Reference to mesh
		const MeshType& mesh_;

		//- Map of zone labels for given element
		mutable Map<label>* zoneMapPtr_;


		// Private member functions

			//- Disallow construct as copy
		ZoneMesh(const ZoneMesh&);

		//- Disallow assignment
		void operator=(const ZoneMesh<ZoneType, MeshType>&);


		//- Create zone map
		void calcZoneMap() const;

		//- Clear addressing
		void clearAddressing();


	public:

		// Constructors

			//- Read constructor given IOobject and a MeshType reference
		ZoneMesh
		(
			const IOobject&,
			const MeshType&
		);

		//- Construct given size
		ZoneMesh
		(
			const IOobject&,
			const MeshType&,
			const label size
		);

		// Destructor

		~ZoneMesh();


		// Member functions

			//- Return the mesh reference
		const MeshType& mesh() const
		{
			return mesh_;
		}

		//- Map of zones containing zone index for all zoned elements
		//  Return -1 if the object is not in the zone
		const Map<label>& zoneMap() const;

		//- Given a global object index, return the zone it is in.  If
		//  object does not belong to any zones, return -1
		label whichZone(const label objectIndex) const;

		//- Return a list of zone types
		wordList types() const;

		//- Return a list of zone names
		wordList names() const;

		//- Find zone index given a name
		label findZoneID(const word& zoneName) const;

		//- Clear the zones
		void clear();

		//- Check zone definition. Return true if in error.
		bool checkDefinition(const bool report = false) const;

		//- Correct zone mesh after moving points
		void movePoints(const pointField&);

		//- Correct after topology update
		void updateMesh();

		//- writeData member function required by regIOobject
		bool writeData(Ostream&) const;


		// Ostream operator

		friend Ostream& operator<< <ZoneType, MeshType>
			(
				Ostream&,
				const ZoneMesh<ZoneType, MeshType>&
				);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <ZoneMesh.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_ZoneMesh_Header
