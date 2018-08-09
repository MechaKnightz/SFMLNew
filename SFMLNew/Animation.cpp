#include "stdafx.h"
#include "Animation.h"
#include <fstream>
#include "nlohmann/json.hpp"
#include "ContentManager.h"

using json = nlohmann::json;

Animation::Animation()
{
}


Animation::~Animation()
{
}

void Animation::loadFromFile(std::string path, ContentManager* content)
{
	std::ifstream iStream(path);

	json j;
	iStream >> j;

	InitializeFromJson(j, this);

	for (auto frame : meta.frames)
	{
		frames.push_back(Frame(frame.frame, frame.spriteSourceSize ,frame.duration));
	}
	texture = &content->loadTexture(meta.meta.imagePath);
}

void Animation::InitializeFromJson(json j, Animation* anim) 
{
	auto metaObject = j["meta"];
	anim->meta.meta.app = metaObject["app"].get<std::string>();
	anim->meta.meta.version = metaObject["version"].get<std::string>();
	anim->meta.meta.imagePath = metaObject["image"].get<std::string>();
	anim->meta.meta.format = metaObject["format"].get<std::string>();

	auto frameObject = j["frames"];
	for (json::iterator it = frameObject.begin(); it != frameObject.end(); ++it) {
		FrameData frameData;
		frameData.filename = it.value()["filename"].get<std::string>();

		frameData.frame = sf::IntRect(
			it.value()["frame"]["x"].get<int>(),
			it.value()["frame"]["y"].get<int>(),
			it.value()["frame"]["w"].get<int>(),
			it.value()["frame"]["h"].get<int>());

		frameData.spriteSourceSize = sf::IntRect(
			it.value()["spriteSourceSize"]["x"].get<int>(),
			it.value()["spriteSourceSize"]["y"].get<int>(),
			it.value()["spriteSourceSize"]["w"].get<int>(),
			it.value()["spriteSourceSize"]["h"].get<int>());

		frameData.duration = it.value()["duration"];
		anim->meta.frames.push_back(frameData);
	}

	anim->meta.meta.scale = j.at("meta").at("scale").get<std::string>();
}