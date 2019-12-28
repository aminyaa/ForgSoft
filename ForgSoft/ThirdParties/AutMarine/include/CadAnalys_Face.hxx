#pragma once
#ifndef _CadAnalys_Face_Header
#define _CadAnalys_Face_Header

#include <Global_Done.hxx>
#include <Entity2d_Box.hxx>

#include <TopoDS_Face.hxx>
#include <TopoDS_Wire.hxx>

namespace AutLib
{

	class CadAnalys_Face
		: public Global_Done
	{

		/*Private Data*/

		TopoDS_Face theFace_;

		TopoDS_Wire theOuter_;

		Entity2d_Box theParaBoundingBox_;

		Standard_Real theTolerance_;

	public:

		CadAnalys_Face()
		{}

		CadAnalys_Face(const TopoDS_Face& theFace)
			: theFace_(theFace)
		{}

		const TopoDS_Face& Face() const
		{
			return theFace_;
		}

		const TopoDS_Wire& Outer() const
		{
			return theOuter_;
		}

		const Entity2d_Box& ParaBoundingBox() const
		{
			return theParaBoundingBox_;
		}

		Standard_Real Tolerance() const
		{
			return theTolerance_;
		}

		void Perform();

		void LoadFace(const TopoDS_Face& theFace)
		{
			theFace_ = theFace;
		}

		static Standard_Real ContourArea(const TopoDS_Wire& theWire);
	};
}

#endif // !_CadAnalys_Face_Header
