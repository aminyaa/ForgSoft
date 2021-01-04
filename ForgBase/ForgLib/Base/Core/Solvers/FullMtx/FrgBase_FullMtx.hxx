#ifndef _FULLMTX_Header
#define _FULLMTX_Header

#include <FrgBase_AbsMtx.hxx>

BeginForgBaseLib

template<typename T>
class FrgBase_FullMtx :public FrgBase_AbsMtx < T >
{

public:
	explicit FrgBase_FullMtx(int n, int m, T**);  // constructor
	FrgBase_FullMtx(int n, int m, const T & = 0);  // constructor
	FrgBase_FullMtx(const FrgBase_FullMtx<T>&);  // copy constructor
	~FrgBase_FullMtx()
	{
		for (int i = 0; i < nrows; i++) delete[] mx[i];
		delete[] mx;
	}

	FrgBase_FullMtx<T>& operator=(const FrgBase_FullMtx<T>&);
	FrgBase_FullMtx<T>& operator+=(const FrgBase_FullMtx<T>&);
	FrgBase_FullMtx<T>& operator-=(const FrgBase_FullMtx<T>&);
	FrgBase_FullMtx<T>& operator+();
	FrgBase_FullMtx<T> operator-();
	FrgBase_FullMtx<T> operator+(const FrgBase_FullMtx<T>&);
	FrgBase_FullMtx<T> operator-(const FrgBase_FullMtx<T>&);
	T* operator[](int i) const { return mx[i]; }
	FrgBase_Vcr<T> operator*(const FrgBase_Vcr<T>&) const;

	FrgBase_Vcr<T> diagonal() const;
	FrgBase_Vcr<T> diagonal_inverse() const;
	T product(const FrgBase_Vcr<T>&, int, int, int) const;

	int size_row() const { return nrows; }
	int size_cols() const { return ncols; }

	void GaussElim(FrgBase_Vcr<T>&) const;  // Gauss elimination without pivoting
	void GaussElimPP(FrgBase_Vcr<T>&) const;  // Gauss Elim with partial pivoting
	void GaussElimCP(FrgBase_Vcr<T>&) const;  // Gauss Elim with complete pivoting

	void print(ostream& out = cout) const;
private:
	int ncols;
	T** mx;
	FrgBase_Vcr<T> preconding(const FrgBase_Vcr<T>&, int i = 0) const;
};

template<typename T>
FrgBase_FullMtx<T>::FrgBase_FullMtx(int n, int m, T** dbp)
{
	nrows = n;
	ncols = m;
	mx = new T * [nrows];
	for (int i = 0; i < nrows; i++) {
		mx[i] = new T[ncols];
		for (int j = 0; j < ncols; j++) mx[i][j] = dbp[i][j];
	}
}

template<typename T>
FrgBase_FullMtx<T>::FrgBase_FullMtx(int n, int m, const T& a)
{
	nrows = n;
	ncols = m;
	mx = new T * [nrows];
	for (int i = 0; i < nrows; i++) {
		mx[i] = new T[ncols];
		for (int j = 0; j < ncols; j++) mx[i][j] = a;
	}
}

template<typename T>
FrgBase_FullMtx<T>::FrgBase_FullMtx(const FrgBase_FullMtx<T>& mat)
{
	nrows = mat.nrows;
	ncols = mat.ncols;
	mx = new T * [nrows];
	for (int i = 0; i < nrows; i++) {
		mx[i] = new T[ncols];
		for (int j = 0; j < ncols; j++) mx[i][j] = mat.mx[i][j];
	}
}

template<typename T>
FrgBase_FullMtx<T>& FrgBase_FullMtx<T>::operator=(const FrgBase_FullMtx<T>& mat)
{
	if (this != &mat) {
		if (nrows != mat.nrows || ncols != mat.ncols) error("bad matrix sizes");
		for (int i = 0; i < nrows; i++)
			for (int j = 0; j < ncols; j++)
				mx[i][j] = mat.mx[i][j];
	}
	return *this;
}

template<typename T>
FrgBase_FullMtx<T>& FrgBase_FullMtx<T>::operator+=(const FrgBase_FullMtx<T>& mat)
{
	if (nrows != mat.nrows || ncols != mat.ncols) error("bad matrix sizes");
	for (int i = 0; i < nrows; i++)
		for (int j = 0; j < ncols; j++)
			mx[i][j] += mat.mx[i][j];
	return *this;
}

template<typename T>
FrgBase_FullMtx<T>& FrgBase_FullMtx<T>::operator-=(const FrgBase_FullMtx<T>& mat)
{
	if (nrows != mat.nrows || ncols != mat.ncols) error("bad matrix sizes");
	for (int i = 0; i < nrows; i++)
		for (int j = 0; j < ncols; j++)
			mx[i][j] -= mat.mx[i][j];
	return *this;
}

