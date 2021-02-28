// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.
#include "TestApp.h"
#include <conio.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>




TestApp::TestApp()
	: Parent(23, 28),
	x(6),//������ ��������� ������ �� ����
	y(0),
	a(15),//������ �������
	b(20),//������ �������
	aP(4),//������ ������
	bP(4),
	well(b, std::vector<wchar_t>(a, L'.')),//��� �������
	Previu(aP, std::vector<wchar_t>(bP, L'.')),//���������� ��������� ������ ����
	Word{ L'S', L'c', L'o', L'r', L'e', L':' },
	TempWord{ L'S', L'c', L'o', L'r', L'e', L':' },
	B(0),//������� �������� ����� ����
	Temp(0),//��������� �� ������ ��������� ������� Word
	Direction( true )
{
	PtrTetra�urrent = TestApp::GetTetramino();
	PtrTetraNext = TestApp::GetTetramino();
	//PtrTetra�urrent = PtrTetraNext;
	Old_Position = PtrTetra�urrent->get_position();
	New_Position = PtrTetra�urrent->get_position();
	xDrowScreen = 0;
	yDrowScreen = 0;
	xDrowWell = 1;
	yDrowWell = 1;
	xDrowPreview = xDrowWell + 16;
	yDrowPreview = yDrowWell;
	xDrowScore = (xDrowPreview / 4) - 1;
	yDrowScore = Y_SIZE - 4;

	OldPosition = { x,y };
	NewPosition = { x,y };

	DrowScreen();
}


