#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<dir.h>
#include<stdbool.h>
#include<conio.h>
#include<string.h>


#define cls system("cls");

/////////////////// File Reader Start ///////////////

bool Reading(char data[],char br,FILE *f)
{
    int i=0;
    data[0]=' ';
    while(!feof(f))
    {
        data[i]=fgetc(f);
        if(data[i]==br)
        {
            data[i]='\0';
            return true;
        }
        else if(data[i]=='\n')
        {
            i--;
        }
        i++;
    }
    return false;
}

////////////////// File Reader End //////////////////
char Globalun[50],gp[50],prep[50],Current_Addr[100];
//////////// Hand Made Header File////////////////

#include "Frame.h"
#include "Hash.h"
#include "Encryption.h"
#include "File_Handeling.h"
#include "Search_System.h"
#include "Function.h"

///////////////////////////////////////////////////


int main()
{
SetConsoleTitle("Donkey");
FILE *f;
f=fopen("C://Donkey/check.txt","r");
if(f==NULL)
{
   mkdir("C://Donkey//");
}
fclose(f);
f=fopen("C://Donkey/check.txt","w");
fclose(f);

   loading();
   account();
return 0;
}
