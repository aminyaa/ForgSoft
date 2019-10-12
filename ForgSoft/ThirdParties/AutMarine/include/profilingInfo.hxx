#pragma once
#ifndef _profilingInfo_Header
#define _profilingInfo_Header

#include <scalar.hxx>

namespace AutLib
{
	class profilingInfo
	{
		// Private data

		// nr of times this was called
		label calls_;

		// total time spent
		scalar totalTime_;

		// time spent in children
		scalar childTime_;

		// unique id to identify it
		label id_;

		// pointer to the parent object (if there is any)
		profilingInfo &parent_;

		// what this does
		string description_;

		// is this currently on the stack?
		bool onStack_;

		// Private Member Functions

		//- Disallow default bitwise copy construct
		profilingInfo(const profilingInfo&);

		//- Disallow default bitwise assignment
		void operator=(const profilingInfo&);

		// Static data members

		//- Counter that is used to generate the ids
		static label nextId_;

		//- get a new ID and update the counter
		static label getID();

		//- raise the next possible ID (to avoid ID-clashes during reading)
		void raiseID(label maxVal);

	protected:

		void addedToStack()
		{
			onStack_ = true;
		}

		void removedFromStack()
		{
			onStack_ = false;
		}

		//- Construct null - only the master-element
		profilingInfo();

		void writeWithOffset(Ostream &os, bool offset = false, scalar time = 0, scalar childTime = 0) const;

	public:

		// Constructors

		//- Construct from components
		profilingInfo(profilingInfo &parent, const string &descr);

		//     //- Construct from Istream
		//     profilingInfo(Istream&);

			// Destructor

		~profilingInfo();


		// Member Functions

		// Access

		label id() const
		{
			return id_;
		}

		label calls() const
		{
			return calls_;
		}

		scalar totalTime() const
		{
			return totalTime_;
		}

		scalar childTime() const
		{
			return childTime_;
		}

		bool onStack() const
		{
			return onStack_;
		}

		const string &description() const
		{
			return description_;
		}

		const profilingInfo &parent() const
		{
			return parent_;
		}

		//- Update it with a new timing information
		void update(scalar elapsedTime);

		friend class profilingStack;
		friend class profilingPool;

		// IOstream Operators

		//        friend Istream& operator>>(Istream&, profilingInfo&);
		friend Ostream& operator<<(Ostream&, const profilingInfo&);
	};
}

#endif // !_profilingInfo_Header
