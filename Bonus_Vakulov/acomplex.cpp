//Vakulov Ivan
//2/11/2017
#include "acomplex.h"
#include "tcomplex.h"
int AComplex::_freeId = 0;

AComplex::AComplex(const double re , const double im ) : _id(++_freeId),_re(re),_im(im){
#ifndef NDEBUG
	cout<<"AComplex with id: "<<_id<<" created - "<< *this <<endl;
#endif
}

AComplex::AComplex(const AComplex& a) : _id(++_freeId),_re(a._re),_im(a._im){
#ifndef NDEBUG
	cout<<"AComplex with id: "<<_id<<" copied form id: "<<a.getId() << " - "<< *this <<endl;
#endif
}

AComplex::~AComplex(){
#ifndef NDEBUG
	cout<<"AComplex with id: "<<_id<<" deleted"<<endl;
#endif
}

AComplex::AComplex (const TComplex& t) : _id(++_freeId),_re(t.re()),_im(t.im()){
#ifndef NDEBUG
	cout<<"TComplex with id: "<<t.getId()<< " - "<<t<<" casted to AComplex with id:"<<_id<<" - "<<*this<<endl;
#endif
}

/*AComplex::operator TComplex() const{
#ifndef NDEBUG
	cout<<"AComplex with id: "<<_id<< " - "<<*this<<" casted to TComplex"<<endl;
#endif
	return TComplex(mod(),arg());
}*/

AComplex& AComplex::operator=(const AComplex& a){
	if(this != &a){
		_re = a._re;
		_im = a._im;
	}
	return *this;
}

AComplex& operator+=(AComplex& a, const AComplex& b){
	a.re()+=b.re();
	a.im()+=b.im();
	return a;
}

AComplex& operator-=(AComplex& a, const AComplex& b){
	a.re()-=b.re();
	a.im()-=b.im();
	return a;
}

AComplex& operator*=(AComplex& a, const AComplex& b){
	a = a*b;
	return a;
}

AComplex& operator/=(AComplex& a, const AComplex& b){
	a = a/b;
	return a;
}

const AComplex operator+(const AComplex& a, const AComplex& b){
	return AComplex(a.re()+b.re(),a.im()+b.im());
}

const AComplex operator-(const AComplex& a, const AComplex& b){
	return AComplex(a.re()-b.re(),a.im()-b.im());
}

bool operator==(const AComplex& a, const AComplex& b){
	return a.re()==b.re()&&a.im()==b.im();
}

bool operator!=(const AComplex& a, const AComplex& b){
	return !(a==b);
}

const AComplex power(const AComplex& a, unsigned int n){
	return power(TComplex(a), n);
}

ostream& operator<<(ostream& os, const AComplex& a){
	return os << "("<<a.re()<<";"<<a.im()<<")";
}

istream& operator>>(istream& is, AComplex& a) { 
	return is >> a.re() >> a.im(); 
}