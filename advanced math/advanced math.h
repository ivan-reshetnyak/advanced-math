#pragma once

// Basic
#include "definitions.h"
#include "matrix.h"
#include "vector.h"

// Equations
#include "equations/solver.h"
// Linear systems
#include "equations/sle.h"
#include "equations/solver_sle_inverse.h"
#include "equations/solver_sle_triangular.h"
#include "equations/solver_sle_lu.h"
// Differential
#include "equations/equation_differential.h"
#include "equations/solver_runge_kutta.h"
#include "equations/solver_predictor_corrector.h"
// Differential systems
#include "equations/sde.h"
#include "equations/solver_sde.h"
#include "equations/solver_sde_runge_kutta.h"
#include "equations/solver_sde_predictor_corrector.h"
// Boundary
#include "equations/equation_boundary.h"
#include "equations/solver_boundary.h"
#include "equations/solver_boundary_finite_difference.h"

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
