#include "stdafx.h"

#include "polynomial_newton.h"

namespace adv_math {
namespace interp {

void polynomial_newton::print( std::ostream &Stream ) const {
  for (int i = 0, Size = Points.size(); i < Size; i++) {
    Stream << DividedDifferences[i] << (i > 0 ? " * " : "");
    for (int j = 0; j < i; j++)
      Stream << "(x - " << Points[j].X << ")";
    Stream << (i == Size - 1 ? "" : " + ");
  }
}

double polynomial_newton::basisPolynomial( int K, double X ) const {
  double res = 1;

  for (int i = 0; i < K; i++)
    res *= X - Points[i].X;

  return res;
}

polynomial_newton::polynomial_newton( const grid &InputPoints ) {
  update(InputPoints);
}

void polynomial_newton::update( const grid &InputPoints ) {
  Points = InputPoints;
  int N = Points.size();
  std::vector<double> DivDiffTable(N * (N + 1) / 2);
  DividedDifferences.resize(N);

  for (int i = 0; i < N; i++)
    DivDiffTable[i] = Points[i].Y;

  auto divDiffNum = [this, N]( int L, int R ) -> int {
    int Col = R - L, Row = L;
    return (N + (N - Col + 1)) * Col / 2 + Row;
    };
  auto divDiff = [this, &DivDiffTable, divDiffNum]( int L, int R ) -> double {
    double
      yr = DivDiffTable[divDiffNum(L + 1, R)],
      yl = DivDiffTable[divDiffNum(L, R - 1)],
      dx = Points[R].X - Points[L].X;
    return (yr - yl) / dx;
    };
  for (int i = 1, cnt = N; i < N; i++)
    for (int j = 0; j < N - i; j++)
      DivDiffTable[cnt++] = divDiff(j, j + i);

  for (int i = 0; i < N; i++)
    DividedDifferences[i] = DivDiffTable[divDiffNum(0, i)];
}

double polynomial_newton::at( double X ) const {
  double res = 0;
  for (int i = 0, Size = Points.size(); i < Size; i++)
    res += DividedDifferences[i] * basisPolynomial(i, X);

  return res;
}

} // End of 'interp' namespace
} // End of 'adv_math' namespace
