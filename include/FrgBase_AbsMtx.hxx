#ifndef _ABSMTX_Header
#define _ABSMTX_Header

#include <FrgBase_Vcr.hxx>

BeginForgBaseLib

template<typename T>
class FrgBase_AbsMtx
{

public:
	virtual FrgBase_Vcr<T> operator*(const FrgBase_Vcr<T>&) const = 0;  // matrix-vector multiply

	int Jacobi(FrgBase_Vcr<T>&, const FrgBase_Vcr<T>&, T&, T, int&);
	int GaussSeidel(FrgBase_Vcr<T>&, const FrgBase_Vcr<T>&, T&, T, int&);
	int CG(FrgBase_Vcr<T>&, const FrgBase_Vcr<T>&, T&, int&, int);
	int GMRES(FrgBase_Vcr<T>& x, const FrgBase_Vcr<T>& b, T& eps, int& iter, int pcn, int m);
	int BiCGStab(FrgBase_Vcr<T>&, const FrgBase_Vcr<T>&, T&, int&, int) const;
protected:
	int nrows;
	virtual FrgBase_Vcr<T> preconding(const FrgBase_Vcr<T>& r, int = 0) const = 0;
	virtual FrgBase_Vcr<T> diagonal() const = 0;                // return diagonal entries
	virtual FrgBase_Vcr<T> diagonal_inverse() const = 0;        // return inverse of diagonal entries
	virtual T product(const FrgBase_Vcr<T>&, int, int, int) const = 0;

};

template<typename T>
int FrgBase_AbsMtx<T>::Jacobi(FrgBase_Vcr<T>& x, const FrgBase_Vcr<T>& b, T& eps, T omega, int& iter)
{
	// x: on entry: initial guess;
	//    on return: approximate solution
	// b: right hand side vector
	// eps: on entry: stopping criterion, epsilon
	//      on return: absolute residual in two-norm for approximate solution
	// iter: on entry: max number iterations allowed
	//       on return: actual number of iteration taken

	fstream res;
	res.open("residual.plt", ios::out);
	res << "VARIABLES = Iteration  Residual\n";

	if (nrows != b.size()) error("matrix and vector sizes do not match");
	const int maxiter = iter;
	FrgBase_Vcr<T> r = b - (*this) * x;       // initial residual
	const T stp = eps * b.twonorm();  // stopping criterion

	if (!r.maxnorm()) {
		eps = 0.0;
		iter = 0;
		return 0;
	}

	const FrgBase_Vcr<T> diag = this->diagonal_inverse();
	FrgBase_Vcr<T> xold = x;

	for (iter = 0; iter < maxiter; iter++) {  // main loop
		x = (1.0 - omega) * xold + omega * diag * (b - (*this) * xold + this->diagonal() * xold);
		r = x - xold;
		T norm = r.twonorm();
		res << iter << "  " << norm << "\n";
		if (norm <= stp) break;
		xold = x;
	}

	eps = r.twonorm();
	if (iter == maxiter) return 1;
	else return 0;
}  // end function jacobi

template<typename T>
int FrgBase_AbsMtx<T>::GaussSeidel(FrgBase_Vcr<T>& x, const FrgBase_Vcr<T>& b, T& eps, T omega, int& iter)
{
	// x: on entry: initial guess;
	//    on return: approximate solution
	// b: right hand side vector
	// eps: on entry: stopping criterion, epsilon
	//      on return: absolute residual in two-norm for approximate solution
	// iter: on entry: max number iterations allowed
	//       on return: actual number of iteration taken

	if (nrows != b.size()) error("matrix and vector sizes do not match");
	const int maxiter = iter;
	FrgBase_Vcr<T> r = b - (*this) * x;       // initial residual
	const T stp = eps * b.twonorm();  // stopping criterion

	if (!r.maxnorm()) {
		eps = 0.0;
		iter = 0;
		return 0;
	}

	const FrgBase_Vcr<T> diag = this->diagonal_inverse();
	FrgBase_Vcr<T> xold = x;

	fstream res;
	res.open("residual.plt", ios::out);
	res << "VARIABLES = Iteration  Residual\n";

	for (iter = 1; iter < maxiter; iter++) {  // main loop
		for (int i = 0; i < b.size(); i++)
		{
			x[i] = (1.0 - omega) * xold[i]
				+ diag[i] * omega * (b[i] - (*this).product(x, i, 0, i) - (*this).product(xold, i, i + 1, b.size()));
		}
		r = x - xold;
		T norm = r.twonorm();
		res << iter << "  " << norm << "\n";
		if (norm <= stp) break;
		xold = x;
	}

	eps = r.twonorm();
	if (iter == maxiter) return 1;
	else return 0;
}

