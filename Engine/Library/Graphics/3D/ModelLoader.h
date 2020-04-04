//#ifndef MODELMANAGER_H
//#define MODELMANAGER_H
//
//#include <map>
//#include <memory>
//
//#include "Model.h"
//
//struct ModelLoader{
//	//delete copy constructors for singleton
//	ModelLoader(const ModelLoader &) = delete;
//	ModelLoader(ModelLoader &&) = delete;
//	ModelLoader &operator=(const ModelLoader &) = delete;
//	ModelLoader &operator=(ModelLoader &&) = delete;
//
//	static ModelLoader *GetInstance();
//
//	Model LoadModel(const std::string& file, const std::string &matName, unsigned int shaderProgram);
//	void PostProcessing();
//
//private:
//	ModelLoader(){}
//
//	//singleton instance pointer
//	static std::unique_ptr<ModelLoader> instance;
//	friend std::default_delete<ModelLoader>;
//
//	std::vector<glm::vec3> vertices, normals;
//	std::vector<glm::vec2> textureCoords;
//
//	std::vector<int> indices, normalIndices, textureIndices;
//
//	std::vector<Vertex> meshVertices;
//
//	std::vector<SubMesh> meshes;
//
//	Material material;
//};
//
//
//#endif // !MODELMANAGER_H
#ifndef LOADOBJMODEL_H
#define LOADOBJMODEL_H

#include "Mesh.h"

#include <sstream>

struct ModelLoader{
	ModelLoader();
	~ModelLoader();

	void OnDestroy();
	void loadModel(const std::string& fileName);
	void loadModel(const std::string& fileName, const std::string& matName);
	int loadTexture(std::string file);
	std::vector<Vertex> getVerts();
	std::vector<int> getIndices();
	std::vector<SubMesh> getSubMeshes();

private:
	std::vector<glm::vec3> vertices, normals;
	std::vector<glm::vec2> textureCoords;
	std::vector<int> indices, normalIndices, textureIndices;
	std::vector<Vertex> meshVertices;
	std::vector<SubMesh> meshes;

	Material material;

	void PostProcessing();
	void LoadMaterial(const std::string& fileName);
	void LoadMaterialLibrary(const std::string& matName);

};
#endif // LOADOBJMODEL_H


