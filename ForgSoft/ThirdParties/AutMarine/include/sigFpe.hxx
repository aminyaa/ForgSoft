#pragma once
#ifndef _sigFpe_Header
#define _sigFpe_Header

typedef	void(*__p_sig_fn_t)(int);

namespace AutLib
{

	class sigFpe
	{
		// Private data

		//- Saved old signal trapping setting
		static __p_sig_fn_t oldAction_;


		// Static data members

		//- Handler for caught signals
		static void sigFpeHandler(int);

	public:


		// Constructors

		sigFpe();


		// Destructor

		~sigFpe();


		// Member functions

		void set(const bool verbose);
	};
}

#endif // !_sigFpe_Header
