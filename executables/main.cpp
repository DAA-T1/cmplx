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

using double_time = std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<double>>;

int main(int Argc, char *Argv[]) {
  if (Argc < 2) {
	std::cerr << "Usage: " << Argv[0] << " --heap/--quick --time --file <filename>" << std::endl;
	exit(1);
  }
  std::string Sort;
  bool Time = false;
  std::string FileName;
  for (int I = 1; I < Argc; I++) {
	if (!strcmp(Argv[I], "--heap")) {
	  Sort = "heap";
	} else if (!strcmp(Argv[I], "--quick")) {
	  Sort = "quick";
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
  if (Sort == "heap") {
	Start = std::chrono::high_resolution_clock::now();
	cmplx::heapsort::sort(Arr, N);
	Stop = std::chrono::high_resolution_clock::now();
  } else if (Sort == "quick") {
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