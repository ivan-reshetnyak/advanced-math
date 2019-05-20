#include <conio.h>

#include "../advanced math/vector.h"
#include "../advanced math/advanced math.h"

using namespace adv_math;
using std::cout;
using std::endl;

int main( void ) {
  /*
  auto Func = func::constant(1) / (func::sin<func::x>(func::x()) + func::cos<func::x>(func::x()));
  integr::trapezoidal TrInt(0.01);
  integr::chebyshev ChInts[] = { integr::chebyshev(2), integr::chebyshev(3),
    integr::chebyshev(4), integr::chebyshev(5), integr::chebyshev(6), integr::chebyshev(7), integr::chebyshev(9) };

  cout << Func << endl;
  cout << TrInt.integrate(Func, -0.2, 0.6) << endl;
  for (const auto &Cheb : ChInts)
    cout << Cheb.integrate(Func, -0.2, 0.6) << endl;
    */

  /*
  auto Cd = func::constant(10).derivative();
  auto Func = func::constant(1) + func::x() + Cd.derivative();
  cout << Cd << endl;
  cout << Func << endl;
  */

  equations::differential_first_order DifEq([]( double X, double Y ) -> double { return Y; }, point(0, 1));
  equations::solver_RK4 RKSolver(DifEq, 100);

  cout << RKSolver(1) << " " << RKSolver(2) << " " << RKSolver(3) << endl;

  _getch();
  return 0;
}
