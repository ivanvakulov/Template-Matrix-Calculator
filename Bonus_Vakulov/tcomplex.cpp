//Vakulov Ivan
//2/11/2017
#include "acomplex.h"
#include "tcomplex.h"
int TComplex::_freeId = 0;

TComplex::TComplex(const double ro, const double phi) : _id(++_freeId),_ro(ro),_phi(phi){
#ifndef NDEBUG
	cout<<"TComplex with id: "<<_id<<" created - "<< *this <<endl;
#endif
}

TComplex::TComplex(const TComplex& a) : _id(++_freeId),_ro(a._ro),_phi(a._phi){
#ifndef NDEBUG
	cout<<"TComplex with id: "<<_id<<" copied form id: "<<a.getId() << " - "<< *this <<endl;
#endif
}

TComplex::~TComplex(){
#ifndef NDEBUG
	cout<<"TComplex with id: "<<_id<<" deleted"<<endl;
#endif
}

TComplex::TComplex (const AComplex& a) : _id(++_freeId),_ro(a.mod()),_phi(a.arg()){
#ifndef NDEBUG
	cout<<"AComplex with id: "<<a.getId()<< " - "<<a<<" casted to TComplex with id:"<<_id<<" - "<<*this<<endl;
#endif
}

/*TComplex::operator AComplex() const{
#ifndef NDEBUG
	cout<<"TComplex with id: "<<_id<< " - "<<*this<<" casted to AComplex"<<endl;
#endif
	return AComplex(re(),im());
}*/

TComplex& TComplex::operator=(const TComplex& a){
	if(this != &a){
		_ro = a._ro;
		_phi = a._phi;
	}
	return *this;
}

TComplex& operator*=(TComplex& a, const TComplex& b){
	a.mod()*=b.mod();
	a.arg()+=b.arg();
	return a;
}

TComplex& operator/=(TComplex& a, const TComplex& b){
	a.mod()/=b.mod();
	a.arg()-=b.arg();
	return a;
}

TComplex& operator+=(TComplex& a, const TComplex& b){
	a = a+b;
	return a;
}

TComplex& operator-=(TComplex& a, const TComplex& b){
	a = a-b;
	return a;
}

const TComplex operator*(const TComplex& a, const TComplex& b){
	return TComplex(a.mod() * b.mod(), a.arg() + b.arg());
}

const TComplex operator/(const TComplex& a, const TComplex& b){
	return TComplex(a.mod() / b.mod(), a.arg() - b.arg());
}

const TComplex power(const TComplex& a, unsigned int n){
	return TComplex(pow(a.mod(), double(n)), n * a.arg());
}

ostream& operator<<(ostream& os, const TComplex& a){
	return os << "("<<a.mod()<<";"<<a.arg()<<")";
}

istream& operator>>(istream& is, TComplex& t) { 
	return is >> t.mod() >> t.arg(); 
}