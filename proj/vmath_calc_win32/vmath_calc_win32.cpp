// vmath_calc_win32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "../../vmath.h"

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#define IMGUI_IMPL
#include "imgui_impl_sdl_gl3.h"

static void imgui_vmath_window(void);

#undef main
int main(int argc, char* argv[])
{
    GLenum glewStatus;
    SDL_Window* window;
    SDL_GLContext gl_context;
    const char* errfun = NULL;
    const char* errmsg = NULL;
    Uint64 frequency;
    Uint64 prev_time;
    float limit_time;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        errfun = "SDL_Init()";
        errmsg = SDL_GetError();
        goto error;
    }

    window = SDL_CreateWindow(
        "Vector math Calculator", 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (!window)
    {                           
        errfun = "SDL_CreateWindow()";
        errmsg = SDL_GetError();
        goto error;
    }

    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
    //SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    //SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    //SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);      
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    gl_context = SDL_GL_CreateContext(window);
    if (!gl_context)
    {
        errfun = "SDL_GL_CreateContext()";
        errmsg = SDL_GetError();
        goto error;
    }
    SDL_GL_MakeCurrent(window, gl_context);
    //SDL_GL_SetSwapInterval(1); // Enable vsync

    glewStatus = glewInit();
    if (glewStatus != GLEW_OK)
    {
        errfun = "glewInit()";
        errmsg = (const char*)glewGetErrorString(glewStatus);
        goto error;
    }

    // Setup ImGui binding
    ImGui::CreateContext();
    ImGui_ImplSdlGL3_Init(window);             
    
    // Setup style
    ImGui::StyleColorsDark();

    // Setup time step (we don't use SDL_GetTicks() because it is using millisecond resolution)
    frequency = SDL_GetPerformanceFrequency();
    prev_time = SDL_GetPerformanceCounter();
    limit_time = 1.0f / 60.0f;

    SDL_Event event;
    while (1)
    {                      
        Uint64 current_time = SDL_GetPerformanceCounter();      
        float dt = (float)((double)(current_time - prev_time) / frequency);
        prev_time = current_time;

        while (SDL_PollEvent(&event))
        {                     
            if (event.type == SDL_QUIT)
            {
                return 0;
            }                                     
            ImGui_ImplSdlGL3_ProcessEvent(&event);
        }        
        ImGui_ImplSdlGL3_NewFrame(window, dt);

        imgui_vmath_window();

        // Rendering
        glViewport(0, 0, (int)ImGui::GetIO().DisplaySize.x, (int)ImGui::GetIO().DisplaySize.y);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui::Render();
        ImGui_ImplSdlGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window);
    }

    // Cleanup
    ImGui_ImplSdlGL3_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;

error:
    fprintf(stderr, "Error at %s: %s\n", errfun, errmsg);
    fprintf(stderr, "An error occured!\n");
    fprintf(stderr, "Press enter to exit...");
    getchar();
    return 1;
}

void imgui_vmath_window(void)
{

    if (ImGui::Begin("vmath"))
    {
        if (ImGui::CollapsingHeader("vec2_t"))
        {                  
            static vec2_t vec2_value;
            static int vec2_selected;
            static const char* vec2_funcnames[] =
            {
                "vec2", 
                "vec2_add", "vec2_sub", "vec2_mul", "vec2_div", 
            };

            ImGui::InputFloat2("Vec2 Result", &vec2_value.x);
            if (ImGui::Combo("Function", &vec2_selected, vec2_funcnames, IM_ARRAYSIZE(vec2_funcnames)))
            {

            }
            switch (vec2_selected)
            {
            case 0: /* vec2 */
            {
                static float x, y;
                if (ImGui::InputFloat("vec2 x", &x))
                {
                    vec2_value.x = x;
                }                             
                if (ImGui::InputFloat("vec2 y", &y))
                {
                    vec2_value.y = y;
                }
            } break;

            case 1: /* vec2_add */
            {
                static vec2_t lhs, rhs;
                if (ImGui::InputFloat2("Vec2 lhs", &lhs.x))
                {
                    vec2_value = vec2_add(lhs, rhs);
                }                         
                if (ImGui::InputFloat2("Vec2 rhs", &rhs.x))
                {
                    vec2_value = vec2_add(lhs, rhs);
                }
            } break;        

            case 2: /* vec2_sub */
            {
                static vec2_t lhs, rhs;
                if (ImGui::InputFloat2("Vec2 lhs", &lhs.x))
                {
                    vec2_value = vec2_sub(lhs, rhs);
                }                         
                if (ImGui::InputFloat2("Vec2 rhs", &rhs.x))
                {
                    vec2_value = vec2_sub(lhs, rhs);
                }
            } break;

            case 3: /* vec2_mul */
            {
                static vec2_t lhs, rhs;
                if (ImGui::InputFloat2("Vec2 lhs", &lhs.x))
                {
                    vec2_value = vec2_mul(lhs, rhs);
                }                         
                if (ImGui::InputFloat2("Vec2 rhs", &rhs.x))
                {
                    vec2_value = vec2_mul(lhs, rhs);
                }
            } break;

            case 4: /* vec2_div */
            {
                static vec2_t lhs, rhs;
                if (ImGui::InputFloat2("Vec2 lhs", &lhs.x))
                {
                    vec2_value = vec2_div(lhs, rhs);
                }                         
                if (ImGui::InputFloat2("Vec2 rhs", &rhs.x))
                {
                    vec2_value = vec2_div(lhs, rhs);
                }
            } break;

            default:
                break;
            }
        }
    }
    ImGui::End();
}