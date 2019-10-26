#pragma once
#ifndef _Leg_Model_Entity_Header
#define _Leg_Model_Entity_Header

#include <Global_AccessMethod.hxx>
#include <Global_Indexed.hxx>
#include <Global_Named.hxx>
#include <Global_Done.hxx>
#include <Entity3d_Box.hxx>

#include <gp_Ax2.hxx>
#include <TopoDS_Shape.hxx>

#include <memory>

namespace AutLib
{

	enum class Leg_EntityIO_Format
	{
		IGES = 0,
		STEP,
		TecPlot
	};

	class Leg_Model_EntityIO
	{

		/*Private Data*/

		word theFileName_;

		Leg_EntityIO_Format theFileFormat_;

	protected:

		Leg_Model_EntityIO();

	public:

		

		GLOBAL_ACCESS_SINGLE(word, FileName)
			GLOBAL_ACCESS_PRIM_SINGLE(Leg_EntityIO_Format, FileFormat)
	};


	class Leg_Model_EntitySystem
	{

		/*Private Data*/

		gp_Ax2 theSystem_;

	protected:

		gp_Ax2& System()
		{
			return theSystem_;
		}

		void SetSystem(const gp_Ax2& theSys)
		{
			theSystem_ = theSys;
		}

		Leg_Model_EntitySystem()
		{}

		Leg_Model_EntitySystem(const gp_Ax2& theSystem)
			: theSystem_(theSystem)
		{}

	public:

		
	};


	class Leg_Model_EntityID
		: public Global_Indexed
		, public Global_Named
	{

		/*Private Data*/

	protected:

		Leg_Model_EntityID()
		{}

		Leg_Model_EntityID(const Standard_Integer theIndex)
			: Global_Indexed(theIndex)
			, Global_Named("Unknown")
		{}

		Leg_Model_EntityID
		(
			const Standard_Integer theIndex,
			const word& theName
		)
			: Global_Indexed(theIndex)
			, Global_Named(theName)
		{}

	public:


	};


	class Leg_Model_EntityDiscrete
	{

		/*Private Data*/

		Standard_Real theDeflection_;
		Standard_Real theAngle_;

	protected:

		Leg_Model_EntityDiscrete()
			: theDeflection_(DEFAULT_DEFLECTION)
			, theAngle_(DEFAULT_ANGLE)
		{}

	public:

		static const Standard_Real DEFAULT_DEFLECTION;
		static const Standard_Real DEFAULT_ANGLE;

		//- Macros

		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Deflection)
			GLOBAL_ACCESS_ONLY_SINGLE(Standard_Real, Angle)
	};


	class Leg_Model_EntityBase
		: public Global_Done
	{

		/*Private Data*/

		Standard_Boolean toDiscrete_;
		Standard_Boolean toSolid_;

		std::shared_ptr<Entity3d_Box> theBox_;

	protected:


		Leg_Model_EntityBase()
			: toDiscrete_(Standard_False)
			, toSolid_(Standard_False)
		{}

		Standard_Boolean& toDiscrete()
		{
			return toDiscrete_;
		}

		Standard_Boolean& toSolid()
		{
			return toSolid_;
		}

		std::shared_ptr<Entity3d_Box>& Box()
		{
			return theBox_;
		}

	public:

		Standard_Boolean toDiscrete() const
		{
			return toDiscrete_;
		}

		Standard_Boolean toSolid() const
		{
			return toSolid_;
		}

		const std::shared_ptr<Entity3d_Box>& Box() const
		{
			return theBox_;
		}
	};


	class Leg_Model_Entity
		: public Leg_Model_EntityBase
		, public Leg_Model_EntityIO
		, public Leg_Model_EntitySystem
		, public Leg_Model_EntityID
		, public Leg_Model_EntityDiscrete
	{

		/*private Data*/

		TopoDS_Shape theEntity_;

		TopoDS_Shape thePreview_;

	protected:

		Leg_Model_Entity()
		{}

		Leg_Model_Entity(const Standard_Integer theIndex)
			: Leg_Model_EntityID(theIndex)
		{}

		Leg_Model_Entity(const Standard_Integer theIndex, const word& theName)
			: Leg_Model_EntityID(theIndex, theName)
		{}

		TopoDS_Shape& ChangeEntity()
		{
			return theEntity_;
		}

		TopoDS_Shape& ChangePreviewEntity()
		{
			return thePreview_;
		}

	public:

		virtual ~Leg_Model_Entity()
		{}

		const Leg_Model_EntityIO& IO() const
		{
			return *this;
		}

		Leg_Model_EntityIO& IO()
		{
			return *this;
		}

		const TopoDS_Shape& Entity() const
		{
			return theEntity_;
		}

		const TopoDS_Shape& PreviewEntity() const
		{
			return thePreview_;
		}

		TopoDS_Shape Section(const gp_Pln& thePlane) const;

		void Discrete();

		void MakeSolid();

		void TransformTo
		(
			const gp_Ax2& theSystem
		);

		void Scale
		(
			const Standard_Real theScale
		);

		void ExportToFile() const;

		void CalcBoundingBox();

		virtual void PerformToPreview() = 0;

		static Entity3d_Box BoundingBox(const TopoDS_Shape& theShape);
	};
}

#endif // !_Leg_Model_Entity_Header
