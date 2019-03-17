#include "stdafx.h"

#include <iostream>
#include <conio.h>

#include "advanced math.h"
#include "functions.h"

using namespace adv_math;
using std::cout;
using std::endl;

int main( void ) {
  func::exp<func::polynomial> ExpX(func::polynomial({0, 1}));

  cout << ExpX << endl;
  cout << ExpX(0) << "; " << ExpX(1) << "; " << ExpX(2) << endl;

  _getch();
  return 0;
}
