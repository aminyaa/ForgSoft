#pragma once
#ifndef _cellModeller_Header
#define _cellModeller_Header

#include <cellModel.hxx>
#include <PtrList.hxx>
#include <HashTable.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							Class cellModeller Declaration
	\*---------------------------------------------------------------------------*/

	class cellModeller
	{
		// Private data

			//- PtrList of models
		static PtrList<cellModel> models_;

		//- List of model pointers
		static List<cellModel*> modelPtrs_;

		//- HashTable of model pointers
		static HashTable<const cellModel*> modelDictionary_;


	public:

		// Constructors

			//- Construct from central "cellModels" file
		cellModeller();

		// Destructor

		~cellModeller();


		// Member functions

			//- Look up a model by name and return a pointer to the model or NULL
		static const cellModel* lookup(const word&);

		//- Look up a model by index and return a pointer to the model or NULL
		static const cellModel* lookup(const label i)
		{
			return modelPtrs_[i];
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_cellModeller_Header
