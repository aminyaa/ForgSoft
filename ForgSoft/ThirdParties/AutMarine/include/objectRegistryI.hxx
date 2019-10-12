#pragma once
#include <typeInfo.hxx>
namespace AutLib
{
	template<class Type>
	wordList objectRegistry::names() const
	{
		wordList objectNames(size());

		label count = 0;
		for (const_iterator iter = begin(); iter != end(); ++iter)
		{
			if (isA<Type>(*iter()))
			{
				objectNames[count++] = iter()->name();
			}
		}

		objectNames.setSize(count);

		return objectNames;
	}


	template<class Type>
	HashTable<const Type*> objectRegistry::lookupClass() const
	{
		HashTable<const Type*> objectsOfClass(size());

		for (const_iterator iter = begin(); iter != end(); ++iter)
		{
			if (isA<Type>(*iter()))
			{
				objectsOfClass.insert
				(
					iter()->name(),
					dynamic_cast<const Type*>(iter())
				);
			}
		}

		return objectsOfClass;
	}


	template<class Type>
	bool objectRegistry::foundObject(const word& name) const
	{
		const_iterator iter = find(name);

		if (iter != end())
		{
			const Type* vpsiPtr_ = dynamic_cast<const Type*>(iter());

			if (vpsiPtr_)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			/*if (&parent_ != dynamic_cast<const objectRegistry*>(&time_))
			{
				return parent_.foundObject<Type>(name);
			}
			else
			{
				return false;
			}*/

			/*Amir*/
			if (&parent_ != dynamic_cast<const objectRegistry*>(&parent_))
			{
				return parent_.foundObject<Type>(name);
			}
			else
			{
				return false;
			}
		}
	}


	template<class Type>
	const Type& objectRegistry::lookupObject(const word& name) const
	{
		const_iterator iter = find(name);

		if (iter != end())
		{
			const Type* vpsiPtr_ = dynamic_cast<const Type*>(iter());

			if (vpsiPtr_)
			{
				return *vpsiPtr_;
			}

			FatalErrorIn("objectRegistry::lookupObject<Type>(const word&) const")
				<< nl
				<< "    lookup of " << name << " from objectRegistry "
				<< this->name()
				<< " successful\n    but it is not a " << Type::typeName
				<< ", it is a " << iter()->type()
				<< abort(FatalError);
		}
		else
		{
			/*if (&parent_ != dynamic_cast<const objectRegistry*>(&time_))
			{
				return parent_.lookupObject<Type>(name);
			}*/
			/*Amir*/
			if (&parent_ != dynamic_cast<const objectRegistry*>(&parent_))
			{
				return parent_.lookupObject<Type>(name);
			}
			else
			{
				FatalErrorIn
				(
					"objectRegistry::lookupObject<Type>(const word&) const"
				) << nl
					<< "    request for " << Type::typeName
					<< " " << name << " from objectRegistry " << this->name()
					<< " failed\n    available objects of type " << Type::typeName
					<< " are" << nl
					<< names<Type>()
					<< abort(FatalError);
			}
		}

		return *reinterpret_cast<const Type*>(0);
	}
}