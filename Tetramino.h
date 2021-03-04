#pragma once
#include <vector>


struct COORD_
{
	int mX;
	int mY;

	
	friend bool operator<(const COORD_& left, const COORD_& right)
	{
		return (left.mX < right.mX) && (left.mY < right.mY);
	}

	friend bool operator==(const COORD_& left, const COORD_& right)
	{
		return (left.mX == right.mX) && (left.mY == right.mY);
	}
	
	friend COORD_ operator+(const COORD_& left, const COORD_& right)
	{
		COORD_ tmp;
		tmp.mX = left.mX + right.mX;
		tmp.mY = left.mY + right.mY;
		return tmp;
	}

	COORD_& operator=(const COORD_& left)
	{
		this->mX = left.mX;
		this->mY = left.mY;
		return *this;
	}
	


};

typedef std::vector <COORD_> Figure;

class ITetramino
{
public:

	virtual std::vector<COORD_>& GetPosition() = 0;//возвращает координаты фигуры
	virtual std::vector<COORD_>& Rotate() = 0;//возвращает указатель на массив координат фигуры при повороте фигуры
};

//фигуры тетриса
// тройничок
class T : public ITetramino  
{
public:
	T();
	~T() {}

	std::vector<COORD_>& GetPosition();//возвращает фигуру

	std::vector<COORD_>& Rotate();//возвращает ссылку на массив координат при повороте фигуры

	void initTetraForm();//инициализация вектора TetraForm

private:
	int mFormSize = 4;//количество положений фигуры
	int mT = 0;//порядковый номер положения фигуры
	std::vector<std::vector<COORD_>>TetraForm; //массив положений фигуры
};


//зеркальная L
class J : public ITetramino
{
public:
	J();
	~J() {}

	std::vector<COORD_>& GetPosition();//возвращает фигуру

	std::vector<COORD_>& Rotate();//возвращает ссылку на массив координат при повороте фигуры

	void initTetraForm();//инициализация вектора TetraForm

private:
	int mFormSize = 4;//количество положений фигуры
	int mJ = 0;//порядковый номер положения фигуры
	std::vector<std::vector<COORD_>>TetraForm; //массив положений фигуры
};




//палка
class I : public ITetramino
{
public:
	I();
	~I() {}

	std::vector<COORD_>& GetPosition();//возвращает фигуру

	std::vector<COORD_>& Rotate();//возвращает ссылку на массив координат при повороте фигуры

	void initTetraForm();//инициализация вектора TetraForm

private:
	int mFormSize = 2;//количество положений фигуры
	int mI = 0;//порядковый номер положения фигуры
	std::vector<std::vector<COORD_>>TetraForm; //массив положений фигуры
};




//кубик
class O : public ITetramino
{
public:
	O();
	~O() {}

	std::vector<COORD_>& GetPosition();//возвращает фигуру

	std::vector<COORD_>& Rotate();//возвращает ссылку на массив координат при повороте фигуры

	void initTetraForm();//инициализация вектора TetraForm

private:
	int mFormSize = 1;//количество положений фигуры
	int mO = 0;//порядковый номер положения фигуры
	std::vector<std::vector<COORD_>>TetraForm; //массив положений фигуры
};



//L
class L : public ITetramino
{
public:
	L();
	~L() {}

	std::vector<COORD_>& GetPosition();//возвращает фигуру

	std::vector<COORD_>& Rotate();//возвращает ссылку на массив координат при повороте фигуры

	void initTetraForm();//инициализация вектора TetraForm

private:
	int mFormSize = 4;//количество положений фигуры
	int mL = 0;//порядковый номер положения фигуры
	std::vector<std::vector<COORD_>>TetraForm; //массив положений фигуры
};




//Z
class Z : public ITetramino
{
public:
	Z();
	~Z() {}

	std::vector<COORD_>& GetPosition();//возвращает фигуру

	std::vector<COORD_>& Rotate();//возвращает ссылку на массив координат при повороте фигуры

	void initTetraForm();//инициализация вектора TetraForm

private:
	int mFormSize = 2;//количество положений фигуры
	int mZ = 0;//порядковый номер положения фигуры
	std::vector<std::vector<COORD_>>TetraForm; //массив положений фигуры
};



//S
class S : public ITetramino
{
public:
	S();
	~S() {}

	std::vector<COORD_>& GetPosition();//возвращает фигуру

	std::vector<COORD_>& Rotate();//возвращает ссылку на массив координат при повороте фигуры

	void initTetraForm();//инициализация вектора TetraForm

private:
	int mFormSize = 2;//количество положений фигуры
	int mS = 0;//порядковый номер положения фигуры
	std::vector<std::vector<COORD_>>TetraForm; //массив положений фигуры
};




