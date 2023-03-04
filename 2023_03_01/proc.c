#include"proc.h"
#include<string.h>
#include<unistd.h>

#define SIZE 102
#define STYLE '='
#define ARR '>'

// "|/-\\"
void process()
{
    const char* lable = "|/-\\";
    char bar[SIZE];
    memset(bar,'\0',sizeof(bar));
    int i = 0;
    while(i <= 100)
    {
        printf("\033[0;32;31m[%-100s][%d%%][%c]\033[m\r",bar,i,lable[i%4]);
        fflush(stdout);
        bar[i] = STYLE;
        i++;
        if(i != 100)
        {
            bar[i] = ARR;
        }
        usleep(100000);
    }
    printf("\n");
}
