//===-- cmplx/utils/complex.h - Complex Implementation ----------------------------===//
///
/// \file
/// This file contains the generic implementation for the Complex Class Data structure.
///
//===------------------------------------------------------------------------------===//

#pragma once
#include <stdio.h>

namespace cmplx::utils {

class ComplexNumber {
public:
  double Real;
  double Imaginary;

  ComplexNumber(double Real, double Imaginary) : Real(Real), Imaginary(Imaginary) {}

  ComplexNumber operator<=(const ComplexNumber &Other) {
	return ((this->Real * this->Real + this->Imaginary * this->Imaginary) <= (Other.Real * Other.Real + Other.Imaginary * Other.Imaginary) ? *this : Other);
  }

  ComplexNumber constructFromText(const char *Text) {
	double RealIn, ImaginaryIn;
	sscanf(Text, "%lf %lf", &RealIn, &ImaginaryIn);
	return ComplexNumber(RealIn, ImaginaryIn);
  }
};
}// namespace cmplx::utils