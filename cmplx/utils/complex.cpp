//===-- cmplx/utils/complex.cpp - CMake Link Fix ----------------------------===//
///
/// \file
/// This file exists to deal with CMake linking issues.
///
//===------------------------------------------------------------------------------===//

#include <cmplx/utils/complex.h>
#include <iomanip>

namespace cmplx::utils {
std::ostream &operator<<(std::ostream &Os, const ComplexNumber &ToPrint) {
  Os << std::fixed << std::setprecision(2) << ToPrint.Real << ' ' << std::showpos << std::setw(6) << std::internal << ToPrint.Imaginary << 'i' << std::noshowpos;
  return Os;
}

double ComplexNumber::getL2Norm() const {
  return std::sqrt(this->Real * this->Real + this->Imaginary * this->Imaginary);
}
}// namespace cmplx::utils