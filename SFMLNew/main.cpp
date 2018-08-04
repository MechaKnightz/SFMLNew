#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Engine.h"
#include <chrono>
#include <iostream>
#include <Windows.h>
#include "MainMenu.h"
#include "ContentManager.h"
#include <codecvt>

int64_t getTickCount();
void update(sf::RenderWindow& window, sf::Time elapsed);
void render(sf::RenderWindow& window);
std::wstring getExecutableDir();
std::string wstringConvert(std::wstring wstring);

eng::Engine* engine;
int64_t startingTime;

const int TICKS_PER_SECOND = 100;
const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
const int MAX_FRAMESKIP = 5;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!", sf::Style::None);

	ContentManager content(wstringConvert(getExecutableDir()) + "Content\\");

	engine = new eng::Engine(content);
	engine->pushState(&MainMenu::instance(content, *engine));
	std::cout << "Starting...";
	startingTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	double next_game_tick = static_cast<double>(getTickCount());
	sf::Clock clock;
	while (window.isOpen() && engine->isGameRunning()) {

		int loops = 0;
		int64_t tempvar = getTickCount();
		while (tempvar > next_game_tick && loops < MAX_FRAMESKIP) {
			sf::Time elapsed = clock.restart();
			update(window, elapsed);

			next_game_tick += SKIP_TICKS;
			loops++;
		}

		const float interpolation = float(getTickCount() + SKIP_TICKS - next_game_tick)
			/ float(SKIP_TICKS);
		render(window);
	}
	window.close();
	delete engine;
	return 0;
}

int64_t getTickCount()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - startingTime;
}

void update(sf::RenderWindow& window, sf::Time elapsed)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
	engine->update(window, elapsed);
}

void render(sf::RenderWindow& window)
{
	sf::Color color(77, 77, 77);
	window.clear(color);
	engine->draw(window);
	window.display();
}

std::wstring getExecutablePath()
{
	std::vector<wchar_t> pathBuf;
	DWORD copied = 0;
	do {
		pathBuf.resize(pathBuf.size() + MAX_PATH);
		copied = GetModuleFileName(0, &pathBuf.at(0), pathBuf.size());
	} while (copied >= pathBuf.size());

	pathBuf.resize(copied);

	std::wstring path(pathBuf.begin(), pathBuf.end());

	return path;
}

std::wstring getExecutableDir()
{
	std::wstring test = getExecutablePath();
	return test.substr(0, test.find_last_of(L"\\") + 1);
}

std::string wstringConvert(std::wstring wstring)
{
	using convert_type = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_type, wchar_t> converter;

	//use converter (.to_bytes: wstr->str, .from_bytes: str->wstr)

	return converter.to_bytes(wstring);
}