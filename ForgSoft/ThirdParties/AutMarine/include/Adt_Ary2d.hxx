#pragma once
#ifndef _Adt_Ary2d_Header
#define _Adt_Ary2d_Header

#include <Standard_TypeDef.hxx>

#include <error.hxx>
#include <OSstream.hxx>

namespace AutLib
{

	template<class T>
	class Adt_Ary2d
	{

		/*private Data*/

		Standard_Integer theNbRows_;
		Standard_Integer theNbCols_;

		T** theEts_;

	public:

		Adt_Ary2d
		(
			const Standard_Integer NbRows = 0,
			const Standard_Integer nbCols = 0
		)
			: theNbRows_(NbRows)
			, theNbCols_(nbCols)
		{
			theEts_ = new T*[theNbRows_];
			forThose(Index, 0, theNbRows_ - 1)
			{
				theEts_[Index] = new T[theNbCols_];
			}
		}

		Adt_Ary2d
		(
			const Standard_Integer NbRows,
			const Standard_Integer nbCols,
			const T Value
		)
			: theNbRows_(NbRows)
			, theNbCols_(nbCols)
		{
			theEts_ = new T*[theNbRows_];
			forThose(Index1, 0, theNbRows_ - 1)
			{
				theEts_[Index1] = new T[theNbCols_];
				forThose(Index2, 0, theNbRows_ - 1)
				{
					theEts_[Index1][Index2] = Value;
				}
			}
		}

		Adt_Ary2d(const Adt_Ary2d& Other)
			: theNbRows_(Other.theNbRows_)
			, theNbCols_(Other.theNbCols_)
		{
			theEts_ = new T*[theNbRows_];
			forThose(Index1, 0, theNbRows_ - 1)
			{
				theEts_[Index1] = new T[theNbCols_];
				forThose(Index2, 0, theNbRows_ - 1)
				{
					theEts_[Index1][Index2] = Other[Index1][Index2];
				}
			}
		}

		~Adt_Ary2d()
		{
			Clear();
		}

		Adt_Ary2d& operator=(const Adt_Ary2d& Other)
		{
			theEts_ = new T*[theNbRows_];
			forThose(Index1, 0, theNbRows_ - 1)
			{
				theEts_[Index1] = new T[theNbCols_];
				forThose(Index2, 0, theNbRows_ - 1)
				{
					theEts_[Index1][Index2] = Other[Index1][Index2];
				}
			}
			return *this;
		}

		Adt_Ary2d& operator+=(const Adt_Ary2d& Other)
		{
			Debug_If_Condition_Message(NOT MatchSizeWith(Other), "No match between two Arrays");
			forThose(Index1, 0, theNbRows_ - 1)
				forThose(Index2, 0, theNbCols_ - 1)
			{
				theEts_[Index1][Index2] += Other[Index1][Index2];
			}
			return *this;
		}

		Adt_Ary2d& operator-=(const Adt_Ary2d& Other)
		{
			Debug_If_Condition_Message(NOT MatchSizeWith(Other), "No match between two Arrays");
			forThose(Index1, 0, theNbRows_ - 1)
				forThose(Index2, 0, theNbCols_ - 1)
			{
				theEts_[Index1][Index2] -= Other[Index1][Index2];
			}
			return *this;
		}

		Adt_Ary2d& operator=(const T Object)
		{
			forThose(Index1, 0, theNbRows_ - 1)
				forThose(Index2, 0, theNbCols_ - 1)
			{
				theEts_[Index1][Index2] = Object;
			}
			return *this;
		}

		Adt_Ary2d& operator+=(const T Object)
		{
			forThose(Index1, 0, theNbRows_ - 1)
				forThose(Index2, 0, theNbCols_ - 1)
			{
				theEts_[Index1][Index2] += Object;
			}
			return *this;
		}

		Adt_Ary2d& operator-=(const T Object)
		{
			forThose(Index1, 0, theNbRows_ - 1)
				forThose(Index2, 0, theNbCols_ - 1)
			{
				theEts_[Index1][Index2] -= Object;
			}
			return *this;
		}

		Adt_Ary2d& operator*=(const T Object)
		{
			forThose(Index1, 0, theNbRows_ - 1)
				forThose(Index2, 0, theNbCols_ - 1)
			{
				theEts_[Index1][Index2] *= Object;
			}
			return *this;
		}

		Adt_Ary2d& operator/=(const T Object)
		{
			forThose(Index1, 0, theNbRows_ - 1)
				forThose(Index2, 0, theNbCols_ - 1)
			{
				theEts_[Index1][Index2] /= Object;
			}
			return *this;
		}

		Adt_Ary2d& operator+()
		{
			return *this;
		}

		Adt_Ary2d operator-() 
		{
			Adt_Ary2d<T> Zero(theNbRows_, theNbCols_, 0);
			return Zero - *this;
		}

		Adt_Ary2d operator+(const T Object)
		{
			auto Temp = *this;
			Temp += Object;
			return std::move(Temp);
		}

		Adt_Ary2d operator-(const T Object)
		{
			auto Temp = *this;
			Temp -= Object;
			return std::move(Temp);
		}

		Adt_Ary2d operator*(const T Object)
		{
			auto Temp = *this;
			Temp *= Object;
			return std::move(Temp);
		}

		Adt_Ary2d operator/(const T Object)
		{
			auto Temp = *this;
			Temp /= Object;
			return std::move(Temp);
		}

