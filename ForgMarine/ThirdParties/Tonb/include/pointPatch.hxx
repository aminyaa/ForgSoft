#pragma once
#ifndef _pointPatch_Header
#define _pointPatch_Header

#include <labelList.hxx>
#include <vectorField.hxx>
#include <triFaceList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of classes

	class pointBoundaryMesh;
	class pointConstraint;

	/*---------------------------------------------------------------------------*\
						  Class pointPatch Declaration
	\*---------------------------------------------------------------------------*/

	class pointPatch
	{
		// Private data

			//- Reference to boundary mesh
		const pointBoundaryMesh& boundaryMesh_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		pointPatch(const pointPatch&);

		//- Disallow default bitwise assignment
		void operator=(const pointPatch&);


	protected:

		// Protected Member Functions

			// The geometry initialisation is called by pointBoundaryMesh
		friend class pointBoundaryMesh;

		//- Initialise the calculation of the patch geometry
		virtual void initGeometry()
		{}

		//- Calculate the patch geometry
		virtual void calcGeometry()
		{}

		//- Correct patches after moving points
		virtual void movePoints()
		{}

		//- Initialise update of the patch topology
		virtual void initUpdateMesh()
		{}

		//- Update of the patch topology
		virtual void updateMesh()
		{}


	public:

		//- Runtime type information
		TypeName("basePatch");


		// Constructor

		pointPatch
		(
			const pointBoundaryMesh& bm
		)
			:
			boundaryMesh_(bm)
		{}


		// Destructor

		virtual ~pointPatch()
		{}


		// Member Functions

			//- Return name
		virtual const word& name() const = 0;

		//- Return size
		virtual label size() const = 0;

		//- Return the index of this patch in the pointBoundaryMesh
		virtual label index() const = 0;

		//- Return boundaryMesh reference
		const pointBoundaryMesh& boundaryMesh() const
		{
			return boundaryMesh_;
		}

		//- Return true if this patch field is coupled
		virtual bool coupled() const
		{
			return false;
		}

		//- Return mesh points
		virtual const labelList& meshPoints() const = 0;

		//- Return mesh points
		virtual const vectorField& localPoints() const = 0;

		//- Return  point normals
		virtual const vectorField& pointNormals() const = 0;

		//- Accumulate the effect of constraint direction of this patch
		virtual void applyConstraint
		(
			const label pointi,
			pointConstraint&
		) const
		{}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_pointPatch_Header
