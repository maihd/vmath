#include <stdio.h>
#include <stdlib.h>

#include "../../vmath.h"
#include "../csfx/csfx.h"

#define NONE
#define VOIDVAL (void)0

#define test_assert(exp, ret)                           \
    do {							                    \
        if (exp) test_pass(#exp);	                    \
        else     test_fail(#exp);					    \
                                                        \
	    return ret;						                \
    } while(0)

void test_pass(const char* exp)
{
    printf("Test pass: %s\n", exp);
}

void test_fail(const char* exp)
{
    printf("Test fail: %s\n", exp);
}

void vmath_test_vec2(void)
{
    test_assert(vec2_length(vec2(0, 0)) == 0, VOIDVAL);
    test_assert(vec2_lengthsquared(vec2(0, 0)) == 0, VOIDVAL);
}

void* csfx_main(void* userdata, int old_state, int state)
{
    vmath_test_vec2();
    
    return userdata;
}
