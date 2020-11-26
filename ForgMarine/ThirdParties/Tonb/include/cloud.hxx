#pragma once
#ifndef _cloud_Header
#define _cloud_Header

#include <objectRegistry.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of classes
	class mapPolyMesh;

	/*---------------------------------------------------------------------------*\
								Class cloud Declaration
	\*---------------------------------------------------------------------------*/

	class cloud
		: public objectRegistry
	{

		// Private Member Functions

			//- Disallow default bitwise copy construct
		cloud(const cloud&);

		//- Disallow default bitwise assignment
		void operator=(const cloud&);


	public:

		//- Runtime type information
		TypeName("cloud");

		//- The prefix to local: %lagrangian
		static const word prefix;

		//- The default cloud name: %defaultCloud
		static word defaultName;


		// Constructors

			//- Construct for the given objectRegistry and named cloud instance
		cloud(const objectRegistry&, const word& cloudName = "");


		//- Destructor
		virtual ~cloud();


		// Member Functions

			// Edit

				//- Remap the cells of particles corresponding to the
				//  mesh topology change
		virtual void autoMap(const mapPolyMesh&) = 0;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_cloud_Header
