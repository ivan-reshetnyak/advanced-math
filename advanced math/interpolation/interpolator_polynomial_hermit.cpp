#include "stdafx.h"

#include "interpolator_polynomial_hermit.h"

namespace adv_math {
namespace interp {

void polynomial_hermit::print( std::ostream &Stream ) const {
  size_t K = Points.size() - 2; // Number of known derivatives

  for (size_t i = 0, N = Points[-1].size() * (K + 1); i < N; i++) {
    Stream << DividedDifferences[i][0] << (i > 0 ? " * " : "");
    for (size_t j = 0; j < i / (K + 1); j++)
      Stream << "(x - " << Points[-1][j] << ")^" << K + 1;
    if (i % (K + 1) > 0)
      Stream << "(x - " << Points[-1][i / (K + 1)] << ")^" << i % (K + 1);
    Stream << (i == N - 1 ? "" : " + ");
  }
}

double polynomial_hermit::basisPolynomial( int I, double X ) const {
  double res = 1;
  int K = Points.size() - 2; // Number of known derivatives

  for (int i = 0; i < I / (K + 1); i++)
    res *= pow(X - Points[-1][i], K + 1);
  res *= pow(X - Points[-1][I / (K + 1)], I % (K + 1));

  return res;
}

polynomial_hermit::polynomial_hermit( const grid_derivative &InputPoints ) {
  update(InputPoints);
}

void polynomial_hermit::update( void ) {
  size_t
    K = Points.size() - 2, // Number of known derivatives
    N = Points[-1].size() * (K + 1);
  DividedDifferences.clear();
  DividedDifferences.resize(N);

  DividedDifferences[0].resize(N);
  for (size_t i = 0; i < Points[-1].size(); i++)
    for (size_t j = 0; j < K + 1; j++)
      DividedDifferences[0][i * (K + 1) + j] = Points[0][i];

  for (size_t i = 1; i < N; i++) {
    DividedDifferences[i].resize(N - i);
      for (size_t j = 0; j < N - i; j++) {
        // *[i][j] = (*[i - 1][j] - *[i - 1][j + 1]) / (z[j + i] - z[j])
        if ((j + i) / (K + 1) == j / (K + 1))
          DividedDifferences[i][j] = Points[i][j / (K + 1)] / factorial(i);
        else
          DividedDifferences[i][j] = (DividedDifferences[i - 1][j + 1] - DividedDifferences[i - 1][j]) /
            (Points[-1][(j + i) / (K + 1)] - Points[-1][j / (K + 1)]);
      }
  }
}

void polynomial_hermit::update( const grid &InputPoints ) {
  Points[0] = InputPoints.X();
  Points[0] = InputPoints.Y();
  update();
}

void polynomial_hermit::update( const grid_derivative &InputPoints ) {
  Points = InputPoints;
  update();
}

double polynomial_hermit::at( double X ) const {
  double res = 0;
  size_t
    K = Points.size() - 2, // Number of known derivatives
    N = Points[-1].size() * (K + 1),
    Size = Points[-1].size();

  for (size_t i = 0; i < N; i++)
    res += DividedDifferences[i][0] * basisPolynomial(i, X);

  return res;
}

} // End of 'interp' namespace
} // End of 'adv_math' namespace
