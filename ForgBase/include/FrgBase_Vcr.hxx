#ifndef _VCR_Header
#define _VCR_Header

#include <FrgBase_Global.hxx>

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

BeginForgBaseLib

template<typename S>
void error(const S& v)
{
	cout << v << ". Program exited!\n";
	system("pause");
	exit(1);
}

template<typename T>
class FrgBase_Vcr
{

public:
	//	explicit FrgBase_Vcr(int, const T* const);  // constructor
	explicit FrgBase_Vcr(int = 0, const T & = 0);  // constructor
	FrgBase_Vcr(const FrgBase_Vcr<T>&);  // copy constructor
	~FrgBase_Vcr() { delete[] vr; }

	int size() const { return lenth; }  // number of entries

	FrgBase_Vcr<T>& operator=(const FrgBase_Vcr<T>&);  // copy assignment
	FrgBase_Vcr<T>& operator=(const T&);
	FrgBase_Vcr<T>& operator+=(const FrgBase_Vcr<T>&);
	FrgBase_Vcr<T>& operator-=(const FrgBase_Vcr<T>&);
	T& operator[](int i) { return vr[i]; }  // subscripting
	T operator[](int i) const { return vr[i]; }
	T maxnorm() const;
	T twonorm() const;

	template<typename S>
	friend S dot(const FrgBase_Vcr<S>&, const FrgBase_Vcr<S>&);
	template<typename F>
	friend F dot(F*, F*, int);
	template<typename F>
	friend FrgBase_Vcr<F> operator+(const FrgBase_Vcr<F>&);
	template<typename F>
	friend FrgBase_Vcr<F> operator-(const FrgBase_Vcr<F>&);
	template<typename F>
	friend FrgBase_Vcr<F> operator+(const FrgBase_Vcr<F>&, const FrgBase_Vcr<F>&);
	template<typename F>
	friend FrgBase_Vcr<F> operator-(const FrgBase_Vcr<F>&, const FrgBase_Vcr<F>&);
	template<typename F>
	friend FrgBase_Vcr<F> operator*(F, const FrgBase_Vcr<F>&);
	template<typename F>
	friend FrgBase_Vcr<F> operator*(const FrgBase_Vcr<F>, F);
	template<typename F>
	friend FrgBase_Vcr<F> operator/(const FrgBase_Vcr<F>&, F);
	template<typename F>
	friend FrgBase_Vcr<F> operator*(const FrgBase_Vcr<F>&, const FrgBase_Vcr<F>&);
	//	template<typename T>
	//	friend FrgBase_Vcr<T> operator*(const T&, const FrgBase_Vcr<T>&);

	void print(ostream& out = cout) const;
private:
	T* vr;
	int lenth;
};

/*template<typename T>
FrgBase_Vcr<T>::FrgBase_Vcr(int n, const T* const abd)
: lenth(n)
{
vr = new T[lenth];
for (int i = 0; i < lenth; i++) vr[i] = *(abd + i);
}*/

template<typename T>
FrgBase_Vcr<T>::FrgBase_Vcr(int n, const T& d)
	: lenth(n)
{
	vr = new T[lenth];
	for (int i = 0; i < lenth; i++) vr[i] = d;
}

template<typename T>
FrgBase_Vcr<T>::FrgBase_Vcr(const FrgBase_Vcr<T>& v)
	: lenth(v.lenth)
{
	vr = new T[lenth];
	for (int i = 0; i < lenth; i++) vr[i] = v[i];
}

template<typename T>
FrgBase_Vcr<T>& FrgBase_Vcr<T>::operator=(const FrgBase_Vcr<T>& v)
{
	if (this != &v) {
		if (lenth != v.lenth) error("bad assignment of vector");
		for (int i = 0; i < lenth; i++) vr[i] = v[i];
	}
	return *this;
}

template<typename T>
FrgBase_Vcr<T>& FrgBase_Vcr<T>::operator=(const T& s)
{
	for (int i = 0; i < lenth; i++) vr[i] = s;
	return *this;
}

