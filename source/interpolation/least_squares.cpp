#include "stdafx.h"

#include "least_squares.h"
#include "../function/polynomial.h"
#include "../equations/sle.h"
#include "../equations/solver_sle_inverse.h"

namespace adv_math {
namespace interp {

void least_squares::print( std::ostream &Stream ) const {
  Stream << Poly;
}

double least_squares::at( double X ) const {
  return Poly(X);
}

least_squares::least_squares( const grid &InputPoints, const std::vector<double> &InputWeights, int Power )
                : Weights(InputWeights), Power(Power) {
  update(InputPoints);
}

least_squares::least_squares( const grid &InputPoints, int Power ) : Weights(std::vector<double>(InputPoints.size(), 1.0)), Power(Power) {
  update(InputPoints);
}

void least_squares::update( const grid &Points ) {
  int Size = Power, PtN = Points.size();
  matrix SysM(Size, Size);
  vector SysC(Size, 0);

  for (int Row = 0; Row < Size; Row++) {
    // dSum/da_Row = _S_d(P^2)/da_Row + _S_2f*dP/da_Row
    for (int Pt = 0; Pt < PtN; Pt++)
      SysC[Row] += Weights[Pt] * pow(Points[Pt].X, Row) * Points[Pt].Y;

    for (int Col = 0; Col < Size; Col++)
      for (int Pt = 0; Pt < PtN; Pt++)
        SysM[Col][Row] += Weights[Pt] * pow(Points[Pt].X, Row + Col);
  }
  SysM.square();
  SysC.resize(SysM.getH());

  equations::solver_sle_inverse Solver;
  auto Result = Solver.solve(equations::sle(SysM, SysC));
  //if (Result.)
  const auto &Roots = Result.getRoots();
  for (int i = 0, Size = Roots.size(); i < Size; i++)
    Poly[i] = Roots[i];
}

} // End of 'interp' namespace
} // End of 'adv_math' namespace
