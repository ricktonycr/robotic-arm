#include <GLFW/glfw3.h>
#include <iostream>

void error_callback(int error, const char* description){
  fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
  glViewport(0, 0, width, height);
}  

int main(int argc, char const *argv[]){
  
  glfwSetErrorCallback(error_callback);
  
  if (!glfwInit()){
    std::cout << "Failed to initialize GLFW" << std::endl;
  }
  
  GLFWwindow* window = glfwCreateWindow(640, 480, "Robotic arm", NULL, NULL);
  
  if (!window){
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
  }

  glfwSetKeyCallback(window, key_callback);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  while (!glfwWindowShouldClose(window)){
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}