template<typename T>
FrgBase_FullMtx<T>& FrgBase_FullMtx<T>::operator+()
{
	return *this;
}

template<typename T>
FrgBase_FullMtx<T> FrgBase_FullMtx<T>::operator-()
{
	FrgBase_FullMtx<T> zero(nrows, ncols);
	return zero - *this;
}

template<typename T>
FrgBase_FullMtx<T> FrgBase_FullMtx<T>::operator+(const FrgBase_FullMtx<T>& mat)
{
	FrgBase_FullMtx<T> sum = *this;
	sum += mat;
	return sum;
}

template<typename T>
FrgBase_FullMtx<T> FrgBase_FullMtx<T>::operator-(const FrgBase_FullMtx<T>& mat)
{
	FrgBase_FullMtx<T> sum = *this;
	sum -= mat;
	return sum;
}

template<typename T>
FrgBase_Vcr<T> FrgBase_FullMtx<T>::operator*(const FrgBase_Vcr<T>& v) const
{
	if (ncols != v.size()) error("matrix and vector sizes do not match");
	FrgBase_Vcr<T> tm(nrows);
	for (int i = 0; i < nrows; i++)
		for (int j = 0; j < ncols; j++)
			tm[i] += mx[i][j] * v[j];
	return tm;
}

template<typename T>
FrgBase_Vcr<T> FrgBase_FullMtx<T>::diagonal() const
{
	FrgBase_Vcr<T> tmp(nrows);
	for (int i = 0; i < nrows; i++)
		tmp[i] = mx[i][i];
	return tmp;
}

template<typename T>
FrgBase_Vcr<T> FrgBase_FullMtx<T>::diagonal_inverse() const
{
	FrgBase_Vcr<T> tmp(nrows);
	for (int i = 0; i < nrows; i++) {
		if (mx[i][i] == 0) error("diagonal entry is zero");
		tmp[i] = 1.0 / mx[i][i];
	}
	return tmp;
}

template<typename T>
T FrgBase_FullMtx<T>::product(const FrgBase_Vcr<T>& vr, int indx, int down, int up) const
{
	T tmp = 0;
	for (int j = down; j < up; j++)
		tmp += mx[indx][j] * vr[j];
	return tmp;
}

template<typename T>
void FrgBase_FullMtx<T>::GaussElim(FrgBase_Vcr<T>& bb) const
{
	if (nrows != bb.size() || nrows != ncols) error("matrix or vector sizes do not match");
	FrgBase_FullMtx<T> tmpx = *this;

	// LU decomposition without pivoting
	for (int k = 0; k < nrows - 1; k++) {
		if (tmpx[k][k] == 0) error("pivot is zero");
		for (int i = k + 1; i < nrows; i++) {
			if (tmpx[i][k] != 0) {
				T mult = tmpx[i][k] / tmpx[k][k];
				tmpx[i][k] = mult;
				for (int j = k + 1; j < ncols; j++)
					tmpx[i][j] -= mult * tmpx[k][j];
			}
		}
	}

	// forward substitution 
	for (int i = 1; i < nrows; i++)
		for (int j = 0; j < i; j++) bb[i] -= tmpx[i][j] * bb[j];

	// back substitution
	for (int i = nrows - 1; i >= 0; i--) {
		for (int j = i + 1; j < nrows; j++) bb[i] -= tmpx[i][j] * bb[j];
		bb[i] /= tmpx[i][i];
	}
}  // end GaussElim function

template<typename T>
void FrgBase_FullMtx<T>::GaussElimPP(FrgBase_Vcr<T>& bb) const
{
	if (nrows != bb.size() || nrows != ncols) error("matrix or vector sizes do not match");
	FrgBase_FullMtx<T> tmpx = *this;

	Vcr<int> pvt(nrows);   // pivoting vector
	for (int k = 0; k < nrows; k++) pvt[k] = k;

	for (int k = 0; k < nrows - 1; k++) {  // main loop

		// find the pivot in column k in rows pvt[k],
		// pvt[k+1], ..., pvt[n-1]

		int pc = k;
		double aet = abs(tmpx[pvt[k]][k]);
		for (int i = k + 1; i < nrows; i++) {
			if (abs(tmpx[pvt[i]][k]) > aet) {
				aet = abs(tmpx[pvt[i]][k]);
				pc = i;
			}
		}

		if (!aet)
			error("pivot is zero in FrgBase_FullMtx::GaussElimPP()");
		if (pc != k) swap(pvt[k], pvt[pc]);
		int pvtk = pvt[k];   // pivot row
		T pivot = tmpx[pvtk][k];  // pivot

		// now eliminate column entries logically
		// below tmpx[pvt[k]][k]
		for (int i = k + 1; i < nrows; i++) {
			int pvti = pvt[i];
			if (tmpx[pvti][k] != 0) {
				T mult = tmpx[pvti][k] / pivot;
				tmpx[pvti][k] = mult;
				for (int j = k + 1; j < ncols; j++)
					tmpx[pvti][j] -= mult * tmpx[pvtk][j];
			}
		}
	}

	// forward substitution for L y = Pb.
	for (int i = 1; i < nrows; i++)
		for (int j = 0; j < i; j++)
			bb[pvt[i]] -= tmpx[pvt[i]][j] * bb[pvt[j]];

	// back substitution for U x = y.
	FrgBase_Vcr<T> xx(nrows);  // xx stores solution in correct order
	for (int i = nrows - 1; i >= 0; i--) {
		for (int j = i + 1; j < ncols; j++)
			bb[pvt[i]] -= tmpx[pvt[i]][j] * xx[j];
		xx[i] = bb[pvt[i]] / tmpx[pvt[i]][i];
	}

	bb = xx;  // put solution in bb
}  // end function GaussElimPP()

