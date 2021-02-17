#pragma once
#include <vector>


struct COORD_
{
	int X;
	int Y;

	
	friend bool operator<(const COORD_& left, const COORD_& right)
	{
		return (left.X < right.X) && (left.Y < right.Y);
	}

	friend bool operator==(const COORD_& left, const COORD_& right)
	{
		return (left.X == right.X) && (left.Y == right.Y);
	}
	
	friend COORD_ operator+(const COORD_& left, const COORD_& right)
	{
		COORD_ tmp;
		tmp.X = left.X + right.X;
		tmp.Y = left.Y + right.Y;
		return tmp;
	}

	COORD_& operator=(const COORD_& left)
	{
		this->X = left.X;
		this->Y = left.Y;
		return *this;
	}
	


};

typedef std::vector <COORD_> Figure;

class ITetramino
{
public:

	virtual std::vector<COORD_> &get_position() = 0;//возвращает координаты фигуры
	virtual std::vector<COORD_>& rotate() = 0;//возвращает указатель на массив координат фигуры при повороте фигуры
};

//фигуры тетриса
// тройничок
class T : public ITetramino  
{
public:
	T();
	~T() {}

	std::vector<COORD_>& get_position();//возвращает фигуру

	std::vector<COORD_>& rotate();//возвращает ссылку на массив координат при повороте фигуры

	void initTetraForm();//инициализация вектора Tetra_form

private:
	int FormSize = 4;//количество положений фигуры
	int t = 0;//порядковый номер положения фигуры
	std::vector<std::vector<COORD_>>Tetra_form; //массив положений фигуры
};


//зеркальная L
class J : public ITetramino
{
public:
	J();
	~J() {}

	std::vector<COORD_>& get_position();//возвращает фигуру

	std::vector<COORD_>& rotate();//возвращает ссылку на массив координат при повороте фигуры

	void initTetraForm();//инициализация вектора Tetra_form

private:
	int FormSize = 4;//количество положений фигуры
	int j = 0;//порядковый номер положения фигуры
	std::vector<std::vector<COORD_>>Tetra_form; //массив положений фигуры
};




//палка
class I : public ITetramino
{
public:
	I();
	~I() {}

	std::vector<COORD_>& get_position();//возвращает фигуру

	std::vector<COORD_>& rotate();//возвращает ссылку на массив координат при повороте фигуры

	void initTetraForm();//инициализация вектора Tetra_form

private:
	int FormSize = 2;//количество положений фигуры
	int i = 0;//порядковый номер положения фигуры
	std::vector<std::vector<COORD_>>Tetra_form; //массив положений фигуры
};




//кубик
class O : public ITetramino
{
public:
	O();
	~O() {}

	std::vector<COORD_>& get_position();//возвращает фигуру

	std::vector<COORD_>& rotate();//возвращает ссылку на массив координат при повороте фигуры

	void initTetraForm();//инициализация вектора Tetra_form

private:
	int FormSize = 1;//количество положений фигуры
	int o = 0;//порядковый номер положения фигуры
	std::vector<std::vector<COORD_>>Tetra_form; //массив положений фигуры
};



//L
class L : public ITetramino
{
public:
	L();
	~L() {}

	std::vector<COORD_>& get_position();//возвращает фигуру

	std::vector<COORD_>& rotate();//возвращает ссылку на массив координат при повороте фигуры

	void initTetraForm();//инициализация вектора Tetra_form

private:
	int FormSize = 4;//количество положений фигуры
	int l = 0;//порядковый номер положения фигуры
	std::vector<std::vector<COORD_>>Tetra_form; //массив положений фигуры
};




//Z
class Z : public ITetramino
{
public:
	Z();
	~Z() {}

	std::vector<COORD_>& get_position();//возвращает фигуру

	std::vector<COORD_>& rotate();//возвращает ссылку на массив координат при повороте фигуры

	void initTetraForm();//инициализация вектора Tetra_form

private:
	int FormSize = 2;//количество положений фигуры
	int z = 0;//порядковый номер положения фигуры
	std::vector<std::vector<COORD_>>Tetra_form; //массив положений фигуры
};



//S
class S : public ITetramino
{
public:
	S();
	~S() {}

	std::vector<COORD_>& get_position();//возвращает фигуру

	std::vector<COORD_>& rotate();//возвращает ссылку на массив координат при повороте фигуры

	void initTetraForm();//инициализация вектора Tetra_form

private:
	int FormSize = 2;//количество положений фигуры
	int s = 0;//порядковый номер положения фигуры
	std::vector<std::vector<COORD_>>Tetra_form; //массив положений фигуры
};




