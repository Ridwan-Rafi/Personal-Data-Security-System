void loading();
void gotoxy(int x, int y);
void Text_Color(int clrr);
void bracket_frame();
void Box();

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Text_Color(int clrr)
{
    WORD wColor;
    HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
    {
        wColor=(csbi.wAttributes & 0xF0)+(clrr & 0x0F);
        SetConsoleTextAttribute(hStdOut,wColor);
    }
}
void Change_Color(char clr[])
{
Wrong_Input:
    cls;
    system("COLOR 0F");
    strcpy(clr,"COLOR ");
    int bc,txt;
    Text_Color(15);
    gotoxy(40,11);
    printf("[0] Black                      ");
    Text_Color(1);
    printf("[1] Blue");
    Text_Color(2);
    gotoxy(40,12);
    printf("[2] Green                      ");
    Text_Color(3);
    printf("[3] Aqua");
    Text_Color(4);
    gotoxy(40,13);
    printf("[4] Red                        ");
    Text_Color(5);
    printf("[5] Purple");
    Text_Color(6);
    gotoxy(40,14);
    printf("[6] Yellow                     ");
    Text_Color(7);
    printf("[7] White");
    Text_Color(8);
    gotoxy(40,15);
    printf("[8] Grey                       ");
    Text_Color(9);
    printf("[9] Light Blue");
    Text_Color(10);
    gotoxy(40,16);
    printf("[10] Light Green               ");
    Text_Color(11);
    printf("[11] Light Aqua");
    Text_Color(12);
    gotoxy(40,17);
    printf("[12] Light Red                 ");
    Text_Color(13);
    printf("[13] Light Purple");
    Text_Color(14);
    gotoxy(40,18);
    printf("[14] Light Yellow              ");
    Text_Color(15);
    printf("[15] Light White");
gotoxy(40,20);
    printf("Enter Background Color: ");
    scanf("%d",&bc);
    if(bc>=0 && bc<=9)
    {

        char t[2];
        t[0]=bc+48;
        t[1]='\0';
        strcat(clr,t);
    }
    else if(bc>=10 && bc<=15)
    {
        if(bc==10)
            strcat(clr,"A");
        else if(bc==11)
            strcat(clr,"B");
        else if(bc==12)
            strcat(clr,"C");
        else if(bc==13)
            strcat(clr,"D");
        else if(bc==14)
            strcat(clr,"E");
        else if(bc==15)
            strcat(clr,"F");
    }
    else
    {
        gotoxy(40,18);
        printf("\n\t\t\tWrong input");
        Sleep(200);
        goto Wrong_Input;

    }
    gotoxy(40,21);
    printf("Enter Text Color: ");
    scanf("%d",&txt);
    if(txt>=0 && txt<=9)
    {
        char t[2];
        t[0]=txt+48;
        t[1]='\0';
        strcat(clr,t);
    }
    else if(txt>=10 && txt<=15)
    {
        if(txt==10)
            strcat(clr,"A");
        else if(txt==11)
            strcat(clr,"B");
        else if(txt==12)
            strcat(clr,"C");
        else if(txt==13)
            strcat(clr,"D");
        else if(txt==14)
            strcat(clr,"E");
        else if(txt==15)
            strcat(clr,"F");
    }
    else
    {
        gotoxy(40,19);
        printf("\n\t\t\tWrong input");
        Sleep(200);
        goto Wrong_Input;

    }
    Select_Color_save(clr);
    return;
}
////////////////////File Reading Frame Start////////////////////
void File_Reading_Frame()
{
    printf("%c",201);
    for(int i=1;i<110;i++)
    {
        if(i==55)
        printf("%c",203);
        else
            printf("%c",205);
    }
    printf("%c\n",187);
    for(int i=0;i<1;i++)
    {
        printf("%c\t\t\t\t\t\t       %c\t\t\t\t\t\t      %c\n",186,186,186);
    }
    printf("%c",204);
    for(int i=1;i<110;i++)
    {
        if(i==55)
        printf("%c",202);
        else
            printf("%c",205);
    }
    printf("%c\n",185);
    for(int i=0;i<1;i++)
    {
        printf("%c\t\t\t\t\t\t\t\t\t\t\t\t\t      %c\n",186,186,186);
    }
    printf("%c",200);
    for(int i=1;i<110;i++)
    {
            printf("%c",205);
    }
    printf("%c\n",188);

}
////////////////////File Reading Frame Start////////////////////
//////////////////// Search Frame Start ////////////////////////

