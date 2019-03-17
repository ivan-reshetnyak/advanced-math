#pragma once

#include "../stdafx.h"

#include "lambda.h"

namespace adv_math {
namespace func {

class sum : public function {

public:
  sum( void ) = default;
  void Add( const lambda &Func );

protected:
  std::vector<lambda> Members;

  double at( double X ) const override;
  double deriveAt( double X ) const override;
  virtual void print( std::ostream &Stream ) const override;
};

} // End of 'func' namespace
} // End of 'adv_math' namespace
