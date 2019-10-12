#pragma once
#ifndef _Hash_Header
#define _Hash_Header

#include <label.hxx>
#include <Hasher.hxx>

namespace AutLib
{

	template<class PrimitiveType>
	class Hash
	{
	public:

		Hash()
		{}

		unsigned operator()(const PrimitiveType& p, unsigned seed) const
		{
			return Hasher(&p, sizeof(p), seed);
		}

		unsigned operator()(const PrimitiveType& p) const
		{
			return Hasher(&p, sizeof(p));
		}

	};

	//- Hash specialization for hashing labels
	template<>
	class Hash<label>
	{
	public:

		Hash()
		{}

		//- Incrementally hash a label.
		//  This will necessarily return a different value than the
		//  non-incremental version.
		unsigned operator()(const label& p, unsigned seed) const
		{
			return Hasher(&p, sizeof(label), seed);
		}

		//- Return the unsigned representation of a label.
		//  This helps if people have relied on the hash value corresponding to
		//  the natural order.
		unsigned operator()(const label& p) const
		{
			return p;
		}
	};

	template<>
	class Hash<void*>
	{
	public:

		Hash()
		{}

		unsigned operator()(const void* const& p, unsigned seed) const
		{
			return Hash<intptr_t>()(intptr_t(p), seed);
		}

		unsigned operator()(const void* const& p) const
		{
			return Hash<intptr_t>()(intptr_t(p));
		}

	};
}

#endif // !_Hash_Header
