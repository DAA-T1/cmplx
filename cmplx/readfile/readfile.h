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
void readMultipleArraysFromFile(std::string FileName, cmplx::utils::ComplexNumber ***ArrayOfArrays, int &N, int &ArrayCount);
void extractArrayFromLine(std::string Line, cmplx::utils::ComplexNumber **Arr);
}// namespace cmplx::readfile
