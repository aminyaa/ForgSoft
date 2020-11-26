#pragma once
#ifndef _FrgBase_Global_Header
#define _FrgBase_Global_Header

#include <FrgBase_Global_Build.hxx>
#include <FrgBase_Global_Type.hxx>

#include <iostream>
#include <vector>
#include <list>
#include <map>

#define FrgGetMacro(type, name, object)\
type Get##name##() const {return object;}
//type& Get##name##() {return object;}

template<typename T>
using StdVector = std::vector<T>;

template<typename T>
using StdList = std::list<T>;

template<typename T, typename U>
using StdMap = std::map<T, U>;

template<typename T>
using StdSharedPtr = std::shared_ptr<T>;

#define StdMakeSharedPtr(type) std::make_shared<type>
#define StdDynamicPtrCast(type) std::dynamic_pointer_cast<type>
#define StdStaticPtrCast(type) std::static_pointer_cast<type>

#define NullPtr nullptr

#define FrgCout std::cout <<
#define FrgEndL << std::endl
#define FrgSpace << "  " <<
#define FrgTab << "\t" <<

#define BeginForgBaseLib namespace ForgBaseLib {
#define EndForgBaseLib }

template<class T>
QString CorrectName(T* parentItem, const QString& name)
{
	QString correctedName;
	bool canBeAdded = false;

	int numberAdded = 1;
	while (!canBeAdded)
	{
		if (numberAdded == 1)
			correctedName = name.simplified();
		else
			correctedName = name.simplified() + " " + QString::number(numberAdded);

		bool wasFound = false;
		for (int i = 0; i < parentItem->childCount(); i++)
		{
			if (parentItem->child(i)->text(0) == correctedName)
			{
				numberAdded++;
				wasFound = true;
				break;
			}
		}
		if(wasFound)
			continue;

		canBeAdded = true;
	}

	return correctedName;
}

#define FreePointer(ptr)\
if(ptr)\
{\
delete ptr;\
ptr = NullPtr;\
}

#define FreeVectorOfPointers(vec)\
for(int iPointer=0; iPointer < vec.size(); iPointer++)\
FreePointer(vec[iPointer]);

#define AreSameType(listOfItems, Type, result)\
if(listOfItems.size() == 1)\
result = False;\
else\
{for (int iSameType = 0; iSameType < listOfItems.size(); iSameType++)\
{\
if (!dynamic_cast<Type*>(listOfItems[iSameType]))\
{result = False; break;}\
else\
{result = True; }\
}}

#endif // !_FrgBase_Global_Header
