#pragma once
#ifndef _ops_Header
#define _ops_Header

namespace AutLib
{

	template<class T1, class T2>
	class eqOp2
	{
	public: void operator()(T1& x, const T2& y) const
	{
		x = y;
	}
	};

	template<class T>
	class eqOp
	{
	public: void operator()(T& x, const T& y) const
	{
		x = y;
	}
	};

	template<class T1, class T2>
	class plusEqOp2
	{
	public: void operator()(T1& x, const T2& y) const
	{
		x += y;
	}
	};

	template<class T>
	class plusEqOp
	{
	public: void operator()(T& x, const T& y) const
	{
		x += y;
	}
	};

	template<class T1, class T2>
	class minusEqOp2
	{
	public: void operator()(T1& x, const T2& y) const
	{
		x -= y;
	}
	};

	template<class T>
	class minusEqOp
	{
	public: void operator()(T& x, const T& y) const
	{
		x -= y;
	}
	};

	template<class T1, class T2>
	class multiplyEqOp2
	{
	public: void operator()(T1& x, const T2& y) const
	{
		x *= y;
	}
	};

	template<class T>
	class multiplyEqOp
	{
	public: void operator()(T& x, const T& y) const
	{
		x *= y;
	}
	};

	template<class T1, class T2>
	class divideEqOp2
	{
	public: void operator()(T1& x, const T2& y) const
	{
		x /= y;
	}
	};

	template<class T>
	class divideEqOp
	{
	public: void operator()(T& x, const T& y) const
	{
		x /= y;
	}
	};

	template<class T1, class T2>
	class eqMagOp2
	{
	public: void operator()(T1& x, const T2& y) const
	{
		x = mag(y);
	}
	};

	template<class T>
	class eqMagOp
	{
	public: void operator()(T& x, const T& y) const
	{
		x = mag(y);
	}
	};

	template<class T>
	class eqSignOp
	{
	public: void operator()(T& x, const T& y) const
	{
		x = sign(y);
	}
	};

	template<class T1, class T2>
	class plusEqMagSqrOp2
	{
	public: void operator()(T1& x, const T2& y) const
	{
		x += magSqr(y);
	}
	};

	template<class T>
	class plusEqMagSqrOp
	{
	public: void operator()(T& x, const T& y) const
	{
		x += magSqr(y);
	}
	};

	template<class T1, class T2>
	class maxEqOp2
	{
	public: void operator()(T1& x, const T2& y) const
	{
		x = max(x, y);
	}
	};

	template<class T>
	class maxEqOp
	{
	public: void operator()(T& x, const T& y) const
	{
		x = max(x, y);
	}
	};

	template<class T1, class T2>
	class minEqOp2
	{
	public: void operator()(T1& x, const T2& y) const
	{
		x = min(x, y);
	}
	};

	template<class T>
	class minEqOp
	{
	public: void operator()(T& x, const T& y) const
	{
		x = min(x, y);
	}
	};

	template<class T1, class T2>
	class andEqOp2
	{
	public: void operator()(T1& x, const T2& y) const
	{
		x = (x && y);
	}
	};

	template<class T>
	class andEqOp
	{
	public: void operator()(T& x, const T& y) const
	{
		x = (x && y);
	}
	};

	template<class T1, class T2>
	class orEqOp2
	{
	public: void operator()(T1& x, const T2& y) const
	{
		x = (x || y);
	}
	};

	template<class T>
	class orEqOp
	{
	public: void operator()(T& x, const T& y) const
	{
		x = (x || y);
	}
	};

	template<class T1, class T2>
	class eqMinusOp2
	{
	public: void operator()(T1& x, const T2& y) const
	{
		x = -y;
	}
	};

	template<class T>
	class eqMinusOp
	{
	public: void operator()(T& x, const T& y) const
	{
		x = -y;
	}
	};

	template<class T, class T1, class T2>
	class sumOp3
	{
	public: T operator()(const T1& x, const T2& y) const
	{
		return x + y;
	}
	};

	template<class T1, class T2>
	class sumOp2
	{
	public: T1 operator()(const T1& x, const T2& y) const
	{
		return x + y;
	}
	};

	template<class T>
	class sumOp
	{
	public: T operator()(const T& x, const T& y) const
	{
		return x + y;
	}
	};

	template<class T, class T1, class T2>
	class plusOp3
	{
	public: T operator()(const T1& x, const T2& y) const
	{
		return x + y;
	}
	};

	template<class T1, class T2>
	class plusOp2
	{
	public: T1 operator()(const T1& x, const T2& y) const
	{
		return x + y;
	}
	};

	template<class T>
	class plusOp
	{
	public: T operator()(const T& x, const T& y) const
	{
		return x + y;
	}
	};

	template<class T, class T1, class T2>
	class minusOp3
	{
	public: T operator()(const T1& x, const T2& y) const
	{
		return x - y;
	}
	};

	template<class T1, class T2>
	class minusOp2
	{
	public: T1 operator()(const T1& x, const T2& y) const
	{
		return x - y;
	}
	};

	template<class T>
	class minusOp
	{
	public: T operator()(const T& x, const T& y) const
	{
		return x - y;
	}
	};

