#pragma once
#ifndef _CadPlnModel_Entity_Header
#define _CadPlnModel_Entity_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>
#include <Entity2d_ChainFwd.hxx>
#include <OFstream.hxx>

#include <gp_Ax22d.hxx>

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class Pln_Entity;
	class Geo_ApprxCurveInfo;

	class CadPlnModel_Entity_System
	{

		/*Private Data*/

		gp_Ax22d theSystem_;

	protected:

		virtual void SetSystem(const gp_Ax22d& theSystem)
		{
			theSystem_ = theSystem;
		}

		CadPlnModel_Entity_System()
		{}

	public:	

		const gp_Ax22d& System() const
		{
			return theSystem_;
		}

		gp_Ax22d& ChangeSystem()
		{
			return theSystem_;
		}
	};

	class CadPlnModel_Entity_ID
		: public Global_Indexed
		, public Global_Named
	{
		
		/*Private Data*/

	protected:

		CadPlnModel_Entity_ID()
		{}

		CadPlnModel_Entity_ID
		(
			const Standard_Integer theIndex,
			const word& theName
		)
			: Global_Indexed(theIndex)
			, Global_Named(theName)
		{}

	public:

	};

	class CadPlnModel_Entity_Discrete
	{

		/*Private Data*/

		mutable std::shared_ptr<Entity2d_Chain> theMesh_;

	protected:

		std::shared_ptr<Entity2d_Chain>& ChangeMesh() const
		{
			return theMesh_;
		}

		void SetMesh(const std::shared_ptr<Entity2d_Chain>& theMesh) const
		{
			theMesh_ = theMesh;
		}

		CadPlnModel_Entity_Discrete()
		{}

	public:

		const std::shared_ptr<Entity2d_Chain>& Mesh() const
		{
			return theMesh_;
		}

		void ReleaseMesh()
		{
			theMesh_.reset();
		}

		virtual void Discrete(const std::shared_ptr<Geo_ApprxCurveInfo>& theInfo) const = 0;
	};

	class CadPlnModel_Entity
		: public CadPlnModel_Entity_System
		, public CadPlnModel_Entity_ID
		, public CadPlnModel_Entity_Discrete
	{

		/*Private Data*/

		std::shared_ptr<Pln_Entity> theEntity_;

	protected:

		CadPlnModel_Entity()
		{}

		CadPlnModel_Entity
		(
			const Standard_Integer theIndex,
			const word& theName
		)
			: CadPlnModel_Entity_ID(theIndex, theName)
		{}


		std::shared_ptr<Pln_Entity>& ChangeEntity()
		{
			return theEntity_;
		}

	public:

		const std::shared_ptr<Pln_Entity>& Entity() const
		{
			return theEntity_;
		}

		//virtual void Make() = 0;

		void Transform(const gp_Trsf2d& theT);

		void ExportToPlt(OFstream& File) const;
	};
}

#endif // !_CadPlnModel_Entity_Header
