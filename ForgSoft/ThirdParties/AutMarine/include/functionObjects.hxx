#pragma once
#ifndef _functionObjects_Header
#define _functionObjects_Header

#include <autoPtr.hxx>
#include <HashTable.hxx>

namespace AutLib
{

	class Time;
	class dictionary;

	class functionObject
	{
		// Private data

		//- Name
		const word name_;


		// Private Member Functions

		//- Disallow default bitwise copy construct
		functionObject(const functionObject&) = delete;

		//- Disallow default bitwise assignment
		void operator=(const functionObject&) = delete;


	public:

		//- Runtime type information
		virtual const word& type() const = 0;

		static debug::debugSwitch debug;


		// Declare run-time constructor selection tables

		/*Amir*/

		/* Construct from argList function pointer type */
		typedef autoPtr< functionObject >(*dictionaryConstructorPtr)(const word& name, const Time& t, const dictionary& dict);

		/* Construct from argList function table type */
		typedef HashTable< dictionaryConstructorPtr, word, string::hash >
			dictionaryConstructorTable;

		/* Construct from argList function pointer table pointer */
		static dictionaryConstructorTable* dictionaryConstructorTablePtr_;

		/* Class to add constructor from argList to table */
		template< class functionObjectType >
		class adddictionaryConstructorToTable
		{
		public:

			static autoPtr< functionObject > New(const word& name, const Time& t, const dictionary& dict)
			{
				return autoPtr< functionObject >(new functionObjectType(name, t, dict));
			}

			adddictionaryConstructorToTable
			(
				const word& lookup = functionObjectType::typeName
			)
			{
				constructdictionaryConstructorTables();
				dictionaryConstructorTablePtr_->insert(lookup, New);
			}

			~adddictionaryConstructorToTable()
			{
				destroydictionaryConstructorTables();
			}
		};

		/* Table constructor called from the table add function */
		static void constructdictionaryConstructorTables();

		/* Table destructor called from the table add function destructor */
		static void destroydictionaryConstructorTables();

		// Constructors

		//- Construct from components
		functionObject(const word& name);

		//- Return clone
		autoPtr<functionObject> clone() const
		{
			notImplemented("functionObject::clone() const");
			return autoPtr<functionObject>(NULL);
		}

		//- Return a pointer to a new functionObject created on freestore
		//  from Istream
		class iNew
		{
			const Time& time_;

		public:

			iNew(const Time& t)
				:
				time_(t)
			{
			}

			autoPtr<functionObject> operator()
				(
					const word& name,
					Istream& is
					) const;
		};


		// Selectors

		//- Select from dictionary, based on its "type" entry
		static autoPtr<functionObject> New
		(
			const word& name,
			const Time&,
			const dictionary&
		);


		// Destructor

		virtual ~functionObject();


		// Member Functions

		//- Name
		virtual const word& name() const;

		//- Called at the start of the time-loop
		virtual bool start() = 0;

		//- Called at each ++ or += of the time-loop
		virtual bool execute() = 0;

		//- Called when Time::run() determines that the time-loop exits.
		//  By default it simply calls execute().
		virtual bool end();

		//- Read and set the function object if its data have changed
		virtual bool read(const dictionary&) = 0;
	};
}

#endif // !_functionObjects_Header
