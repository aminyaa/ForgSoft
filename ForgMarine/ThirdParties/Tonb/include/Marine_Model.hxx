#pragma once
#ifndef _Marine_Model_Header
#define _Marine_Model_Header

#include <Marine_Entity.hxx>

namespace tnbLib
{

	// Forward Declarations
	class Cad3d_TModel;

	class Marine_Model
		: public Marine_Entity
	{

		/*Private Data*/

		std::shared_ptr<Cad3d_TModel> theModel_;

	protected:

		Marine_Model();

		Marine_Model(const Standard_Integer theIndex);

		Marine_Model(const Standard_Integer theIndex, const word& theName);

	public:

		const auto& Model() const
		{
			return theModel_;
		}
	};
}

#endif // !_Marine_Model_Header
