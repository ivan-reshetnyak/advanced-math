#include <conio.h>

#include "../advanced math/advanced math.h"

using namespace adv_math;
using std::cout;
using std::endl;

int main( void ) {
  auto Y1 = []( double X, const std::vector<double> &Y ) -> double {
      return 2 * Y[0];
    };
  auto Y2 = []( double X, const std::vector<double> &Y ) -> double {
      return 2 * Y[0] + Y[1];
    };
  equations::sde Sys({Y1, Y2}, 0, {1, 2});
  solvers::sde_runge_kutta<4> Solver(Sys, 0.1);

  double Points[] = { 1, 2, 3, 4 };
  for (const auto &Pt : Points) {
    auto Sol = Solver(Pt);
    cout << Pt << ": ";
    for (const auto &Y : Sol)
      cout << Y << "; ";
    cout << endl;
  }

  _getch();
  return 0;
}
