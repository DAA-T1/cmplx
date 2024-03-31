//===-- cmplx/readfile/readfile.cpp - Read File Implementation -----------===//
///
/// \file
/// This file contains the implementation of the Read File data structure.
///
//===--------------------------------------------------------------------===//

#include <cmplx/readfile/readfile.h>
namespace cmplx::readfile {
void readFromFile(std::string FileName, cmplx::utils::ComplexNumber **Arr, int &N) {
  std::string Line;
  std::ifstream MyFile(FileName);

  if (MyFile.is_open()) {
	std::getline(MyFile, Line);
	MyFile.close();
  } else {
	std::cout << "Unable to open file";
	std::exit(1);
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