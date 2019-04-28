#include "stdafx.h"

#include "matrix.h"

namespace adv_math {

std::ostream & operator<<( std::ostream &Stream, const matrix &Matr ) {
  int W = Matr.getW(), H = Matr.getH();
  for (int iy = 0; iy < H; iy++) {
    for (int ix = 0; ix < W; ix++)
      Stream << Matr[ix][iy] << " ";
    Stream << std::endl;
  }
  return Stream;
}

matrix::matrix( int W, int H ) : NeedUpdate(true) {
  Data.resize(W, col_t(H, 0));
}

matrix::matrix( const row_t &MIn ) : Data(MIn), NeedUpdate(true) {
  transpose();
}

int matrix::getW( void ) const {
  return Data.size();
}

int matrix::getH( void ) const {
  return Data[0].size();
}

matrix::col_t & matrix::operator[]( int X ) {
  NeedUpdate = true;
  return Data[X];
}

const matrix::col_t & matrix::operator[]( int X ) const {
  return Data[X];
}

matrix matrix::minor( int X, int Y ) const {
  matrix Res(getW() - 1, getH() - 1);

  for (int ix = 0, sx = max(X, getW() - 1); ix < sx; ix++)
    for (int iy = 0, sy = max(Y, getH() - 1); iy < sy; iy++)
      Res[ix][iy] = (*this)[ix >= X ? ix + 1 : ix][iy >= Y ? iy + 1 : iy];
  return Res;
}

matrix matrix::adjoint( void ) const {
  matrix Adj(getW(), getH());

  for (int ix = 0, sx = getW(); ix < sx; ix++)
    for (int iy = 0, sy = getH(); iy < sy; iy++)
      Adj[ix][iy] = ((ix + iy) % 2 == 0 ? 1 : -1) * minor(ix, iy).determinant();

  return Adj;
}

double matrix::determinant( void ) const {
  if (!NeedUpdate)
    return Determinant;

  Determinant = 0;
  int Size = getW();
  if (Size == 1)
    Determinant = (*this)[0][0];
  else if (Size == 2)
    Determinant = (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
  else for (int ix = 0; ix < Size; ix++)
    Determinant += (ix % 2 == 0 ? 1 : -1) * (*this)[ix][0] * minor(ix, 0).determinant();

  NeedUpdate = false;
  return Determinant;
}

matrix & matrix::inverse( void ) {
  if (getW() == 1 && getH() == 1) {
    (*this)[0][0] = 1. / (*this)[0][0];
    return *this;
  }

  (*this) = adjoint() / determinant();
  NeedUpdate = true;
  return *this;
}

matrix matrix::inversed( void ) const {
  return matrix(*this).inverse();
}

matrix matrix::operator/( double C ) const {
  matrix Res = *this;
  for (auto &Col : Res.Data)
    for (auto &Cell : Col)
      Cell /= C;

  return Res;
}

matrix & matrix::operator/=( double C) {
  for (auto &Col : Data)
    for (auto &Cell : Col)
      Cell /= C;

  NeedUpdate = true;
  return *this;
}

matrix matrix::operator*( double C ) const {
  matrix Res = *this;
  for (auto &Col : Res.Data)
    for (auto &Cell : Col)
      Cell *= C;

  return Res;
}

matrix & matrix::operator*=( double C) {
  for (auto &Col : Data)
    for (auto &Cell : Col)
      Cell *= C;

  NeedUpdate = true;
  return *this;
}

vector operator*( const vector &Vec, const matrix &Matr ) {
  vector Res;
  Res.resize(Matr.getH(), 0);

  for (int iy = 0, sy = Matr.getH(); iy < sy; iy++)
    for (int ix = 0, sx = Matr.getW(); ix < sx; ix++)
      Res[iy] += Vec[ix] * Matr[ix][iy];
  return Res;
}

vector & operator*=( vector &Vec, const matrix &Matr ) {
  Vec = Vec * Matr;
  return Vec;
}

matrix & matrix::slice( const std::pair<int, int> &P1, const std::pair<int, int> &P2 ) {
  *this = sliced(P1, P2);
  NeedUpdate = true;
  return *this;
}

matrix matrix::sliced( const std::pair<int, int> &P1, const std::pair<int, int> &P2 ) const {
  int
    sx = P2.first - P1.first + 1,
    sy = P2.second - P1.second + 1;

  matrix Res(sx, sy);
  for (int ix = 0; ix < sx; ix++)
    for (int iy = 0; iy < sy; iy++)
      Res[ix][iy] = (*this)[P1.first + ix][P1.second + iy];
  return Res;
}

matrix & matrix::square( void ) {
  int size = min(getW(), getH());

  return slice({0, 0}, {size - 1, size - 1});
}

matrix & matrix::transpose( void ) {
  int W = getW(), H = getH();
  for (int Y = 0; Y < H; Y++)
    for (int X = 0; X < Y; X++)
      std::swap((*this)[X][Y], (*this)[Y][X]);

  return *this;
}

matrix matrix::transposed( void ) const {
  return matrix(*this).transpose();
}

matrix matrix::identity( int Size ) {
  matrix M(Size, Size);

  for (int i = 0; i < Size; i++)
    M[i][i] = 1;

  return M;
}

} // End of 'adv_math' namespace
