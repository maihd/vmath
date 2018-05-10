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

struct
{
    int quit;
} app;

static void _sighandler(int sig);

int main(int argc, char* argv[])
{
    csfx_init();
    signal(SIGINT, _sighandler);

    csfx_script_t script;
    csfx_script_init(&script, _LIBNAME);

    csfx_filetime_t files[] =
    {
	{ 0, "./src" } /* listen folder */
    };
    csfx_watch_files(files, countof(files));
    
    while (!app.quit)
    {
	if (csfx_watch_files(files, countof(files)))
	{
	    system("make libtest");
	    /* Call csfx_watch_files again to ignore change after build */
	    csfx_watch_files(files, countof(files));
	}
	
        switch (csfx_script_update(&script))
	{
	default:
	    break;
	}
	
	_sleep(1000);
    }

    csfx_script_free(&script);
    csfx_quit();
    return 0;
}

void _sighandler(int sig)
{
    if (sig == SIGINT)
    {
	app.quit = 1;
    }
}
