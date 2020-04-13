//#include "ModelLoader.h"
//
//#include <sstream>
//
//#include "../Materials/MaterialManager.h"
//
//std::unique_ptr<ModelLoader> ModelLoader::instance = nullptr;
//
//Model ModelLoader::LoadModel(const std::string &file, const std::string &matN, unsigned int shaderProgram){
//	material = MaterialManager::GetInstance()->LoadMaterial(matN);
//	std::ifstream in(file.c_str(), std::ios::in);
//	if(!in){
//		Debug::error("Could not load Obj file " + file, __FILE__, __LINE__);
//		return Model();
//	}
//	std::string line;
//	while(std::getline(in, line)){
//		//vetex indecies
//		if(line.substr(0, 2) == "v "){
//			std::istringstream v(line.substr(2));
//			glm::vec3 vert;
//			double x, y, z;
//			v >> x >> y >> z;
//			vert = glm::vec3(x, y, z);
//
//			vertices.push_back(vert);
//		}
//
//		//normal data
//		else if(line.substr(0, 3) == "vn "){
//			std::istringstream vn(line.substr(3));
//			glm::vec3 norm;
//			double x, y, z;
//			vn >> x >> y >> z;
//			norm = glm::vec3(x, y, z);
//			normals.push_back(norm);
//		}
//		//texture coodinate data
//		else if(line.substr(0, 3) == "vt "){
//			std::istringstream vc(line.substr(3));
//			glm::vec2 tex;
//			double x, y;
//			vc >> x >> y;
//			tex = glm::vec2(x, y);
//			textureCoords.push_back(tex);
//		}
//
//		else if(line.substr(0, 2) == "f "){
//			int vt, vt2, vt3, textIndex, textIndex2, textIndex3, normal, normal2, normal3;
//
//			char camera;
//
//			std::istringstream f(line.substr(2));
//
//			f >> vt >> camera >> textIndex >> camera >> normal >> vt2 >> camera >> textIndex2 >> camera >> normal2 >> vt3 >> camera >> textIndex3 >> camera >> normal3;
//			indices.push_back(vt - 1);
//			indices.push_back(vt2 - 1);
//			indices.push_back(vt3 - 1);
//
//			textureIndices.push_back(textIndex - 1);
//			textureIndices.push_back(textIndex2 - 1);
//			textureIndices.push_back(textIndex3 - 1);
//
//			normalIndices.push_back(normal - 1);
//			normalIndices.push_back(normal2 - 1);
//			normalIndices.push_back(normal3 - 1);
//
//		}
//
//		//new material (new subMesh)
//		else if(line.substr(0, 7) == "usemtl "){
//			if(indices.size() > 0){
//				PostProcessing();
//			}
//			material = *MaterialManager::GetInstance()->GetMaterial(line.substr(7));
//		}
//	}
//	PostProcessing();
//
//	Model m;
//	for(size_t i = 0; i < meshes.size(); i++){
//		m.AddMesh(new Mesh(meshes[i], shaderProgram));
//	}
//	return m;
//}
//
//void ModelLoader::PostProcessing(){
//
//	for(size_t i = 0; i < indices.size(); i++){
//		Vertex vert;
//		vert.position = vertices[indices[i]];
//		vert.normal = normals[normalIndices[i]];
//		vert.texCoords = textureCoords[textureIndices[i]];
//		meshVertices.push_back(vert);
//	}
//	SubMesh subMesh;
//	subMesh.vertexList = meshVertices;
//	subMesh.meshIndices = indices;
//	subMesh.material = material;
//	meshes.push_back(subMesh);
//	indices.clear();
//	normalIndices.clear();
//	textureIndices.clear();
//	meshVertices.clear();
//}
//
//ModelLoader * ModelLoader::GetInstance(){
//	if(instance == nullptr){
//		instance.reset(new ModelLoader);
//	}
//	return instance.get();
//}
#include "ModelLoader.h"

#include "../../Debugging/Debug.h"
#include "../Textures/TextureManager.h"
//#include "../Materials/MaterialManager.h"

#include <algorithm>
#include <iostream>

ModelLoader::ModelLoader() : material(Material()){}

ModelLoader::~ModelLoader(){
	OnDestroy();
}

void ModelLoader::OnDestroy(){
	vertices.clear();
	normals.clear();
	textureCoords.clear();
	indices.clear();
	normalIndices.clear();
	textureIndices.clear();
	meshVertices.clear();
	meshes.clear();
}

