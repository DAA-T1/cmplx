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

  bool operator<=(const ComplexNumber &Other) {
	return (this->getL2Norm() <= Other.getL2Norm());
  }

  bool operator>=(const ComplexNumber &Other) {
	return (this->getL2Norm() >= Other.getL2Norm());
  }

  bool operator==(const ComplexNumber &Other) {
	return ((this->Real == Other.Real) && (this->Imaginary == Other.Imaginary));
  }

  bool operator>(const ComplexNumber &Other) {
	return (this->getL2Norm() > Other.getL2Norm());
  }

  bool operator<(const ComplexNumber &Other) {
	return (this->getL2Norm() < Other.getL2Norm());
  }

  bool operator!=(const ComplexNumber &Other) {
	return ((this->Real != Other.Real) || (this->Imaginary != Other.Imaginary));
  }

  friend std::ostream &operator<<(std::ostream &os, const ComplexNumber &toprint);

  inline double getL2Norm() const {
	return sqrt(this->Real * this->Real + this->Imaginary * this->Imaginary);
  }

  static ComplexNumber constructFromString(const std::string Text) {
	double RealIn, ImaginaryIn;

	if (Text.find('+') == std::string::npos) {
	  sscanf(Text.c_str(), "%lf - %lfi", &RealIn, &ImaginaryIn);
	  ImaginaryIn *= -1;
	} else {
	  sscanf(Text.c_str(), "%lf + %lfi", &RealIn, &ImaginaryIn);
	}

	return ComplexNumber(RealIn, ImaginaryIn);
  }
};

std::ostream &operator<<(std::ostream &os, const ComplexNumber &toprint) {
  os << toprint.Real << '+' << toprint.Imaginary << 'i';
  return os;
}
}// namespace cmplx::utils
