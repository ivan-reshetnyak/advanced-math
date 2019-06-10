#include <conio.h>

#include "../advanced math/advanced math.h"

using namespace adv_math;
using std::cout;
using std::endl;

int main( void ) {
  /*
  auto Y1 = []( double X, const std::vector<double> &Y ) -> double {
      return Y[1];
    };
  auto Y2 = []( double X, const std::vector<double> &Y ) -> double {
      return 3 * exp(X) - cos(X) * cos(X) * Y[0] - (1 + sin(X) * sin(X)) * Y[1];
    };
  equations::sde Sys({Y1, Y2}, 0, {1, 1});
  solvers::sde_runge_kutta<4> Solver(Sys, 0.01);

  double Points[] = { 1, 2, 3, 4 };
  for (const auto &Pt : Points) {
    auto Sol = Solver(Pt);
    cout << Pt << ": ";
    for (const auto &Y : Sol)
      cout << Y << "; ";
    cout << "in " << Solver.getNumSteps() << endl;
  }
  */
  /*
  auto Func = []( const point &P ) -> double {
      return P.Y;
    };
  equations::differential Eq(Func, {0, 1});
  solvers::predictor_corrector<solvers::runge_kutta<2>, 2> Solver(Eq, 0.1);

  double Points[] = { 1, 2, 3, 4 };
  for (const auto &Pt : Points) {
    double Y = Solver(Pt);
    cout << Pt << ": " << Y
         << " in " << Solver.getNumSteps() << endl;
  }
  */
  equations::boundary Eq(new auto(func::constant(1) + func::sin<func::x>(func::x()) * func::sin<func::x>(func::x())),
    new auto(func::cos<func::x>(func::x()) * func::cos<func::x>(func::x())),
    new auto(func::constant(3) * func::exp<func::x>(func::x())),
    {{0, 1}, {1, e}});
  solvers::finite_difference Solver(Eq);

  int N = 3;
  double H = 1. / N;
  auto Pts = Solver.Solve(N);
  for (int i = 0; i <= N; i++)
    //cout << "f(" << i * H << ") = " << Pts[i] << "; "
    //     << "e(" << i * H << ") = " << exp(i * H) << "; "
    //     << endl;
    cout << Pts[i] - exp(i * H) << endl;

  _getch();
  return 0;
}
