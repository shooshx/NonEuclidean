#include "FrameBuffer.h"
#include "GameHeader.h"
#include "Engine.h"
#include <iostream>

FrameBuffer::FrameBuffer() {
  glGenTextures(1, &texId);
  glBindTexture(GL_TEXTURE_2D, texId);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, GH_FBO_SIZE, GH_FBO_SIZE, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
  //-------------------------
  glGenFramebuffers(1, &fbo);
  glBindFramebuffer(GL_FRAMEBUFFER_EXT, fbo);
  glFramebufferTexture2D(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, texId, 0);
  //-------------------------
  glGenRenderbuffers(1, &renderBuf);
  glBindRenderbuffer(GL_RENDERBUFFER_EXT, renderBuf);
  glRenderbufferStorage(GL_RENDERBUFFER_EXT, GL_DEPTH_COMPONENT16, GH_FBO_SIZE, GH_FBO_SIZE);
  //-------------------------
  glFramebufferRenderbuffer(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, renderBuf);
  //-------------------------

  //Does the GPU support current FBO configuration?
  GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER_EXT);
  if (status != GL_FRAMEBUFFER_COMPLETE_EXT) {
    return;
  }

  //Unbind so future rendering can proceed normally
  glBindFramebuffer(GL_FRAMEBUFFER_EXT, 0);
}

void FrameBuffer::Use() {
  glBindTexture(GL_TEXTURE_2D, texId);
}

void FrameBuffer::Render(const Camera& cam, GLuint curFBO, const Portal* skipPortal) {
  glBindFramebuffer(GL_FRAMEBUFFER_EXT, fbo);
  glViewport(0, 0, GH_FBO_SIZE, GH_FBO_SIZE);
  GH_ENGINE->Render(cam, fbo, skipPortal);
  glBindFramebuffer(GL_FRAMEBUFFER_EXT, curFBO);
}
