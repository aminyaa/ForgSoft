#pragma once
#ifndef _CadAnalys_Wire_Header
#define _CadAnalys_Wire_Header

#include <Global_Done.hxx>
#include <Global_AccessMethod.hxx>

#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>

class ShapeAnalysis_Wire;

namespace AutLib
{

	// Forward Declarations
	class CadAnalys_Wire_Info;

	class CadAnalys_Wire
		: public Global_Done
	{

		/*Private Data*/

		TopoDS_Wire theWire_;
		TopoDS_Face theFace_;

		std::shared_ptr<CadAnalys_Wire_Info> theInfo_;

		Standard_Boolean Order2d_;
		Standard_Boolean Order3d_;
		Standard_Boolean Connected_;
		Standard_Boolean Small_;
		Standard_Boolean EdgeCurves_;
		Standard_Boolean Degenerated_;
		Standard_Boolean Closed_;
		Standard_Boolean SelfIntersection_;
		Standard_Boolean Lacking_;
		Standard_Boolean Gap2d_;
		Standard_Boolean Gap3d_;

		Standard_Real theMinDist2d_;
		Standard_Real theMinDist3d_;
		Standard_Real theMaxDist2d_;
		Standard_Real theMaxDist3d_;

		Standard_Integer theNbEdges_;

		Handle(ShapeAnalysis_Wire) theAnalysis_;

	public:

		CadAnalys_Wire(const std::shared_ptr<CadAnalys_Wire_Info>& theInfo)
			: theInfo_(theInfo)
		{}

		CadAnalys_Wire
		(
			const TopoDS_Wire& theWire,
			const TopoDS_Face& theFace,
			const std::shared_ptr<CadAnalys_Wire_Info>& theInfo
		)
			: theWire_(theWire)
			, theFace_(theFace)
			, theInfo_(theInfo)
		{}

		const TopoDS_Wire& Wire() const
		{
			return theWire_;
		}

		const TopoDS_Face& Face() const
		{
			return theFace_;
		}

		const std::shared_ptr<CadAnalys_Wire_Info>& Info() const
		{
			return theInfo_;
		}

		Standard_Boolean Connected() const
		{
			return Connected_;
		}

		Standard_Boolean Small() const
		{
			return Connected_;
		}

		Standard_Boolean EdgeCurves() const
		{
			return EdgeCurves_;
		}

		Standard_Boolean Degenerated() const
		{
			return Degenerated_;
		}

		Standard_Boolean Closed() const
		{
			return Closed_;
		}

		Standard_Boolean SelfIntersection() const
		{
			return SelfIntersection_;
		}

		Standard_Boolean Lacking() const
		{
			return Lacking_;
		}

		Standard_Boolean Gap2d() const
		{
			return Gap2d_;
		}

		Standard_Boolean Gap3d() const
		{
			return Gap3d_;
		}

		void Perform();

		//- Macros
		GLOBAL_ACCESS_ONLY_SINGLE(Standard_Real, MinDist2d)
			GLOBAL_ACCESS_ONLY_SINGLE(Standard_Real, MinDist3d)
			GLOBAL_ACCESS_ONLY_SINGLE(Standard_Real, MaxDist2d)
			GLOBAL_ACCESS_ONLY_SINGLE(Standard_Real, MaxDist3d)

			GLOBAL_ACCESS_ONLY_SINGLE(Standard_Integer, NbEdges)
	};
}

#endif // !_CadAnalys_Wire_Header