	template<class T, class T1, class T2>
	class multiplyOp3
	{
	public: T operator()(const T1& x, const T2& y) const
	{
		return x * y;
	}
	};

	template<class T1, class T2>
	class multiplyOp2
	{
	public: T1 operator()(const T1& x, const T2& y) const
	{
		return x * y;
	}
	};

	template<class T>
	class multiplyOp
	{
	public: T operator()(const T& x, const T& y) const
	{
		return x * y;
	}
	};

	template<class T, class T1, class T2>
	class divideOp3
	{
	public: T operator()(const T1& x, const T2& y) const
	{
		return x / y;
	}
	};

	template<class T1, class T2>
	class divideOp2
	{
	public: T1 operator()(const T1& x, const T2& y) const
	{
		return x / y;
	}
	};

	template<class T>
	class divideOp
	{
	public: T operator()(const T& x, const T& y) const
	{
		return x / y;
	}
	};

	template<class T, class T1, class T2>
	class cmptMultiplyOp3
	{
	public: T operator()(const T1& x, const T2& y) const
	{
		return cmptMultiply(x, y);
	}
	};

	template<class T1, class T2>
	class cmptMultiplyOp2
	{
	public: T1 operator()(const T1& x, const T2& y) const
	{
		return cmptMultiply(x, y);
	}
	};

	template<class T>
	class cmptMultiplyOp
	{
	public: T operator()(const T& x, const T& y) const
	{
		return cmptMultiply(x, y);
	}
	};

	template<class T, class T1, class T2>
	class cmptDivideOp3
	{
	public: T operator()(const T1& x, const T2& y) const
	{
		return cmptDivide(x, y);
	}
	};

	template<class T1, class T2>
	class cmptDivideOp2
	{
	public: T1 operator()(const T1& x, const T2& y) const
	{
		return cmptDivide(x, y);
	}
	};

	template<class T>
	class cmptDivideOp
	{
	public: T operator()(const T& x, const T& y) const
	{
		return cmptDivide(x, y);
	}
	};

	template<class T, class T1, class T2>
	class stabiliseOp3
	{
	public: T operator()(const T1& x, const T2& y) const
	{
		return stabilise(x, y);
	}
	};

	template<class T1, class T2>
	class stabiliseOp2
	{
	public: T1 operator()(const T1& x, const T2& y) const
	{
		return stabilise(x, y);
	}
	};

	template<class T>
	class stabiliseOp
	{
	public: T operator()(const T& x, const T& y) const
	{
		return stabilise(x, y);
	}
	};

	template<class T, class T1, class T2>
	class maxOp3
	{
	public: T operator()(const T1& x, const T2& y) const
	{
		return max(x, y);
	}
	};

	template<class T1, class T2>
	class maxOp2
	{
	public: T1 operator()(const T1& x, const T2& y) const
	{
		return max(x, y);
	}
	};

	template<class T>
	class maxOp
	{
	public: T operator()(const T& x, const T& y) const
	{
		return max(x, y);
	}
	};

	template<class T, class T1, class T2>
	class minOp3
	{
	public: T operator()(const T1& x, const T2& y) const
	{
		return min(x, y);
	}
	};

	template<class T1, class T2>
	class minOp2
	{
	public: T1 operator()(const T1& x, const T2& y) const
	{
		return min(x, y);
	}
	};

	template<class T>
	class minOp
	{
	public: T operator()(const T& x, const T& y) const
	{
		return min(x, y);
	}
	};

	template<class T, class T1, class T2>
	class minModOp3
	{
	public: T operator()(const T1& x, const T2& y) const
	{
		return minMod(x, y);
	}
	};

	template<class T1, class T2>
	class minModOp2
	{
	public: T1 operator()(const T1& x, const T2& y) const
	{
		return minMod(x, y);
	}
	};

	template<class T>
	class minModOp
	{
	public: T operator()(const T& x, const T& y) const
	{
		return minMod(x, y);
	}
	};

	template<class T, class T1, class T2>
	class andOp3
	{
	public: T operator()(const T1& x, const T2& y) const
	{
		return x && y;
	}
	};

	template<class T1, class T2>
	class andOp2
	{
	public: T1 operator()(const T1& x, const T2& y) const
	{
		return x && y;
	}
	};

	template<class T>
	class andOp
	{
	public: T operator()(const T& x, const T& y) const
	{
		return x && y;
	}
	};

	template<class T, class T1, class T2>
	class orOp3
	{
	public: T operator()(const T1& x, const T2& y) const
	{
		return x || y;
	}
	};

	template<class T1, class T2>
	class orOp2
	{
	public: T1 operator()(const T1& x, const T2& y) const
	{
		return x || y;
	}
	};

	template<class T>
	class orOp
	{
	public: T operator()(const T& x, const T& y) const
	{
		return x || y;
	}
	};

	template<class T, class T1, class T2>
	class eqEqOp3
	{
	public: T operator()(const T1& x, const T2& y) const
	{
		return x == y;
	}
	};

	template<class T1, class T2>
	class eqEqOp2
	{
	public: T1 operator()(const T1& x, const T2& y) const
	{
		return x == y;
	}
	};

	template<class T>
	class eqEqOp
	{
	public: T operator()(const T& x, const T& y) const
	{
		return x == y;
	}
	};
}

#endif // !_ops_Header
