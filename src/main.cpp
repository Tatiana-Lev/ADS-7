// Copyright 2022 NNTU-CS
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "train.h"

int main() {
  std::srand(static_cast<unsigned int>(time(nullptr)));
  std::cout << "n\tfalse\t\ttrue\t\trandom\n";
  for (int n = 2; n <= 100; n = n + 1) {
    int opFalse, opTrue, opRandom;
    {
      Train train;
      for (int i = 0; i < n; i = i + 1) {
        train.addCar(false);
      }
      train.getLength();
      opFalse = train.getOpCount();
    }
    {
      Train train;
      for (int i = 0; i < n; i = i + 1) {
        train.addCar(true);
      }
      train.getLength();
      opTrue = train.getOpCount();
    }
    {
      Train train;
      for (int i = 0; i < n; i = i + 1) {
        bool light = (std::rand() % 2) == 1;  // 0 или 1
        train.addCar(light);
      }
      train.getLength();
      opRandom = train.getOpCount();
    }
    std::cout << n << "\t"
              << opFalse << "\t\t"
              << opTrue << "\t\t"
              << opRandom << "\n";
  }

  return 0;
