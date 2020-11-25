
#include "String.h"

#include <iostream>

using namespace std;

//конструктор по умолчанию
String::String()
{
	char empty[] = "";
	
	_str = nullptr;
	setStr(empty);
}

//конструктор с параметром
String::String(char * str)
{
	_str = nullptr;
	setStr(str);
}

//конструктор копирования
String::String(const String &str)
{
	_str = nullptr;
	setStr(str._str);
}

//деструктор
String::~String()
{
	delete[] _str;
}



//получение строки
char * String::getStr()
{
	char* copy = new char[_size + 1];
	strcpy_s(copy, _size + 1, _str);

	return copy;
}

//получение размера
int String::getSize()
{
	return _size;
}

//получение символа по индексу
char& String::getSymbol(int index)
{
	if ((index < 0) || (index >= _size))
		throw exception("Bad index!");

	return _str[index];
}



//изменение строки
void String::setStr(char * str)
{
	if (!str)
		throw exception("Nullptr!");

	_size = strlen(str);
	
	delete[] _str;
	_str = new char[_size + 1];
	strcpy_s(_str, _size + 1, str);
}



//поиск подстроки
int String::subStr(char * str)
{
	if (!str)
		throw exception("Nullptr!");

	for (int i = 0; i <= _size - strlen(str); i++)
	{
		int j;

		for (j = 0;j < strlen(str); j++)
			if (_str[i + j] != str[j])
				break;

		if (j == strlen(str))
			return i;
	}

	return -1;
}

//объединение строк
String String::concate(const String& str)
{
	char* result = new char[_size + str._size + 1];
	strcpy_s(result, _size+1, _str);
	strcat_s(result, _size + str._size + 1, str._str);

	return String(result);
}