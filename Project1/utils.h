#ifndef UTILS_H
#define UTILS_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void printShaderLog(GLuint shader);
void printProgramLog(int prog);
bool checkOpenGLError();
string readShaderSource(const char* filePath);
GLuint createShaderProgram(const char* vertex, const char* fragment);
GLuint loadTexture(const char* texImagePath);
float* silverAmbient();
float* silverDiffuse();
float* silverSpecular();
float silverShininess();

#endif // !UTILS_H