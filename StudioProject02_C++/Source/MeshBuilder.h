#ifndef MESH_BUILDER_H
#define MESH_BUILDER_H

#include "Mesh.h"
#include "Vertex.h"
#include "Vector3.h"
/******************************************************************************/
/*!
		Class MeshBuilder:
\brief	Provides methods to generate mesh of different shapes
*/
/******************************************************************************/
class MeshBuilder
{
public:
	static Mesh* GenerateQuad(const std::string &meshName, Color color, float length);
	static Mesh* GenerateQuad(const std::string &meshName, Color color, float length, float height, bool repeat);
	static Mesh* GenerateOBJ(const std::string &meshName, const std::string &file_path);
	static Mesh* GenerateText(const std::string &meshName, unsigned numRow, unsigned numCol);
};

#endif