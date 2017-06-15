//Vakulov Ivan
//2/11/2017
#ifndef _ACOMPLEX_H_
#define _ACOMPLEX_H_

#include <iostream>
#include <cmath>
using namespace std;

class TComplex;
class AComplex{
private: 
	double _re, _im; 
	static int _freeId;
	const int _id;
public: 
	AComplex(const double re = 0, const double im = 0); 
	AComplex (const TComplex&);
	AComplex(const AComplex&); 
	~AComplex(); 
	//operator TComplex() const; 
	AComplex& operator=(const AComplex&); 
	inline double& re() { return _re; } 
	inline double& im() { return _im; } 
	inline const double& re() const { return _re; } 
	inline const double& im() const { return _im; }
	inline double mod() const { return sqrt(_re * _re + _im * _im); } 
	inline double arg() const { return atan2(_im, _re); } 
	inline const AComplex conj() const { return AComplex(_re, -_im); } 
	inline const int& getId() const {return _id;}
};


AComplex& operator+=(AComplex&, const AComplex&);
AComplex& operator-=(AComplex&, const AComplex&);
AComplex& operator*=(AComplex&, const AComplex&);
AComplex& operator/=(AComplex&, const AComplex&);

const AComplex power(const AComplex&, unsigned int);

const AComplex operator+(const AComplex&, const AComplex&); 
const AComplex operator-(const AComplex&, const AComplex&); 
bool operator==(const AComplex&, const AComplex&); 
bool operator!=(const AComplex&, const AComplex&); 
ostream& operator<<(ostream&, const AComplex&); 
istream& operator>>(istream&, AComplex&);
#endif