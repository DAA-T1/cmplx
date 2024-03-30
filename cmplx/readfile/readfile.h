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

namespace cmplx::readfile {
void readFromFile(std::string FileName, int** Arr, int& N) {
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
  *Arr = new int[N];

  int i = 0;
  std::string Tmp = "";
  for (auto &C : Line) {
	if (C == ',') {
	  (*Arr)[i++] = stoi(Tmp);
	  Tmp = "";
	} else if (C == ' ') {
	  continue;
	} else {
	  Tmp += C;
	}
  }
}
}// namespace cmplx::readfile
