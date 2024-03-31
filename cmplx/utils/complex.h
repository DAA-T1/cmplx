//===-- cmplx/utils/complex.h - Complex Implementation ----------------------------===//
///
/// \file
/// This file contains the generic implementation for the Complex Class Data structure.
///
//===------------------------------------------------------------------------------===//

#pragma once
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>

namespace cmplx {
namespace utils {

class ComplexNumber {
public:
  double L2Norm;

  ComplexNumber(double Real, double Imaginary) : Real(Real), Imaginary(Imaginary) {
	L2Norm = this->getL2Norm();
  }
  ComplexNumber() : Real(0), Imaginary(0) {
	L2Norm = this->getL2Norm();
  }
  ComplexNumber(const std::string Text) {

	if (Text.find('+') == std::string::npos) {
	  sscanf(Text.c_str(), "%lf - %lfi", &(Real), &(Imaginary));
	  Imaginary *= -1;
	} else {
	  sscanf(Text.c_str(), "%lf + %lfi", &(Real), &(Imaginary));
	}

	L2Norm = this->getL2Norm();
  }

  double getReal() const {
	return Real;
  }

  double getImaginary() const {
	return Imaginary;
  }

  bool operator<(const ComplexNumber &Other) {
	if (*this == Other) {
	  if (this->Real < Other.Real) {
		return true;
	  }
	  return (this->Imaginary < Other.Imaginary);
	}
	return (this->L2Norm < Other.L2Norm);
  }

  bool operator>(const ComplexNumber &Other) {
	return !(*this < Other);
  }

  bool operator>=(const ComplexNumber &Other) {
	return (*this > Other) || (*this == Other);
  }

  bool operator<=(const ComplexNumber &Other) {
	return (*this < Other) || (*this == Other);
  }

  bool operator==(const ComplexNumber &Other) {
	return (this->L2Norm == Other.L2Norm);
  }

  bool operator!=(const ComplexNumber &Other) {
	return !(*this == Other);
  }

  friend std::ostream &operator<<(std::ostream &Os, const ComplexNumber &ToPrint);

private:
  double Real;
  double Imaginary;

  inline double getL2Norm() const {
	return sqrt(this->Real * this->Real + this->Imaginary * this->Imaginary);
  }
};

inline std::ostream &operator<<(std::ostream &Os, const ComplexNumber &ToPrint) {
  Os << std::fixed << std::setprecision(2) << ToPrint.Real << ' ' << std::showpos << std::setw(6) << std::internal << ToPrint.Imaginary << 'i' << std::noshowpos;
  return Os;
}
}// namespace utils
}// namespace cmplx
