#pragma once
#ifndef _Aft_FrontInfo_Header
#define _Aft_FrontInfo_Header

#include <Standard_TypeDef.hxx>
#include <Entity_Box.hxx>
#include <error.hxx>
#include <OSstream.hxx>

namespace AutLib
{

	enum Aft_AlgCondition
	{
		Aft_AlgCondition_Generation = 0,
		Aft_AlgCondition_Repair
	};

	enum Aft_PointCondition
	{
		Aft_PointCondition_NewPoint = 0,
		Aft_PointCondition_PickedUp
	};

	class Aft_FrontInfoBase
	{

		/*Private Data*/

		// true if the new Node appended to the candidate list
		Standard_Boolean AppendedNode_;

		Aft_AlgCondition theAlgCondition_;

		Aft_PointCondition thePointCondition_;

		mutable Standard_Integer theCandidateSize_;

		Standard_Real theElementSize_;

		Standard_Real theLocalRadius_;
		Standard_Real theSearchRadius_;
		Standard_Real theMaxElmLength_;

		Standard_Real theMinDistanceFactor_;

	public:

		Aft_FrontInfoBase()
		{}

		Standard_Boolean AppendedNode() const
		{
			return AppendedNode_;
		}

		Standard_Boolean& AppendedNode()
		{
			return AppendedNode_;
		}

		Aft_AlgCondition AlgCondition() const
		{
			return theAlgCondition_;
		}

		Aft_AlgCondition& AlgCondition()
		{
			return theAlgCondition_;
		}

		Aft_PointCondition PointCondition() const
		{
			return thePointCondition_;
		}

		Aft_PointCondition& PointCondition()
		{
			return thePointCondition_;
		}

		Standard_Integer CandidateSize() const
		{
			return theCandidateSize_;
		}

		Standard_Integer& CandidateSize()
		{
			return theCandidateSize_;
		}

		Standard_Real ElementSize() const
		{
			return theElementSize_;
		}

		Standard_Real& ElementSize()
		{
			return theElementSize_;
		}

		Standard_Real LocFrontRadius() const
		{
			return theLocalRadius_;
		}

		Standard_Real SquareLocFrontRadius() const
		{
			return theLocalRadius_ * theLocalRadius_;
		}

		Standard_Real& LocFrontRadius()
		{
			return theLocalRadius_;
		}

		Standard_Real SearchRadius() const
		{
			return theSearchRadius_;
		}

		Standard_Real SquareSearchRadius() const
		{
			return theSearchRadius_ * theSearchRadius_;
		}

		Standard_Real& SearchRadius()
		{
			return theSearchRadius_;
		}

		Standard_Real MaxElmLength() const
		{
			return theMaxElmLength_;
		}

		Standard_Real SquareMaxElmLength() const
		{
			return theMaxElmLength_ * theMaxElmLength_;
		}

		Standard_Real& MaxElmLength()
		{
			return theMaxElmLength_;
		}

		Standard_Real MinDistFactor() const
		{
			return theMinDistanceFactor_;
		}

		Standard_Real& MinDistFactor()
		{
			return theMinDistanceFactor_;
		}

		void SwitchAlgToGeneration()
		{
			theAlgCondition_ = Aft_AlgCondition_Generation;
		}

		void SwitchAlgToRepair()
		{
			theAlgCondition_ = Aft_AlgCondition_Repair;
		}

		void SetCandidateSize(const Standard_Integer theSize) const
		{
			theCandidateSize_ = theSize;
		}

		void SetLocFrontRadius(const Standard_Real theRadius)
		{
			Debug_If_Condition_Message(theRadius <= 0, "Invalid Radius value (<=0)");
			theLocalRadius_ = theRadius;
		}

		void SetSearchRadius(const Standard_Real theRadius)
		{
			Debug_If_Condition_Message(theRadius <= 0, "Invalid Radius value (<=0)");
			theSearchRadius_ = theRadius;
		}

		void SetMaxElmLength(const Standard_Real theLength)
		{
			Debug_If_Condition_Message(theLength <= 0, "Invalid MaxElmLength value (<=0)");
			theMaxElmLength_ = theLength;
		}

		void SetMinDistFactor(const Standard_Real theFactor)
		{
			Debug_If_Condition_Message(theFactor <= 0, "Invalid MinDistFactor value (<=0)");
			theMinDistanceFactor_ = theFactor;
		}

		void SetElementSize(const Standard_Real theSize)
		{
			Debug_If_Condition_Message(theSize <= 0, "Invalid ElementSize value (<=0)");
			theElementSize_ = theSize;
		}

#ifdef RESET_FRONT_INFO
		void Reset()
		{
			ElementSize() = 0;
			LocFrontRadius() = 0;
			SearchRadius() = 0;
			MaxElmLength() = 0;
			CandidateSize() = 0;
			//MinDistFactor() = 0;
		}
#endif
	};


	template<class InfoAdaptor>
	class Aft_FrontInfo
		: public InfoAdaptor
		, public Aft_FrontInfoBase
	{

	public:

		typedef typename InfoAdaptor::nodeType nodeType;
		typedef typename InfoAdaptor::frontType frontType;
		typedef typename InfoAdaptor::elementType elementType;
		typedef typename nodeType::ptType Point;

		typedef std::shared_ptr<nodeType> nodeTypePtr;
		typedef std::shared_ptr<frontType> frontTypePtr;
		typedef std::shared_ptr<elementType> elementTypePtr;

	private:

		/*Private Data*/

		Point theCoord_;

		mutable Entity_Box<Point> theBoundingBox_;

		nodeTypePtr theTemp_;
		nodeTypePtr theValid_;

		frontTypePtr theCurrent_;

		elementTypePtr theElement_;

	public:

		Aft_FrontInfo()
		{}

		const Point& Coord() const
		{
			return theCoord_;
		}

		Point& Coord()
		{
			return theCoord_;
		}

		const Entity_Box<Point>& BoundingBox() const
		{
			return theBoundingBox_;
		}

		const nodeTypePtr& ValidNode() const
		{
			return theValid_;
		}

		nodeTypePtr& ValidNode()
		{
			return theValid_;
		}

		const nodeTypePtr& TempoNode() const
		{
			return theTemp_;
		}

		nodeTypePtr& TempoNode()
		{
			return theTemp_;
		}

		const frontTypePtr& CurrentFront() const
		{
			return theCurrent_;
		}

		frontTypePtr& CurrentFront()
		{
			return theCurrent_;
		}

		const elementTypePtr& Element() const
		{
			return theElement_;
		}

		elementTypePtr& Element()
		{
			return theElement_;
		}

		void SetCoord(const Point& theCoord)
		{
			theCoord_ = theCoord;
		}

		void SetBoundingBox(const Entity_Box<Point>& theBox) const
		{
			theBoundingBox_ = theBox;
		}

		void SetTempoNode(const nodeTypePtr& theNode)
		{
			theTemp_ = theNode;
		}

		void SetValidNode(const nodeTypePtr& theValid)
		{
			theValid_ = theValid;
		}

		void SetCurrentFront(const frontTypePtr& theCurrent)
		{
			theCurrent_ = theCurrent;
		}

		void SetElement(const elementTypePtr& theElement)
		{
			theElement_ = theElement;
		}

#ifdef RESET_FRONT_INFO
		void Reset()
		{
			SetValidNode(0);
			SetCurrentFront(0);
			SetElement(0);

			Aft_FrontInfoBase::Reset();

			InfoAdaptor::Reset();
		}
#endif

	};
}

#endif // !_Aft_FrontInfo_Header