//===-- cmplx/readfile/readfile.h - Read File Definition --------------===//
///
/// \file
/// This file contains the declaration of the file reading functions.
///
//===-----------------------------------------------------------------===//

#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <cmplx/utils/complex.h>
namespace cmplx::readfile {
void readFromFile(std::string FileName, cmplx::utils::ComplexNumber** Arr, int& N) {
  std::string Line;
  std::ifstream MyFile(FileName);

  if (MyFile.is_open()) {
	std::getline(MyFile, Line);
	MyFile.close();
  } else {
	std::cout << "Unable to open file";
	std::exit(0);
  }
  Line += ',';
  int Count = 0;
  for (auto &C : Line) {
	if (C == ',') {
	  Count++;
	}
  }
  N = Count;
  *Arr = new cmplx::utils::ComplexNumber[N]();

  int I = 0;
  std::string Tmp = "";
  for (auto &C : Line) {
	if (C == ',') {
	  (*Arr)[I++] = cmplx::utils::ComplexNumber(Tmp);
	  Tmp = "";
	} else if (C == ' ') {
	  continue;
	} else {
	  Tmp += C;
	}
  }
}
}// namespace cmplx::readfile
