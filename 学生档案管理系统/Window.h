#pragma once
#include "Configure.h"

class Window
{

public:
	Window(int w, int h, int flag);
	int exec();//���غ���
	void setWindowTitle(const std::string& title);//const������	
	
	//�þ�̬����ֻ��ȡ��Ϣ
	static int width();//��ȡ���
	static int height();//��ȡ����
	static void clear();
	static void beginDraw();
	static void flushDraw();
	static void endDraw();


private:
	 HWND m_handle;//���ھ��
};

