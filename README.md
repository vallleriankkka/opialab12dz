# Домашнее задание к работе 12
## Условия задания
Задание 2. Напишите программу, которая выводит на экран текущее время.\
Задание 2.2 Добавьте вывод следующей информации:\
6. «с первой пары прошло k часов m минут»\
Задание 2.3 Организуйте вывод на экран так, чтобы сообщения размещались точно в центре строки экрана (80 символов). Для подготовки строки используйте функцию sprintf(). Свободное пространство заполните символами ‘*’ и стилизуйте  вывод в виде прямоугольного окна (10 символов).
## 1. Реализация программы
```c
	#include <locale.h>
	#include <stdio.h>
	#include <time.h>

	struct tm* mytime;
	time_t t;

	void str_left(int len);
	void str_right(int len);
	int  lesson(char* buf);
	int  time_now(char* buf, struct tm* tm);

	int main()
	{
		setlocale(LC_CTYPE, "");

		t = time(NULL);
		mytime = localtime(&t);

		char buf1[128];
		int len1 = time_now(buf1, mytime);

		for (int i = 0; i < 78; i++) putchar('*'); // начало
		putchar('\n');

		str_left(len1);
		printf(buf1);

		str_right(len1);

		char buf2[128];
		int diff = 0;
		int len2 = lesson(buf2);
		str_left(len2);
		printf(buf2);

		str_right(len2);

		for (int i = 0; i < 78; i++) putchar('*'); // конец
		putchar('\n');


		return 0;
	}

	void str_left(int len)
	{
		putchar('*');
		for (int i = 0; i < (78 - len) / 2; i++) putchar(' ');        // слева
	}


	void str_right(int len)
	{
		for (int i = 0; i < 74 - len - (74 - len) / 2; i++) putchar(' '); // справа
		putchar('*');
		putchar('\n');    
	}

	int lesson(char* buf)
	{
		int now_min = mytime->tm_hour * 60 + mytime->tm_min;
		int start_min = 8 * 60 + 30;
		int diff = now_min - start_min;

		return sprintf(buf, "С первой пары прошло %02d часов %02d минут", diff / 60, diff % 60);
	}


	int time_now(char* buf, struct tm* mytime)
	{
		return sprintf(buf, "Московское время %02d:%02d:%02d", mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
	}
```
## 3. Результаты работы программы
``` c
******************************************************************************
*                          Московское время 15:16:44                         *
*                    С первой пары прошло 06 часов 46 минут                  *
******************************************************************************

C:\Users\valer\source\repos\opialab12dz\x64\Debug\opialab12dz.exe (процесс 26976) завершил работу с кодом 0 (0x0).
Чтобы автоматически закрывать консоль при остановке отладки, включите параметр "Сервис" ->"Параметры" ->"Отладка" -> "Автоматически закрыть консоль при остановке отладки".
Нажмите любую клавишу, чтобы закрыть это окно:


```
## 4. Информация о разработчике
Елфимова Валерия бОТИ-261
