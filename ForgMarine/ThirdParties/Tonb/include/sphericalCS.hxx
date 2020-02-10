#pragma once
#ifndef _sphericalCS_Header
#define _sphericalCS_Header

#include <coordinateSystem.hxx>
#include <Switch.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							 Class sphericalCS Declaration
	\*---------------------------------------------------------------------------*/

	class sphericalCS
		:
		public coordinateSystem
	{
		// Private data members

			//- Are angles in degrees? (default = true)
		Switch inDegrees_;


	protected:

		// Protected Member Functions

			//- Convert from local coordinate system to the global Cartesian system
			//  with optional translation for the origin
		virtual vector localToGlobal(const vector&, bool translate) const;

		//- Convert from local coordinate system to the global Cartesian system
		//  with optional translation for the origin
		virtual tmp<vectorField> localToGlobal
		(
			const vectorField&,
			bool translate
		) const;

		//- Convert from global Cartesian system to the local coordinate system
		//  with optional translation for the origin
		virtual vector globalToLocal(const vector&, bool translate) const;

		//- Convert from global Cartesian system to the local coordinate system
		//  with optional translation for the origin
		virtual tmp<vectorField> globalToLocal
		(
			const vectorField&,
			bool translate
		) const;

	public:

		//- Runtime type information
		TypeName("spherical");


		// Constructors

			//- Construct null
		sphericalCS(const bool inDegrees = true);

		//- Construct copy
		sphericalCS
		(
			const coordinateSystem&,
			const bool inDegrees = true
		);

		//- Construct copy with a different name
		sphericalCS
		(
			const word& name,
			const coordinateSystem&,
			const bool inDegrees = true
		);

		//- Construct from origin and rotation
		sphericalCS
		(
			const word& name,
			const point& origin,
			const coordinateRotation&,
			const bool inDegrees = true
		);

		//- Construct from origin and 2 axes
		sphericalCS
		(
			const word& name,
			const point& origin,
			const vector& axis,
			const vector& dirn,
			const bool inDegrees = true
		);

		//- Construct from dictionary
		sphericalCS(const word& name, const dictionary&);

		//- Return clone
		virtual autoPtr<coordinateSystem> clone() const
		{
			return autoPtr<coordinateSystem>(new sphericalCS(*this));
		}


		// Member Functions

			// Global information about the coordinate system

				//- Directions in which the span is limited
		virtual spanInfo spanLimited() const;

		//- Span bounds
		virtual boundBox spanBounds() const;


		//- Are angles in degrees?
		bool inDegrees() const;

		//- Non-const access to inDegrees
		Switch& inDegrees();


		// Write

			//- Write
		virtual void write(Ostream&) const;

		//- Write dictionary
		virtual void writeDict(Ostream&, bool subDict = true) const;
	};

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_sphericalCS_Header
