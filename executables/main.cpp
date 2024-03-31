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
	std::cerr << "Usage: " << Argv[0] << " (--heap|--quick|--both) [--time] (--file <filename>)" << std::endl;
	exit(1);
  }
  int SortFlag = 0;
  bool Time = false;
  std::string FileName;
  for (int I = 1; I < Argc; I++) {
	if (!strcmp(Argv[I], "--heap")) {
	  SortFlag = 0;
	} else if (!strcmp(Argv[I], "--quick")) {
	  SortFlag = 1;
	} else if (!strcmp(Argv[I], "--time")) {
	  Time = true;
	} else if (!strcmp(Argv[I], "--file")) {
	  FileName = Argv[++I];
	}
  }
  cmplx::utils::ComplexNumber *Arr;
  int N;
  cmplx::readfile::readFromFile(FileName, &Arr, N);

  double_time Start;
  double_time Stop;

  if (SortFlag == 0) {
	Start = std::chrono::high_resolution_clock::now();
	cmplx::heapsort::sort(Arr, N);
	Stop = std::chrono::high_resolution_clock::now();
  } else {
	Start = std::chrono::high_resolution_clock::now();
	cmplx::quicksort::sort(Arr, N);
	Stop = std::chrono::high_resolution_clock::now();
  }

  auto Duration = std::chrono::duration_cast<std::chrono::nanoseconds>(Stop - Start);

  std::cout << "Sorted Array: ";
  cmplx::utils::printArray(Arr, N);
  if (Time) {
	std::cout << "Duration (in nanoseconds): " << Duration.count() << std::endl;

	delete Arr;
  }
}