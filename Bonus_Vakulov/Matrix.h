//Vakulov
//3/9/2017
#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <iostream>
#include <time.h>
using namespace std;
template<typename T,size_t N>
class Matrix{

public:
	Matrix() : _n(N) {
		autofill();
#ifndef NDEBUG
		cout << "Matrix ["<<_n<<"]["<<_n<<"], type - "<<typeid(T).name()<<" created!"<<endl;
#endif
	}
	~Matrix() {
#ifndef NDEBUG
		cout << "Matrix ["<<_n<<"]["<<_n<<"], type - "<<typeid(T).name()<<" deleted!"<<endl;
#endif
	}
	Matrix(const Matrix<T,N>& a) : _n(N){
		for(size_t i = 0;i<a.size();i++){
			for(size_t j=0;j<a.size();j++){
				(*this) [i][j] = a[i][j];
			}
		}
	}
	inline T* operator[](size_t n){return _mat[n];}
	inline const T* operator[](size_t n) const{return _mat[n];}
	inline const size_t& size() const {return _n;}
	void zerofill(){
		for(size_t i = 0;i<size();i++){
			for(size_t j=0;j<size();j++){
				(*this) [i][j] = 0;
			}
		}
	};
	Matrix<T,N>& operator=(const Matrix<T,N> &a){
		if(this != &a){
			for(size_t i = 0;i<size();i++){
				for(size_t j=0;j<size();j++){
					(*this) [i][j] = a[i][j];
				}
			}
		}
		return *this;
	}
private:
	const size_t _n;
	T _mat[N][N];
	void autofill(){
		for(size_t i = 0;i<size();i++){
			for(size_t j=0;j<size();j++){
				(*this) [i][j] = rand()%10;
			}
		}
	}

};

template<typename T,size_t N>
ostream& operator<<(ostream& os,const Matrix<T,N>& mat){
	for(size_t i = 0;i<mat.size();i++){
		for(size_t j=0;j<mat.size();j++){
			os<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	return os;
}



template<typename T1,typename T2,size_t N>
Matrix<T1,N>& operator-=(Matrix<T1,N>& a,const Matrix<T2,N>& b){
	for(size_t i=0;i<a.size();i++){
		for(size_t j=0;j<a.size();j++){
			a[i][j] -= b[i][j];
		}
	}
	return a;
}

template<typename T1,typename T2,size_t N>
Matrix<T1,N>& operator+=(Matrix<T1,N>& a,const Matrix<T2,N>& b){
	for(size_t i=0;i<a.size();i++){
		for(size_t j=0;j<a.size();j++){
			a[i][j] += b[i][j];
		}
	}
	return a;
}

template<typename T1,typename T2,size_t N>
const Matrix<T1,N> operator-(Matrix<T1,N> a,const Matrix<T2,N>& b){
	a-=b;
	return a;
}

template<typename T1,typename T2,size_t N>
const Matrix<T1,N> operator+(Matrix<T1,N> a,const Matrix<T2,N>& b){
	a+=b;
	return a;
}

template<typename T1,typename T2,size_t N>
const Matrix<T1,N> operator*(Matrix<T1,N> a,const Matrix<T2,N>& b){
	a*=b;
	return a;
}

template <typename T1,typename T2, size_t N> 
Matrix<T1, N>& operator*= (Matrix<T1, N>& a, const Matrix<T2, N>& b) { 
	Matrix<T1, N> res; 
	res.zerofill();
	for (size_t i = 0; i < a.size(); i++) {
		for (size_t j = 0; j < a.size(); j++) { 
			for (size_t k = 0; k < a.size(); k++) { 
				res[i][j] += a[i][k] * b[k][j]; 
			} 
		} 
	} 
	a = res; 
	return a; 
}

template<typename T1,typename T2,size_t N>
const Matrix<T1,N> operator*(Matrix<T1,N> a,const T2& b){
	a*=b;
	return a;
}

template <typename T1,typename T2, size_t N> 
Matrix<T1, N>& operator*= (Matrix<T1, N>& a, const T2& b) { 
	for (size_t i = 0; i < a.size(); i++) {
		for (size_t j = 0; j < a.size(); j++) { 
			a[i][j] *= b;
		} 
	} 
	return a; 
}
#endif