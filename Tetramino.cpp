#include "Tetramino.h"
#include <conio.h>

#include <iostream>



T::T() : TetraForm(mFormSize, std::vector<COORD_>(4))
{
	initTetraForm();
}

void T::initTetraForm()
{
	TetraForm[0] = { {0, 1}, {1, 0}, {1, 1}, {1, 2} };
	TetraForm[1] = { {1, 0}, {0, 1}, {1, 1}, {2, 1} };
	TetraForm[2] = { {0, 0}, {0, 1}, {1, 1}, {0, 2} };
	TetraForm[3] = { {0, 0}, {1, 0}, {2, 0}, {1, 1} };
}

std::vector<COORD_>& T::GetPosition()
{
	return TetraForm[mT];
}

//имеем массив нынешнего положения фигуры и возвращаем следующий
std::vector<COORD_>& T::Rotate()
{
	++mT;
	if (mT == mFormSize)
	{
		mT = 0;
	}
	return TetraForm.at(mT);
	
}


//J
J::J() : TetraForm(mFormSize, std::vector<COORD_>(4))
{
	J::initTetraForm();
}

void J::initTetraForm()
{
	TetraForm[0] = { {1, 0}, {1, 1}, {1, 2}, {0, 2} };
	TetraForm[1] = { {0, 0}, {0, 1}, {1, 1}, {2, 1} };
	TetraForm[2] = { {0, 0}, {1, 0}, {0, 1}, {0, 2} };
	TetraForm[3] = { {0, 0}, {1, 0}, {2, 0}, {2, 1} };
}

std::vector<COORD_>& J::GetPosition()
{
	return TetraForm[mJ];
}

//имеем массив нынешнего положения фигуры и возвращаем следующий
std::vector<COORD_>& J::Rotate()
{
	++mJ;
	if (mJ == mFormSize)
	{
		mJ = 0;
	}
	return TetraForm.at(mJ);
}



//I
I::I() : TetraForm(mFormSize, std::vector<COORD_>(4))
{
	I::initTetraForm();
}

void I::initTetraForm()
{
	TetraForm[0] = { {0, 0}, {0, 1}, {0, 2}, {0, 3} };
	TetraForm[1] = { {0, 0}, {1, 0}, {2, 0}, {3, 0} };
}

std::vector<COORD_>& I::GetPosition()
{
	return TetraForm[mI];
}

//имеем массив нынешнего положения фигуры и возвращаем следующий
std::vector<COORD_>& I::Rotate()
{
	++mI;
	if (mI == mFormSize)
	{
		mI = 0;
	}
	return TetraForm.at(mI);

}




//O
O::O() : TetraForm(mFormSize, std::vector<COORD_>(4))
{
	O::initTetraForm();
}

void O::initTetraForm()
{
	TetraForm[0] = { {0, 0}, {1, 0}, {0, 1}, {1, 1} };
}

std::vector<COORD_>& O::GetPosition()
{
	return TetraForm[0];
}

//имеем массив нынешнего положения фигуры и возвращаем следующий
std::vector<COORD_>& O::Rotate()
{
	return TetraForm.at(0);
}



//L
L::L() : TetraForm(mFormSize, std::vector<COORD_>(4))
{
	L::initTetraForm();
}

void L::initTetraForm()
{
	TetraForm[0] = { {0, 0}, {0, 1}, {0, 2}, {1, 2} };
	TetraForm[1] = { {0, 0}, {1, 0}, {2, 0}, {0, 1} };
	TetraForm[2] = { {0, 0}, {1, 0}, {1, 1}, {1, 2} };
	TetraForm[3] = { {2, 0}, {0, 1}, {1, 1}, {2, 1} };
}

std::vector<COORD_>& L::GetPosition()
{
	return TetraForm[mL];
}

//имеем массив нынешнего положения фигуры и возвращаем следующий
std::vector<COORD_>& L::Rotate()
{
	++mL;
	if (mL == mFormSize)
	{
		mL = 0;
	}
	return TetraForm.at(mL);

}




//Z
Z::Z() : TetraForm(mFormSize, std::vector<COORD_>(4))
{
	Z::initTetraForm();
}

void Z::initTetraForm()
{
	TetraForm[0] = { {0, 0}, {1, 0}, {1, 1}, {2, 1} };
	TetraForm[1] = { {1, 0}, {0, 1}, {1, 1}, {0, 2} };

}

std::vector<COORD_>& Z::GetPosition()
{
	return TetraForm[mZ];
}

//имеем массив нынешнего положения фигуры и возвращаем следующий
std::vector<COORD_>& Z::Rotate()
{
	++mZ;
	if (mZ == mFormSize)
	{
		mZ = 0;
	}
	return TetraForm.at(mZ);

}




//S
S::S() : TetraForm(mFormSize, std::vector<COORD_>(4))
{
	S::initTetraForm();
}

void S::initTetraForm()
{
	TetraForm[0] = { {1, 0}, {2, 0}, {0, 1}, {1, 1} };
	TetraForm[1] = { {0, 0}, {0, 1}, {1, 1}, {1, 2} };
}

std::vector<COORD_>& S::GetPosition()
{
	return TetraForm[mS];
}

//имеем массив нынешнего положения фигуры и возвращаем следующий
std::vector<COORD_>& S::Rotate()
{
	++mS;
	if (mS == mFormSize)
	{
		mS = 0;
	}
	return TetraForm.at(mS);

}