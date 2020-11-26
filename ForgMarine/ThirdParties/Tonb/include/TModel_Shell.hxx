#pragma once
#ifndef _TModel_Shell_Header
#define _TModel_Shell_Header

#include <TModel_Entity.hxx>
#include <Entity3d_BoxFwd.hxx>
#include <TModel_WaterTight.hxx>

#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class TModel_Surface;
	class Cad_Tools;

	class TModel_Shell
		: public TModel_Entity
	{

		typedef std::vector<std::shared_ptr<TModel_Surface>> surfaceList;

		/*Private Data*/

		surfaceList theSurfaces_;

		TModel_WaterTight theWaterTight_;

	protected:

		void Insert
		(
			const std::shared_ptr<TModel_Surface>& theSurface
		)
		{
			theSurfaces_.push_back(theSurface);
		}

		void SetWaterCondition
		(
			const TModel_WaterTight theTightness
		)
		{
			theWaterTight_ = theTightness;
		}

	public:

		TModel_Shell()
		{}

		TModel_Shell
		(
			const Standard_Integer theIndex
		)
			: TModel_Entity(theIndex)
		{}

		TModel_Shell
		(
			const Standard_Integer theIndex,
			const word& theName
		)
			: TModel_Entity(theIndex, theName)
		{}

		auto NbSurfaces() const
		{
			return (Standard_Integer)theSurfaces_.size();
		}

		const auto& Surfaces() const
		{
			return theSurfaces_;
		}

		auto WaterTightness() const
		{
			return theWaterTight_;
		}

		Entity3d_Box CalcBoundingBox() const;


	};
}

#endif // !_TModel_Shell_Header
