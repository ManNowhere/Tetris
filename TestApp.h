#pragma once
#include <vector>
#include "BaseApp.h"
#include <cwchar>
#include "Tetramino.h"


class TestApp : public BaseApp
{
	typedef BaseApp Parent;
	typedef std::vector<std::vector<wchar_t>> Well;

	private:
		COORD_ OldPosition;// ���������� ������ �� ����
		COORD_ NewPosition;
		void SetTetramino(ITetramino *PtrTetra);//�������� � ������� ������
		ITetramino* GetTetramino();//���������� ������ �� ������
		bool Verific(ITetramino* PtrTetra);
		bool Direction;
		int a;
		int b;
		int aP;
		int bP;
		int B;
		wchar_t Word[10] = {};//������ ����� ����
		wchar_t TempWord[10] = {};//�������������� �������� ������ ����� ����
		int Temp;//��������� �� ������ ��������� ������� Word
		int x;// ��������� ���������� ������ �� ����
		int y;

		int xDrowScreen;
		int yDrowScreen;
		int xDrowWell;
		int yDrowWell;
		int xDrowPreview;
		int yDrowPreview;
		int xDrowScore;
		int yDrowScore;
		ITetramino* PtrTetra�urrent;
		ITetramino* PtrTetraNext;
		Figure Old_Position;//������ ��������� ������
		Figure New_Position;// ����� ��������� ������


		void DrowScreen();
		void DrowWell();

		void DrowPreview();

		void DrowScore();

		void DrowBorders();
		bool belongs_to_figure(const COORD_& coord);//�������� ��������� �������� �� �������������� ������� ������
		void clearKeyboardBuffer();//������� ������ ����������
		

	public:
		TestApp();
		~TestApp()override
		{}

		void Delete_line(Well&, int line_index);//������� ������ ������ � �������� ����� ���� ��� ������� �� ������ ����
		bool is_line_empty(const std::vector<wchar_t>& Line)const;//����� ������ ��� ������ ��� ���������� ������
		void Delete_filled_lines();//��������� ����� ����� ���������
		bool is_line_filled(const std::vector<wchar_t>& Line)const;//��������� ������ �� �������������

		Well well;
		Well Previu;
		bool going_beyond;
		virtual void KeyPressed(int btnCode);
		virtual void UpdateF(float deltaTime);
		
		float current_speed = 0.8;
		const float default_speed = 0.4;
};