template<typename T>
int FrgBase_AbsMtx<T>::CG(FrgBase_Vcr<T>& x, const FrgBase_Vcr<T>& b, T& eps, int& iter, int pcn)
{
	// preconditioned conjugate gradient method for Ax=b
	// It returns 0 if successful and 1 if breakdown
	// x: on entry: initial guess;
	//    on return: approximate solution
	// b: right hand side vector
	// eps: on entry: stopping criterion, epsilon
	//      on return: absolute residual in two-norm for approximate solution
	// iter: on entry: max number iterations allowed
	//       on return: actual number of iteration taken
	// pcn: = 0 if no preconditioner, = 1 if diag precond
	//      = 2 if SSOR preconditioner

	if (nrows != b.size()) error("matrix and vector sizes do not match");
	const int maxiter = iter;
	FrgBase_Vcr<T> r = b - (*this) * x;       // initial residual
	FrgBase_Vcr<T> p = r;

	const T stp = eps * b.twonorm();  // stopping criterion

	if (!r.maxnorm()) {
		eps = 0.0;
		iter = 0;
		return 0;
	}

	fstream res;
	res.open("residual.plt", ios::out);
	res << "VARIABLES = Iteration  Residual\n";

	T rho0;

	for (iter = 0; iter < maxiter; iter++) {  // main loop
		FrgBase_Vcr<T> w = preconding(r, pcn);
		T rho = dot(r, w);

		if (iter == 0) p = w;
		else {
			T beta = rho / rho0;
			p = w + beta * p;
		}

		FrgBase_Vcr<T> q = (*this) * p;
		T alpha = rho / dot(p, q);
		x += alpha * p;
		r -= alpha * q;
		T norm = r.twonorm();
		res << iter << "  " << norm << "\n";

		if (norm <= stp) break;

		rho0 = rho;
	}

	eps = r.twonorm();
	if (iter == maxiter) return 1;
	else return 0;
}  // end CG function

template<typename T>
int FrgBase_AbsMtx<T>::BiCGStab(FrgBase_Vcr<T>& x, const FrgBase_Vcr<T>& b, T& eps, int& iter, int pcn) const
{
	// preconditioned conjugate gradient method for Ax=b
	// It returns 0 if successful and 1 if breakdown
	// x: on entry: initial guess;
	//    on return: approximate solution
	// b: right hand side vector
	// eps: on entry: stopping criterion, epsilon
	//      on return: absolute residual in two-norm for approximate solution
	// iter: on entry: max number iterations allowed
	//       on return: actual number of iteration taken
	// pcn: = 0 if no preconditioner, = 1 if diag precond
	//      = 2 if SSOR preconditioner

	if (nrows != b.size()) error("matrix and vector sizes do not match");
	const int maxiter = iter;
	FrgBase_Vcr<T> r0 = b - (*this) * x;       // initial residual
	FrgBase_Vcr<T> rb(r0.size(), 1.0);
	FrgBase_Vcr<T> p0 = r0;
	FrgBase_Vcr<T> v0 = r0;
	FrgBase_Vcr<T> p = r0;

	const T stp = eps * b.twonorm();  // stopping criterion

	if (!r0.maxnorm()) {
		eps = 0.0;
		iter = 0;
		return 0;
	}

	T rho0;
	T alpha0;
	T omega0;

	fstream res;
	res.open("residual.plt", ios::out);
	res << "VARIABLES = Iteration  Residual\n";

	for (iter = 0; iter < maxiter; iter++) {  // main loop
		T rho = dot(rb, r0);

		if (rho == 0) error("unexpected zero-divisor in BiCGStab: rho");

		if (iter == 0);
		else {
			T beta = (rho / rho0) * (alpha0 / omega0);
			p = r0 + beta * (p0 - omega0 * v0);
		}

		FrgBase_Vcr<T> pb = preconding(p, pcn);
		FrgBase_Vcr<T> v = (*this) * pb;
		T alpha = rho / dot(rb, v);
		FrgBase_Vcr<T> s = r0 - alpha * v;

		if (s.twonorm() <= stp) {
			x += alpha * pb;
			break;
		}

		FrgBase_Vcr<T> sb = preconding(s, pcn);
		FrgBase_Vcr<T> t = (*this) * sb;
		T omega = dot(t, s) / dot(t, t);
		x += alpha * pb + omega * sb;
		FrgBase_Vcr<T> r = s - omega * t;
		T norm = r.twonorm();
		res << iter << "  " << norm << "\n";

		if (norm <= stp) break;

		if (omega == 0) error("unexpected zero-divisor in BiCGStab: omega");

		r0 = r;
		v0 = v;
		p0 = p;
		rho0 = rho;
		alpha0 = alpha;
		omega0 = omega;
	}

	eps = r0.twonorm();
	if (iter == maxiter) return 1;
	else return 0;
}  // end function BiCGStab()

