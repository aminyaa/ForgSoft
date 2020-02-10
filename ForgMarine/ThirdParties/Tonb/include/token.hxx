#pragma once
#ifndef _token_Header
#define _token_Header

#include <label.hxx>
#include <uLabel.hxx>
#include <scalar.hxx>
#include <word.hxx>
#include <InfoProxy.hxx>
#include <refCount.hxx>
#include <typeInfo.hxx>
#include <autoPtr.hxx>

#include <HashTable.hxx> //- added by amir
#include <Istream.hxx> //- added by amir

#define NoHashTableC
#include <runTimeSelectionTables.hxx>

#include <iostream>

namespace tnbLib
{

	// Forward declaration of friend functions and operators
	class Istream;
	class token;
	Istream& operator>>(Istream&, token&);
	Ostream& operator<<(Ostream&, const token&);

	/*---------------------------------------------------------------------------*\
							   Class token Declaration
	\*---------------------------------------------------------------------------*/

	class token
	{

	public:

		//- Enumeration defining the types of token
		enum tokenType
		{
			UNDEFINED,

			PUNCTUATION,
			WORD,
			STRING,
			LABEL,
			FLOAT_SCALAR,
			DOUBLE_SCALAR,
			LONG_DOUBLE_SCALAR,
			COMPOUND,

			FATALERROR
		};


		//- Standard punctuation tokens
		enum punctuationToken
		{
			NULL_TOKEN = '\0',
			SPACE = ' ',
			TAB = '\t',
			NL = '\n',

			END_STATEMENT = ';',
			BEGIN_LIST = '(',
			END_LIST = ')',
			BEGIN_SQR = '[',
			END_SQR = ']',
			BEGIN_BLOCK = '{',
			END_BLOCK = '}',
			COLON = ':',
			COMMA = ',',

			BEGIN_STRING = '"',
			END_STRING = BEGIN_STRING,

			ASSIGN = '=',
			ADD = '+',
			SUBTRACT = '-',
			MULTIPLY = '*',
			DIVIDE = '/'
		};


		//- Abstract base class for complex tokens
		class compound
			:
			public refCount
		{
			// Private data

			bool empty_;


			// Private Member Functions

				//- Disallow default bitwise copy construct
			compound(const compound&);

			//- Disallow default bitwise assignment
			void operator=(const compound&);


		public:

			//- Runtime type information
			TypeName("compound");


			//- Declare run-time constructor selection table
			typedef autoPtr<compound> (*IstreamConstructorPtr)(Istream& is);
			typedef HashTable<IstreamConstructorPtr, word, string::hash> IstreamConstructorTable;
			static IstreamConstructorTable* IstreamConstructorTablePtr_;

			template <class compoundType>
			class addIstreamConstructorToTable
			{
			public:
				static autoPtr<compound> New(Istream& is) { return autoPtr<compound>(new compoundType(is)); }

				addIstreamConstructorToTable(const word& lookup = compoundType::typeName)
				{
					constructIstreamConstructorTables();
					IstreamConstructorTablePtr_->insert(lookup, New);
				}

				~addIstreamConstructorToTable() { destroyIstreamConstructorTables(); }
			};

			static void constructIstreamConstructorTables();
			static void destroyIstreamConstructorTables();


			// Constructors

				//- Construct null
			compound()
				:
				empty_(false)
			{}


			// Selectors

				//- Select null constructed
			static autoPtr<compound> New(const word& type, Istream&);


			// Destructor

			virtual ~compound();


			// Member Functions

				// Access

					//- Return true if name is a compound type
			static bool isCompound(const word& name);

			bool empty() const
			{
				return empty_;
			}

			bool& empty()
			{
				return empty_;
			}

			virtual label size() const = 0;


			// Check

			// Edit

			// Write

			virtual void write(Ostream&) const = 0;


			// IOstream Operators

			friend Ostream& operator<<(Ostream&, const compound&);
		};


		//- A templated class for holding compound tokens

#ifndef SWIG
		template<class T>
		class Compound
			:
			public token::compound,
			public T
		{
		public:

			//- Runtime type information
			TypeName("Compound<T>");

			Compound(Istream& is)
				:
				T(is)
			{}

			label size() const
			{
				return T::size();
			}

			void write(Ostream& os) const
			{
				operator<<(os, static_cast<const T&>(*this));
			}
		};
#endif

		//- Static undefined token
		static token undefinedToken;


	private:

		// Private data

			//- The token type
		tokenType type_;

