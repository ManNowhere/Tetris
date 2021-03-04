// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.
#include "TestApp.h"
#include <conio.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <thread>




TestApp::TestApp()
	: Parent(23, 28),
	mDefaultFigureStartPositionX(6),//начало отрисовки фигуры на поле
	mDefaultFigureStartPositionY(0),
	mWellWidth(15),//ширина колодца
	mHightWell(20),//высота колодца
	mPreviewWidth(4),//размер превью
	mPreviewHight(4),
	Game_over(false),
	mWell(mHightWell, std::vector<wchar_t>(mWellWidth, L'.')),//сам колодец
	mPreviu{mPreviewWidth, std::vector<wchar_t>(mPreviewHight, L'.')},//отражается следующая фигура игры
	mResultScoreWord{ L'S', L'c', L'o', L'r', L'e', L':' },
	mDefaultWord{ L'S', L'c', L'o', L'r', L'e', L':' },
	mScoreNumber(0)//интовое значение очков игры
{

    PtrTetraCurrent = GetTetramino();
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	PtrTetraNext = GetTetramino();
    Old_Position = PtrTetraCurrent->GetPosition();
    New_Position = PtrTetraCurrent->GetPosition();
	xDrowScreen = 0;
	yDrowScreen = 0;
	xDrowWell = 1;
	yDrowWell = 1;
	xDrowPreview = xDrowWell + 16;
	yDrowPreview = yDrowWell;
	xDrowScore = (xDrowPreview / 4) - 1;
	yDrowScore = Y_SIZE - 4;

	mOldFigureStartPosition = { mDefaultFigureStartPositionX,mDefaultFigureStartPositionY };
	mNewFigureStartPosition = { mDefaultFigureStartPositionX,mDefaultFigureStartPositionY };

	DrowScreen();
}


