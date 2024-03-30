//===-- cmplx/readfile/readfile.h - Read File Definition --------------===//
///
/// \file
/// This file contains the declaration of the file reading functions.
///
//===-----------------------------------------------------------------===//

#pragma once
#include "cmplx/superarr/superarr.h"
#include <string>

namespace cmplx::readfile {
    cmplx::superarr::SuperArray<int> readIntArray(std::string fileName);
// cmplx::superarr::SuperArray<int> readIntArray(string);
// cmplx::superarr::SuperArray<Complex>
} // namespace cmplx::readfile