bool ModelLoader::loadModel(const std::string & fileName){
	std::ifstream in(fileName.c_str(), std::ios::in);
	if(!in){
		Debug::error("Could not load Obj file " + fileName, __FILE__, __LINE__);
		return false;
	}
	std::string line;
	while(std::getline(in, line)){
		//vetex indecies
		if(line.substr(0, 2) == "v "){
			std::istringstream v(line.substr(2));
			glm::vec3 vert;
			double x, y, z;
			v >> x >> y >> z;
			vert = glm::vec3(x, y, z);

			vertices.push_back(vert);
		}

		//normal data
		if(line.substr(0, 3) == "vn "){
			std::istringstream vn(line.substr(3));
			glm::vec3 norm;
			double x, y, z;
			vn >> x >> y >> z;
			norm = glm::vec3(x, y, z);
			normals.push_back(norm);
		}
		//texture coodinate data
		if(line.substr(0, 3) == "vt "){
			std::istringstream vc(line.substr(3));
			glm::vec2 tex;
			double x, y;
			vc >> x >> y;
			tex = glm::vec2(x, y);
			textureCoords.push_back(tex);
		}

		if(line.substr(0, 2) == "f "){
			int vt, vt2, vt3, textIndex, textIndex2, textIndex3, normal, normal2, normal3;

			char c;

			std::istringstream f(line.substr(2));

			f >> vt >> c >> textIndex >> c >> normal >> vt2 >> c >> textIndex2 >> c >> normal2 >> vt3 >> c >> textIndex3 >> c >> normal3;
			indices.push_back(vt - 1);
			indices.push_back(vt2 - 1);
			indices.push_back(vt3 - 1);

			textureIndices.push_back(textIndex - 1);
			textureIndices.push_back(textIndex2 - 1);
			textureIndices.push_back(textIndex3 - 1);

			normalIndices.push_back(normal - 1);
			normalIndices.push_back(normal2 - 1);
			normalIndices.push_back(normal3 - 1);

		}

		//new material (new mesh)
		else if(line.substr(0, 7) == "usemtl "){
			if(indices.size() > 0){
				PostProcessing();
			}
			LoadMaterial(line.substr(7));
		}
	}
	PostProcessing();
	return true;
}

bool ModelLoader::loadModel(const std::string & fileName, const std::string & matName){
	LoadMaterialLibrary(matName);
	return loadModel(fileName);
}

int ModelLoader::loadTexture(std::string file){
	GLuint currentTexture = TextureManager::GetInstance()->GetTexture(file);
	if(currentTexture == 0){
		TextureManager::GetInstance()->CreateTexture(file, "Resources/Textures/" + file + ".jpg");
		currentTexture = TextureManager::GetInstance()->GetTexture(file);
	}
	return currentTexture;
}

std::vector<Vertex> ModelLoader::getVerts(){
	return meshVertices;
}

std::vector<int> ModelLoader::getIndices(){
	return indices;
}

std::vector<SubMesh> ModelLoader::getSubMeshes(){
	return meshes;
}

void ModelLoader::PostProcessing(){
	for(size_t i = 0; i < indices.size(); i++){
		Vertex vert;
		vert.position = vertices[indices[i]];
		vert.normal = normals[normalIndices[i]];
		vert.texCoords = textureCoords[textureIndices[i]];
		meshVertices.push_back(vert);
	}
	SubMesh mesh;
	mesh.vertexList = meshVertices;
	mesh.meshIndices = indices;
	mesh.material = material;
	meshes.push_back(mesh);
	indices.clear();
	normalIndices.clear();
	textureIndices.clear();
	meshVertices.clear();
	material = Material();
}

void ModelLoader::LoadMaterial(const std::string & fileName){
	material = MaterialManager::GetInstance()->GetMaterial(fileName);
}

void ModelLoader::LoadMaterialLibrary(const std::string & matName){
	std::ifstream in(matName.c_str(), std::ios::in);
	if(!in){
		Debug::error("Cannot open MTL file " + matName, __FILE__, __LINE__);
		return;
	}
	Material m = Material();
	std::string matN = "";
	std::string line;
	while(std::getline(in, line)){
		if(line.substr(0, 7) == "newmtl "){
			if(m.diffuseMap != 0){
				MaterialManager::GetInstance()->AddMaterial(matN, m);
				m = Material();
			}
			matN = line.substr(7);

			m.diffuseMap = loadTexture(matN);
		}
		//Shine
		if(line.substr(0, 4) == "	Ns "){
			std::istringstream v(line.substr(4));
			v >> m.shine;
		}

		//Transparency
		if(line.substr(0, 3) == "	d "){
			std::istringstream v(line.substr(3));
			v >> m.transparency;
		}

		//Ambient
		if(line.substr(0, 4) == "	Ka "){
			std::istringstream v(line.substr(4));

			double x, y, z;

			v >> x >> y >> z;
			m.ambient = glm::vec3(x, y, z);
		}

		//Diffuse
		if(line.substr(0, 4) == "	Kd "){
			std::istringstream v(line.substr(4));

			double x, y, z;

			v >> x >> y >> z;
			m.diffuse = glm::vec3(x, y, z);
		}

		//Specular
		if(line.substr(0, 4) == "	Ks "){
			std::istringstream v(line.substr(4));

			double x, y, z;

			v >> x >> y >> z;
			m.specular = glm::vec3(x, y, z);
		}
	}

	if(m.diffuseMap != 0){
		MaterialManager::GetInstance()->AddMaterial(matN, m);
	}
}