#pragma once
#ifndef _FastDiscrete_Params_Header
#define _FastDiscrete_Params_Header

#include <Standard_TypeDef.hxx>
#include <Precision.hxx>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <memory>

namespace AutLib
{

	struct FastDiscrete_Params
	{

		//! Angular deflection
		Standard_Real Angle;

		//! Deflection
		Standard_Real Deflection;

		//! Minimal allowed size of mesh element
		Standard_Real MinSize;

		//! Switches on/off multy thread computation
		Standard_Boolean InParallel;

		//! Switches on/off relative computation of edge tolerance<br>
		//! If true, deflection used for the polygonalisation of each edge will be 
		//! <defle> * Size of Edge. The deflection used for the faces will be the 
		//! maximum deflection of their edges.
		Standard_Boolean Relative;

		//! Adaptive parametric tolerance flag. <br>
		//! If this flag is set to true the minimal parametric tolerance
		//! is computed taking minimal parametric distance between vertices
		//! into account
		Standard_Boolean AdaptiveMin;

		//! Mode to take or not to take internal face vertices into account
		//! in triangulation process
		Standard_Boolean InternalVerticesMode;

		//! Parameter to check the deviation of triangulation and interior of
		//! the face
		Standard_Boolean  ControlSurfaceDeflection;

	public:

		FastDiscrete_Params()
			: Angle(0.1)
			, Deflection(0.005)
			, MinSize(Precision::Confusion())
			, InParallel(Standard_False)
			, Relative(Standard_False)
			, AdaptiveMin(Standard_False)
			, InternalVerticesMode(Standard_True)
			, ControlSurfaceDeflection(Standard_True)
		{}

	private:

		friend class boost::serialization::access;

		template<class Archive>
		void serialize(Archive& ar, const unsigned int version)
		{
			ar& Angle;
			ar& Deflection;
			ar& MinSize;
			ar& InParallel;
			ar& Relative;
			ar& AdaptiveMin;
			ar& InternalVerticesMode;
			ar& ControlSurfaceDeflection;
		}
	};

	extern std::shared_ptr<FastDiscrete_Params> gl_fast_discrete_parameters;
}

#endif // !_FastDiscrete_Params_Header
