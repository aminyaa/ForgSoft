#pragma once
#ifndef _TModel_Shell_Header
#define _TModel_Shell_Header

#include <TModel_Entity.hxx>
#include <Entity3d_Box.hxx>
#include <error.hxx>
#include <OSstream.hxx>
#include <OFstream.hxx>

#include <vector>

namespace AutLib
{

	// Forward Declarations
	class TModel_Surface;

	class TModel_Shell
		: public TModel_Entity
	{

		typedef std::shared_ptr<TModel_Surface> surface_ptr;
		typedef std::vector<surface_ptr> surfaceList;

		/*Private Data*/

		std::shared_ptr<surfaceList> theSurfaces_;

		Entity3d_Box theBoundingBox_;

		Standard_Boolean IsWaterTight_;


		//- Private functions and operators

		void WaterTightCondition();

		void CalcBoundingBox();

	public:

		TModel_Shell
		(
			const std::shared_ptr<surfaceList>& theSurfaces
		);

		TModel_Shell
		(
			const Standard_Integer theIndex, 
			const std::shared_ptr<surfaceList>& theSurfaces
		);

		TModel_Shell
		(
			const Standard_Integer theIndex, 
			const word& theName,
			const std::shared_ptr<surfaceList>& theSurfaces
		);


		const std::shared_ptr<surfaceList>& Surfaces() const
		{
			return theSurfaces_;
		}

		const Entity3d_Box& BoundingBox() const
		{
			return theBoundingBox_;
		}

		Standard_Boolean IsWaterTight() const
		{
			return IsWaterTight_;
		}


		//- Io functions and operators

		void ExportToPlt(OFstream& File) const;


		//- static functions and operators

		static Standard_Boolean IsLess
		(
			const std::shared_ptr<TModel_Shell>& theSh0,
			const std::shared_ptr<TModel_Shell>& theSh1
		)
		{
			Debug_Null_Pointer(theSh0);
			Debug_Null_Pointer(theSh1);

			return theSh0->Index() < theSh1->Index();
		}
	};
}

#endif // !_TModel_Shell_Header
