#define _CRT_SECURE_NO_WARNINGS
#include "Engine.h"

#ifdef WIN32
#if 0
int APIENTRY WinMain(HINSTANCE hCurrentInst, HINSTANCE hPreviousInst, LPSTR lpszCmdLine, int nCmdShow) {
  //Open console in debug mode
#ifdef _DEBUG
  AllocConsole();
  //SetWindowPos(GetConsoleWindow(), 0, 1920, 200, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
  AttachConsole(GetCurrentProcessId());
  freopen("CON", "w", stdout);
#endif
#endif
int main() {

  //Run the main engine
  Engine engine;
  engine.Run();
  getchar();
  return 0;
}

#else

#include <emscripten.h>
#include <emscripten/html5.h>
#include <iostream>


Engine* g_engine = nullptr;

extern "C"
void run_main() {
    EmscriptenWebGLContextAttributes attr;


    emscripten_webgl_init_context_attributes(&attr);

    attr.majorVersion = 2;
    attr.minorVersion = 0;
    attr.enableExtensionsByDefault = 1;
    //    attr.premultipliedAlpha = false;
    attr.alpha = false;
    auto ctx = emscripten_webgl_create_context("mycanvas", &attr);
    auto ret = emscripten_webgl_make_context_current(ctx);


    g_engine = new Engine;
    //engine.Run();
}

extern "C"
 
int main() {
    std::cout << "main" << std::endl;
    EM_ASM_("start()");
}

#endif