template<typename T>
int FrgBase_AbsMtx<T>::GMRES(FrgBase_Vcr<T>& x, const FrgBase_Vcr<T>& b, T& eps, int& iter, int pcn, int m)
{
	// Restarted GMRES for solving Ax = b, called GMRES(m)
	// Return 0 if successful and 1 if breackdown
	// It outputs the approximate solution, residual, and
	// number of iterations taken.
	//
	// A: any nonsingular matrix, may not be symmetric
	// x: on entry: initial guess
	//    on return: approximate solution
	// b: right-side vector
	// eps: on entry: stopping criterion, epsilon
	//      on return: absolute residual in two-norm for approximate solution
	// iter: on entry: max number iterations allowed
	//       on return: actual number of iteration taken
	// pcn: = 0 if no preconditioner, = 1 if diag precond
	//      = 2 if SSOR preconditioner
	// m: number of iteration for restarting GMRES

	const int maxiter = iter;
	const T stp = (preconding(b, pcn)).twonorm() * eps;
	FrgBase_Vcr<T> r = preconding(b - (*this) * x, pcn);
	T beta = r.twonorm();
	bool conv = false;

	if (m > nrows)
		error("In GMRES(m), m is bigger than number of rows");
	if (abs(beta) <= stp) {  // return if initial guess
		eps = abs(beta);    // is true
		iter = 0;
		return 0;
	}

	// orthonormal basis for krylov space,
	// v[i] is a pointer to ith basis vector
	FrgBase_Vcr<T>** v = new FrgBase_Vcr<T>*[m + 1];
	for (int i = 0; i <= m; i++)
		v[i] = new FrgBase_Vcr<T>(nrows);  // ith orthonormal basis

	// Hessenburg matrix h, (m+1) by m;
	// h[i] stores ith column of h that has i+2 entries.
	// Only nonzero part of h is stored
	T** h = new T * [m];
	for (int i = 0; i < m; i++) h[i] = new T[i + 2];

	fstream res;
	res.open("residual.plt", ios::out);
	res << "VARIABLES = Iteration  Residual\n";

	iter = 1;
	while (iter <= maxiter) {  // iterations for GMRES(m)
		*v[0] = r / beta;
		FrgBase_Vcr<T> g(m + 1);
		g[0] = beta;

		FrgBase_Vcr<T> cs(m), sn(m);
		int k;
		for (k = 0; k < m && iter <= maxiter; k++, iter++) {
			FrgBase_Vcr<T> w = preconding((*this) * (*v[k]), pcn);
			T nmw = w.twonorm();
			for (int i = 0; i <= k; i++) {
				h[k][i] = dot(w, *v[i]);
				w -= h[k][i] * (*v[i]);
			}
			h[k][k + 1] = w.twonorm();

			// if h[k][k+1] is small, do reorthogonalization
			if (nmw + 1.0e-4 * h[k][k + 1] == nmw) {
				for (int i = 0; i <= k; i++) {
					T hri = dot(w, *v[i]);  // reorthogonalization
					h[k][i] += hri;
					w -= hri * (*v[i]);
				}
				h[k][k + 1] = w.twonorm();
			}
			if (h[k][k + 1] == 0)
				error("unexpected zero-divisor in GMRES");
			*v[k + 1] = w / h[k][k + 1];

			// apply givens G_0, G_1, ..., G_{k-1} to column k of h
			for (int i = 0; i < k; i++) {
				T tv[2] = { cs[i], sn[i] };
				T tmp = dot(&h[k][i], tv, 2);
				h[k][i + 1] = -sn[i] * h[k][i] + cs[i] * h[k][i + 1];
				h[k][i] = tmp;
			}

			// generate givens rotation G_k from kth column of h
			if (h[k][k + 1] == 0) {
				cs[k] = 1;
				sn[k] = 0;
			}
			else {
				T tpm = sqrt(dot(&h[k][k], &h[k][k], 2));
				cs[k] = h[k][k] / tpm;
				sn[k] = h[k][k + 1] / tpm;
			}

			// apply givens rotaion G_k to kth column of h and go g
			T tv[2] = { cs[k], sn[k] };
			h[k][k] = dot(&h[k][k], tv, 2);
			T tmp = dot(&g[k], tv, 2);
			g[k + 1] = -sn[k] * g[k] + cs[k] * g[k + 1];
			g[k] = tmp;
			if (abs(g[k + 1]) <= stp) {  // stop if residual small
				k++;
				break;
			}
		}

		// back solve the upper triangular system
		for (int i = k - 1; i >= 0; i--) {
			for (int j = i + 1; j < k; j++) g[i] -= h[j][i] * g[j];
			g[i] /= h[i][i];
		}

		// update the solution x = x0 + sum v[i]*y[i]
		for (int i = 0; i < k; i++) x += g[i] * (*v[i]);

		// calculate residual and check for convergence
		r = preconding(b - (*this) * x, pcn);
		beta = r.twonorm();
		res << iter << "  " << beta << "\n";
		if (abs(beta) <= stp) { // stop if residual small
			conv = true;
			break;
		}
	}

	eps = (b - (*this) * x).twonorm();  // get final residual

	// deallocate space for v and h
	for (int i = 0; i <= m; i++) delete v[i];
	delete[] v;
	for (int i = 0; i < m; i++) delete[] h[i];
	delete[] h;

	if (conv) return 0;
	else return 1;
} // end function GMRES(m)

EndForgBaseLib

#endif // !_ABSMTX_Header
