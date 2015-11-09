#pragma once
class Input
{public:

	enum {
		BUTTON_LEFT = 1 << 0,
		BUTTON_MIDDLE = 1 << 1,
		BUTTON_RIGHT = 1 << 2,
		BUTTON_UP = 1 << 3,
		BUTTON_DOWN = 1 << 4,
		BUTTON_DCLICK = 1 << 5,
		BUTTON_NULL = 1 << 6,
	};
public:
	Input();
	~Input();
	void Init();
	// mouse
 	virtual int  GetMouseX();
 	virtual int  GetMouseY();
 	virtual void SetMouse(int x, int y);
 
 	virtual int  GetMouseWheel();	
 	virtual void SetMouseWheel(int wheel);
 

	virtual int  GetMouseState();
	virtual void SetMouseState(int state);
	virtual int  GetMouseButton();
 	virtual void SetMouseButton(int button);
private:
	int mouse_x;						// mouse
	int mouse_y;
	int mouse_show;
	int mouse_wheel;
	int mouse_state;
	int mouse_button;

};

