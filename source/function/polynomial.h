#pragma once

#include "../stdafx.h"

#include "function.h"

namespace adv_math {
namespace func {

class polynomial : public function {

public:
  double & operator[]( int Power );
  polynomial( void ) = default;
  polynomial( const std::initializer_list<double> &Powers );
  polynomial( const std::map<int, double> &Powers );
  polynomial( const std::string &FileName );
  void derivative( polynomial &Der ) const;
  polynomial polynomial::derivative( void ) const;
  int size( void );

protected:
  std::map<int, double> Members;  // Power-value pair

  virtual void print( std::ostream &Stream ) const override;
  virtual double at( double X ) const override;
  virtual double deriveAt( double X ) const override;
};

} // End of 'func' namespace
} // End of 'adv_math' namespace
