#pragma once
#include "Configure.h"

class Window
{

public:
	Window(int w, int h, int flag);
	int exec();//返回函数
	void setWindowTitle(const std::string& title);//const的引用	
	
	//用静态函数只获取信息
	static int width();//获取宽度
	static int height();//获取长度
	static void clear();
	static void beginDraw();
	static void flushDraw();
	static void endDraw();


private:
	 HWND m_handle;//窗口句柄
};

