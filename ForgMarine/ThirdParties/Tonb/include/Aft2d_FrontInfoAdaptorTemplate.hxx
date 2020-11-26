#pragma once
#ifndef _Aft2d_FrontInfoAdaptorTemplate_Header
#define _Aft2d_FrontInfoAdaptorTemplate_Header

#include <Standard_TypeDef.hxx>

#include <memory>

namespace tnbLib
{

	template<class FrontTraits>
	class Aft2d_FrontInfoAdaptorTemplate
	{

	public:

		typedef typename FrontTraits::nodeType nodeType;
		typedef typename FrontTraits::edgeType edgeType;
		typedef typename FrontTraits::edgeType frontType;
		typedef typename FrontTraits::elementType elementType;

	private:

		std::shared_ptr<edgeType> thePaired0_;
		std::shared_ptr<edgeType> thePaired1_;

		std::shared_ptr<edgeType> theCreated0_;
		std::shared_ptr<edgeType> theCreated1_;

	public:

		Aft2d_FrontInfoAdaptorTemplate()
		{}

		const auto& PairedEdge0() const
		{
			return thePaired0_;
		}

		auto& PairedEdge0()
		{
			return thePaired0_;
		}

		const auto& PairedEdge1() const
		{
			return thePaired1_;
		}

		auto& PairedEdge1()
		{
			return thePaired1_;
		}

		const auto& CreatedEdge0() const
		{
			return theCreated0_;
		}

		auto& CreatedEdge0()
		{
			return theCreated0_;
		}

		const auto& CreatedEdge1() const
		{
			return theCreated1_;
		}

		auto& CreatedEdge1()
		{
			return theCreated1_;
		}

		auto IsPairedEdge0() const
		{
			return (Standard_Boolean)thePaired0_;
		}

		auto IsPairedEdge1() const
		{
			return (Standard_Boolean)thePaired1_;
		}

		auto IsCreatedEdge0() const
		{
			return (Standard_Boolean)theCreated0_;
		}

		auto IsCreatedEdge1() const
		{
			return (Standard_Boolean)theCreated1_;
		}

		void SetPairedEdge0(const std::shared_ptr<edgeType>& theEdge)
		{
			thePaired0_ = theEdge;
		}

		void SetPairedEdge1(const std::shared_ptr<edgeType>& theEdge)
		{
			thePaired1_ = theEdge;
		}

		void SetCreatedEdge0(const std::shared_ptr<edgeType>& theEdge)
		{
			theCreated0_ = theEdge;
		}

		void SetCreatedEdge1(const std::shared_ptr<edgeType>& theEdge)
		{
			theCreated1_ = theEdge;
		}

#ifdef RESET_FRONT_INFO
		void Reset()
		{
			PairedEdge0() = 0;
			PairedEdge1() = 0;

			CreatedEdge0() = 0;
			CreatedEdge1() = 0;
		}
#endif

	};
}

#endif // !_Aft2d_FrontInfoAdaptorTemplate_Header