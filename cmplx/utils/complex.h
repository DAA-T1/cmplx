//===-- cmplx/utils/complex.h - Complex Implementation ----------------------------===//
///
/// \file
/// This file contains the generic implementation for the Complex Class Data structure.
///
//===------------------------------------------------------------------------------===//

#pragma once
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

namespace cmplx::utils {

class ComplexNumber {
public:
  double Real;
  double Imaginary;

  ComplexNumber(double Real, double Imaginary) : Real(Real), Imaginary(Imaginary) {}
  ComplexNumber() : Real(0), Imaginary(0) {}

  bool operator<(const ComplexNumber &Other) {
	if (*this == Other) {
	  if (this->Real < Other.Real) {
		return true;
	  }
	  return (this->Imaginary < Other.Imaginary);
	}
	return (this->getL2Norm() < Other.getL2Norm());
  }

  bool operator>(const ComplexNumber &Other) {
	return !(*this < Other);
  }

  bool operator>= (const ComplexNumber &Other) {
    return (*this > Other) || (*this == Other);
  }

  bool operator<= (const ComplexNumber &Other) {
    return (*this < Other) || (*this == Other);
  }

  bool operator==(const ComplexNumber &Other) {
	return (this->getL2Norm() == Other.getL2Norm());
  }

  bool operator!=(const ComplexNumber &Other) {
	return !(*this == Other);
  }

  friend std::ostream &operator<<(std::ostream &os, const ComplexNumber &toprint);

  inline double getL2Norm() const {
	return sqrt(this->Real * this->Real + this->Imaginary * this->Imaginary);
  }

  ComplexNumber(const std::string Text) {

	if (Text.find('+') == std::string::npos) {
	  sscanf(Text.c_str(), "%lf - %lfi", &(Real), &(Imaginary));
	  Imaginary *= -1;
	} else {
	  sscanf(Text.c_str(), "%lf + %lfi", &(Real), &(Imaginary));
	}
  }

};

std::ostream &operator<<(std::ostream &os, const ComplexNumber &toprint) {
  os << toprint.Real << '+' << toprint.Imaginary << 'i';
  return os;
}
}// namespace cmplx::utils
