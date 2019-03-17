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
  //func::lambda FuncRunge([]( double X ) -> double { return 1.0 / (1. + 25. * X * X); },
  //                       []( std::ostream &Stream ) { Stream << "1 / (1 + 25x^2)"; });
  func::polynomial Func({0, 0, 1, 1});
  grids::regular GridIn(-1, 1, 3, Func);
  interp::least_squares LeSq(GridIn, 3);
  grids::regular GridOut(-1, 1, 5, LeSq);

  /*
  equations::sle
    SysLinEq1(vec<vector>({ {1., 2., 1.}, {2., 1., 2.}, {5., 7., 8.} }),
              vector(std::vector<double>({8., 10., 43.}))),
    SysLinEq2(vec<vector>({ {1., 2., 1.}, {2., 1., 2.}, {3., 3., 3.} }),
              vector(std::vector<double>({8., 10., 43.})));
  equations::solver_sle_inverse Solver;

  cout << SysLinEq1 << Solver.solve(SysLinEq1) << endl << endl;
  cout << SysLinEq2 << Solver.solve(SysLinEq2) << endl << endl;
  */
  for (const auto &Pt : GridOut)
    cout << std::setw(9) << Pt.X << " ";
  cout << endl;
  for (const auto &Pt : GridOut)
    cout << std::setw(9) << Func(Pt.X) << " ";
  cout << endl;
  for (const auto &Pt : GridOut)
    cout << std::setw(9) << Pt.Y << " ";
  cout << endl;

  _getch();
  return 0;
}
