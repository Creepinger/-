#include "Window.h"
#include<iostream>
Window::Window(int w, int h, int flag)//���ô��ڵĿ�ȣ��߶Ⱥͱ�־
{
	m_handle =::initgraph(w, h, flag);//���洰�ھ������Ϣ
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
