#include <list>
#pragma once

class Deque
{

private:
	std::list <int> deque; // Двусвязный список
	int length; // Количество элементов в деке

public:
	Deque(); // Созание дека
	~Deque(); // Очищение памяти
	int SizeDeque(); // Размер дека
	void OutputAll(); // вывести все элементы дека
	void OutputEnd(); // Выводит последний элемент
	void OutputStart(); // Выводит первый элемент
	void DeleteStart(); // Удалить первый элемент
	void DeleteEnd(); //Удалить последний элемент
	void AddStart(int value); // Добавить элемент в начало
	void AddEnd(int value); // Добавить элемент в конец
	void WriteToFile(); // Записать дек в файл
	void ReadFromFile(); // Считать дек из файла
};