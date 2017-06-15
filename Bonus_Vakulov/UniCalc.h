//Vakulov
//3/9/2017
#include "Wrapper.h"
template <typename T1, typename T2>
class UniCalc;

template<typename T1, typename T2>
class UniCalc<Wrapper<T1>, Wrapper<T2>>{
private:
	Wrapper<T1> _a;
	Wrapper<T2> _x;
public:
	UniCalc(const T1& a = T1(),const T2& x = T2()) : _a(a),_x(x){};
	const T1& getA() {return _a.a();}
	const T2& getX() {return _x.a();}
	void setA(const T1& a){_a.a() = a;}
	void setX(const T2& x){_x.a() = x;}

	typedef const T1(*const pocc)(Wrapper<T1>,const Wrapper<T2> &);
	const T1 doOp(pocc f){
		return f(_a,_x);
	}

	typedef T1&(*const pocr) (Wrapper<T1>&, const Wrapper<T2>&);
	const Wrapper<T1> doOp(pocr f){
		return (_a = f(_a,_x));
	}
};