#pragma once
#include "stdafx.h"



namespace Resource
{
	enum ID
	{
		Textures, Sounds, Fonts
	};
}


template <class T>
class ResourceHolder
{
private:

	std::unordered_map<std::string, std::shared_ptr<T>> resources;

public:

	void load(Resource::ID id, cStr &filename)
	{
		// Load the resource from a file on disk
		T resource;
		if (!resource.loadFromFile(filename))
			throw std::runtime_error("Error! Failed to open file " + filename);
		resources.emplace(filename, std::make_shared<T>(resource));
	}

	const std::shared_ptr<T>& get(cStr &filename)
	{
		// Get the source
		return resources[filename];
	}

}; 