template<typename T>
FrgBase_Vcr<T>& FrgBase_Vcr<T>::operator+=(const FrgBase_Vcr<T>& v)
{
	if (lenth != v.lenth) error("bad sizes");
	for (int i = 0; i < lenth; i++) vr[i] += v[i];
	return *this;
}

template<typename T>
FrgBase_Vcr<T>& FrgBase_Vcr<T>::operator-=(const FrgBase_Vcr<T>& v)
{
	if (lenth != v.lenth) error("bad sizes");
	for (int i = 0; i < lenth; i++) vr[i] -= v[i];
	return *this;
}

template<typename T>
T FrgBase_Vcr<T>::maxnorm() const
{
	T nm = abs(vr[0]);
	for (int i = 0; i < lenth; i++) nm = max(nm, abs(vr[i]));
	return nm;
}

template<typename T>
T FrgBase_Vcr<T>::twonorm() const
{
	T nm = vr[0] * vr[0];
	for (int i = 0; i < lenth; i++) nm += vr[i] * vr[i];
	return sqrt(nm);
}

template<typename S>
S dot(const FrgBase_Vcr<S>& v1, const FrgBase_Vcr<S>& v2)
{
	if (v1.lenth != v2.lenth) error("bad vector sizes");
	S tm = v1[0] * v2[0];
	for (int i = 1; i < v1.lenth; i++) tm += v1[i] * v2[i];
	return tm;
}

template<typename T>
T dot(T* a, T* b, int n) {
	T init = 0;
	for (int i = 0; i < n; i++) init += *a++ * *b++;
	return init;
}

/*template<typename T>
FrgBase_Vcr<T> operator*(const T& d, const FrgBase_Vcr<T>& v)
{
FrgBase_Vcr<T> product(v.lenth);
for (int i = 0; i < v.lenth; i++)
product[i] = d*v[i];
return product;
}*/

template<typename T>
void FrgBase_Vcr<T>::print(ostream& out) const
{
	for (int i = 0; i < lenth; i++)
		out << vr[i] << "  ";
	out << "\n";
}

template<typename T>
FrgBase_Vcr<T> operator+(const FrgBase_Vcr<T>& v)
{
	return v;
}

template<typename T>
FrgBase_Vcr<T> operator-(const FrgBase_Vcr<T>& v)
{
	return zero(v.lenth) - v;
}

template<typename T>
FrgBase_Vcr<T> operator+(const FrgBase_Vcr<T>& v1, const FrgBase_Vcr<T>& v2)
{
	if (v1.lenth != v2.lenth) error("bad vector sizes");
	FrgBase_Vcr<T> sum(v1);
	sum += v2;
	return sum;
}

template<typename T>
FrgBase_Vcr<T> operator-(const FrgBase_Vcr<T>& v1, const FrgBase_Vcr<T>& v2)
{
	if (v1.lenth != v2.lenth) error("bad vector sizes");
	FrgBase_Vcr<T> sum(v1);
	sum -= v2;
	return sum;
}

template<typename T>
FrgBase_Vcr<T> operator*(T scalar, const FrgBase_Vcr<T>& v)
{
	FrgBase_Vcr<T> tm(v.lenth);
	for (int i = 0; i < v.lenth; i++) tm[i] = scalar * v[i];
	return tm;
}

template<typename T>
FrgBase_Vcr<T> operator*(const FrgBase_Vcr<T>& v, T scalar)
{
	return scalar * v;
}

template<typename T>
FrgBase_Vcr<T> operator*(const FrgBase_Vcr<T>& v1, const FrgBase_Vcr<T>& v2)
{
	if (v1.lenth != v2.lenth) error("bad vector sizes");
	int n = v1.lenth;
	FrgBase_Vcr<T> tm(n);
	for (int i = 0; i < n; i++) tm[i] = v1[i] * v2[i];
	return tm;
}

template<typename T>
FrgBase_Vcr<T> operator/(const FrgBase_Vcr<T>& v, T scalar)
{
	if (!scalar) error("division by zero");
	return (1.0 / scalar) * v;
}

EndForgBaseLib

#endif // ! _VCR_Header
