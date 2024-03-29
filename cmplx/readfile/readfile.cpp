//===-- cmplx/readfile/readfile.cpp - Read File Implementation -----------===//
///
/// \file
/// This file contains the implementation of the Read File data structure.
///
//===--------------------------------------------------------------------===//

// #include "readfile.h"
#include <fstream>
#include <iostream>
#include <cmplx/superarr/superarr.h>
#include <string> 
namespace cmplx::readfile {
cmplx::superarr::SuperArray<int> readIntArray(std::string fileName) {
  std::string line;
  std::ifstream myfile(fileName);

  if (myfile.is_open()) {
    std::getline(myfile, line);
    myfile.close();
  }
  else {
    std::cout << "Unable to open file";
    std::exit(0);
  }
    line += ',';
    int count = 0;
    for (auto &c : line) {
      if (c == ',') {
        count++;
      }
    }

  cmplx::superarr::SuperArray<int> array(count);

  int i = 0;
  std::string tmp = "";
  for (auto &c: line) {
    if (c == ',') {
        array[i++] = stoi(tmp);
        tmp = "";
    }
    else if (c == ' ') {
        continue;
    }
    else {
        tmp += c;
    }
  }
  return array;
}
} // namespace cmplx::readfile

int main() {
    auto array = cmplx::readfile::readIntArray("file.txt");
    std::cout << array << std::endl;
    return 0;
}