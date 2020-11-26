#pragma once
#ifndef _toroidalCS_Header
#define _toroidalCS_Header

#include <coordinateSystem.hxx>
#include <Switch.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{


	/*---------------------------------------------------------------------------*\
							Class toroidalCS Declaration
	\*---------------------------------------------------------------------------*/

	class toroidalCS
		:
		public coordinateSystem
	{
		// Private data

			//- Radius of the torus
		scalar radius_;

		//- Are angles in degrees? (default = true)
		Switch inDegrees_;


		// Private Member Functions

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
		TypeName("toroidal");


		// Constructors

			//- Construct from origin, rotation and radius
		toroidalCS
		(
			const word& name,
			const point& origin,
			const coordinateRotation&,
			const scalar radius,
			const bool inDegrees = true
		);


		//- Construct from dictionary
		toroidalCS(const word& name, const dictionary&);

		//- Return clone
		virtual autoPtr<coordinateSystem> clone() const
		{
			return autoPtr<coordinateSystem>(new toroidalCS(*this));
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

		//- Return radius
		scalar radius() const
		{
			return radius_;
		}

		//- Write
		virtual void write(Ostream&) const;

		//- Write dictionary
		virtual void writeDict(Ostream&, bool subDict = true) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_toroidalCS_header
