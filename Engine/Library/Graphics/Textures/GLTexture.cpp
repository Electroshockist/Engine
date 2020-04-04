#include "GLTexture.h"
#include "TextureManager.h"

GLTexture::GLTexture() :textureID(0) {}


GLTexture::~GLTexture() {}

//bool GLTexture::LoadTexture(const File file){
//	ATexture* t = TextureManager::GetInstance()->GetTexture(file);
//	if(t == nullptr){
//		//load texture
//		return true;
//	}
//
//	GLTexture* t = dynamic_cast<GLTexture*>()
//
//	return true;
//}