		T* operator[](const Standard_Integer Index) const
		{
			Debug_Bad_Index(Index, 0, theNbRows_ - 1);
			return theEts_[Index];
		}

		T*& operator[](const Standard_Integer Index)
		{
			Debug_Bad_Index(Index, 0, theNbRows_ - 1);
			return theEts_[Index];
		}

		const T& operator()(const Standard_Integer Index1, const Standard_Integer Index2) const
		{
			Debug_Bad_Index(Index1, 0, theNbRows_ - 1);
			Debug_Bad_Index(Index2, 0, theNbCols_ - 1);

			return theEts_[Index1][Index2];
		}

		T& operator()(const Standard_Integer Index1, const Standard_Integer Index2)
		{
			Debug_Bad_Index(Index1, 0, theNbRows_ - 1);
			Debug_Bad_Index(Index2, 0, theNbCols_ - 1);

			return theEts_[Index1][Index2];
		}

		Standard_Integer Size(const Standard_Integer Index) const
		{
			if (Index == 0)
				return theNbRows_;
			else
				return theNbCols_;
		}

		Standard_Integer NbRows() const
		{
			return theNbRows_;
		}

		Standard_Integer NbCols() const
		{
			return theNbCols_;
		}

		Standard_Integer LowerRow() const
		{
			return 0;
		}

		Standard_Integer UpperRow() const
		{
			return theNbRows_ - 1;
		}

		Standard_Integer LowerCol() const
		{
			return 0;
		}

		Standard_Integer UpperCol() const
		{
			return theNbCols_ - 1;
		}

		Standard_Boolean MatchSizeWith(const Adt_Ary2d<T>& Other) const
		{
			if (theNbRows_ NOT_EQUAL Other.theNbRows_)
				return Standard_False;
			else if (theNbCols_ NOT_EQUAL Other.theNbCols_)
				return Standard_False;
			else
				return Standard_True;
		}

		void Init(const T Value)
		{
			forThose(Index1, 0, theNbRows_ - 1)
				forThose(Index2, 0, theNbCols_ - 1)
			{
				theEts_[Index1][Index2] = Value;
			}
		}

		void Clear()
		{
			forThose(Index, 0, theNbRows_ - 1)
			{
				delete[] theEts_[Index];
			}
			delete[] theEts_;
		}

		void Resize(const Standard_Integer NbRows, const Standard_Integer NbCols)
		{
			Clear();

			theNbRows_ = NbRows;
			theNbCols_ = NbCols;

			theEts_ = new T*[theNbRows_];
			forThose(Index, 0, theNbRows_ - 1)
			{
				theEts_[Index] = new T[theNbCols_];
			}
		}

		void DynResize(const Standard_Integer NbRows, const Standard_Integer NbCols)
		{
			auto Temp = *this;

			Clear();

			Standard_Integer MinNbRows = MIN(NbRows, theNbRows_);
			Standard_Integer MinNbCols = MIN(NbCols, theNbCols_);

			theNbRows_ = NbRows;
			theNbCols_ = NbCols;

			theEts_ = new T*[theNbRows_];

			forThose(Index, 0, theNbRows_ - 1)
			{
				theEts_[Index] = new T[theNbCols_];
			}

			forThose(Index1, 0, MinNbRows - 1)
				forThose(Index2, 0, MinNbCols - 1)
			{
				theEts_[Index1][Index2] = Temp[Index1][Index2];
			}
		}
	};

	template<typename T>
	Adt_Ary2d<T> operator+(const Adt_Ary2d<T>& A1, const Adt_Ary2d<T>& A2)
	{
		Adt_Ary2d<T> Temp = A1;

		Temp += A2;

		MOVE(Temp);
	}

	template<typename T>
	Adt_Ary2d<T> operator-(const Adt_Ary2d<T>& A1, const Adt_Ary2d<T>& A2)
	{
		Adt_Ary2d<T> Temp = A1;

		Temp -= A2;

		MOVE(Temp);
	}

	template<typename T>
	Adt_Ary2d<T> operator+(const Adt_Ary2d<T>& A1, const T & Object)
	{
		Adt_Ary2d<T> Temp = A1;

		Temp += Object;

		MOVE(Temp);
	}

	template<typename T>
	Adt_Ary2d<T> operator+(const T & Object, const Adt_Ary2d<T>& A1)
	{
		Adt_Ary2d<T> Temp = A1;

		Temp += Object;

		MOVE(Temp);
	}

	template<typename T>
	Adt_Ary2d<T> operator-(const Adt_Ary2d<T>& A1, const T & Object)
	{
		Adt_Ary2d<T> Temp = A1;

		Temp -= Object;

		MOVE(Temp);
	}

	template<typename T>
	Adt_Ary2d<T> operator*(const Adt_Ary2d<T>& A1, const T & Object)
	{
		Adt_Ary2d<T> Temp = A1;

		Temp *= Object;

		MOVE(Temp);
	}

	template<typename T>
	Adt_Ary2d<T> operator*(const T & Object, const Adt_Ary2d<T>& A1)
	{
		Adt_Ary2d<T> Temp = A1;

		Temp *= Object;

		MOVE(Temp);
	}

	template<typename T>
	Adt_Ary2d<T> operator/(const Adt_Ary2d<T>& A1, const T & Object)
	{
		Adt_Ary2d<T> Temp = A1;

		Temp /= Object;

		MOVE(Temp);
	}
}

#endif // !_Adt_Ary2d_Header
