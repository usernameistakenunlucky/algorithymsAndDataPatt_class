#pragma once
#include <UnorderedMap.h>
#include <Global.h>
#include "Texture.h"

/*
Create a singleton class called TextureManager
a. UnorderedMap<size_t, Texture> mTextures;
b. Singleton setup functions
c. size_t LoadTexture(const std::string& filePath);
i. Call Globals::HashFunction(filePath) to get a UniqueId from the
filepath
ii. Use this UniqueId to add the texture to the mTextures (if not added)
iii. UniqueId is the UnorderedMap Key
iv. Return the UniqueId
*/

class TextureManager
{
private:
	UnorderedMap<size_t, Texture> _textures;

	TextureManager() {}

public:
	// Singleton setup functions
	static TextureManager* Get()
	{
		static TextureManager sInstance;
		return &sInstance;
	}
	TextureManager(const TextureManager&) = delete;
	TextureManager& operator=(const TextureManager&) = delete;


	size_t LoadTexture(const std::string& filePath)
	{
		std::size_t uniqueId = Global::HashFunction(filePath);
		Texture texture = { filePath };

		// UniqueId is the UnorderedMap Key
		if (!_textures.Find(uniqueId, texture))
		{
			_textures.Insert(uniqueId, texture);
		}

		return uniqueId;
	}

	Texture* GetTexture(std::size_t key)
	{
		if (_textures.Has(key))
		{
			return &_textures[key];
		}
		
		return nullptr;
	}
};