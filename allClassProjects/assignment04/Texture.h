#pragma once
#include <string>
#include <iostream>

/*
1) Create a class called Texture
a.std::string mFilePath
b.Void Print() will print “Rendering <mFilePath>”
c.Texture(const std::string& filePath);
d.Texture()
*/

class Texture
{
private:
	std::string _filePath;


public:
	Texture() {}

	Texture(const std::string& filePath)
		: _filePath(filePath)
	{
	}

	void Print()
	{
		std::cout << "Rendering " << _filePath << "\n";
	}
	

};