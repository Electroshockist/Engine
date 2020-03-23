#include "ModelLoader.h"

#include <sstream>

#include "../Materials/MaterialManager.h"

std::unique_ptr<ModelLoader> ModelLoader::instance = nullptr;

Model ModelLoader::LoadModel(std::string file, unsigned int shaderProgram){
	std::ifstream in(file.c_str(), std::ios::in);
	if(!in){
		Debug::error("Could not load Obj file " + file, __FILE__, __LINE__);
		return Model();
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
		else if(line.substr(0, 3) == "vn "){
			std::istringstream vn(line.substr(3));
			glm::vec3 norm;
			double x, y, z;
			vn >> x >> y >> z;
			norm = glm::vec3(x, y, z);
			normals.push_back(norm);
		}
		//texture coodinate data
		else if(line.substr(0, 3) == "vt "){
			std::istringstream vc(line.substr(3));
			glm::vec2 tex;
			double x, y;
			vc >> x >> y;
			tex = glm::vec2(x, y);
			textureCoords.push_back(tex);
		}

		else if(line.substr(0, 2) == "f "){
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

		//new material (new subMesh)
		else if(line.substr(0, 7) == "usemtl "){
			if(indices.size() > 0){
				PostProcessing();
			}
			MaterialManager::GetInstance()->GetMaterial(line.substr(7));
		}
	}
	PostProcessing();

	Model m;
	for(int i = 0; i < meshes.size(); i++){
		m.AddMesh(new Mesh(meshes[i], shaderProgram));
	}
	return m;
}

void ModelLoader::PostProcessing(){


	Material material = Material();
	for(size_t i = 0; i < indices.size(); i++){
		Vertex vert;
		vert.position = vertices[indices[i]];
		vert.normal = normals[normalIndices[i]];
		vert.texCoords = textureCoords[textureIndices[i]];
		meshVertices.push_back(vert);
	}
	SubMesh subMesh;
	subMesh.vertexList = meshVertices;
	subMesh.meshIndices = indices;
	subMesh.material = material;
	meshes.push_back(subMesh);
	indices.clear();
	normalIndices.clear();
	textureIndices.clear();
	meshVertices.clear();
}

ModelLoader * ModelLoader::GetInstance(){
	if(instance == nullptr){
		instance.reset(new ModelLoader);
	}
	return nullptr;
}
