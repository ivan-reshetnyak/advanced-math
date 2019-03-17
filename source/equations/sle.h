#pragma once

#include <vector>

#include "../matrix.h"
#include "../vector.h"

namespace adv_math {
namespace equations {

class sle : public matrix {
private:
  vector ConstantTerms;

public:
  sle( const matrix &System, const vector &Constants ) : matrix(System), ConstantTerms(Constants) {
  }

  sle( const matrix &System ) : matrix(System) {
    ConstantTerms.resize(System.getH(), 0);
  }

  const vector & getConstants( void ) const {
    return ConstantTerms;
  }
};

} // End of 'equations' namespace
} // End of 'adv_math' namespace
