#pragma once
#include "GameHeader.h"
#include "Camera.h"
#include "Input.h"
#include "Object.h"
#include "Portal.h"
#include "Player.h"
#include "Timer.h"
#include "Scene.h"
#include "Sky.h"
#include <GL/glew.h>
#ifdef WIN32
#include <windows.h>
#endif
#include <memory>
#include <vector>

class Engine {
public:
  Engine();
  ~Engine();

  int Run();
  void Update();
  void Render(const Camera& cam, GLuint curFBO, const Portal* skipPortal);
  void LoadScene(int ix);

#ifdef WIN32
  LRESULT WindowProc(HWND hCurWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
#endif

  const Player& GetPlayer() const { return *player; }
  float NearestPortalDist() const;

  void RunSingleLoop();

private:
  void CreateGLWindow();
  void InitGLObjects();
  void DestroyGLObjects();
  void SetupInputs();
  void ConfineCursor();
  void ToggleFullscreen();


#ifdef WIN32
  HDC   hDC;           // device context
  HGLRC hRC;				   // opengl context
  HWND  hWnd;				   // window
  HINSTANCE hInstance; // process id

#else 

#endif
  long iWidth;         // window width
  long iHeight;        // window height
  bool isFullscreen;   // fullscreen state


  int64_t ticks_per_step;
  int64_t cur_ticks;

  Camera main_cam;
  Input input;
  Timer timer;

  std::vector<std::shared_ptr<Object>> vObjects;
  std::vector<std::shared_ptr<Portal>> vPortals;
  std::shared_ptr<Sky> sky;
  std::shared_ptr<Player> player;

  GLint occlusionCullingSupported = 0;

  std::vector<std::shared_ptr<Scene>> vScenes;
  std::shared_ptr<Scene> curScene;
};
