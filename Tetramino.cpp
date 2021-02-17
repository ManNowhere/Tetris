#include "Tetramino.h"
#include <conio.h>

#include <iostream>



T::T() : Tetra_form(FormSize, std::vector<COORD_>(4))
{
	initTetraForm();
}

void T::initTetraForm()
{
	Tetra_form[0] = { {0, 1}, {1, 0}, {1, 1}, {1, 2} };
	Tetra_form[1] = { {1, 0}, {0, 1}, {1, 1}, {2, 1} };
	Tetra_form[2] = { {0, 0}, {0, 1}, {1, 1}, {0, 2} };
	Tetra_form[3] = { {0, 0}, {1, 0}, {2, 0}, {1, 1} };
}

std::vector<COORD_>& T::get_position()
{
	return Tetra_form[t];
}

//имеем массив нынешнего положения фигуры и возвращаем следующий
std::vector<COORD_>& T::rotate()
{
	++t;
	if (t == FormSize)
	{
		t = 0;
	}
	return Tetra_form.at(t);
	
}


//J
J::J() : Tetra_form(FormSize, std::vector<COORD_>(4))
{
	J::initTetraForm();
}

void J::initTetraForm()
{
	Tetra_form[0] = { {1, 0}, {1, 1}, {1, 2}, {0, 2} };
	Tetra_form[1] = { {0, 0}, {0, 1}, {1, 1}, {2, 1} };
	Tetra_form[2] = { {0, 0}, {1, 0}, {0, 1}, {0, 2} };
	Tetra_form[3] = { {0, 0}, {1, 0}, {2, 0}, {2, 1} };
}

std::vector<COORD_>& J::get_position()
{
	return Tetra_form[j];
}

//имеем массив нынешнего положения фигуры и возвращаем следующий
std::vector<COORD_>& J::rotate()
{
	++j;
	if (j == FormSize)
	{
		j = 0;
	}
	return Tetra_form.at(j);
}



//I
I::I() : Tetra_form(FormSize, std::vector<COORD_>(4))
{
	I::initTetraForm();
}

void I::initTetraForm()
{
	Tetra_form[0] = { {0, 0}, {0, 1}, {0, 2}, {0, 3} };
	Tetra_form[1] = { {0, 0}, {1, 0}, {2, 0}, {3, 0} };
}

std::vector<COORD_>& I::get_position()
{
	return Tetra_form[i];
}

//имеем массив нынешнего положения фигуры и возвращаем следующий
std::vector<COORD_>& I::rotate()
{
	++i;
	if (i == FormSize)
	{
		i = 0;
	}
	return Tetra_form.at(i);

}




//O
O::O() : Tetra_form(FormSize, std::vector<COORD_>(4))
{
	O::initTetraForm();
}

void O::initTetraForm()
{
	Tetra_form[0] = { {0, 0}, {1, 0}, {0, 1}, {1, 1} };
}

std::vector<COORD_>& O::get_position()
{
	return Tetra_form[0];
}

//имеем массив нынешнего положения фигуры и возвращаем следующий
std::vector<COORD_>& O::rotate()
{
	return Tetra_form.at(0);
}



//L
L::L() : Tetra_form(FormSize, std::vector<COORD_>(4))
{
	L::initTetraForm();
}

void L::initTetraForm()
{
	Tetra_form[0] = { {0, 0}, {0, 1}, {0, 2}, {1, 2} };
	Tetra_form[1] = { {0, 0}, {1, 0}, {2, 0}, {0, 1} };
	Tetra_form[2] = { {0, 0}, {1, 0}, {1, 1}, {1, 2} };
	Tetra_form[3] = { {2, 0}, {0, 1}, {1, 1}, {2, 1} };
}

std::vector<COORD_>& L::get_position()
{
	return Tetra_form[l];
}

//имеем массив нынешнего положения фигуры и возвращаем следующий
std::vector<COORD_>& L::rotate()
{
	++l;
	if (l == FormSize)
	{
		l = 0;
	}
	return Tetra_form.at(l);

}




//Z
Z::Z() : Tetra_form(FormSize, std::vector<COORD_>(4))
{
	Z::initTetraForm();
}

void Z::initTetraForm()
{
	Tetra_form[0] = { {0, 0}, {1, 0}, {1, 1}, {2, 1} };
	Tetra_form[1] = { {1, 0}, {0, 1}, {1, 1}, {0, 2} };

}

std::vector<COORD_>& Z::get_position()
{
	return Tetra_form[z];
}

//имеем массив нынешнего положения фигуры и возвращаем следующий
std::vector<COORD_>& Z::rotate()
{
	++z;
	if (z == FormSize)
	{
		z = 0;
	}
	return Tetra_form.at(z);

}




//S
S::S() : Tetra_form(FormSize, std::vector<COORD_>(4))
{
	S::initTetraForm();
}

void S::initTetraForm()
{
	Tetra_form[0] = { {1, 0}, {2, 0}, {0, 1}, {1, 1} };
	Tetra_form[1] = { {0, 0}, {0, 1}, {1, 1}, {1, 2} };
}

std::vector<COORD_>& S::get_position()
{
	return Tetra_form[s];
}

//имеем массив нынешнего положения фигуры и возвращаем следующий
std::vector<COORD_>& S::rotate()
{
	++s;
	if (s == FormSize)
	{
		s = 0;
	}
	return Tetra_form.at(s);

}