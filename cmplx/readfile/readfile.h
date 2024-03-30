//===-- cmplx/readfile/readfile.h - Read File Definition --------------===//
///
/// \file
/// This file contains the declaration of the file reading functions.
///
//===-----------------------------------------------------------------===//

#pragma once
#include "cmplx/superarr/superarr.h"
#include <fstream>
#include <iostream>
#include <string>

namespace cmplx::readfile {
template<typename T>
cmplx::superarr::SuperArray<T> readFromFile(std::string FileName) {
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
  for (auto &c : Line) {
	if (c == ',') {
	  Count++;
	}
  }

  cmplx::superarr::SuperArray<T> Array(Count);

  int i = 0;
  std::string Tmp = "";
  for (auto &c : Line) {
	if (c == ',') {
	  Array[i++] = stoi(Tmp);
	  Tmp = "";
	} else if (c == ' ') {
	  continue;
	} else {
	  Tmp += c;
	}
  }
  return Array;
}
}// namespace cmplx::readfile
