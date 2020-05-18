#include "pch.h"
#include "Deque.h"
#include <list>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma once
#pragma warning(disable : 4996)

using namespace std;
#define STRLEN(x) (sizeof(x)/sizeof(TCHAR) - 1)

int main()
{
	// Установка кириллицы
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//буферы для Сonsole
	DWORD bufferDWORD;
	COORD point;

	point.X = 0; point.Y = 0;

	const char* bufferConstChar;
	char bufferCharArr[4];
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	Deque dq;

	bool f = true;
	int val;

	while (f)
	{
		system("cls");

		bufferConstChar = "\t\t\tМЕНЮ\n";
		WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

		bufferConstChar = "1 - Добавить элемент в начало\n";
		WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

		bufferConstChar = "2 - Добавить элемент в конец\n";
		WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

		bufferConstChar = "3 - Удалить элемент из начала\n";
		WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

		bufferConstChar = "4 - Удалить элемент из конца\n";
		WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

		bufferConstChar = "5 - Вывести первый элемент\n";
		WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

		bufferConstChar = "6 - Вывести последний элемент\n";
		WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

		bufferConstChar = "7 - Вывести количество элементов\n";
		WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

		bufferConstChar = "8 - Вывести все элементы\n";
		WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

		bufferConstChar = "9 - Сохранить дек в файл\n";
		WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

		bufferConstChar = "10 - Прочитать дек из файла\n";
		WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

		bufferConstChar = "0 - Выход\n";
		WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

		bufferConstChar = "Введите номер функции, которую хотите проверить: \n";
		WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

		ReadFile(hIn, bufferCharArr, 4, &bufferDWORD, NULL);

		int n = atoi(bufferCharArr);

		switch (n)
		{
		default:
			bufferConstChar = "Вы выбрали не существующий пункт!";
			WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);
			break;

		case 0:
			f = false;
			break;

		case 1:
			system("cls");

			bufferConstChar = "Введите значение элемента: \n";
			WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

			ReadFile(hIn, bufferCharArr, 4, &bufferDWORD, NULL);
			val = atoi(bufferCharArr);

			dq.AddStart(val);
			break;

		case 2:
			system("cls");

			bufferConstChar = "Введите значение элемента: \n";
			WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

			ReadFile(hIn, bufferCharArr, 4, &bufferDWORD, NULL);
			val = atoi(bufferCharArr);

			dq.AddEnd(val);

			bufferConstChar = "Число записано в конец!\n";
			WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);
			break;

		case 3:
			system("cls");
			dq.DeleteStart();
			break;

		case 4:
			system("cls");
			dq.DeleteEnd();
			break;

		case 5:
			system("cls");
			dq.OutputStart();
			break;

		case 6:
			system("cls");
			dq.OutputEnd();
			break;

		case 7:
			system("cls");
			cout << "Количество элемнтов: " << dq.SizeDeque() << endl;
			break;
		case 8:
			system("cls");
			dq.OutputAll();
			break;

		case 9:
			system("cls");

			dq.WriteToFile();

			bufferConstChar = "Дек успешно записан в файл\n";
			WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);
			break;

		case 10:
			system("cls");

			dq.ReadFromFile();

			bufferConstChar = "Дек успешно считан из файла, можете посмотреть результат, выбрав 8 пункт меню\n";
			WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

			break;
		}

		bufferConstChar = "Нажмите Enter для продолжения...";
		WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);
		ReadFile(hIn, bufferCharArr, 4, &bufferDWORD, NULL);
	}
}