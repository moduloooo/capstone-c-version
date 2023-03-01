#include <cmath>
#include <vector>
#include <iostream>
#include <glm/glm.hpp>
#include "sphere.h";

using namespace std;

sphere::sphere() {
	init(48);
}

sphere::sphere(int prec) {
	init(prec);
}

float sphere::toRadians(float degrees) { 
	return (degrees * 2.0f * 3.14159f) / 360.0f; 
}

void sphere::init(int prec) {
	numVertices = (prec + 1) * (prec + 1);
	numIndices = prec * prec * 6;
	for (int i = 0; i < numVertices; i++) { vertices.push_back(glm::vec3()); } // std::vector::push_back()
	for (int i = 0; i < numVertices; i++) { texCoords.push_back(glm::vec2()); } // inserts new element at
	for (int i = 0; i < numVertices; i++) { normals.push_back(glm::vec3()); } // the end of a vector and
	for (int i = 0; i < numIndices; i++) { indices.push_back(0); } // increases the vector size by 1
	// calculate triangle vertices
	for (int i = 0; i <= prec; i++) {
		for (int j = 0; j <= prec; j++) {
			float y = (float)cos(toRadians(180.0f - i * 180.0f / prec));
			float x = -(float)cos(toRadians(j * 360.0f / prec)) * (float)abs(cos(asin(y)));
			float z = (float)sin(toRadians(j * 360.0f / prec)) * (float)abs(cos(asin(y)));
			vertices[i * (prec + 1) + j] = glm::vec3(x, y, z);
			texCoords[i * (prec + 1) + j] = glm::vec2(((float)j / prec), ((float)i / prec));
			normals[i * (prec + 1) + j] = glm::vec3(x, y, z);
		}
	}
	// calculate triangle indices
	for (int i = 0; i < prec; i++) {
		for (int j = 0; j < prec; j++) {
			indices[6 * (i * prec + j) + 0] = i * (prec + 1) + j;
			indices[6 * (i * prec + j) + 1] = i * (prec + 1) + j + 1;
			indices[6 * (i * prec + j) + 2] = (i + 1) * (prec + 1) + j;
			indices[6 * (i * prec + j) + 3] = i * (prec + 1) + j + 1;
			indices[6 * (i * prec + j) + 4] = (i + 1) * (prec + 1) + j + 1;
			indices[6 * (i * prec + j) + 5] = (i + 1) * (prec + 1) + j;
		}
	}
}

int sphere::getNumVertices() { return numVertices; }
int sphere::getNumIndices() { return numIndices; }
std::vector<int> sphere::getIndices() { return indices; }
std::vector<glm::vec3> sphere::getVertices() { return vertices; }
std::vector<glm::vec2> sphere::getTexCoords() { return texCoords; }
std::vector<glm::vec3> sphere::getNormals() { return normals; }
