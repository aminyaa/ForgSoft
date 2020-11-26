#pragma once
#ifndef _Entity3d_TetrahedralizationTools_Header
#define _Entity3d_TetrahedralizationTools_Header

#include <Standard_TypeDef.hxx>

#include <utility>

namespace tnbLib
{

	class Entity3d_TetrahedralizationTools
	{

		/*Private Data*/

	public:

		typedef std::pair<Standard_Integer, Standard_Integer> edgeConnectivity;
		typedef std::tuple<Standard_Integer, Standard_Integer, Standard_Integer>
			facetConnectivity;

		//- Static functions and operators

		static edgeConnectivity EdgeIndices(const Standard_Integer theIndex);

		static facetConnectivity FacetIndices(const Standard_Integer theIndex);

		
	};
}

#endif // !_Entity3d_TetrahedralizationTools_Header
