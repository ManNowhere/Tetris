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

	void DeleteLine(Well&, int line_index);//������� ������ ������ � �������� ����� ���� ��� ������� �� ������ ����
	bool IsLineEmpty(const std::vector<wchar_t>& Line)const;//����� ������ ��� ������ ��� ���������� ������
	void DeleteFilledLines();//��������� ����� ����� ���������
	bool IsLineFilled(const std::vector<wchar_t>& Line)const;//��������� ������ �� �������������
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
		COORD_ mOldFigureStartPosition;// ���������� ������ �� ����
		COORD_ mNewFigureStartPosition;
		void SetTetramino(ITetramino *PtrTetra);//�������� � ������� ������
		ITetramino* GetTetramino();//���������� ������ �� ������
		bool CanMoveFigure(ITetramino* PtrTetra);

		int mPreviewWidth;
		int mPreviewHight;
		int mScoreNumber;
		wchar_t mResultScoreWord[10];//������ ����� ����
		wchar_t mDefaultWord[10];//�������������� �������� ������ ����� ����
		int mDefaultFigureStartPositionX;// ��������� ���������� ������ �� ����
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
		Figure Old_Position;//������ ��������� ������
		Figure New_Position;// ����� ��������� ������


		void DrowScreen();
		void DrowWell();

		void DrowPreview();

		void DrowScore();

		void DrowBorders();
		bool belongs_to_figure(const COORD_& coord);//�������� ��������� �������� �� �������������� ������� ������
		void clearKeyboardBuffer();//������� ������ ����������
		
		bool Game_over;
};


