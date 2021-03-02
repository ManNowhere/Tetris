#pragma once
#include <vector>
#include "BaseApp.h"
#include <cwchar>
#include "Tetramino.h"


class TestApp : public BaseApp
{
	typedef BaseApp Parent;
	typedef std::vector<std::vector<wchar_t>> Well;

public:
	TestApp();
	~TestApp()override {}

	void DeleteLine(Well&, int line_index);//удаляет полную строку и опускает часть поля над строкой на строку вниз
	bool IsLineEmpty(const std::vector<wchar_t>& Line)const;//будет искать или пустую или зполненную строку
	void DeleteFilledLines();//управляет этими двумя функциями
	bool IsLineFilled(const std::vector<wchar_t>& Line)const;//проверяет строку на заполненность
	bool IsGameOver();
	virtual void KeyPressed(int btnCode);
	virtual void UpdateF(float deltaTime);
	int mWellWidth;
	int mHightWell;
	Well mWell;
	Well mPreviu;
	float mCurrentSpeed = 0.8;
	const float mDefaultSpeed = 0.4;

	

	private:
		COORD_ mOldFigureStartPosition;// координаты фигуры на поле
		COORD_ mNewFigureStartPosition;
		void SetTetramino(ITetramino *PtrTetra);//помещает в колодец фигуру
		ITetramino* GetTetramino();//возвращает ссылку на фигуру
		bool CanMoveFigure(ITetramino* PtrTetra);

		int mPreviewWidth;
		int mPreviewHight;
		int mScoreNumber;
		wchar_t mResultScoreWord[10];//строка счета игры
		wchar_t mDefaultWord[10];//первоначальное состяние строки счета игры
		int mDefaultFigureStartPositionX;// начальные координаты фигуры на поле
		int mDefaultFigureStartPositionY;

		int xDrowScreen;
		int yDrowScreen;
		int xDrowWell;
		int yDrowWell;
		int xDrowPreview;
		int yDrowPreview;
		int xDrowScore;
		int yDrowScore;
        ITetramino* PtrTetraCurrent;
		ITetramino* PtrTetraNext;
		Figure Old_Position;//старое положение фигуры
		Figure New_Position;// новое положение фигуры


		void DrowScreen();
		void DrowWell();

		void DrowPreview();

		void DrowScore();

		void DrowBorders();
		bool belongs_to_figure(const COORD_& coord);//проверка следующих кординат на принадлежность текущей фигуре
		void clearKeyboardBuffer();//очистка буфера клавиатуры
		
		bool Game_over;
};