//создает фигуру
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
		old_x_position = mOldFigureStartPosition.mX + Old_Position[i].mX;
		old_y_position = mOldFigureStartPosition.mY + Old_Position[i].mY;
		mWell[old_y_position][old_x_position] = L'.';
	}

	for (int i = 0; i < 4; ++i)
	{
		new_x_position = mNewFigureStartPosition.mX + New_Position[i].mX;
		new_y_position = mNewFigureStartPosition.mY + New_Position[i].mY;

		mWell[new_y_position][new_x_position] = L'@';
	}
	mOldFigureStartPosition = mNewFigureStartPosition;
	Old_Position = New_Position;
	
}


	//поверить все элементы массива на принадлежность игровому полю и самой фигуре
	bool TestApp::CanMoveFigure(ITetramino* PtrTetra)
{
	for (int i = 0; i < 4; ++i)
	{
		const int next_x_position = mNewFigureStartPosition.mX + PtrTetra->GetPosition()[i].mX;
		const int next_y_position = mNewFigureStartPosition.mY + PtrTetra->GetPosition()[i].mY;

		const bool tempX = (next_x_position >= 0) && (next_x_position < mWell[i].size());
		const bool tempY = (next_y_position >= 0) && (next_y_position < mWell.size());

		const bool in_filed = tempX && tempY;
		if (!in_filed)
		{
			return false;
		}
		const bool is_figure = belongs_to_figure({ next_x_position , next_y_position });
		const bool not_empty = mWell[next_y_position][next_x_position] != L'.' && (!is_figure);

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
		for (int i = 0; i < mHightWell; ++i)
		{
			for (int j = 0; j < mWellWidth; ++j)
			{
				SetChar(xDrowWell + j, yDrowWell + i, mWell[i][j]);
			}
		}
	}

	void TestApp::DrowPreview()//рисует анонс фигуры
	{	
		Figure Preview = PtrTetraNext->GetPosition();

		for (int i = 0; i < mPreviewWidth; i++)
		{
			for (int j = 0; j < mPreviewHight; j++)
			{
				SetChar(xDrowPreview + i, yDrowPreview + j, L' ');
			}
		}

		for (int i = 0; i < 4; ++i)
		{
			SetChar((xDrowPreview + Preview[i].mX)+1, yDrowPreview + Preview[i].mY, L'@');
		}
	}

	void TestApp::DrowScore()//отображает счет игры
	{
		
		copy_n(mDefaultWord, 10, mResultScoreWord);
		wchar_t buf[4];//..что осталось от инта B
		_itow_s(mScoreNumber, buf, 10);//преобразуем int в char
		wcscat_s(mResultScoreWord, buf);// складываем два chara вместе

		for (int i = 0; mResultScoreWord[i] != '\0'; ++i)
		{
			SetChar(xDrowScore + i, yDrowScore, mResultScoreWord[i]);
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
        const auto figure = PtrTetraCurrent->GetPosition();

		for (size_t i = 0; i < figure.size(); i++)
		{
			const COORD_ old_coord = { figure[i] + mOldFigureStartPosition};
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
	void TestApp::DeleteFilledLines()
	{
		for (int i = mWell.size() - 1; i > -1 && !(IsLineEmpty(mWell[i])); --i)
		{
			while (IsLineFilled(mWell[i]))
			{
				DeleteLine(mWell, i);//--i;
			}
		}

	}

	//удаляет полную строку и заполняет ее пустыми элементами
	void TestApp::DeleteLine(Well& well, int line_index)
	{
			for (int i = 0; i < well[line_index].size(); ++i)
			{
				well[line_index][i] = L'.';
			}
			while (IsLineEmpty(well[line_index]) && line_index >= 1)
			{
				swap(well[line_index], well[line_index - 1]);
				--line_index;
			}
		
			++mScoreNumber;
	}

	//если не втсретил этот элемент ни разу, знач строка пустая
	bool TestApp::IsLineEmpty(const std::vector<wchar_t>& Line) const
	{
		return !any_of(Line.begin(), Line.end(), [](wchar_t j) {return j == L'@'; });
	}

	//если строка полная возвращаем true
	bool TestApp::IsLineFilled(const std::vector<wchar_t>& Line)const
	{
		return !any_of(Line.begin(), Line.end(), [](wchar_t j) {return j == L'.'; });
	}


	bool TestApp::IsGameOver()
	{
		return (mNewFigureStartPosition.mX == mDefaultFigureStartPositionX) && (mNewFigureStartPosition.mY == 1);
	}
	

	void TestApp::KeyPressed(int btnCode)
{
	
		switch (btnCode)
		{
		//поворот фигуры
		case 32:
			//clearKeyboardBuffer();
            Old_Position = PtrTetraCurrent->GetPosition();
            PtrTetraCurrent->Rotate();
            New_Position = PtrTetraCurrent->GetPosition();
			//если развернутая фигура выходит за пределы колодца, отодвигаем точку начала отрисовки фигуры по оси Х на 1 назад
			for (int i = 0; i < New_Position.size(); i++)
			{
				if ((mNewFigureStartPosition.mX + New_Position[i].mX) >= mWell[0].size())
				{
					--mNewFigureStartPosition.mX;
					i = 0;
				}
			}
            SetTetramino(PtrTetraCurrent);
			DrowWell();
			break;

		//влево
		case 75:
			//clearKeyboardBuffer();
			--mNewFigureStartPosition.mX;
            if (!CanMoveFigure(PtrTetraCurrent))
			{
				++mNewFigureStartPosition.mX;
				break;
			}
            SetTetramino(PtrTetraCurrent);
			DrowWell();
			break;

		//вправо
		case 77:
			//clearKeyboardBuffer();
			++mNewFigureStartPosition.mX;
            if (!CanMoveFigure(PtrTetraCurrent))
			{
				--mNewFigureStartPosition.mX;
				break;
			}
            SetTetramino(PtrTetraCurrent);
			DrowWell();
			break;

		//вниз
		case 80:
			//clearKeyboardBuffer();
			mCurrentSpeed = 0.03;
			break;
		
		}

}

	void TestApp::UpdateF(float deltaTime)
	{
		if (Game_over)
		{
			return;
		}
		 Time_to_update += deltaTime;
		 if (Time_to_update >= mCurrentSpeed)
		 {
			 
             if(CanMoveFigure(PtrTetraCurrent))
			 {
                 SetTetramino(PtrTetraCurrent);
				 DrowWell();
				 mNewFigureStartPosition.mY++;
			 }
			 else
			 {
							 if (IsGameOver())
							 {
								 Game_over = true;
								 return;
							 }
				 DeleteFilledLines();
				 mNewFigureStartPosition.mX = mDefaultFigureStartPositionX;
				 mNewFigureStartPosition.mY = mDefaultFigureStartPositionY;
				 mOldFigureStartPosition = mNewFigureStartPosition;
				 mCurrentSpeed = mDefaultSpeed;
                 delete PtrTetraCurrent;
                 PtrTetraCurrent = PtrTetraNext;
				 PtrTetraNext = GetTetramino();
                 Old_Position = PtrTetraCurrent->GetPosition();
                 New_Position = PtrTetraCurrent->GetPosition();
				 DrowWell();
				 DrowScore();
				 DrowPreview();
				 return;
			 }
			 Time_to_update = 0;
			 
		 }
		 
	}

