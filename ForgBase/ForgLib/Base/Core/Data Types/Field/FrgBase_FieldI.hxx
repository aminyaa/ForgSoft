#pragma once

#include <FrgBase_SymbolTable.hxx>

//template<typename T>
//inline std::string ForgBaseLib::FrgBase_Field<T>::GetFullPresentationName(const std::string& delimiter) const
//{
//	if (theSymbolTable_)
//		return theSymbolTable_->GetFullPresentationName(delimiter) + delimiter + thePresentationName_;
//
//	return thePresentationName_;
//}

//template<typename T>
//inline std::string ForgBaseLib::FrgBase_Field<T>::GetFullName(const std::string& delimiter) const
//{
//	if (theSymbolTable_)
//		return theSymbolTable_->GetFullName(delimiter) + delimiter + theName_;
//
//	return theName_;
//}

//template<typename T>
//inline bool ForgBaseLib::FrgBase_Field<T>::AddVariableToSymbolTable()
//{
//	if (!theSymbolTable_)
//		return false;
//
//	if constexpr (std::is_same_v<T, double>)
//		return theSymbolTable_->AddVariable(GetFullName(), theValue_);
//	else if constexpr (std::is_same_v<T, std::vector<double>>)
//		return theSymbolTable_->AddVector(GetFullName(), theValue_);
//
//	return false;
//}

//template<typename T>
//inline void ForgBaseLib::FrgBase_Field<T>::Build()
//{
//	if (theSymbolTable_)
//		theSymbolTable_->AddVariable(GetFullName(), theValue_);
//}

//template<typename T>
//inline std::vector<ForgBaseLib::FrgBase_SymbolTable*> ForgBaseLib::FrgBase_Field<T>::RetrieveSymbolTables() const
//{
//	std::vector<FrgBase_SymbolTable*> tables;
//
//	FrgBase_SymbolTable* base = theSymbolTable_;
//	while (base)
//	{
//		tables.push_back(theSymbolTable_);
//
//		base = theSymbolTable_->GetParentSymbolTable();
//	}
//
//	return tables;
//}