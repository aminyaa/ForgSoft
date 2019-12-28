#pragma once
#ifndef _CadCascade_Model_Header
#define _CadCascade_Model_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>
#include <Pnt3d.hxx>
#include <gp_Ax2.hxx>

#include <memory>

#include <TopoDS_Shape.hxx>

namespace AutLib
{

	class CadCascade_Model
		: public Global_Indexed
		, public Global_Named
		, public std::enable_shared_from_this<CadCascade_Model>
	{

		/*Private Data*/

		TopoDS_Shape theShape_;

	protected:

		CadCascade_Model()
		{}

		CadCascade_Model
		(
			const Standard_Integer theIndex,
			const word& theName
		)
			: Global_Indexed(theIndex)
			, Global_Named(theName)
		{}

		TopoDS_Shape& ChangeShape()
		{
			return theShape_;
		}

	public:

		virtual ~CadCascade_Model()
		{}


		const TopoDS_Shape& Shape() const
		{
			return theShape_;
		}
	};
}

#endif // !_CadCascade_Model_Header
