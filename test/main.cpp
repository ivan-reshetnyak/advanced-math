#include <conio.h>

#include "../source/vector.h"
#include "../source/advanced math.h"
#include "../source/functions.h"
#include "../source/grids.h"
#include "../source/interpolators.h"
#include "../source/equations/solver_sle_inverse.h"

using namespace adv_math;
using std::cout;
using std::endl;

int main( void ) {
  auto Func = func::constant(1) / (func::sin<func::x>(func::x()) + func::cos<func::x>(func::x()));

  cout << Func;
  _getch();
  return 0;
}