template<typename T>
void FrgBase_FullMtx<T>::GaussElimCP(FrgBase_Vcr<T>& bb) const
{
	if (nrows != bb.size() || nrows != ncols) error("matrix or vector sizes do not match");
	FrgBase_FullMtx<T> tmpx = *this;

	Vcr<int> px(nrows);   // row pivoting vector
	Vcr<int> qy(nrows);   // column pivoting vector
	for (int k = 0; k < nrows; k++) px[k] = qy[k] = k;

	for (int k = 0; k < nrows - 1; k++) {  // main loop

		// find pivot entry in column qy[k], qy[k+1], ...,
		// qy[n-1] and in rows px[k], px[k+1], ..., px[n-1]
		int pct = k, qdt = k;
		T aet = 0;
		for (int i = k; i < nrows; i++) {
			for (int j = k; j < nrows; j++) {
				T tmp = abs(tmpx[px[i]][qy[j]]);
				if (tmp > aet) {
					aet = tmp;
					pct = i;
					qdt = j;
				}
			}
		}

		if (!aet) error("pivot is zero in GaussElimCP()");

		swap(px[k], px[pct]);
		swap(qy[k], qy[qdt]);

		// eliminate column entries logically below and right
		// to the entry mx[px[k]][qy[k]]
		for (int i = k + 1; i < nrows; i++) {
			if (tmpx[px[i]][qy[k]] != 0) {
				T mult = tmpx[px[i]][qy[k]] / tmpx[px[k]][qy[k]];
				tmpx[px[i]][qy[k]] = mult;
				for (int j = k + 1; j < nrows; j++)
					tmpx[px[i]][qy[j]] -= mult * tmpx[px[k]][qy[j]];
			}
		}
	}

	// forward substitution for L y = Pb. Store y in b
	for (int i = 1; i < nrows; i++)
		for (int j = 0; j < i; j++)
			bb[px[i]] -= tmpx[px[i]][qy[j]] * bb[px[j]];

	// back substitution for U z = y and x = Q z
	FrgBase_Vcr<T> xx(nrows);  // xx stores solution
	for (int i = nrows - 1; i >= 0; i--) {
		for (int j = i + 1; j < nrows; j++)
			bb[px[i]] -= tmpx[px[i]][qy[j]] * xx[qy[j]];
		xx[qy[i]] = bb[px[i]] / tmpx[px[i]][qy[i]];
	}

	bb = xx;
}  // end function GaussElimCP()

template<typename T>
FrgBase_Vcr<T> FrgBase_FullMtx<T>::preconding(const FrgBase_Vcr<T>& r, int precn) const
{
	if (precn == 0) {  // no preconditioner is used
		return r;
	}
	else if (precn == 1) {  // diagonal preconditioning
		FrgBase_Vcr<T> z(nrows);
		for (int i = 0; i < nrows; i++) z[i] = r[i] / mx[i][i];
		return z;
	}
	else if (precn == 2) {  // symmetric SOR precondition
		const T omega = 1.75;   // SSOR parameter
		FrgBase_Vcr<T> z(nrows);
		for (int i = 0; i < nrows; i++) {
			T sum = 0;
			for (int j = 0; j < i; j++) sum += mx[i][j] * z[j];
			z[i] = (r[i] - omega * sum) / mx[i][i];
		}
		for (int i = nrows - 1; i >= 0; i--) {
			T sum = 0;
			for (int j = i + 1; j < nrows; j++)
				sum += mx[i][j] * z[j];
			z[i] -= omega * sum / mx[i][i];
		}
		return z;
	}
	else {
		error("specified preconditioner not implemented");
	}
}  // end function preconding

template<typename T>
void FrgBase_FullMtx<T>::print(ostream& out) const
{
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) out << mx[i][j] << "   ";
		out << endl;
	}
}

EndForgBaseLib

#endif // ! _FULLMTX_Header
