#pragma once
#ifndef _multiValued_Variable_Header
#define _multiValued_Variable_Header

#include <OFstream.hxx>
#include <Ostream.hxx>
#include <iostream>

namespace AutLib
{

	template<class Type, int nbVAR>
	class multiValued_Variable
	{

		/*Private Data*/

		Type theValue_[nbVAR];

	public:

		multiValued_Variable()
		{}

		const Type& Value(const int i) const
		{
			return theValue_[i];
		}

		Type& Value(const int i)
		{
			return theValue_[i];
		}

		void AddToPlt(OFstream& os) const;

		template<class Type, int nbVAR>
		friend std::ostream& operator<<(std::ostream& os, const multiValued_Variable&);

		template<class Type, int nbVAR>
		friend Ostream& operator<<(Ostream& os, const multiValued_Variable&);
	};

	namespace multiValued
	{
		typedef multiValued_Variable<double, 1> real_1;
		typedef multiValued_Variable<double, 2> real_2;
		typedef multiValued_Variable<double, 3> real_3;
	}
}

#include <multiValued_VariableI.hxx>

#endif // !_multiValued_Variable_Header
