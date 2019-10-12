#pragma once
#ifndef _Smart_Variable_Header
#define _Smart_Variable_Header

#include <Standard_TypeDef.hxx>
#include <Global_Named.hxx>
#include <UnitSystem.hxx>
#include <scalar.hxx>
#include <error.hxx>
#include <OSstream.hxx>

namespace AutLib
{

	class Smart_VariableSpecified
	{

		/*Private Data*/

		Standard_Boolean IsSpecified_;

	protected:

		void doSpecify()
		{
			IsSpecified_ = Standard_True;
		}

		void unSpecify()
		{
			IsSpecified_ = Standard_False;
		}

	public:

		Smart_VariableSpecified()
			: IsSpecified_(Standard_False)
		{}

		Smart_VariableSpecified(const Standard_Boolean Sp)
			: IsSpecified_(Sp)
		{}

		Standard_Boolean IsSpecified() const
		{
			return IsSpecified_;
		}
	};


	template<class Type, class UnitTypeExp>
	class Smart_Variable
		: public Global_Named
		, public Smart_VariableSpecified
	{

		typename typedef UnitType
			<
			UnitTypeExp::MASS,
			UnitTypeExp::LENGTH,
			UnitTypeExp::TIME,
			UnitTypeExp::TEMPERATURE,
			UnitTypeExp::MOLES,
			UnitTypeExp::CURRENT,
			UnitTypeExp::LUMINOUS_INTENSITY,
			UnitTypeExp::ANGLE
			>::type unit;

		/*Private Data*/

		//- The data value
		Type theValue_;

		unit theUnit_;

	public:

		//- Component type
		//typedef typename pTraits<Type>::cmptType cmptType;

		//- Construct from dictionary, with default value.
		static Smart_Variable<Type, UnitTypeExp> lookupOrDefault
		(
			const word&,
			const dictionary&,
			const unit theUnit,
			const Type& defaultValue = pTraits<Type>::zero
		);

		//- Construct from dictionary, with default value.
		//  If the value is not found, it is added into the dictionary.
		static Smart_Variable<Type, UnitTypeExp> lookupOrAddToDict
		(
			const word&,
			dictionary&,
			const unit theUnit,
			const Type& defaultValue = pTraits<Type>::zero
		);

		Smart_Variable()
			: Global_Named("unknown")
			, Smart_VariableSpecified(Standard_False)
			, theValue_(0)
		{}

		Smart_Variable
		(
			const word& theName,
			const Type x
		)
			: Global_Named(theName)
			, Smart_VariableSpecified(Standard_True)
			, theValue_(x)
		{}

		Smart_Variable
		(
			const word& theName,
			const Type x, 
			const unit theUnit
		)
			: Global_Named(theName)
			, Smart_VariableSpecified(Standard_True)
			, theValue_(x)
			, theUnit_(theUnit)
		{}

		void SetUnit(const unit theUnit)
		{
			if (theUnit_ != theUnit)
			{
				theValue_ *= ConvertUnit(theUnit_, theUnit);
				theUnit_ = theUnit;
			}
		}

		Type Value() const
		{
			if (!IsSpecified())
			{
				FatalErrorIn("Type Value() const")
					<< " No value is specified: " << Name()
					<< abort(FatalError);
			}
			return theValue_;
		}

		Type& Value()
		{
			if (!IsSpecified()) doSpecify();
			return theValue_;
		}

		unit Unit() const
		{
			return theUnit_;
		}

		// IOstream operators
		template <class Type, class UnitTypeExp>
		friend Istream& operator>>(Istream&, Smart_Variable<Type, UnitTypeExp>&);

		template <class Type, class UnitTypeExp>
		friend Ostream& operator<<(Ostream&, const Smart_Variable<Type, UnitTypeExp>&);
	};

	template<class Type>
	class Smart_Variable<Type, NullUnitExps>
		: public Global_Named
		, public Smart_VariableSpecified
	{

		/*Private Data*/

		//- The data value
		Type theValue_;

	public:

		//- Component type
		//typedef typename pTraits<Type>::cmptType cmptType;

		//- Construct from dictionary, with default value.
		static Smart_Variable<Type, NullUnitExps> lookupOrDefault
		(
			const word&,
			const dictionary&,
			const Type& defaultValue = pTraits<Type>::zero
		);

		//- Construct from dictionary, with default value.
		//  If the value is not found, it is added into the dictionary.
		static Smart_Variable<Type, NullUnitExps> lookupOrAddToDict
		(
			const word&,
			dictionary&,
			const Type& defaultValue = pTraits<Type>::zero
		);

		Smart_Variable()
			: Global_Named("unknown")
			, Smart_VariableSpecified(Standard_False)
			, theValue_(0)
		{}

		Smart_Variable(const word& theName, const Type x)
			: Global_Named(theName)
			, Smart_VariableSpecified(Standard_True)
			, theValue_(x)
		{}

		Type Value() const
		{
			if (!IsSpecified())
			{
				FatalErrorIn("Type Value() const")
					<< " No value is specified: " << Name()
					<< abort(FatalError);
			}
			return theValue_;
		}

		Type& Value()
		{
			if (!IsSpecified()) doSpecify();
			return theValue_;
		}

		Type operator()() const
		{
			return Value();
		}

		Type& operator()()
		{
			return Value();
		}

		// IOstream operators
		template <class Type>
		friend Istream& operator>>(Istream&, Smart_Variable<Type, NullUnitExps>&);

		template <class Type>
		friend Ostream& operator<<(Ostream&, const Smart_Variable<Type, NullUnitExps>&);
	};

	namespace Variables
	{

		typedef Smart_Variable<scalar, MassUnitExps> mass;
		typedef Smart_Variable<scalar, LengthUnitExps> length;
		typedef Smart_Variable<scalar, PressureUnitExps> pressure;
		typedef Smart_Variable<scalar, VelocityUnitExps> velocity;
		typedef Smart_Variable<scalar, AccelerationUnitExps> acceleration;
		typedef Smart_Variable<scalar, DensityUnitExps> density;
		typedef Smart_Variable<scalar, PowerUnitExps> power;
		typedef Smart_Variable<scalar, ForceUnitExps> force;
		typedef Smart_Variable<scalar, AngleUnitExps> angle;
		typedef Smart_Variable<scalar, DynViscosityUnitExps> dynViscosity;
		typedef Smart_Variable<scalar, KinViscosityUnitExps> kinViscosity;

		typedef Smart_Variable<scalar, NullUnitExps> realDimless;
		typedef Smart_Variable<label, NullUnitExps> labelDimless;
	}
}

#include <Smart_VariableI.hxx>

#endif // !_Smart_Variable_Header