		//- Anonymous Union of token types
		union
		{
			punctuationToken punctuationToken_;
			word* wordTokenPtr_;
			string* stringTokenPtr_;
			label labelToken_;
			floatScalar floatScalarToken_;
			doubleScalar doubleScalarToken_;
			longDoubleScalar longDoubleScalarToken_;
			mutable compound* compoundTokenPtr_;
		};

		//- Line number in the file this token was read from
		label lineNumber_;


		// Private member functions

			//- Clear any allocated storage (word or string)
		void clear();

		// Parse error, expected 'expected', found ...
		void parseError(const char* expected) const;


	public:

		// Static data members

		static const char* const typeName;


		// Constructors

			//- Construct null
		token();

		//- Construct as copy
		token(const token&);

		//- Construct punctuation character token
		token(punctuationToken, label lineNumber = 0);

		//- Construct word token
		token(const word&, label lineNumber = 0);

		//- Construct string token
		token(const string&, label lineNumber = 0);

		//- Construct label token
		token(const label, label lineNumber = 0);

		//- Construct floatScalar token
		token(const floatScalar, label lineNumber = 0);

		//- Construct doubleScalar token
		token(const doubleScalar, label lineNumber = 0);

		//- Construct longDoubleScalar token
		token(const longDoubleScalar, label lineNumber = 0);

		//- Construct from Istream
		token(Istream&);


		// Destructor

		~token();


		// Member functions

			// Access

		tokenType type() const;

		bool good() const;
		bool undefined() const;
		bool error() const;

		bool isPunctuation() const;
		punctuationToken pToken() const;

		bool isWord() const;
		const word& wordToken() const;

		bool isString() const;
		const string& stringToken() const;

		bool isLabel() const;
		label labelToken() const;

		bool isFloatScalar() const;
		floatScalar floatScalarToken() const;

		bool isDoubleScalar() const;
		doubleScalar doubleScalarToken() const;

		bool isLongDoubleScalar() const;
		longDoubleScalar longDoubleScalarToken() const;

		bool isScalar() const;
		scalar scalarToken() const;

		bool isNumber() const;
		scalar number() const;

		bool isCompound() const;
		const compound& compoundToken() const;
		compound& transferCompoundToken();

		label lineNumber() const;
		label& lineNumber();


		// Edit

			//- Set bad
		void setBad();


		// Info

			//- Return info proxy.
			//  Used to print token information to a stream
		InfoProxy<token> info() const
		{
			return *this;
		}


		// Member operators

			// Assignment

		void operator=(const token&);

		void operator=(const punctuationToken);

		void operator=(word*);
		void operator=(const word&);

		void operator=(string*);
		void operator=(const string&);

		void operator=(const label);
		void operator=(const floatScalar);
		void operator=(const doubleScalar);
		void operator=(const longDoubleScalar);

		void operator=(compound*);


		// Equality

		bool operator==(const token&) const;
		bool operator==(const punctuationToken) const;
		bool operator==(const word&) const;
		bool operator==(const string&) const;
		bool operator==(const label) const;
		bool operator==(const floatScalar) const;
		bool operator==(const doubleScalar) const;
		bool operator==(const longDoubleScalar) const;


		// Inequality

		bool operator!=(const token&) const;
		bool operator!=(const punctuationToken) const;
		bool operator!=(const word&) const;
		bool operator!=(const string&) const;
		bool operator!=(const label) const;
		bool operator!=(const floatScalar) const;
		bool operator!=(const doubleScalar) const;
		bool operator!=(const longDoubleScalar) const;


		// IOstream operators

		friend Istream& operator>>(Istream&, token&);
		friend Ostream& operator<<(Ostream&, const token&);

		friend Ostream& operator<<(Ostream&, const punctuationToken&);
		friend std::ostream& operator<<(std::ostream&, const punctuationToken&);

		friend std::ostream& operator<<(std::ostream&, const InfoProxy<token>&);
	};


	Ostream& operator<<(Ostream&, const token::punctuationToken&);
	std::ostream& operator<<(std::ostream&, const token::punctuationToken&);
	std::ostream& operator<<(std::ostream&, const InfoProxy<token>&);
	Ostream& operator<<(Ostream&, const token::compound&);


#define defineCompoundTypeName(Type, Name)                                    \
    typedef token::Compound<Type > tokenCompound##Name##_;                    \
    defineTemplateTypeNameAndDebugWithName(tokenCompound##Name##_, #Type, 0);

#define addCompoundToRunTimeSelectionTable(Type, Name)                        \
    token::compound::addIstreamConstructorToTable<token::Compound<Type >>    \
        add##Name##IstreamConstructorToTable_;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#include <tokenI.hxx>

#endif // !_token_Header
