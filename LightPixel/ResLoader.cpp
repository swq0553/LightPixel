#include "LightPixel.hpp"
#include "ResLoader.hpp"
#include "PreDeclare.hpp"
#include "Util.hpp"
#include "RenderEffect.hpp"

ResLoader::ResLoader()
{
}


ResLoader::~ResLoader()
{
}


//EffectLoader
EffectLoader& EffectLoader::Instance()
{
	static EffectLoader globalMgr;
	return globalMgr;

}

EffectLoader::EffectLoader()
{

}

EffectLoader::~EffectLoader()
{

}

RenderTechniquePtr EffectLoader::ParseEffect(const char *filename)
{
 	std::fstream _file;
 	_file.open(filename, std::ios::in);
 	if (!_file)
	{
		std::cout << filename << "is not exist";
		return NULL;
	}
	XmlFile mfile(filename);
	XmlDoc mDoc;
	mDoc.parse<0>(mfile.data());
	XmlNode *effectXml, *shaderXml, *techniqeXml, *passXml;

	effectXml = mDoc.first_node("effect");
 
 	//∂¡»°shader‘¥¬Î
 	ShaderSrc VSSrc, PSSrc;
	shaderXml = effectXml->first_node("shader");
	while (shaderXml)
 	{
 		ShaderSrc shadersrc;
		std::string type = shaderXml->first_attribute("type")->value();
		std::string name = shaderXml->first_attribute("name")->value();
		std::string src = shaderXml->first_node()->value();
 
 		switch (Str2Int(type))
 		{
 		case 0:
 			VSSrc.type = 0;
 			VSSrc.name = name;
 			VSSrc.src = src;
 			break;
 		case 1:
 			PSSrc.type = 1;
 			PSSrc.name = name;
 			PSSrc.src = src;
 			break;
 		}
 
		shaderXml = shaderXml->next_sibling("shader");
 	}
 
 	//∂¡»°tech
 	RenderTechniquePtr renderTech = MakeSharedPtr<RenderTechnique>();
	techniqeXml = effectXml->first_node("technique");
	if (techniqeXml)
 	{
 		passXml = techniqeXml->first_node("pass");
 		while (passXml)
 		{
 			std::string vs = passXml->first_node("program")->first_attribute("VS")->value();
 			std::string ps = passXml->first_node("program")->first_attribute("PS")->value();
 
 			ProgramPtr shaderobj = MakeSharedPtr<Program>();
 			shaderobj->compileShader(VSSrc.src, Program::VS);
 			shaderobj->compileShader(PSSrc.src, Program::PS);
			shaderobj->link();
 			RenderPassPtr renderPass = MakeSharedPtr<RenderPass>();
 			renderPass->SetProgram(shaderobj);
 			renderTech->AddPass(renderPass);
 
 			passXml = passXml->next_sibling("pass");
 		}
 		return renderTech;
 	}

	return nullptr;
}