void Search_Frame()
{
    char x=205;
    gotoxy(0,0);
    printf("%c",201);
    for(int i=0;i<30;i++)
        {
            printf("%c",x);
        }
    gotoxy(81,0);
    for(int i=0;i<30;i++)
        {
            printf("%c",x);
        }
    printf("%c\n",187);
    for(int i=0;i<15;i++)
    {
        gotoxy(0,i+1);
        printf("%c",186);
        gotoxy(111,i+1);
        printf("%c\n",186);
    }

}

//////////////////// Search Frame End ////////////////////////

////////////////////Main Menu Frame Start ///////////////////////////

void Upper_angel()
{
    char x=205;
    gotoxy(0,0);
    printf("%c",201);
    for(int i=0;i<30;i++)
        {
            printf("%c",x);
        }
    gotoxy(81,0);
    for(int i=0;i<30;i++)
        {
            printf("%c",x);
        }
    printf("%c\n",187);
    for(int i=0;i<7;i++)
    {
        gotoxy(0,i+1);
        printf("%c",186);
        gotoxy(111,i+1);
        printf("%c\n",186);
    }

}
void Lower_angel(int zoto_tuku_nice)
{
    for(int i=0;i<7;i++)
    {
        gotoxy(0,zoto_tuku_nice+i+1);
        printf("%c",186);
        gotoxy(111,zoto_tuku_nice+i+1);
        printf("%c\n",186);
    }
    char x=205;
    printf("%c",200);
    for(int i=0;i<30;i++)
        {
            printf("%c",x);
        }
        for(int i=0;i<50;i++)printf(" ");
    for(int i=0;i<30;i++)
        {
            printf("%c",x);
        }
    printf("%c",188);

}
void Main_Menu_frame(int lb)
{
    Upper_angel();
Lower_angel(lb);
}

///////////////////Main Menu Frame End ///////////////////////////

//////////////////// Animation Code Start   /////////////////////////


