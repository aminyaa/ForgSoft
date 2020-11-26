#pragma once
#ifndef _Marine_CmpSection_Header
#define _Marine_CmpSection_Header

#include <Entity2d_BoxFwd.hxx>
#include <Marine_Entity.hxx>
#include <OFstream.hxx>

#include <vector>

#include <Standard_Handle.hxx>

class TopoDS_Edge;
class TopoDS_Shape;
class Geom2d_Curve;
class gp_Trsf2d;

namespace tnbLib
{

	// Forward Declarations
	class MarineBase_Tools;
	class Marine_Section;
	class Pln_Curve;

	class Marine_CmpSection
		: public Marine_Entity
	{

		friend class MarineBase_Tools;

		/*Private Data*/

		std::vector<std::shared_ptr<Marine_Section>> theSections_;

	protected:

		

		void Insert
		(
			const std::shared_ptr<Marine_Section>& theSection
		)
		{
			theSections_.push_back(theSection);
		}

	public:

		Marine_CmpSection();

		Marine_CmpSection
		(
			const Standard_Integer theIndex
		);

		Marine_CmpSection
		(
			const Standard_Integer theIndex,
			const word& theName
		);

		Entity2d_Box BoundingBox() const;

		auto NbSections() const
		{
			return (Standard_Integer)theSections_.size();
		}

		const auto& Sections() const
		{
			return theSections_;
		}

		auto& ChangeSections()
		{
			return theSections_;
		}

		Standard_Real X() const;

		std::shared_ptr<Marine_CmpSection> Copy() const;

		void Transform(const gp_Trsf2d& t);

		void ExportToPlt(OFstream& File) const;

		static std::shared_ptr<Marine_CmpSection>
			CreateCmpSection
			(
				const std::vector<std::shared_ptr<Pln_Curve>>& theCurves,
				const gp_Ax2& theSystem,
				const Standard_Real theMinTol,
				const Standard_Real theMaxTol
			);

		static std::shared_ptr<Marine_CmpSection>
			CreateCmpSection
			(
				const std::vector<Handle(Geom2d_Curve)>& theCurves,
				const gp_Ax2& theSystem,
				const Standard_Real theMinTol,
				const Standard_Real theMaxTol
			);

		static std::shared_ptr<Marine_CmpSection>
			CreateCmpSection
			(
				const TopoDS_Shape& theEdges,
				const gp_Ax2& theSystem,
				const Standard_Real theMinTol,
				const Standard_Real theMaxTol
			);

		static std::vector<Handle(Geom2d_Curve)>
			RetrieveParaCurves
			(
				const std::vector<TopoDS_Edge>& theEdges,
				const gp_Ax2& theSystem
			);

		static std::vector<TopoDS_Edge>
			RetrieveEdges
			(
				const TopoDS_Shape& theEdges
			);
	};
}

#endif // !_Marine_CmpSection_Header
