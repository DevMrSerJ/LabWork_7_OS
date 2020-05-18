#include <list>
#pragma once

class Deque
{

private:
	std::list <int> deque; // ���������� ������
	int length; // ���������� ��������� � ����

public:
	Deque(); // ������� ����
	~Deque(); // �������� ������
	int SizeDeque(); // ������ ����
	void OutputAll(); // ������� ��� �������� ����
	void OutputEnd(); // ������� ��������� �������
	void OutputStart(); // ������� ������ �������
	void DeleteStart(); // ������� ������ �������
	void DeleteEnd(); //������� ��������� �������
	void AddStart(int value); // �������� ������� � ������
	void AddEnd(int value); // �������� ������� � �����
	void WriteToFile(); // �������� ��� � ����
	void ReadFromFile(); // ������� ��� �� �����
};