#include <GLFW/glfw3.h>
#include <Sask/Window.hpp>
#include <memory>
#include <string>

using sask::Window;

void Window::MakeCurrent() {
  glfwMakeContextCurrent(this->wrappedWindow.window);
}

void Window::Flush() { glfwSwapBuffers(this->wrappedWindow.window); }

void Window::UpdateViewport() {
  int width, height;
  glfwGetFramebufferSize(this->wrappedWindow.window, &width, &height);
  glViewport(0, 0, width, height);
  glClear(GL_COLOR_BUFFER_BIT);
}

bool Window::IsKeyDown(int key) {
  return glfwGetKey(this->wrappedWindow.window, key) == GLFW_PRESS;
}

std::unique_ptr<std::string> Window::GetOpenGLVersion() {
  const GLubyte *glVersion = glGetString(GL_VERSION);
  std::string version((char *)glVersion);

  return std::make_unique<std::string>(version);
}

std::unique_ptr<std::string> Window::GetRenderer() {
  const GLubyte *glRenderer = glGetString(GL_RENDERER);
  std::string renderer((char *)glRenderer);

  return std::make_unique<std::string>(renderer);
}