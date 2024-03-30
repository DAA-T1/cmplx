//
// Created by jalan on 30-03-2024.
//

#include <iostream>
#include <cmplx/heapsort/heapsort.h>
#include <cmplx/readfile/readfile.h>
#include <string.h>
#include <chrono>

int main(int Argc, char* Argv[]) {
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
	}
	else if (!strcmp(Argv[I], "--quick")) {
	  Sort = "quick";
	}
	else if (!strcmp(Argv[I], "--time")) {
	  Time = true;
	  }
	  else if (!strcmp(Argv[I], "--file")) {
		FileName = Argv[++I];
	  }
  }
  int *Arr;
  int N;
  cmplx::readfile::readFromFile(FileName, &Arr, N);
  for (int I = 0; i < N; i++) {
	std::cout << Arr[I] << " ";
  }
  std::cout << std::endl;
  std::cout << Time << std::endl;


  auto Start = std::chrono::high_resolution_clock::now();
  if (Sort == "heap") {
	cmplx::heapsort::sort(Arr, N);
  }
  else if (Sort == "quick") {
	cmplx::quicksort::sort(Arr, N);
  }
  auto Stop = std::chrono::high_resolution_clock::now();
  auto Duration = duration_cast<std::chrono::microseconds>(Stop - Start);
  if (Time) {
  std::cout << "Duration (in microseconds): " << Duration.count() << std::endl;
  }

}
