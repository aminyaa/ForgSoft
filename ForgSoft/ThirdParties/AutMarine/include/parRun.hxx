#pragma once
#ifndef _parRun_Header
#define _parRun_Header

#include <Pstream.hxx>

namespace AutLib
{

	class ParRunControl
	{
		bool RunPar;

	public:

		ParRunControl()
			: RunPar(false)
		{}

		~ParRunControl()
		{
			if (RunPar)
			{
				Info << "Finalising parallel run" << endl;
				Pstream::exit(0);
			}
		}

		void runPar(int& argc, char**& argv)
		{
			RunPar = true;

			if (!Pstream::init(argc, argv))
			{
				Info << "Failed to start parallel run" << endl;
				Pstream::exit(1);
			}
		}

		bool parRun() const
		{
			return RunPar;
		}
	};
}

#endif // !_parRun_Header
