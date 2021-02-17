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

	virtual std::vector<COORD_> &get_position() = 0;//���������� ���������� ������
	virtual std::vector<COORD_>& rotate() = 0;//���������� ��������� �� ������ ��������� ������ ��� �������� ������
};

//������ �������
// ���������
class T : public ITetramino  
{
public:
	T();
	~T() {}

	std::vector<COORD_>& get_position();//���������� ������

	std::vector<COORD_>& rotate();//���������� ������ �� ������ ��������� ��� �������� ������

	void initTetraForm();//������������� ������� Tetra_form

private:
	int FormSize = 4;//���������� ��������� ������
	int t = 0;//���������� ����� ��������� ������
	std::vector<std::vector<COORD_>>Tetra_form; //������ ��������� ������
};


//���������� L
class J : public ITetramino
{
public:
	J();
	~J() {}

	std::vector<COORD_>& get_position();//���������� ������

	std::vector<COORD_>& rotate();//���������� ������ �� ������ ��������� ��� �������� ������

	void initTetraForm();//������������� ������� Tetra_form

private:
	int FormSize = 4;//���������� ��������� ������
	int j = 0;//���������� ����� ��������� ������
	std::vector<std::vector<COORD_>>Tetra_form; //������ ��������� ������
};




//�����
class I : public ITetramino
{
public:
	I();
	~I() {}

	std::vector<COORD_>& get_position();//���������� ������

	std::vector<COORD_>& rotate();//���������� ������ �� ������ ��������� ��� �������� ������

	void initTetraForm();//������������� ������� Tetra_form

private:
	int FormSize = 2;//���������� ��������� ������
	int i = 0;//���������� ����� ��������� ������
	std::vector<std::vector<COORD_>>Tetra_form; //������ ��������� ������
};




//�����
class O : public ITetramino
{
public:
	O();
	~O() {}

	std::vector<COORD_>& get_position();//���������� ������

	std::vector<COORD_>& rotate();//���������� ������ �� ������ ��������� ��� �������� ������

	void initTetraForm();//������������� ������� Tetra_form

private:
	int FormSize = 1;//���������� ��������� ������
	int o = 0;//���������� ����� ��������� ������
	std::vector<std::vector<COORD_>>Tetra_form; //������ ��������� ������
};



//L
class L : public ITetramino
{
public:
	L();
	~L() {}

	std::vector<COORD_>& get_position();//���������� ������

	std::vector<COORD_>& rotate();//���������� ������ �� ������ ��������� ��� �������� ������

	void initTetraForm();//������������� ������� Tetra_form

private:
	int FormSize = 4;//���������� ��������� ������
	int l = 0;//���������� ����� ��������� ������
	std::vector<std::vector<COORD_>>Tetra_form; //������ ��������� ������
};




//Z
class Z : public ITetramino
{
public:
	Z();
	~Z() {}

	std::vector<COORD_>& get_position();//���������� ������

	std::vector<COORD_>& rotate();//���������� ������ �� ������ ��������� ��� �������� ������

	void initTetraForm();//������������� ������� Tetra_form

private:
	int FormSize = 2;//���������� ��������� ������
	int z = 0;//���������� ����� ��������� ������
	std::vector<std::vector<COORD_>>Tetra_form; //������ ��������� ������
};



//S
class S : public ITetramino
{
public:
	S();
	~S() {}

	std::vector<COORD_>& get_position();//���������� ������

	std::vector<COORD_>& rotate();//���������� ������ �� ������ ��������� ��� �������� ������

	void initTetraForm();//������������� ������� Tetra_form

private:
	int FormSize = 2;//���������� ��������� ������
	int s = 0;//���������� ����� ��������� ������
	std::vector<std::vector<COORD_>>Tetra_form; //������ ��������� ������
};




