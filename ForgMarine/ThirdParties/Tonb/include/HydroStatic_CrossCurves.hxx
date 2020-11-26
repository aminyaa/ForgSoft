#pragma once
#ifndef _HydroStatic_CrossCurves_Header
#define _HydroStatic_CrossCurves_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>
#include <Global_Done.hxx>
#include <Global_Verbose.hxx>
#include <Global_AccessMethod.hxx>
#include <Entity3d_Box.hxx>

#include <memory>

#include <gp_Ax1.hxx>

namespace tnbLib
{

	// Forward Declarations
	class CrossSection_xShapeStation;
	class Marine_Graph;
	class Marine_Domain;
	class Geo_xDistb;

	class HydroStatic_CrossCurves
		: public Global_Indexed
		, public Global_Named
		, public Global_Done
		, public Global_Verbose
	{

		/*Private Data*/

		gp_Ax1 theK_;

		std::shared_ptr<Marine_Domain> theDomain_;
		std::shared_ptr<CrossSection_xShapeStation> theModel_;
		std::shared_ptr<Geo_xDistb> theHeel_;

		std::shared_ptr<Marine_Graph> theGraph_;

		Standard_Integer theNbWaters_;

		auto& ChangeGraph()
		{
			return theGraph_;
		}

	public:

		static const Standard_Integer DEFAULT_NB_WATERS;

		HydroStatic_CrossCurves
		(
			const std::shared_ptr<Marine_Domain>& theDomain
		);

		HydroStatic_CrossCurves
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<Marine_Domain>& theDomain
		);

		HydroStatic_CrossCurves
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<Marine_Domain>& theDomain
		);

		/*auto NbWaters() const
		{
			return theNbWaters_;
		}*/

		/*const auto& K() const
		{
			return theK_;
		}*/

		const auto& Model() const
		{
			return theModel_;
		}

		const auto& Heel() const
		{
			return theHeel_;
		}

		const auto& Graph() const
		{
			return theGraph_;
		}

		const auto& Domain() const
		{
			return theDomain_;
		}

		void Perform();

		void LoadModel
		(
			const std::shared_ptr<CrossSection_xShapeStation>& theModel
		)
		{
			theModel_ = theModel;
		}

		void LoadHeel
		(
			const std::shared_ptr<Geo_xDistb>& theHeel
		)
		{
			theHeel_ = theHeel;
		}

		//- Macros
		GLOBAL_ACCESS_SINGLE(gp_Ax1, K)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, NbWaters)
		
	};
}

#endif // !_HydroStatic_CrossCurves_Header