void _1(char a,char b,char c,char d)
{
    int x=34,y=5;
    gotoxy(x,y);
    printf("%c%c%c%c%c%c   %c%c%c%c%c%c  %c%c%c    %c%c %c%c   %c%c %c%c%c%c%c%c%c %c%c    %c%c \n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(x,y+1);
    printf("%c%c   %c%c %c%c    %c%c %c%c%c%c   %c%c %c%c  %c%c  %c%c       %c%c  %c%c  \n",b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b);
    gotoxy(x,y+2);
    printf("%c%c   %c%c %c%c    %c%c %c%c %c%c  %c%c %c%c%c%c%c   %c%c%c%c%c     %c%c%c%c    \n",b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b);
    gotoxy(x,y+3);
    printf("%c%c   %c%c %c%c    %c%c %c%c  %c%c %c%c %c%c  %c%c  %c%c         %c%c    \n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    gotoxy(x,y+4);
    printf("%c%c%c%c%c%c   %c%c%c%c%c%c  %c%c   %c%c%c%c %c%c   %c%c %c%c%c%c%c%c%c    %c%c    \n",d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d,d);

}

void _2(char a)
{
    int x=34,y=12;
    gotoxy(x,y);
    printf("%c%c%c%c%c%c   %c%c%c%c%c%c  %c%c%c    %c%c %c%c   %c%c %c%c%c%c%c%c%c %c%c    %c%c \n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(x,y+1);
    printf("%c%c   %c%c %c%c    %c%c %c%c%c%c   %c%c %c%c  %c%c  %c%c       %c%c  %c%c  \n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(x,y+2);
    printf("%c%c   %c%c %c%c    %c%c %c%c %c%c  %c%c %c%c%c%c%c   %c%c%c%c%c     %c%c%c%c    \n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(x,y+3);
    printf("%c%c   %c%c %c%c    %c%c %c%c  %c%c %c%c %c%c  %c%c  %c%c         %c%c    \n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(x,y+4);
    printf("%c%c%c%c%c%c   %c%c%c%c%c%c  %c%c   %c%c%c%c %c%c   %c%c %c%c%c%c%c%c%c    %c%c    \n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);

}

void Slide(int j)
{
    int i;
    char a,b,c,d;
    i=j%4;
    if(i==0)
    {
        a=176;
        b=a+1;
        c=b+1;
        d=219;
        _1(a,b,c,d);
        fflush(stdout);
    }
    else if(i==1)
    {
        d=176;
        a=d+1;
        b=a+1;
        c=219;
        _1(a,b,c,d);
        fflush(stdout);
    }
    else if(i==2)
    {
        c=176;
        d=c+1;
        a=d+1;
        b=219;
        _1(a,b,c,d);
        fflush(stdout);
    }
    else if(i==3)
    {
        b=176;
        c=b+1;
        d=c+1;
        a=219;
        _1(a,b,c,d);
        fflush(stdout);
    }
    Sleep(150);
}

void Fade(int t)
{
    int i;
    char a;
    for(int j=0; j<t; j++)
    {
        for(int f=0; f<4; f++)
        {
            i=f%4;
            if(i==0)
            {
                a=176;
                _2(a);
                fflush(stdout);
            }
            else if(i==1)
            {
                a=177;
                _2(a);
                fflush(stdout);
            }
            else if(i==2)
            {
                a=178;
                _2(a);
                fflush(stdout);
            }
            else if(i==3)
            {
                a=219;
                _2(a);
                fflush(stdout);
            }
            Sleep(150);
        }
        for(int b=3; b>=0; b--)
        {
            i=b%4;
            if(i==0)
            {
                a=176;
                _2(a);
                fflush(stdout);
            }
            else if(i==1)
            {
                a=177;
                _2(a);
                fflush(stdout);
            }
            else if(i==2)
            {
                a=178;
                _2(a);
                fflush(stdout);
            }
            else if(i==3)
            {
                a=219;
                _2(a);
                fflush(stdout);
            }
            Sleep(150);
        }
    }
}

/////////////////// Animation Code End   /////////////////////////////

void loading()
{
    system("COLOR 0E");
    Fade(3);
    cls;

    char c;
    float a;
    char st[9]="COLOR 70";
//system(st);
    for(int i=1; i<=24; i++)
    {
        fflush(stdout);
        Slide(i);
        fflush(stdout);
        c=221;
        gotoxy(54,13);
        printf("Loading...\n\n");
        a=(float)i/24*100;
        gotoxy(40,15);
    Text_Color(15);
        printf("%.2f%% ",a);
  Text_Color(12);
        for(int x=1; x<i; x++)
        {
            printf("%c",c);
            fflush(stdout);
        }
Text_Color(11);
        fflush(stdout);
//        if(i%7==0)
//        {
//            Sleep(300);
//        }
//        if(i<24)
//            system("cls");
    }
    gotoxy(50,17);
    printf("Successfully Loaded");
    Sleep(300);
    cls;
    system("COLOR 07");
}

void bracket_frame()
{
    gotoxy(2,1);
    int y=15,x=75,down=1;
    for(int i=0,j=x; i<y; i++,j--)
    {
        printf("\t\t");
        for(int k=0; k<=i-1; k++)printf(" ");
        printf("\\\\");
        for(int k=0; k<j-i+1; k++)printf(" ");
        printf("//");
        gotoxy(2,down++);
    }
    for(int i=y-2,j=x-14; i>=0; i--,j++)
    {
        printf("\t\t");
        for(int k=i; k>=0; k--)printf(" ");
        printf("//");
        for(int k=0; k<j-i; k++)printf(" ");

        printf("\\\\");
        gotoxy(2,down++);
    }
}
void Box()
{
    for(int i=0; i<112; i++)printf("=");
    printf("\n");
    // printf("#################\t\t\t\t#################\n");
    for(int i=0; i<28; i++)
        printf("||\t\t\t\t\t\t\t\t\t\t\t\t\t      ||\n");
    for(int i=0; i<112; i++)printf("=");
}
void Small_Box()
{
    gotoxy(28,12);
     printf("%c",201);
    for(int i=0;i<55;i++)
        printf("%c",205);
    printf("%c",187);
    for(int i=1;i<=4;i++)
    {
        gotoxy(28,i+12);
        printf("%c",186);
        gotoxy(84,i+12);
        printf("%c",186);
    }
    gotoxy(28,17);
    printf("%c",200);
    for(int i=0;i<53;i++)
        printf("%c",205);
    printf("%c",188);
}
