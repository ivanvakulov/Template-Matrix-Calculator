//Vakulov
//3/9/2017
#ifndef _WRAPPER_H_
#define _WRAPPER_H_
#include "Matrix.h"

template <typename T>
class Wrapper{
public:
	Wrapper(const T& v = T()) : _a(v){
#ifndef NDEBUG
		cout << "Wrapper [type: " << typeid(T).name() << "] " << this << " created"<<endl;
#endif
	}
	Wrapper(const Wrapper<T>& w) : _a(w._a){
#ifndef NDEBUG
  cout << "Wrapper [type: " << typeid(T).name() << "] " << this << " copied from " << this << endl;
#endif 
	}
	Wrapper& operator=(const Wrapper& w){
		if(this != &w){
			_a = w._a;
		}
		return *this;
	}
	~Wrapper(){
#ifndef NDEBUG
  cout << "Wrapper [type: " << typeid(T).name() << "] " << this << " deleted"<<endl;
#endif
	}
	operator T() { return  _a; }
	inline const T& a() const { return _a; }
	inline T& a() { return _a; }
private:
	T _a;
};

template <typename T1, typename T2>
 T1& operator/=(Wrapper<T1>&a,const Wrapper<T2>& b){
	return (a.a()/=b.a());
}

template <typename T1, typename T2>
 T1& operator*=(Wrapper<T1>&a,const Wrapper<T2>&b){
	return (a.a()*=b.a());
}

template <typename T1, typename T2>
 T1& operator+=(Wrapper<T1>&a,const Wrapper<T2>& b){
	return (a.a()+=b.a());
}

template <typename T1, typename T2>
 T1& operator-=(Wrapper<T1>&a,const Wrapper<T2>& b){
	return (a.a()-=b.a());
}

template <typename T1, typename T2>
const T1 operator/(Wrapper<T1> a,const Wrapper<T2>& b){
	return a/=b;
}

template <typename T1, typename T2>
const T1 operator*(Wrapper<T1> a,const Wrapper<T2>& b){
	return a*=b;
}

template <typename T1, typename T2>
const T1 operator+(Wrapper<T1> a,const Wrapper<T2>& b){
	return a+=b;
}

template <typename T1, typename T2>
const T1 operator-(Wrapper<T1> a,const Wrapper<T2>& b){
	return a-=b;
}
#endif