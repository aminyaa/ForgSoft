#pragma once
#ifndef _Marine_Graph_Header
#define _Marine_Graph_Header

#include <Marine_GraphEntity.hxx>
#include <Marine_GraphTitle.hxx>
#include <Marine_GraphAxis_X.hxx>
#include <Marine_GraphAxis_Y.hxx>

#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class Marine_GraphCurve;

	class Marine_Graph
		: public Marine_GraphEntity
	{

		/*Private Data*/

		Marine_GraphTitle theTitle_;
		
		Marine_GraphAxis_X theX_;
		Marine_GraphAxis_Y theY_;

		std::vector<std::shared_ptr<Marine_GraphCurve>> theCurves_;

	public:

		Marine_Graph();

		Marine_Graph
		(
			const Standard_Integer theIndex
		);

		Marine_Graph
		(
			const Standard_Integer theIndex,
			const word& theName
		);

		Standard_Integer NbCurves() const;

		const auto& X() const
		{
			return theX_;
		}

		auto& X()
		{
			return theX_;
		}

		const auto& Y() const
		{
			return theY_;
		}

		auto& Y()
		{
			return theY_;
		}

		const auto& Title() const
		{
			return theTitle_;
		}

		auto& Title()
		{
			return theTitle_;
		}

		auto& ChangeCurves()
		{
			return theCurves_;
		}

		const auto& Curves() const
		{
			return theCurves_;
		}


	};
}

#endif // !_Marine_Graph_Header
