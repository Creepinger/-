#include "Window.h"
#include<iostream>
Window::Window(int w, int h, int flag)//设置窗口的宽度，高度和标志
{
	m_handle =::initgraph(w, h, flag);//保存窗口句柄的信息
}

int Window::exec()
{
	return getchar();
}

void Window::setWindowTitle(const std::string& title)
{
	::SetWindowText(m_handle, title.c_str());
}

int Window::width()
{
	return 0;
}

int Window::height()
{
	return 0;
}

void Window::clear()
{
}

void Window::beginDraw()
{
}

void Window::flushDraw()
{
}

void Window::endDraw()
{
}
