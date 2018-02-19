#include "TextureLoader.h"

TextureLoader::TextureLoader()
{

}

TextureLoader::TextureLoader(const TextureLoader &textureLoader)
{

}

TextureLoader & TextureLoader::operator = (const TextureLoader &textureLoader)
{
	return *this;
}

TextureLoader::TextureLoader(TextureLoader &&textureLoader)
{

}

TextureLoader & TextureLoader::operator = (TextureLoader &&textureLoader)
{
	return *this;
}

TextureLoader::~TextureLoader()
{

}

GLuint TextureLoader::LoadBMP(const char *imagepath)
{
	// Data read from the header of the BMP file
	array<unsigned char, 54> header;	// Each BMP file begins by a 54-bytes header
	unsigned int dataPos;		// Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;		// = width * height * 3
	unsigned char *data;		// Actual RGB data

	// Open the file
	FILE *file;
	
	fopen_s(&file, imagepath, "rb");

	if (!file)
	{
		cout << "Image could not be opened" << endl;

		return static_cast<GLuint>(0.0);
	}

	if (fread(header.data(), static_cast<size_t>(1.0), static_cast<size_t>(54.0), file) != 54)
	{ // If not 54 bytes read : problem
		cout << "Not a correct BMP file" << endl;

		return static_cast<GLuint>(0.0);
	}

	if (header.at(0) != 'B' || header.at(1) != 'M')
	{
		cout << "Not a correct BMP file" << endl;

		return static_cast<GLuint>(0.0);
	}

	// Read ints from the byte array
	dataPos = *reinterpret_cast<int *>(&header.at(10));
	imageSize = *reinterpret_cast<int *>(&header.at(34));
	width = *reinterpret_cast<int *>(&header.at(18));
	height = *reinterpret_cast<int *>(&header.at(22));

	// Some BMP files are misformatted, guess missing information
	if (imageSize == 0.0)
	{
		imageSize = width * height * 3; // 3 : one byte for each Red, Green and Blue component
	}

	if (dataPos == 0.0)
	{
		dataPos = 54; // The BMP header is done that way
	}

	// Create a buffer
	data = new unsigned char[imageSize];

	// Read the actual data from the file into the buffer
	fread(data, 1, imageSize, file);

	//Everything is in memory now, the file can be closed
	fclose(file);

	// Create one OpenGL texture
	GLuint textureID;
	glGenTextures(static_cast<GLsizei>(1.0), &textureID);

	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);

	// Give the image to OpenGL
	glTexImage2D(GL_TEXTURE_2D, static_cast<GLint>(0.0), GL_RGB, width, height, static_cast<GLint>(0.0), GL_BGR_EXT, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	delete data;

	return textureID;
}