//===-- cmplx/readfile/readfile.h - Read File Definition --------------===//
///
/// \file
/// This file contains the declaration of the file reading functions.
///
//===-----------------------------------------------------------------===//

#pragma once
#include <cmplx/utils/complex.h>
#include <fstream>
#include <iostream>
#include <string>

namespace cmplx::readfile {
void readFromFile(std::string FileName, cmplx::utils::ComplexNumber **Arr, int &N);
}// namespace cmplx::readfile
