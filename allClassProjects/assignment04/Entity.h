#pragma once
#include <Vector2.h>
#include <string>
#include <iostream>

#include "TextureManager.h"

/*
Create a class Entity
a. size_t mTextureId;
b. Vector2 mPosition;
c. Void Initialize(const std::string& textureFilePath)
i. Loads a texture through the texture manager and stores texture id
ii. Randomly gives a position
d. Void Update()
i. Moves the mPosition to another location between –200 to 200
e. Void Render()
i. Obtains the texture from the texture manager and calls “Print()”
ii. Also print entity’s position
*/

class Entity
{
private:
	size_t _textureId = 0;
	Vector2 _position = { 0,0 };

	Vector2 RandomPos()
	{
		float x = rand() % 401 - 200;
		float y = rand() % 401 - 200;
		return Vector2{ x, y };
	}

public:
	Entity() {}

	void Initialize(const std::string& textureFilePath)
	{
		// i. Loads a texture through the texture manager and stores texture id
		TextureManager* manager = TextureManager::Get();
		_textureId = manager->LoadTexture(textureFilePath);

		// ii.Randomly gives a position
		_position = RandomPos();
	}

	void Update()
	{
		// Moves the mPosition to another location between –200 to 200
		_position = RandomPos();
	}

	void Render()
	{
		// i.Obtains the texture from the texture manager and calls “Print()”
		TextureManager* manager = TextureManager::Get();
		manager->GetTexture(_textureId)->Print();
	
		// ii.Also print entity’s position
		std::cout << "Entity Position = (" << _position.x << "," << _position.y << ")\n";
	}

	Vector2 GetPosition() const { return _position; }
};