#pragma once
namespace AutLib
{
	template<class Type, int nbVAR>
	inline void multiValued_Variable<Type, nbVAR>::AddToPlt(OFstream & os) const
	{
		for (int i = 0; i < nbVAR; i++)
		{
			os << Value(i) << "  ";
		}
	}

	template<class Type, int nbVAR>
	std::ostream & operator<<
		(
			std::ostream & os, 
			const multiValued_Variable<Type, nbVAR>& m
			)
	{
		for (int i = 0; i < nbVAR; i++)
		{
			os << m.Value(i) << "  ";
		}
	}

	template<class Type, int nbVAR>
	Ostream & operator<<
		(
			Ostream & os, 
			const multiValued_Variable<Type, nbVAR>& m
			)
	{
		for (int i = 0; i < nbVAR - 2; i++)
		{
			os << m.Value(i) << ", ";
		}
		os << m.Value(nbVAR - 1);
	}
}