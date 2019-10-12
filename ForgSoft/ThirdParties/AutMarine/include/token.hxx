#pragma once
#ifndef _token_Header
#define _token_Header

#include <refCount.hxx>
#include <word.hxx>
#include <autoPtr.hxx>
#include <InfoProxy.hxx>
#include <HashTable.hxx>

namespace AutLib
{

	template<class T, class Key, class Hash>
	class HashTable;

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
			: public refCount
		{

			// Private data

			bool empty_;

			// Private Member Functions

			//- Disallow default bitwise copy construct
			compound(const compound&) = delete;

			//- Disallow default bitwise assignment
			void operator=(const compound&) = delete;

		public:

			//- Runtime type information
			static const char* typeName_() { return "compound"; }
			static const word typeName;
			static debug::debugSwitch debug;;
			virtual const word& type() const { return typeName; };

			/* Construct from argList function pointer type */
			typedef autoPtr< compound >(*IstreamConstructorPtr)(Istream& is);

			/* Construct from argList function table type */
			typedef HashTable< IstreamConstructorPtr, word, string::hash >
				IstreamConstructorTable;

			/* Construct from argList function pointer table pointer */
			static IstreamConstructorTable* IstreamConstructorTablePtr_;

			/* Table constructor called from the table add function */
			static void constructIstreamConstructorTables();

			/* Table destructor called from the table add function destructor */
			static void destroyIstreamConstructorTables();

			/* Class to add constructor from argList to table */
			template< class compoundType >
			class addIstreamConstructorToTable
			{
			public:

				static autoPtr< compound > New(Istream& is)
				{
					return autoPtr< compound >(new compoundType(is));
				}

				addIstreamConstructorToTable
				(
					const word& lookup = compoundType::typeName
				)
				{
					constructIstreamConstructorTables();
					IstreamConstructorTablePtr_->insert(lookup, New);
				}

				~addIstreamConstructorToTable()
				{
					destroyIstreamConstructorTables();
				}
			};

			/* Class to add constructor from argList to table */
			/* Remove only the entry (not the table) upon destruction */
			template< class compoundType >
			class addRemovableIstreamConstructorToTable
			{
				/* retain lookup name for later removal */
				const word& lookup_;

			public:

				static autoPtr< compound > New(Istream& is)
				{
					return autoPtr< compound >(new compoundType(is));
				}

				addRemovableIstreamConstructorToTable
				(
					const word& lookup = compoundType::typeName
				)
					: lookup_(lookup)
				{
					constructIstreamConstructorTables();
					IstreamConstructorTablePtr_->set(lookup, New);
				}

				~addRemovableIstreamConstructorToTable()
				{
					if (IstreamConstructorTablePtr_)
					{
						IstreamConstructorTablePtr_->erase(lookup_);
					}
				}
			};

			compound()
				: empty_(false)
			{}

			//- Select null constructed
			static autoPtr<compound> New(const word& type, Istream&);

			virtual ~compound();

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

			virtual void write(Ostream&) const = 0;

			// IOstream Operators

			friend Ostream& operator<<(Ostream&, const compound&);
		};


		template<class T>
		class Compound
			: public token::compound
			, public T
		{
		public:

			//- Runtime type information
			static const char* typeName_() { return "Compound<T>"; }

			static const word typeName;
			static debug::debugSwitch debug;;

			virtual const word& type() const { return typeName; };

			Compound(Istream& is)
				: T(is)
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

	Ostream& operator<<(Ostream&, const InfoProxy<token>&);
}

#include <tokenI.hxx>

#endif // !_token_Header
