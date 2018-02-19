#pragma once

#include <Windows.h>
#include <gl\gl.h>	// Header File For The OpenGL32 Library
#include <gl\glu.h>	// Header File For The GLu32 Library
#include <iostream>
#include <array>

using namespace std;

class TextureLoader
{
public:
	TextureLoader();
	TextureLoader(const TextureLoader &);
	TextureLoader & operator = (const TextureLoader &);
	TextureLoader(TextureLoader &&);
	TextureLoader & operator = (TextureLoader &&);
	~TextureLoader();

	static GLuint LoadBMP(const char *);
};