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

	return sprintf(buf, "— первой пары прошло %02d часов %02d минут", diff / 60, diff % 60);
}


int time_now(char* buf, struct tm* mytime)
{
	return sprintf(buf, "ћосковское врем€ %02d:%02d:%02d", mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
}