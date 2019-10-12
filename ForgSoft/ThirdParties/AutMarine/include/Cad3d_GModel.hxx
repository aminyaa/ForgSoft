#pragma once
#ifndef _Cad3d_GModel_Header
#define _Cad3d_GModel_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>
#include <OFstream.hxx>

class TopoDS_Face;
class TopoDS_Shape;

#include <memory>
#include <vector>

namespace AutLib
{

	// Forward Declaration
	class GModel_Surface;

	class Cad3d_GModel
		: public Global_Indexed
		, public Global_Named
	{

		typedef std::vector<std::shared_ptr<GModel_Surface>> faceList;

		/*Private Data*/

		faceList theSurfaces_;

	public:

		Cad3d_GModel
		(
			const std::vector<std::shared_ptr<GModel_Surface>>& theSurfaces
		)
			: theSurfaces_(theSurfaces)
		{}

		const std::vector<std::shared_ptr<GModel_Surface>>& Surfaces() const
		{
			return theSurfaces_;
		}

		Standard_Integer NbSurfaces() const
		{
			return (Standard_Integer)theSurfaces_.size();
		}


		//- Io functions and operators

		void ExportToPlt(OFstream& File) const;



		//- Static functions and operators

		static std::shared_ptr<GModel_Surface>
			GetSurface
			(
				const TopoDS_Face& theFace
			);

		static faceList
			GetSurfaces
			(
				const TopoDS_Shape& theShape
			);

		static std::shared_ptr<Cad3d_GModel>
			GModel
			(
				const TopoDS_Shape& theShape
			);
	};
}

#endif // !_Cad3d_GModel_Header
