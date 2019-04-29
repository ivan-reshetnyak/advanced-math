#pragma once

#include "definitions.h"
#include "matrix.h"
#include "vector.h"

// Equations
#include "equations/sle.h"
#include "equations/solver.h"
#include "equations/solver_sle_inverse.h"
#include "equations/solver_sle_triangular.h"
#include "equations/solver_sle_lu.h"

// Grids
#include "grids/grid_chebyshev.h"
#include "grids/grid_regular.h"

// Functions
#include "function/function.h"
#include "function/function_lambda.h"
#include "function/function_polynomial.h"
#include "function/function_basic.h"
#include "function/function_trigonometric.h"
#include "function/function_exponent.h"

// Interpolators
#include "interpolation/interpolator.h"
#include "interpolation/interpolator_polynomial_newton.h"
#include "interpolation/interpolator_polynomial_hermit.h"
#include "interpolation/interpolator_least_squares.h"

// Integrators
#include "integration/integrator.h"
#include "integration/integrator_trapezoidal.h"
#include "integration/integrator_chebyshev.h"
