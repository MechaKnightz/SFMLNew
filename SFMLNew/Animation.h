#pragma once
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <tuple>
#include <nlohmann/json_fwd.hpp>

class ContentManager;

class Animation
{
	class Frame
	{
	public:
		Frame(sf::IntRect rect, sf::IntRect size, float duration) : sourceRect(rect), sizeRect(size), duration(duration) {}

		sf::IntRect& getSourceRect()
		{
			return sourceRect;
		}
		sf::IntRect& getSizeRect()
		{
			return sizeRect;
		}
		float getDuration() const
		{
			return duration;
		}
	private:
		sf::IntRect sourceRect;
		sf::IntRect sizeRect;
		float duration;
	};
	class FrameData
	{
	public:
		std::string filename;
		sf::IntRect frame;
		bool rotated;
		bool trimmed;
		sf::IntRect spriteSourceSize;
		//sourceSize, first: width, second: height ???
		std::tuple<int, int> sourceSize;
		//duration in millisec
		float duration;
	};
	class Metadata
	{
	public:
		class Meta
		{
			class FrameTag {};
			class Layer
			{
			public:
				std::string name;
				int opacity;
				std::string blendMode;
			};
		public:
			std::string app;
			std::string version;
			std::string imagePath;
			std::string format;
			//size, first: width, second: height
			std::tuple<int, int> sourceSize;
			//no idea why this is a string
			std::string scale;
			std::vector<FrameTag> frameTags;

		};
	public:
		std::vector<FrameData> frames;
		Meta meta;

	};
public:
	Animation();
	~Animation();

	void loadFromFile(std::string path, ContentManager* content);

	static void InitializeFromJson(nlohmann::json j, Animation * anim);

	sf::Texture* texture;
	std::vector<Frame> frames;
	Metadata meta;
};

