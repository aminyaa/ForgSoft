#pragma once
#ifndef _IO_Shape_Header
#define _IO_Shape_Header

#include <Global_Named.hxx>
#include <Global_Indexed.hxx>
#include <Entity3d_Box.hxx>
#include <OFstream.hxx>

#include <Bnd_Box.hxx>
#include <TopoDS_Shape.hxx>

namespace AutLib
{

	class IO_Shape
		: public Global_Named
		, public Global_Indexed
	{

		/*Private Data*/

		TopoDS_Shape theShape_;

		Entity3d_Box theBoundingBox_;

	protected:

		void SetShape(const TopoDS_Shape& theShape)
		{
			theShape_ = theShape;
		}

		void SetBoundingBox(const Entity3d_Box& theBox)
		{
			theBoundingBox_ = theBox;
		}

	public:

		IO_Shape()
		{}

		const TopoDS_Shape& Shape() const
		{
			return theShape_;
		}

		const Entity3d_Box& BoundingBox() const
		{
			return theBoundingBox_;
		}

		void ExportToPlt(OFstream& File) const;
	};
}

#endif // !_IO_Shape_Header
