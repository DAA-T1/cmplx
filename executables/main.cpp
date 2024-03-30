//
// Created by jalan on 30-03-2024.
//

#include <iostream>
#include <cmplx/superarr/superarr.h>
#include <cmplx/heapsort/heapsort.h>
#include <cmplx/readfile/readfile.h>
#include <string.h>

int main(int Argc, char* Argv[]) {
  if (Argc < 2) {
	std::cerr << "Usage: " << Argv[0] << " --heap/--quick --time --file <filename>" << std::endl;
	exit(1);
  }
  std::string Sort;
  bool Time = false;
  std::string FileName;
  for (int i = 1; i < Argc; i++) {
	if (!strcmp(Argv[i], "--heap")) {
	  Sort = "heap";
	}
	else if (!strcmp(Argv[i], "--quick")) {
	  Sort = "quick";
	}
	else if (!strcmp(Argv[i], "--time")) {
	  Time = true;
	  }
	  else if (!strcmp(Argv[i], "--file")) {
		FileName = Argv[++i];
	  }
  }
  auto Arr = cmplx::readfile::readFromFile<int>(FileName);
  std::cout << Arr << std::endl;

}
