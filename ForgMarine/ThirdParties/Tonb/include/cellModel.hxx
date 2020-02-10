#pragma once
#ifndef _cellModel_Header
#define _cellModel_Header

#include <pointField.hxx>
#include <edgeList.hxx>
#include <faceList.hxx>
#include <InfoProxy.hxx>
#include <autoPtr.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of friend functions and operators

	class cellModel;
	inline bool operator==(const cellModel&, const cellModel&);
	inline bool operator!=(const cellModel&, const cellModel&);
	Ostream& operator<<(Ostream&, const cellModel&);


	/*---------------------------------------------------------------------------*\
							   Class cellModel Declaration
	\*---------------------------------------------------------------------------*/

	class cellModel
	{
		// Private data

			//- Name
		word name_;

		//- Label in the model list
		label index_;

		//- Number of points in the model which determines the geometry
		label nPoints_;

		//- Faces of the model
		faceList faces_;

		//- Edges of the model
		edgeList edges_;


	public:

		// Constructors

			//- Construct from Istream
		cellModel(Istream&);

		//- Return a new cellModel on free-store created from Istream
		static autoPtr<cellModel> New(Istream& is)
		{
			return autoPtr<cellModel>(new cellModel(is));
		}

		//- Return clone
		autoPtr<cellModel> clone() const
		{
			return autoPtr<cellModel>(new cellModel(*this));
		}


		// Member functions

			// Access

				//- Return model name
		const word& name() const;

		//- Return index of model in the model list
		label index() const;

		//- Return number of points
		label nPoints() const;

		//- Return number of edges
		label nEdges() const;

		//- Return number of faces
		label nFaces() const;

		//- Return list of edges
		edgeList edges(const labelList& pointLabels) const;

		//- Return a raw list of model faces
		const faceList& modelFaces() const;

		//- Return list of faces
		faceList faces(const labelList& pointLabels) const;


		//- Vector centroid
		vector centre
		(
			const labelList& pointLabels,
			const pointField& points
		) const;

		//- Cell volume
		scalar mag
		(
			const labelList& pointLabels,
			const pointField& points
		) const;

		//- Return info proxy.
		//  Used to print token information to a stream
		InfoProxy<cellModel> info() const
		{
			return *this;
		}

		//- WriteData member function required by regIOobject
		bool writeData(Ostream& os) const
		{
			os << *this;
			return os.good();
		}


		// Friend operators

			//- Equality operator: true => ptr to models are equal !
		friend bool operator==(const cellModel&, const cellModel&);

		//- Inequality operator: true => ptr to models are not equal !
		friend bool operator!=(const cellModel&, const cellModel&);


		// Ostream operator

		friend Ostream& operator<<(Ostream&, const cellModel&);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <cellModelI.hxx>

#endif // !_cellModel_Header
