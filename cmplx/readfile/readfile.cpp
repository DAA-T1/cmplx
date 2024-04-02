//===-- cmplx/readfile/readfile.cpp - Read File Implementation -----------===//
///
/// \file
/// This file contains the implementation of the Read File data structure.
///
//===--------------------------------------------------------------------===//

#include <cmplx/readfile/readfile.h>
#include <iostream>
#include <string>

namespace cmplx::readfile {

void readMultipleArraysFromFile(std::string FileName, cmplx::utils::ComplexNumber ***ArrayOfArrays, int &N, int &ArrayCount) {

  std::string ArrayLine;
  std::string TmpCount;
  std::string TmpN;
  std::ifstream MyFile(FileName, std::ifstream::in);// Open the file

  if (!MyFile.is_open()) {
	std::cerr << "Unable to open file: " << FileName << std::endl;
	std::exit(1);
  }

  // read len of file
  std::getline(MyFile, TmpCount, ' ');
  ArrayCount = std::stoi(TmpCount);

  // read size of arrays
  std::getline(MyFile, TmpN, '\n');
  N = std::stoi(TmpN);

  // read the arrays

  // allocate memory for the array
  *ArrayOfArrays = new cmplx::utils::ComplexNumber *[ArrayCount];

  for (int I = 0; I < ArrayCount; I++) {
	std::getline(MyFile, ArrayLine, '\n');

	// allocate space for the particular array
	(*ArrayOfArrays)[I] = new cmplx::utils::ComplexNumber[N]();

	extractArrayFromLine(ArrayLine, &(*ArrayOfArrays)[I]);
  }

  MyFile.close();
}

void extractArrayFromLine(std::string Line, cmplx::utils::ComplexNumber **Arr) {

  int I = 0;
  std::string Tmp = "";
  for (auto &C : Line) {
	// each complex number is separated by a comma
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