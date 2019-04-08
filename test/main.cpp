#include <conio.h>

#include "../source/vector.h"
#include "../source/advanced math.h"

using namespace adv_math;
using std::cout;
using std::endl;

int main( void ) {
  auto Func = func::constant(1) / (func::sin<func::x>(func::x()) + func::cos<func::x>(func::x()));
  integr::trapezoidal TrInt(0.01);

  cout << Func << endl;
  cout << TrInt.integrate(Func, -0.2, 0.6);
  _getch();
  return 0;
}
