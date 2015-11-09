#pragma once
class ResLoader
{
public:
	ResLoader();
	~ResLoader();
};

class EffectLoader
{	
public:
	struct ShaderSrc
	{
		int type;
		std::string name;
		std::string src;
	};
public:
	static EffectLoader& Instance();
	EffectLoader();
	~EffectLoader();
	RenderTechniquePtr ParseEffect(const char *filename);

};