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
		COORD_ OldPosition;// координаты фигуры на поле
		COORD_ NewPosition;
		void SetTetramino(ITetramino *PtrTetra);//помещает в колодец фигуру
		ITetramino* GetTetramino();//возвращает ссылку на фигуру
		bool Verific(ITetramino* PtrTetra);
		bool Direction;
		int a;
		int b;
		int aP;
		int bP;
		int B;
		wchar_t Word[10] = {};//строка счета игры
		wchar_t TempWord[10] = {};//первоначальное состяние строки счета игры
		int Temp;//кличество не пустых элементов массива Word
		int x;// начальные координаты фигуры на поле
		int y;

		int xDrowScreen;
		int yDrowScreen;
		int xDrowWell;
		int yDrowWell;
		int xDrowPreview;
		int yDrowPreview;
		int xDrowScore;
		int yDrowScore;
		ITetramino* PtrTetraСurrent;
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
		

	public:
		TestApp();
		~TestApp()override
		{}

		void Delete_line(Well&, int line_index);//удаляет полную строку и опускает часть поля над строкой на строку вниз
		bool is_line_empty(const std::vector<wchar_t>& Line)const;//будет искать или пустую или зполненную строку
		void Delete_filled_lines();//управляет этими двумя функциями
		bool is_line_filled(const std::vector<wchar_t>& Line)const;//проверяет строку на заполненность

		Well well;
		Well Previu;
		bool going_beyond;
		virtual void KeyPressed(int btnCode);
		virtual void UpdateF(float deltaTime);
		
		float current_speed = 0.8;
		const float default_speed = 0.4;
};


