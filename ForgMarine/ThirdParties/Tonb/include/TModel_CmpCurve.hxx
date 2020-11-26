#pragma once
#ifndef _TModel_CmpParaCurve_Header
#define _TModel_CmpParaCurve_Header

#include <TModel_Entity.hxx>
#include <Entity2d_BoxFwd.hxx>

#include <memory>
#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class TModel_ParaCurve;
	class TModel_ParaWire;
	class Cad_Tools;

	class TModel_CmpCurve
		: public TModel_Entity
	{

		typedef std::vector<std::shared_ptr<TModel_ParaCurve>> curveList;

		friend TModel_ParaWire;
		friend Cad_Tools;

		/*Private Data*/

		curveList theCurves_;

	protected:

		void Insert(const std::shared_ptr<TModel_ParaCurve>& theCurve)
		{
			theCurves_.push_back(theCurve);
		}

	public:

		TModel_CmpCurve()
		{}

		TModel_CmpCurve
		(
			const Standard_Integer theIndex
		)
			: TModel_Entity(theIndex)
		{}

		TModel_CmpCurve
		(
			const Standard_Integer theIndex, 
			const word& theName
		)
			: TModel_Entity(theIndex, theName)
		{}

		auto NbCurves() const
		{
			return (Standard_Integer)theCurves_.size();
		}

		const auto& Curves() const
		{
			return theCurves_;
		}

		Entity2d_Box CalcBoundingBox() const;
	};
}

#endif // !_TModel_CmpParaCurve_Header
