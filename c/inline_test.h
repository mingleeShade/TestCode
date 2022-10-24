#ifndef __INLINE_TEST_HEAD__
#define __INLINE_TEST_HEAD__

#include <stdio.h>

#ifndef INLINE
#   define INLINE __inline__ __attribute__((always_inline))
#endif

#ifndef inline
#   define inline INLINE
#endif


#endif
