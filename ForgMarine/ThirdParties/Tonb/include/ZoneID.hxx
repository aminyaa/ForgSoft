#pragma once
#ifndef _ZoneID_Header
#define _ZoneID_Header

#include <label.hxx>
#include <word.hxx>
#include <polyMesh.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<class ZoneType, class MeshType> class ZoneMesh;

	// Forward declaration of friend functions and operators

	template<class ZoneType> class ZoneID;

	template<class ZoneType>
	Ostream& operator<<(Ostream&, const ZoneID<ZoneType>&);

	/*---------------------------------------------------------------------------*\
							   Class ZoneID Declaration
	\*---------------------------------------------------------------------------*/

	template<class ZoneType>
	class ZoneID
	{
		// Private data

			//- Zone name
		word name_;

		//- Zone index
		label index_;


	public:

		// Constructors

			//- Construct from name
		ZoneID(const word& name, const ZoneMesh<ZoneType, polyMesh>& zm)
			:
			name_(name),
			index_(zm.findZoneID(name))
		{}

		//- Construct from Istream
		ZoneID(Istream& is, const ZoneMesh<ZoneType, polyMesh>& zm)
			:
			name_(is),
			index_(zm.findZoneID(name_))
		{}


		// Destructor - default


		// Member Functions

			// Access

				//- Return name
		const word& name() const
		{
			return name_;
		}

		//- Return index
		label index() const
		{
			return index_;
		}

		//- Has the zone been found
		bool active() const
		{
			return index_ > -1;
		}

		// Edit

			//- Update
		void update(const ZoneMesh<ZoneType, polyMesh>& zm)
		{
			index_ = zm.findZoneID(name_);
		}


		// IOstream Operators

		friend Ostream& operator<< <ZoneType>
			(
				Ostream& os, const ZoneID<ZoneType>& p
				);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	template<class ZoneType>
	Ostream& operator<<
		(
			Ostream& os, const ZoneID<ZoneType>& p
			)
	{
		os << token::BEGIN_LIST
			<< p.name_ << token::SPACE
			<< p.index_
			<< token::END_LIST;

		// Check state of Ostream
		os.check("Ostream& operator<<(Ostream&, const ZoneID<ZoneType>&)");

		return os;
	}


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_ZoneID_Header