#pragma once
#ifndef _GeoMesh_Data_Header
#define _GeoMesh_Data_Header

#include <Standard_TypeDef.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <memory>
#include <vector>

#include "Mesh2d_Element.hxx"
#include "Mesh2d_Node.hxx"

namespace AutLib
{

	// Forward Declarations
	template<class Point, class Connectivity, bool NeighbData>
	class Entity_StaticData;

	struct GeoMesh_DataInfo
	{
		static const int DEFAULT_MAX_CYCLES;
	};

	template<class ElementType>
	class GeoMesh_Data
		: public GeoMesh_DataInfo
	{

	public:

		typedef ElementType elementType;
		typedef std::vector<std::shared_ptr<elementType>> elementList;

		typedef typename elementType::nodeType nodeType;
		typedef typename nodeType::ptType Point;
		typedef typename elementType::connectType connectType;
		typedef typename elementType::edgeType edgeType;
		typedef typename elementType::facetType facetType;

		typedef Entity_StaticData<Point, connectType, false>
			triangulation;

	private:

		/*Private Data*/

		elementList theElements_;


	public:

		GeoMesh_Data()
		{}

		void Construct(const triangulation& theTriangulation);

		const elementList& Elements() const
		{
			return theElements_;
		}

		const std::shared_ptr<elementType>& FirstElement() const
		{
			Debug_If_Condition_Message(theElements_.empty(), "the elements list is empty");
			return theElements_[0];
		}

		std::shared_ptr<elementType> TriangleLocation
		(
			const std::shared_ptr<elementType>& theStart,
			const Point& theCoord
		) const;

		std::shared_ptr<triangulation> StaticData() const;

		void RetrieveNodesTo
		(
			std::vector<std::shared_ptr<nodeType>>& theNodes
		) const;
	};
}

#include <GeoMesh_DataI.hxx>

#endif // !_GeoMesh_Data_Header