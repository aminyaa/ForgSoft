#pragma once
#ifndef _Aft_Model_Cache_Header
#define _Aft_Model_Cache_Header

#include <map>
#include <memory>

namespace AutLib
{

	// Forward Declarations

	class Aft2d_Model_Cache
	{

	public:

		typedef std::map<unsigned, unsigned> indexMap;

	private:

		/*Private Data*/

	protected:

		mutable unsigned nodeIndex;
		mutable unsigned edgeIndex;
		mutable unsigned elementIndex;

		mutable std::shared_ptr<indexMap> NodesIndices;
		mutable std::shared_ptr<indexMap> EdgesIndices;
		mutable std::shared_ptr<indexMap> ElementsIndices;

		Aft2d_Model_Cache()
		{}
	};

	class Aft3d_Model_Cache
	{

	public:

		typedef std::map<unsigned, unsigned> indexMap;

	private:

		/*Private Data*/

	protected:

		mutable unsigned nodeIndex;
		mutable unsigned edgeIndex;
		mutable unsigned facetIndex;
		mutable unsigned elementIndex;

		mutable std::shared_ptr<indexMap> NodesIndices;
		mutable std::shared_ptr<indexMap> EdgesIndices;
		mutable std::shared_ptr<indexMap> FacetsIndices;
		mutable std::shared_ptr<indexMap> ElementsIndices;

		Aft3d_Model_Cache()
		{}
	};
}

#endif // !_Aft_Model_Cache_Header
