#pragma once
class RenderLayout
{
public:
	enum topology_type
	{
		TT_PointList,
		TT_LineList,
		TT_LineStrip,
		TT_TriangleList,
		TT_TriangleStrip
	};
	enum stream_type
	{
		ST_Geometry,
		ST_Instance
	};

public:
	RenderLayout();
	~RenderLayout();
};

