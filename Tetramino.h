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

	virtual std::vector<COORD_>& GetPosition() = 0;//���������� ���������� ������
	virtual std::vector<COORD_>& Rotate() = 0;//���������� ��������� �� ������ ��������� ������ ��� �������� ������
};

//������ �������
// ���������
class T : public ITetramino  
{
public:
	T();
	~T() {}

	std::vector<COORD_>& GetPosition();//���������� ������

	std::vector<COORD_>& Rotate();//���������� ������ �� ������ ��������� ��� �������� ������

	void initTetraForm();//������������� ������� TetraForm

private:
	int mFormSize = 4;//���������� ��������� ������
	int mT = 0;//���������� ����� ��������� ������
	std::vector<std::vector<COORD_>>TetraForm; //������ ��������� ������
};


//���������� L
class J : public ITetramino
{
public:
	J();
	~J() {}

	std::vector<COORD_>& GetPosition();//���������� ������

	std::vector<COORD_>& Rotate();//���������� ������ �� ������ ��������� ��� �������� ������

	void initTetraForm();//������������� ������� TetraForm

private:
	int mFormSize = 4;//���������� ��������� ������
	int mJ = 0;//���������� ����� ��������� ������
	std::vector<std::vector<COORD_>>TetraForm; //������ ��������� ������
};




//�����
class I : public ITetramino
{
public:
	I();
	~I() {}

	std::vector<COORD_>& GetPosition();//���������� ������

	std::vector<COORD_>& Rotate();//���������� ������ �� ������ ��������� ��� �������� ������

	void initTetraForm();//������������� ������� TetraForm

private:
	int mFormSize = 2;//���������� ��������� ������
	int mI = 0;//���������� ����� ��������� ������
	std::vector<std::vector<COORD_>>TetraForm; //������ ��������� ������
};




//�����
class O : public ITetramino
{
public:
	O();
	~O() {}

	std::vector<COORD_>& GetPosition();//���������� ������

	std::vector<COORD_>& Rotate();//���������� ������ �� ������ ��������� ��� �������� ������

	void initTetraForm();//������������� ������� TetraForm

private:
	int mFormSize = 1;//���������� ��������� ������
	int mO = 0;//���������� ����� ��������� ������
	std::vector<std::vector<COORD_>>TetraForm; //������ ��������� ������
};



//L
class L : public ITetramino
{
public:
	L();
	~L() {}

	std::vector<COORD_>& GetPosition();//���������� ������

	std::vector<COORD_>& Rotate();//���������� ������ �� ������ ��������� ��� �������� ������

	void initTetraForm();//������������� ������� TetraForm

private:
	int mFormSize = 4;//���������� ��������� ������
	int mL = 0;//���������� ����� ��������� ������
	std::vector<std::vector<COORD_>>TetraForm; //������ ��������� ������
};




//Z
class Z : public ITetramino
{
public:
	Z();
	~Z() {}

	std::vector<COORD_>& GetPosition();//���������� ������

	std::vector<COORD_>& Rotate();//���������� ������ �� ������ ��������� ��� �������� ������

	void initTetraForm();//������������� ������� TetraForm

private:
	int mFormSize = 2;//���������� ��������� ������
	int mZ = 0;//���������� ����� ��������� ������
	std::vector<std::vector<COORD_>>TetraForm; //������ ��������� ������
};



//S
class S : public ITetramino
{
public:
	S();
	~S() {}

	std::vector<COORD_>& GetPosition();//���������� ������

	std::vector<COORD_>& Rotate();//���������� ������ �� ������ ��������� ��� �������� ������

	void initTetraForm();//������������� ������� TetraForm

private:
	int mFormSize = 2;//���������� ��������� ������
	int mS = 0;//���������� ����� ��������� ������
	std::vector<std::vector<COORD_>>TetraForm; //������ ��������� ������
};




