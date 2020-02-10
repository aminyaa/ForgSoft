#pragma once
#ifndef _procLduInterface_Header
#define _procLduInterface_Header

#include <labelList.hxx>
#include <scalarField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	class lduInterfaceField;

	/*---------------------------------------------------------------------------*\
							   Class procLduInterface Declaration
	\*---------------------------------------------------------------------------*/

	class procLduInterface
	{
		// Private data

		labelList faceCells_;
		scalarField coeffs_;
		label myProcNo_;
		label neighbProcNo_;


		// Private member functions

			//- Dissallow construction as copy
		procLduInterface(const procLduInterface&);


	public:

		friend class LUscalarMatrix;


		// Constructors

		procLduInterface
		(
			const lduInterfaceField& interface,
			const scalarField& coeffs
		);

		procLduInterface(Istream& is);

		autoPtr<procLduInterface> clone()
		{
			notImplemented("procLduInterface::clone()");
			return autoPtr<procLduInterface>(NULL);
		}

		static autoPtr<procLduInterface> New(Istream& is)
		{
			return autoPtr<procLduInterface>(new procLduInterface(is));
		}


		// Ostream operator

		friend Ostream& operator<<(Ostream&, const procLduInterface&);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_procLduInterface_Header
