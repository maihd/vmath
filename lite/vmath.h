#pragma once

#include "vtypes.h"

#if VMATH_SIMD_ENABLE
#   if VMATH_NEON_SUPPORT
#       #include "sse2neon.h"
#   endif
#   include "vmath_simd.h"
#else
#   include "vmath_scalar.h"
#endif
