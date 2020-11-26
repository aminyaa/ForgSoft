#pragma once
#ifndef _Marine_Model_Header
#define _Marine_Model_Header

#include <Marine_Entity.hxx>

#include <TopoDS_Shape.hxx>

namespace tnbLib
{

	// Forward Declarations
	class Marine_SectionDistribution;

	class Marine_Model
		: public Marine_Entity
	{

		/*Private Data*/

		TopoDS_Shape theModel_;

	protected:

		Marine_Model();

		Marine_Model(const Standard_Integer theIndex);

		Marine_Model(const Standard_Integer theIndex, const word& theName);

		auto& ChangeModel()
		{
			return theModel_;
		}

	public:

		const auto& Model() const
		{
			return theModel_;
		}

		virtual Standard_Boolean IsVessel() const
		{
			return Standard_False;
		}

	};
}

#endif // !_Marine_Model_Header
