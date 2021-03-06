#pragma once
class Config
{
public:
	Config();
	~Config();
	
	void Load(const char* cfg);
	void Save(const char* cfg);

	bool	hide_win;
	bool	full_screen;
	int		left;
	int		top;
	int		width;
	int		height;

	//GL GLES
	std::string render_name;
};

