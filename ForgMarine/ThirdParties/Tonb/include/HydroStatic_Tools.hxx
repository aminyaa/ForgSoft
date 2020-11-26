#pragma once
#ifndef _HydroStatic_Tools_Header
#define _HydroStatic_Tools_Header

#include <Standard_TypeDef.hxx>

#include <vector>
#include <memory>

namespace tnbLib
{

	namespace hsLib
	{

		struct xSection
		{
			Standard_Real x;
			Standard_Real value;
		};
	}

	// Forward Declarations
	class HydroStatic_Boundary;
	class TModel_Surface;

	class HydroStatic_Tools
	{

	public:

		static Standard_Real CalcArea(const std::vector<hsLib::xSection>& theQ);

		static std::vector<std::shared_ptr<TModel_Surface>> RetrieveSurfaces(const HydroStatic_Boundary& theBoundary);

		static std::vector<std::shared_ptr<TModel_Surface>> RetrieveSurfaces(const std::vector<std::shared_ptr<HydroStatic_Boundary>>& theBoundaries);
	};
}

#endif // !_HydroStatic_Tools_Header
