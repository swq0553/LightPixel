#include "LightPixel.hpp"
#include "Config.hpp"


Config::Config()
	: hide_win(false), full_screen(false),
	left(0), top(0), width(800), height(600)
{
	render_name = "GL";
}

Config::~Config()
{
}

void Config::Load(const char* cfg)
{

}

void Config::Save(const char* cfg)
{

}
