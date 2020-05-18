#include "pch.h"
#include "Deque.h"
#include <list>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma once
#pragma warning(disable : 4996)

using namespace std;

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
DWORD bufferDWORD;
const char* bufferConstChar;
char bufferCharArr[4];
LPCWSTR bufferLPCWSTR;
char bufferDequeStr[250];

Deque::Deque()
{
	deque.resize(0); // Задаём 0 длину
	length = 0; // Храним длину равную 0
}

Deque::~Deque()
{
	deque.clear(); // Удаляем все элементы дека
	length = 0; // Храним длину равную 0
}

int Deque::SizeDeque()
{
	return length;
}

void Deque::OutputAll()
{
	for (int n : deque)
		std::cout << n << " ";

	std::cout << std::endl;
}

void Deque::OutputEnd()
{
	cout << "Последний элемент дека: " << deque.back() << endl; // Выводим первый элемент
}

void Deque::OutputStart()
{
	cout << "Первый элемент дека: " << deque.front() << endl; // Выводим первый элемент
}

void Deque::DeleteStart()
{
	deque.pop_front(); // Удаляем первый элемент в деке
	length--;
	cout << "Число из начала удалено!" << endl;
}

void Deque::DeleteEnd()
{
	deque.pop_back(); // Удаляем последний элемент в деке
	length--;
	cout << "Число из конца удалено!" << endl;
}

void Deque::AddStart(int value)
{
	deque.push_front(value); // Записываем в начало value
	length++;
	cout << "Число записано в начало!" << endl;
}

void Deque::AddEnd(int value)
{
	deque.push_back(value); // Записываем в конец value
	length++;
}

void Deque::WriteToFile()
{
	string strDeque = "";

	for (int n : deque)
	{
		strDeque += to_string(n);
		strDeque += ";";
	}

	LPCSTR LPCStrDeque = strDeque.c_str();
	HANDLE hFile;

	hFile = CreateFile(L"DequeFile.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	WriteFile(hFile, LPCStrDeque, strlen(LPCStrDeque), &bufferDWORD, NULL);
	CloseHandle(hFile);
}

void Deque::ReadFromFile()
{
	deque.resize(0); // Задаём 0 длину
	length = 0; // Храним длину равную 0

	HANDLE hFile;

	hFile = CreateFile(L"DequeFile.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	ReadFile(hFile, bufferDequeStr, 250, &bufferDWORD, NULL);
	CloseHandle(hFile);

	char *ptr;

	if ((ptr = strtok(bufferDequeStr, ";")) != nullptr)
	{

		AddEnd(atoi(ptr));
		ptr = strtok(0, ";");

		while (ptr) {
			AddEnd(atoi(ptr));
			ptr = strtok(0, ";");

		}
	}
}