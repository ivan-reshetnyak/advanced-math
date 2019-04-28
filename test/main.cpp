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

  cout << Func << endl;
  cout << TrInt.integrate(Func, -0.2, 0.6);
  */
  matrix M({ {1., 0.}, {2., 1.} });
  vector C({2., 7.});
  equations::sle SLE(M, C);
  equations::solver_sle_triangular_lower Solver;

  auto Roots = equations::solver_sle_triangular_lower().solve(SLE);
  cout << M << Roots << endl;

  M.transpose();
  SLE = { M, C };
  Roots = equations::solver_sle_triangular_upper().solve(SLE);
  cout << M << Roots << endl;

  M = matrix({{10, -7, 0}, {-3, 6, 2}, {5, -1, 5}});
  SLE = { M, vector({1, 1, 1}) };
  Roots = equations::solver_sle_lu().solve(SLE);
  cout << M << Roots << endl;

  _getch();
  return 0;
}
