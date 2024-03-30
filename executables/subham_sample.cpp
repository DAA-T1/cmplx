//===-- executables/print_hello.cpp - Basic test function --===//
///
/// \file
/// This file contains a basic hello world executable.
///
//===-------------------------------------------------------===//

#include "cmplx/superarr/superarr.h"
#include <cmplx/readfile/readfile.h>
#include <string>

class Test {
public:
  int Val;
  int pow(int A, int B) {
	if (B == 0) {
	  return 1;
	} else {
	  return A * pow(A, B - 1);
	}
  }
  Test() {
	Val = 0;
  }
  Test(std::string Str) {
	Val = 0;
	int Len = Str.length();
	for (int i = 0; i < Len; i++) {
	  Val += (Str[Len - i - 1] - '0') * pow(10, i);
	}
  }
  friend std::ostream &operator<<(std::ostream &Out, Test &C) {
	Out << C.Val;
	return Out;
  }
};
int main() {
  auto Arr = cmplx::readfile::readFromFile<Test>("../../executables/file.txt");
  std::cout << Arr << std::endl;
}