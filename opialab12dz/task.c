#include <locale.h>
#include <stdio.h>
#include <time.h>

struct tm* mytime;
time_t t;

int main()
{
    setlocale(LC_CTYPE, "");

    t = time(NULL);
    mytime = localtime(&t);
    printf("Московское время %02d:%02d:%02d \n", mytime->tm_hour, mytime->tm_min, mytime->tm_sec);

    int now_min = mytime->tm_hour * 60 + mytime->tm_min;
    int start_min = 8 * 60 + 30;
    int diff = now_min - start_min;


    printf("С первой пары прошло %02d часов %02d минут\n", diff / 60, diff % 60);

    return 0;
}