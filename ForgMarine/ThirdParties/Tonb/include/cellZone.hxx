#pragma once
#ifndef _cellZone_Header
#define _cellZone_Header

#include <labelList.hxx>
#include <typeInfo.hxx>
#include <dictionary.hxx>
#include <cellZoneMeshFwd.hxx>
#include <pointFieldFwd.hxx>
#include <Map.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of friend functions and operators

	class cellZone;
	Ostream& operator<<(Ostream&, const cellZone&);


	/*---------------------------------------------------------------------------*\
							   Class cellZone Declaration
	\*---------------------------------------------------------------------------*/

	class cellZone
		: public labelList
	{
		// Private data

			//- Name of zone
		word name_;

		//- Index of zone
		label index_;

		//- Reference to zone list
		const cellZoneMesh& zoneMesh_;

		// Demand-driven private data

			//- Map of cell labels in zone for fast location lookup
		mutable Map<label>* cellLookupMapPtr_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		cellZone(const cellZone&);

		//- Return map of local cell indices
		const Map<label>& cellLookupMap() const;

		//- Build map of local cell indices
		void calcCellLookupMap() const;


	public:

		//- Runtime type information
		TypeName("cellZone");


		// Declare run-time constructor selection tables

		declareRunTimeSelectionTable
		(
			autoPtr,
			cellZone,
			dictionary,
			(
				const word& name,
				const dictionary& dict,
				const label index,
				const cellZoneMesh& zm
				),
				(name, dict, index, zm)
		);


		// Constructors

			//- Construct from components
		cellZone
		(
			const word& name,
			const labelList& addr,
			const label index,
			const cellZoneMesh&
		);

		//- Construct from components, transferring contents
		cellZone
		(
			const word& name,
			const Xfer<labelList>& addr,
			const label index,
			const cellZoneMesh&
		);

		//- Construct from dictionary
		cellZone
		(
			const word& name,
			const dictionary&,
			const label index,
			const cellZoneMesh&
		);

		//- Construct given the original zone and resetting the
		//  cell list and zone mesh information
		cellZone
		(
			const cellZone&,
			const labelList& addr,
			const label index,
			const cellZoneMesh&
		);

		//- Construct given the original zone, resetting the
		//  cell list and zone mesh information
		cellZone
		(
			const cellZone&,
			const Xfer<labelList>& addr,
			const label index,
			const cellZoneMesh&
		);

		//- Construct and return a clone, resetting the zone mesh
		virtual autoPtr<cellZone> clone(const cellZoneMesh& zm) const
		{
			return autoPtr<cellZone>
				(
					new cellZone(*this, *this, index(), zm)
					);
		}

		//- Construct and return a clone, resetting the cell list
		//  and zone mesh
		virtual autoPtr<cellZone> clone
		(
			const labelList& addr,
			const label index,
			const cellZoneMesh& zm
		) const
		{
			return autoPtr<cellZone>
				(
					new cellZone(*this, addr, index, zm)
					);
		}


		// Selectors

			//- Return a pointer to a new cell zone
			//  created on freestore from dictionary
		static autoPtr<cellZone> New
		(
			const word& name,
			const dictionary&,
			const label index,
			const cellZoneMesh&
		);


		//- Destructor

		virtual ~cellZone();


		// Member Functions

			//- Return name
		const word& name() const
		{
			return name_;
		}

		//- Map storing the local cell index for every global cell
		//  index.  Used to find out the index of cell in the zone from
		//  the known global cell index.  If the cell is not in the
		//  zone, returns -1
		label whichCell(const label globalCellID) const;

		//- Return the index of this zone in zone list
		label index() const
		{
			return index_;
		}

		//- Return zoneMesh reference
		const cellZoneMesh& zoneMesh() const;

		//- Clear addressing
		void clearAddressing();

		//- Check zone definition. Return true if in error.
		bool checkDefinition(const bool report = false) const;

		//- Correct patch after moving points
		virtual void movePoints(const pointField&)
		{}

		//- Correct after topology update  Note: Zone has been rebuilt
		//  and no mapping is required.  HJ, 1/Mar/2009
		void updateMesh();

		//- Write
		virtual void write(Ostream&) const;

		//- Write dictionary
		virtual void writeDict(Ostream&) const;


		// Member Operators

			//- Assign to zone clearing demand-driven data
		void operator=(const cellZone&);

		//- Assign addressing clearing demand-driven data
		void operator=(const labelList&);


		// Ostream Operator

		friend Ostream& operator<<(Ostream&, const cellZone&);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_cellZone_Header
