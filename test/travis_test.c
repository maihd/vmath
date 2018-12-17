#include <stdio.h>
#include <stdlib.h>

#include "../vmath.h"

#define CSFX_IMPL
#include "csfx/csfx.h"

#if defined(_WIN32)
#include <Windows.h>
#define _sleep(ms) Sleep(ms)
#else
#include <unistd.h>
#define _sleep(ms) usleep(ms * 1000)
#endif

#if defined(_WIN32) || defined(__CYGWIN__)
#define _LIBNAME   "bin/libtest.dll"
#else
#define _LIBNAME   "bin/libtest.so"
#endif

#define countof(x) (sizeof(x) / sizeof((x)[0]))

int main(int argc, char* argv[])
{
    csfx_init();

    csfx_script_t script;
    csfx_script_init(&script, _LIBNAME);

    switch (csfx_script_update(&script))
    {
    default:
        break;
    }

    csfx_script_free(&script);
    csfx_quit();
    return 0;
}
