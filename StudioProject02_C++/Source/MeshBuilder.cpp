#include "MeshBuilder.h"
#include <GL\glew.h>
#include <vector>
#include "Vertex.h"
#include "MyMath.h"
#include "LoadOBJ.h"

/******************************************************************************/
/*!
\brief
Generate the vertices of a quad; Use random color for each vertex
Then generate the VBO/IBO and store them in Mesh object

\param meshName - name of mesh
\param lengthX - width of quad
\param lengthY - height of quad

\return Pointer to mesh storing VBO/IBO of quad
*/
/******************************************************************************/
Mesh* MeshBuilder::GenerateQuad(const std::string &meshName, Color color, float length)
{
	// An array of 3 vectors which represents 3 vertices
	Vertex v;
	std::vector<Vertex> vertex_buffer_data;

	v.pos.Set(-0.5f * length,-0.5f * length,0); 
	v.color = color;
	v.normal.Set(0, 0, 1);
	v.texCoord.Set(0, 0);
	vertex_buffer_data.push_back(v);

	v.pos.Set(0.5f * length,-0.5f * length,0);
	v.color = color;
	v.texCoord.Set(1, 0);
	vertex_buffer_data.push_back(v);

	v.pos.Set(0.5f * length,0.5f * length,0); 
	v.color = color;
	v.texCoord.Set(1, 1);
	vertex_buffer_data.push_back(v);

	v.pos.Set(-0.5f * length,0.5f * length,0); 
	v.color = color;
	v.texCoord.Set(0, 1);
	vertex_buffer_data.push_back(v);

	std::vector<GLuint> index_buffer_data;
	index_buffer_data.push_back(3);
	index_buffer_data.push_back(0);
	index_buffer_data.push_back(2);
	index_buffer_data.push_back(1);
	index_buffer_data.push_back(2);
	index_buffer_data.push_back(0);

	Mesh *mesh = new Mesh(meshName);


	

	
	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);

	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLES;

	return mesh;
}

Mesh* MeshBuilder::GenerateQuad(const std::string &meshName, Color color, float length, float height, bool repeat)
{
	// An array of 3 vectors which represents 3 vertices
	Vertex v;
	std::vector<Vertex> vertex_buffer_data;

	v.pos.Set(-0.5f * length, -0.5f * height, 0);
	v.color = color;
	v.normal.Set(0, 0, 1);
	v.texCoord.Set(0, 0);
	vertex_buffer_data.push_back(v);

	v.pos.Set(0.5f * length, -0.5f * height, 0);
	v.color = color;
	if (repeat == true) {
		v.texCoord.Set(10, 0);
	}
	else {
		v.texCoord.Set(1, 0);
	}
	vertex_buffer_data.push_back(v);

	v.pos.Set(0.5f * length, 0.5f * height, 0);
	v.color = color;
	if (repeat == true) {
		v.texCoord.Set(10, 10);
	}
	else {
		v.texCoord.Set(1, 1);
	}
	vertex_buffer_data.push_back(v);

	v.pos.Set(-0.5f * length, 0.5f * height, 0);
	v.color = color;
	if (repeat == true) {
		v.texCoord.Set(0, 10);
	}
	else {
		v.texCoord.Set(0, 1);
	}
	vertex_buffer_data.push_back(v);

	std::vector<GLuint> index_buffer_data;
	index_buffer_data.push_back(3);
	index_buffer_data.push_back(0);
	index_buffer_data.push_back(2);
	index_buffer_data.push_back(1);
	index_buffer_data.push_back(2);
	index_buffer_data.push_back(0);

	Mesh *mesh = new Mesh(meshName);





	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);

	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLES;

	return mesh;
}

float sphereX(float phi, float theta) {
	return cos(Math::DegreeToRadian(phi)) * cos(Math::DegreeToRadian(theta));
}
float sphereY(float phi, float theta) {
	return sin(Math::DegreeToRadian(phi));
}
float sphereZ(float phi, float theta) {
	return cos(Math::DegreeToRadian(phi)) * sin(Math::DegreeToRadian(theta));
}




Mesh* MeshBuilder::GenerateOBJ(const std::string &meshName, const std::string &file_path) {
	//Read vertices, texcoords & normals from OBJ
	std::vector<Position> vertices;
	std::vector<TexCoord> uvs;
	std::vector<Vector3> normals;

	bool success = LoadOBJ(file_path.c_str(), vertices,
		uvs, normals);

	if (!success)
		return NULL;

	//Index the vertices, texcoords & normals properly
	std::vector<Vertex> vertex_buffer_data;
	std::vector<GLuint> index_buffer_data;
	IndexVBO(vertices, uvs, normals, index_buffer_data,
		vertex_buffer_data);
	//Create the mesh and call glBindBuffer, glBufferData
	//Use triangle list and remember to set index size

	Mesh *mesh = new Mesh(meshName);

	mesh->mode = Mesh::DRAW_TRIANGLES;

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex),
		&vertex_buffer_data[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint),
		&index_buffer_data[0], GL_STATIC_DRAW);

	mesh->indexSize = index_buffer_data.size();

	return mesh;
		
}

Mesh* MeshBuilder::GenerateText(const std::string &meshName, unsigned numRow, unsigned numCol)
{
	Vertex v;
	std::vector<Vertex> vertex_buffer_data;
	std::vector<GLuint> index_buffer_data;

	float width = 1.f / numCol;
	float height = 1.f / numRow;
	int offset = 0;

	for (unsigned j = 0; j < numRow; ++j)
	{
		for (unsigned i = 0; i < numCol; ++i)
		{
			float u1 = i * width;
			float v1 = 1.f - height - j * height;

			v.pos.Set(-0.5, -0.5, 0);
			v.texCoord.Set(u1, v1);
			vertex_buffer_data.push_back(v);

			v.pos.Set(0.5, -0.5, 0);
			v.texCoord.Set(u1 + width, v1);
			vertex_buffer_data.push_back(v);

			v.pos.Set(0.5, 0.5, 0);
			v.texCoord.Set(u1 + width, v1 + height);
			vertex_buffer_data.push_back(v);

			v.pos.Set(-0.5, 0.5, 0);
			v.texCoord.Set(u1, v1 + height);
			vertex_buffer_data.push_back(v);

			index_buffer_data.push_back(offset + 0);
			index_buffer_data.push_back(offset + 1);
			index_buffer_data.push_back(offset + 2);

			index_buffer_data.push_back(offset + 0);
			index_buffer_data.push_back(offset + 2);
			index_buffer_data.push_back(offset + 3);
			offset += 4;

		}
	}

	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex),
		&vertex_buffer_data[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint),
		&index_buffer_data[0], GL_STATIC_DRAW);
	
	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLES;

	return mesh;
}

