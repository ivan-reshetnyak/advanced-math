#pragma once

#include "../stdafx.h"

#include "../definitions.h"
#include "../function/function.h"

namespace adv_math {

class interpolator : public function {
public:
  interpolator( void ) = default;
  virtual void update( const grid &NewPoints ) = 0;
};

} // End of 'adv_math' namespace
