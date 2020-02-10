#pragma once
#ifndef _CadIO_Shape_Header
#define _CadIO_Shape_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>
#include <Entity3d_Box.hxx>

#include <TopoDS_Shape.hxx>

namespace tnbLib
{

	class CadIO_Shape
		: public Global_Indexed
		, public Global_Named
	{

		/*Private Data*/

		TopoDS_Shape theShape_;

		Entity3d_Box theBoundingBox_;


	protected:

		CadIO_Shape()
		{}


		auto& ChangeShape()
		{
			return theShape_;
		}

		auto& ChangeBoundingBox()
		{
			return theBoundingBox_;
		}

		void SetShape(const TopoDS_Shape& theShape)
		{
			theShape_ = theShape;
		}

		void SetBoundingBox(const Entity3d_Box& theBox)
		{
			theBoundingBox_ = theBox;
		}

	public:

		const auto& Shape() const
		{
			return theShape_;
		}

		const auto& BoundingBox() const
		{
			return theBoundingBox_;
		}
	};
}

#endif // !_CadIO_Shape_Header
