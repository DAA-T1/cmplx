//
// Created by jalan on 30-03-2024.
//

#include <chrono>
#include <cmplx/heapsort/heapsort.h>
#include <cmplx/quicksort/quicksort.h>
#include <cmplx/readfile/readfile.h>
#include <cmplx/utils/complex.h>
#include <cmplx/utils/utils.h>
#include <iostream>
#include <string.h>

using double_time = std::chrono::time_point<std::chrono::high_resolution_clock>;

int main(int Argc, char *Argv[]) {
  if (Argc < 2) {
	std::cerr << "Usage: " << Argv[0] << " (--heap|--quick) [--time] [--print] (--file <filename>)" << std::endl;
	exit(1);
  }
  int SortFlag = -1;
  bool ToPrintTime = false;
  bool ToPrintArray = false;
  bool ToPrintComparisonCount = true;

  std::string FileName;
  for (int I = 1; I < Argc; I++) {
	if (!strcmp(Argv[I], "--heap")) {
	  SortFlag = 0;
	} else if (!strcmp(Argv[I], "--quick")) {
	  SortFlag = 1;
	} else if (!strcmp(Argv[I], "--time")) {
	  ToPrintTime = true;
	} else if (!strcmp(Argv[I], "--file")) {
	  FileName = Argv[++I];
	} else if (!strcmp(Argv[I], "--print")) {
	  ToPrintArray = true;
	}
  }

  if (SortFlag == -1) {
	std::cerr << "Invalid Sort Flag. Which Algorithm to use?" << std::endl;
	exit(1);
  }

  cmplx::utils::ComplexNumber **ComplexNumberArrays;

  int N;
  int ArrayCount;
  // function to read multiple arrays from a file

  cmplx::readfile::readMultipleArraysFromFile(FileName, &ComplexNumberArrays, N, ArrayCount);

  // ArrayCount is the number of arrays extracted
  // N is the number of elements in each array
  // ComplexNumberArrays is a pointer to an array of pointers to ComplexNumber objects

  double_time Start;
  double_time Stop;
  int ComparisonCount;

  for (int I = 0; I < ArrayCount; I++) {

	cmplx::utils::ComplexNumber *Arr = ComplexNumberArrays[I];

	if (SortFlag == 0) {
	  ToPrintTime ? Start = std::chrono::high_resolution_clock::now() : Start;
	  ComparisonCount = cmplx::heapsort::sort(Arr, N);
	  ToPrintTime ? Stop = std::chrono::high_resolution_clock::now() : Stop;
	} else {
	  ToPrintTime ? Start = std::chrono::high_resolution_clock::now() : Start;
	  ComparisonCount = cmplx::quicksort::sort(Arr, N);
	  ToPrintTime ? Stop = std::chrono::high_resolution_clock::now() : Stop;
	}

	if (ToPrintArray) {
	  std::cout << "Sorted Array: ";
	  cmplx::utils::printArray(Arr, N);
	}

	if (ToPrintTime) {
	  auto Duration = std::chrono::duration_cast<std::chrono::nanoseconds>(Stop - Start);
	  std::cout << "Time: " << Duration.count() << "ns" << std::endl;
	}

	if (ToPrintComparisonCount) {
	  std::cout << "Comparisons: " << ComparisonCount << std::endl;
	}

	delete Arr;
  }

  delete[] ComplexNumberArrays;
}