//������� ������
	ITetramino* TestApp::GetTetramino()
{
	ITetramino* TempPtrTetra = new T();

	srand(time(NULL));
	int num;
	num = 1 + rand() % 7;

	switch (num)
	{
	case 1:
		TempPtrTetra = new T();
		return TempPtrTetra;
		break;
	case 2:
		TempPtrTetra = new O();
		return TempPtrTetra;
		break;
	case 3:
		TempPtrTetra = new I();
		return TempPtrTetra;
		break;
	case 4:
		TempPtrTetra = new Z();
		return TempPtrTetra;
		break;
	case 5:
		TempPtrTetra = new S();
		return TempPtrTetra;
		break;
	case 6:
		TempPtrTetra = new J();
		return TempPtrTetra;
		break;
	case 7:
		TempPtrTetra = new L();
		return TempPtrTetra;
		break;
	}
	return TempPtrTetra;
}

	float Time_to_update = 0;

	void TestApp::SetTetramino(ITetramino* PtrTetra)
{
	int old_x_position = 0;
	int old_y_position = 0;

	int new_x_position = 0;
	int new_y_position = 0;

	for (int i = 0; i < 4; ++i)
	{
		old_x_position = OldPosition.X + Old_Position[i].X;
		old_y_position = OldPosition.Y + Old_Position[i].Y;
		well[old_y_position][old_x_position] = L'.';
	}

	for (int i = 0; i < 4; ++i)
	{
		new_x_position = NewPosition.X + New_Position[i].X;
		new_y_position = NewPosition.Y + New_Position[i].Y;

		well[new_y_position][new_x_position] = L'@';
	}
	OldPosition = NewPosition;
	Old_Position = New_Position;
	
}


	//�������� ��� �������� ������� �� �������������� �������� ���� � ����� ������
	bool TestApp::Verific(ITetramino* PtrTetra)
{
	for (int i = 0; i < 4; ++i)
	{
		const int next_x_position = NewPosition.X + PtrTetra->get_position()[i].X;
		const int next_y_position = NewPosition.Y + PtrTetra->get_position()[i].Y;

		const bool tempX = (next_x_position >= 0) && (next_x_position < well[i].size());
		const bool tempY = (next_y_position >= 0) && (next_y_position < well.size());

		const bool in_filed = tempX && tempY;
		if (!in_filed)
		{
			return false;
		}
		const bool is_figure = belongs_to_figure({ next_x_position , next_y_position });
		const bool not_empty = well[next_y_position][next_x_position] != L'.' && (!is_figure);

		if (not_empty)
		{
			return false;
		}
		
	}
	return true;
}

	void TestApp::DrowScreen()//������ ��� ���� ����
{
	DrowBorders();
	DrowPreview();
	DrowWell();
	DrowScore();
	
}

	void TestApp::DrowWell()//������ ������� � ��������
	{
		for (int i = 0; i < b; ++i)
		{
			for (int j = 0; j < a; ++j)
			{
				SetChar(xDrowWell + j, yDrowWell + i, well[i][j]);
			}
		}
	}

	void TestApp::DrowPreview()//������ ����� ������
	{	
		Figure Preview = PtrTetraNext->get_position();

		for (int i = 0; i < aP; i++)
		{
			for (int j = 0; j < bP; j++)
			{
				SetChar(xDrowPreview + i, yDrowPreview + j, L' ');
			}
		}

		for (int i = 0; i < 4; ++i)
		{
			SetChar((xDrowPreview + Preview[i].X)+1, yDrowPreview + Preview[i].Y, L'@');
		}
	}

	void TestApp::DrowScore()//���������� ���� ����
	{
		
		copy_n(TempWord, 10, Word);
		wchar_t buf[4];//..��� �������� �� ���� B
		_itow_s(B, buf, 10);//����������� int � char
		wcscat_s(Word, buf);// ���������� ��� chara ������

		// ������� �� ������ �������� ������� Word
		while (Word[Temp] != 0)
		{
			++Temp;
		}

		for (int i = 0; i < Temp; ++i)
		{
			SetChar(xDrowScore + i, yDrowScore, Word[i]);
		}
	}

	void TestApp::DrowBorders()// ���������� ������� �������� ����
	{

		for (int i = 0; i < X_SIZE; ++i)
		{
			for (int j = 0; j < Y_SIZE; ++j)
			{
				bool TopLine = ((i >= 0 || i < X_SIZE) && (j == 0));
				bool BottomLine = ((i >= 0 || i < X_SIZE) && (j == Y_SIZE - 1));

				bool VLeftLine = ((i == 0) && ((j > 0) || (j < Y_SIZE)));
				bool VRightLine = ((i == X_SIZE - 1) && ((j > 0) || (j < Y_SIZE)));

				bool VSplitLine = (i == xDrowPreview - 1) && (j > 0 || j < Y_SIZE);
				bool HSplitLine = (i >= 0 && i < xDrowPreview - 1) && (j == 21);

				if (TopLine || BottomLine || VLeftLine || VRightLine || VSplitLine || HSplitLine)
				{
					SetChar(i, j, L'#');
				}
			}

		}





	}

	bool TestApp::belongs_to_figure(const COORD_& coord)
	{
		const auto figure = PtrTetra�urrent->get_position();

		for (size_t i = 0; i < figure.size(); i++)
		{
			const COORD_ old_coord = { figure[i] + OldPosition};
			if (coord == old_coord)
			{
				return true;
			}
		}
		return false;
	}

	void TestApp::clearKeyboardBuffer()
	{
		while (_kbhit())
		{
			_getche();
		}
	}

	//��������� ����� ��������� ��� �������� ������
	void TestApp::Delete_filled_lines()
	{
		for (int i = well.size() - 1;  !(is_line_empty(well[i])) || i < 1; --i)
		{
			while (is_line_filled(well[i]))
			{
				Delete_line(well, i);
				//--i;
			}
		}
	}

	//������� ������ ������ � ��������� �� ������� ����������
	void TestApp::Delete_line(Well& well, int line_index)
	{
			for (int i = 0; i < well[line_index].size(); ++i)
			{
				well[line_index][i] = L'.';
			}
			while (is_line_empty(well[line_index]) && line_index >= 1)
			{
				swap(well[line_index], well[line_index - 1]);
				--line_index;
			}
		
			++B;
	}

	//���� �� �������� ���� ������� �� ����, ���� ������ ������
	bool TestApp::is_line_empty(const std::vector<wchar_t>& Line) const
	{
		return !any_of(Line.begin(), Line.end(), [](wchar_t j) {return j == L'@'; });
	}

	//���� ������ ������ ���������� true
	bool TestApp::is_line_filled(const std::vector<wchar_t>& Line)const
	{
		return !any_of(Line.begin(), Line.end(), [](wchar_t j) {return j == L'.'; });
	}

	

	void TestApp::KeyPressed(int btnCode)
{
	
		switch (btnCode)
		{
		//������� ������
		case 32:
			//clearKeyboardBuffer();
			Old_Position = PtrTetra�urrent->get_position();
			PtrTetra�urrent->rotate();
			New_Position = PtrTetra�urrent->get_position();
			//���� ����������� ������ ������� �� ������� �������, ���������� ����� ������ ��������� ������ �� ��� � �� 1 �����
			for (int i = 0; i < New_Position.size(); i++)
			{
				if ((NewPosition.X + New_Position[i].X) >= well[0].size())
				{
					--NewPosition.X;
					i = 0;
				}
			}
			SetTetramino(PtrTetra�urrent);
			DrowWell();
			break;

		//�����
		case 75:
			//clearKeyboardBuffer();
			--NewPosition.X;
			if (!Verific(PtrTetra�urrent))
			{
				++NewPosition.X;
				break;
			}
			SetTetramino(PtrTetra�urrent);
			DrowWell();
			break;

		//������
		case 77:
			//clearKeyboardBuffer();
			++NewPosition.X;
			if (!Verific(PtrTetra�urrent))
			{
				--NewPosition.X;
				break;
			}
			SetTetramino(PtrTetra�urrent);
			DrowWell();
			break;

		//����
		case 80:
			//clearKeyboardBuffer();
			current_speed = 0.03;
			break;
		
		}

}

	void TestApp::UpdateF(float deltaTime)
	{
		 Time_to_update += deltaTime;
		 if (Time_to_update >= current_speed)
		 {
			 
			 if(Verific(PtrTetra�urrent))
			 {
				 SetTetramino(PtrTetra�urrent);
				 DrowWell();
				 NewPosition.Y++;
			 }
			 else
			 {
				 Delete_filled_lines();
				 NewPosition.X = x;
				 NewPosition.Y = y;
				 OldPosition = NewPosition;
				 current_speed = default_speed;
				 delete PtrTetra�urrent;
				 PtrTetra�urrent = PtrTetraNext;
				 PtrTetraNext = GetTetramino();
				 Old_Position = PtrTetra�urrent->get_position();
				 New_Position = PtrTetra�urrent->get_position();
				 DrowWell();
				 DrowScore();
				 DrowPreview();
				 return;
			 }
			 Time_to_update = 0;
			 
		 }
		 
	}

