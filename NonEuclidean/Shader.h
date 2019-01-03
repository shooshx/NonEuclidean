#pragma once
#include <GL/glew.h>
#include <vector>
#include "Vector.h"

class Shader {
public:
  Shader(const char* name);
  ~Shader();

  void Use();
  void SetMVP(const Matrix4& mvp, const Matrix4& mv);

private:
  GLuint LoadShader(const char* fname, GLenum type);

  std::vector<std::string> attribs;
  GLuint vertId;
  GLuint fragId;
  GLuint progId;
  GLuint mvpId;
  GLuint mvId;
};
