//Vakulov Ivan
//2/11/2017
#ifndef _TCOMP_H_
#define _TCOMP_H_

#include <cmath>
#include <iostream>
using namespace std;

class AComplex;
class TComplex{
private:
	double _ro, _phi;
	static int _freeId;
	const int _id;
public:
	TComplex(const double ro=0, const double phi=0);
	TComplex (const AComplex&);
	TComplex(const TComplex& z);
	~TComplex();
	//operator AComplex() const;
	TComplex& operator=(const TComplex&);
	inline double& mod() {return _ro;}
	inline double& arg() {return _phi;}
	inline const double& mod() const {return _ro;}
	inline const double& arg() const {return _phi;}
	inline double re() const {return _ro*cos(_phi);}
	inline double im() const {return _ro*sin(_phi);}
	inline const int& getId() const {return _id;}
};

TComplex& operator+=(TComplex& a, const TComplex& b);
TComplex& operator-=(TComplex& a, const TComplex& b);
TComplex& operator*=(TComplex& a, const TComplex& b);
TComplex& operator/=(TComplex& a, const TComplex& b);

const TComplex  power(const TComplex&, unsigned int);

const TComplex operator*(const TComplex&, const TComplex&);
const TComplex operator/(const TComplex&, const TComplex&);
ostream& operator<<(ostream&, const TComplex&);
istream& operator>>(istream &, TComplex&);
#endif