#pragma once
#ifndef _Mesh_EntityCounterM_Header
#define _Mesh_EntityCounterM_Header


#define Mesh_EntityCounter(EntityName)					\
	class Mesh_##EntityName##Counter					\
	{													\
		/*Private Data*/								\
		Standard_Integer the##EntityName##_;			\
														\
	public:												\
														\
		Mesh_##EntityName##Counter()					\
			: the##EntityName##_(0)						\
			{}											\
														\
		Standard_Integer EntityName() const				\
		{												\
			return the##EntityName##_;					\
		}												\
														\
		Standard_Integer& EntityName()					\
		{												\
			return the##EntityName##_;					\
		}												\
	}

#endif // !_Mesh_EntityCounterM_Header