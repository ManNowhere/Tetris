// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.
#include "TestApp.h"
#include <conio.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>




TestApp::TestApp()
	: Parent(23, 28),
	x(6),//начало отрисовки фигуры на поле
	y(0),
	a(15),//ширина колодца
	b(20),//высота колодца
	aP(4),//размер превью
	bP(4),
	well(b, std::vector<wchar_t>(a, L'.')),//сам колодец
	Previu(aP, std::vector<wchar_t>(bP, L'.')),//отражается следующая фигура игры
	Word{ L'S', L'c', L'o', L'r', L'e', L':' },
	B(0),//интовое значение очков игры
	Temp(0),//кличество не пустых элементов массива Word
	Direction( true )
{
	TestApp::GetTetramino();
	Old_Position = PtrTetra->get_position();
	New_Position = PtrTetra->get_position();
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





//создает фигуру
	void TestApp::GetTetramino()
{
	srand(time(NULL));
	int num;
	num = 1 + rand() % 7;

	switch (num)
	{
	case 1:
		PtrTetra = new T();
		break;
	case 2:
		PtrTetra = new O();
		break;
	case 3:
		PtrTetra = new I();
		break;
	case 4:
		PtrTetra = new Z();
		break;
	case 5:
		PtrTetra = new S();
		break;
	case 6:
		PtrTetra = new J();
		break;
	case 7:
		PtrTetra = new L();
		break;

	}
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


	//поверить все элементы массива на принадлежность игровому полю и самой фигуре
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

	void TestApp::DrowScreen()//рисует все окно игры
{
	DrowBorders();
	DrowPreview();
	DrowWell();
	DrowScore();
	
}

	void TestApp::DrowWell()//рисует колодец с фигурами
	{
		for (int i = 0; i < b; ++i)
		{
			for (int j = 0; j < a; ++j)
			{
				SetChar(xDrowWell + j, yDrowWell + i, well[i][j]);
			}
		}
	}

	void TestApp::DrowPreview()//рисует анонс фигуры
	{
		for (int i = 0; i < aP; i++)
		{
			for (int j = 0; j < bP; j++)
			{
				SetChar(xDrowPreview + i, yDrowPreview + j, Previu[i][j]);
			}
		}
	}

	void TestApp::DrowScore()//отображает счет игры
	{
		wchar_t buf[2];//..что осталось от инта B
		_itow_s(B, buf, 10);//преобразуем int в char
		wcscat_s(Word, buf);// складываем два chara вместе

		// считаем не пустые элементы массива Word
		while (Word[Temp] != 0)
		{
			++Temp;
		}


		for (int i = 0; i < Temp; ++i)
		{
			SetChar(xDrowScore + i, yDrowScore, Word[i]);
		}
	}

	void TestApp::DrowBorders()// отображает границы игрового поля
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
		const auto figure = PtrTetra->get_position();

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



	//управляет тремя функциями для удаления строки
	void TestApp::Delete_filled_lines()
	{
		for (int i = well.size() - 1;  !is_line_empty(well[i])  ; --i)
		{
			while (is_line_filled(well[i]))
			{
				Delete_line(well, i);
				//--i;
			}
		}
		
	}


	//удаляет полную строку и заполняет ее пустыми элементами
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
		
		
	}

	//если не втсретил этот элемент ни разу, знач строка пустая
	bool TestApp::is_line_empty(const std::vector<wchar_t>& Line) const
	{
		return !any_of(Line.begin(), Line.end(), [](wchar_t j) {return j == L'@'; });
	}


	//если строка полная
	bool TestApp::is_line_filled(const std::vector<wchar_t>& Line)const
	{
		return !any_of(Line.begin(), Line.end(), [](wchar_t j) {return j == L'.'; });
	}



	void TestApp::KeyPressed(int btnCode)
{
	
		switch (btnCode)
		{

		//поворот фигуры
		case 32:
			//clearKeyboardBuffer();
			Old_Position = PtrTetra->get_position();
			PtrTetra->rotate();
			New_Position = PtrTetra->get_position();
			SetTetramino(PtrTetra);
			DrowWell();
			break;

		//влево
		case 75:
			//clearKeyboardBuffer();
			--NewPosition.X;
			if (NewPosition.X < 0)
			{
				NewPosition.X = 0;
			}
			SetTetramino(PtrTetra);
			DrowWell();
			break;

		//вправо
		case 77:
			//clearKeyboardBuffer();
			++NewPosition.X;
			if (!Verific(PtrTetra))
			{
				--NewPosition.X;
			}
			SetTetramino(PtrTetra);
			DrowWell();
			break;

		//вниз
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
			 
			 if(Verific(PtrTetra))
			 {
				 SetTetramino(PtrTetra);
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
				 GetTetramino(); 
				 Old_Position = PtrTetra->get_position();
				 New_Position = PtrTetra->get_position();
				 DrowWell();
				 return;
			 }
			 Time_to_update = 0;
			 
		 }
		 
	}

