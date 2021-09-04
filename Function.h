void Welcome(char name[]);
void Main_Menu();
void registration();
void login();
void account();
void Add_New_Category(int Main_Menu_list_Size);
void Delete_Category(int Main_Menu_list_Size);
int Main_Menu_List_Display();
void Category(int Serial);
int Category_List_Display();
void New_Category_File();
void Delete_Category_File();
void Category_File_View_Edit(int File_No);

void Category_File_View_Edit(int File_No)
{
    char addr[100],Data[1000000],input,Hash[10000],view[200],Del[200]="del ";
    int key;
    strcpy(addr,Current_Addr);
    strcat(addr,Category_Files_List[File_No].File_Name);
    strcat(addr,".txt");

File_View:

    cls;
    File_Reading_Frame();
    gotoxy(82,2);
    printf("[E] Edit");
    gotoxy(16,2);
    printf("[B] Back");
    gotoxy(45,3);
    printf("%s",Category_Files_List[File_No].File_Name);

    gotoxy(44,5);
    printf("Input[    ]\n");

        key=Key(prep,0);
        pass_to_hash(prep,Hash,key);
        gotoxy(0,7);
        Display_Files(Category_Files_List[File_No].File_Name,Hash,key,false);

    gotoxy(51,5);
    scanf("%c",&input);
    fflush(stdin);

    fflush(stdin);
    if(input=='B')
    {
        return;
    }
    else if(input=='E')
    {
        strcpy(view,"\"");
        strcat(view,addr);
        strcat(view,"\"");
        gotoxy(0,5);
        printf("\t\t\tPlease press \"Enter Key\" after every end of line\n");

            key=Key(prep,0);
            pass_to_hash(prep,Hash,key);
            gotoxy(0,7);
            Display_Files(Category_Files_List[File_No].File_Name,Hash,key,true);

        system(view);
        encryption(Category_Files_List[File_No].File_Name,Hash,key);
        strcat(Del,view);
        system(Del);
        goto File_View;
    }
    else
    {
        gotoxy(40,5);
        printf("       Wrong Input       ");
        goto File_View;
    }
}

void Delete_Category_File(int Category_File_List_Size)
{
    int CTNO;
    bool x;
    //  gotoxy(36,13+Main_Menu_list_Size);
    gotoxy(35,11+Category_File_List_Size);
    printf("(Delete)Category File's Serial: ");
    scanf("%d",&CTNO);
    fflush(stdin);
    x=Delete_Category_File_Files(CTNO,Category_File_List_Size);
    if(x)
    {
        gotoxy(38,11+Category_File_List_Size);
        printf("File successfully deleted         ");
        Sleep(400);
    }
    else
    {
        gotoxy(33,11+Category_File_List_Size);
        printf("          Invalid category            ");
        Sleep(400);
    }
}

int Category_List_Display()
{
    char List[500],addr[100];
    int cnt=0;
    strcpy(addr,Current_Addr);
    strcat(addr,"check.txt");
    FILE *f;
    f=fopen(addr,"r");

    if(f==NULL)printf("File dosentt exist\n");
    else
    {
        while(Reading(List,'~',f))
        {
            strcpy(Category_Files_List[cnt].File_Name,List);
            gotoxy(40,6+cnt);
            printf("[%d] %s\n",1+cnt++,List);
        }
        if(cnt==0)
        {
            gotoxy(51,8);
            printf("Empty List");
        }
        fclose(f);
    }
    return cnt;
}

void New_Category_File(int Category_List_Cnt)
{
    char File_Name[100];
    gotoxy(42,11+Category_List_Cnt);
    printf("Enter File name: ");
    gets(File_Name);
    fflush(stdin);
    if(New_Category_File_Files(File_Name))
    {
        gotoxy(35,12+Category_List_Cnt);
        printf("     File created successfully          ");
        Sleep(400);
    }

    else
    {
        gotoxy(40,12+Category_List_Cnt);
        printf("     Already Exist!!               ");
        Sleep(400);
    }
}
void Category(int Serial)
{
    char input[10];
    int len,Category_List_Cnt;
    strcat(Current_Addr,Main_Menu_list[Serial-1].List_Name);
    strcat(Current_Addr,"\\");

CategoryStart:
    cls;
    gotoxy(30,2);
    printf("%s",Main_Menu_list[Serial-1].List_Name);
    gotoxy(25,0);
    printf("%c",186);
    gotoxy(25,1);
    printf("%c",186);
    gotoxy(25,2);
    printf("%c",186);
    gotoxy(25,3);
    printf("%c",200);
    gotoxy(26,3);
    for(int i=0; i<56; i++)printf("%c",205);

    gotoxy(2,2);
    printf("[M] Main Menu");
    gotoxy(2,3);
    printf("[S] Search Files");
    gotoxy(86,2);
    printf("[N] Create New File");
    gotoxy(86,3);
    printf("[D] Delete File");

    Category_List_Cnt=Category_List_Display();
    Main_Menu_frame(Category_List_Cnt+5);

For_Input:

    gotoxy(45,11+Category_List_Cnt);
    printf("Input:[      ]               ");
    gotoxy(53,11+Category_List_Cnt);
    scanf("%s",input);
    fflush(stdout);
    fflush(stdin);

    if(input[0]>=48 && input[0]<=57)
    {
        int i=0,File_No=0;

        while(input[i]!='\0')
        {
            File_No=(File_No*10)+(input[i]-48);
            i++;
        }

        if(File_No<=0 || File_No>Category_List_Cnt)
        {
            gotoxy(45,10+Category_List_Cnt);
            printf("    Wrong Input     ");
            Sleep(400);
            goto For_Input;
        }

        else
        {
            Category_File_View_Edit(File_No-1);
            goto CategoryStart;
        }
    }
    else if(input[0]=='N')
    {
        New_Category_File(Category_List_Cnt);
        goto CategoryStart;
    }
    else if(input[0]=='D')
    {
        Delete_Category_File(Category_List_Cnt);
        goto CategoryStart;
    }
    else if(input[0]=='M')
    {
        len=strlen(Current_Addr);
        len--;
        while(Current_Addr[len-1]!='\\')
        {
            Current_Addr[len-1]='\0';
            len--;
        }
        return;
    }
    else if(input[0]=='S')
        {
            Search(0);
             goto CategoryStart;
        }
    else
    {
        gotoxy(45,10+Category_List_Cnt);
        printf("    Wrong Input     ");
        Sleep(400);
        goto For_Input;
    }
}

int Main_Menu_List_Display()
{
    char List[500],addr[100];
    int cnt=0;
    strcpy(addr,Current_Addr);
    strcat(addr,"check.txt");
    FILE *f;
    f=fopen(addr,"r");
    if(f==NULL)
    {
        gotoxy(51,10);
        printf("Empty List");
    }
    else
    {
        while(Reading(List,'~',f))
        {
            strcpy(Main_Menu_list[cnt].List_Name,List);
            gotoxy(46,11+cnt);
            printf("[%d] %s\n",1+cnt++,List);
        }
        if(cnt==0)
        {
            gotoxy(51,10);
            printf("Empty List");
        }
    }
    fclose(f);

    return cnt;
}

void Delete_Category(int Main_Menu_list_Size)
{
    int x,CTNO;
    gotoxy(36,14+Main_Menu_list_Size);
    printf("      (Delete) Category Serial:");
    scanf("%d",&CTNO);
    fflush(stdin);
    if(CTNO<=0 || CTNO>Main_Menu_list_Size)
    {
        printf("\n\t\t\t\t\t   Invalid Category\n");
        Sleep(500);
    }
    else
    {
        x=Delete_Category_Files(CTNO,Main_Menu_list_Size);
        if(x)
        {
            printf("\n\t\t\t\t          Category successfully deleted\n");
            Sleep(500);
        }
        else
        {
            printf("\n\t\t\t\t\t   Invalid Category\n");
            Sleep(500);
        }
    }


    return;
}
void  Add_New_Category(int Main_Menu_list_Size)
{
    char category[100];
    gotoxy(20,14+Main_Menu_list_Size);
    printf("\t\t\tEnter Category name:");
    gets(category);
    if(Add_New_Category_Files(category))
    {
        gotoxy(23,14+Main_Menu_list_Size);
        printf("\t            Category added successfully         \n");
        Sleep(300);
    }

    else
    {
        gotoxy(20,14+Main_Menu_list_Size);
        printf("\t\t             Already Exist!!             \n");
        Sleep(400);
    }
    return;
}

void Welcome(char name[])
{
    cls;
    system("COLOR F0");
    int ln,ln1;
    ln=strlen(name);
    ln1=ln+9;
    char name1[ln1];
    strcpy(name1,"Welcome ");
    strcat(name1,name);
    gotoxy(49,13);
    Text_Color(1);
    for(int i=0; i<ln+8; i++)
    {
        Sleep(100);
        printf("%c",name1[i]);
        if(i%3==0)
            Sleep(100);
        if(i==7)
            Text_Color(0);
    }
    Text_Color(1);
    gotoxy(43,16);
    printf("Press Enter to continue..");
    getchar();
    system("COLOR 07");
}
void Main_Menu()
{
    char input[10],Color[10];
    int Main_Menu_List_Count,List_No,i;
    Select_Color();
    while(1)
    {
        cls;

        gotoxy(51,4);
        printf("Main Menu");
        gotoxy(49,5);
        printf("============");

        printf("\n\t\t[New] Add a New Category\t\t\t\t[Del] Delete a Category\n");

        gotoxy(90,2);
        printf("[C] Change Color");
        gotoxy(90,3);
        printf("[P] Change Password");

        gotoxy(3,2);
        printf("[S] Search Category");
        Main_Menu_List_Count=Main_Menu_List_Display();
        //Design
        gotoxy(5,18+Main_Menu_List_Count);
        printf("[L] Logout");
        gotoxy(80,18+Main_Menu_List_Count);
        printf("[E] Delete This Account");
        Main_Menu_frame(11+Main_Menu_List_Count);

        gotoxy(40,14+Main_Menu_List_Count);
        printf("     Input:[      ]               ");
        gotoxy(53,14+Main_Menu_List_Count);
        scanf("%s",input);
        fflush(stdout);
        fflush(stdin);
        if(input[0]>=48 && input[0]<=57)
        {
            i=0,List_No=0;
            while(input[i]!='\0')
            {
                List_No=(List_No*10)+(input[i]-48);
                i++;
            }
            if(List_No<=0 || List_No>Main_Menu_List_Count)
            {
                gotoxy(45,15+Main_Menu_List_Count);
                printf("    Wrong Input     ");
                Sleep(400);
            }
            else
            {
                Category(List_No);
            }
        }
        else if(strcmp(input,"New")==0)
        {
            Add_New_Category(Main_Menu_List_Count);
        }
        else if(strcmp(input,"Del")==0)
        {
            Delete_Category(Main_Menu_List_Count);

        }
        else if(strcmp(input,"L")==0)
        {
            return;
        }
        else if(strcmp(input,"E")==0)
        {
            Delete_Account();
        }
        else if(strcmp(input,"C")==0)
        {
            Change_Color(Color);
            system(Color);
        }
        else if(strcmp(input,"S")==0)
        {
            Search(1);
        }
        else if(strcmp(input,"P")==0)
        {
            Change_Password();
        }
        else
        {
            gotoxy(45,15+Main_Menu_List_Count);
            printf("    Wrong Input     ");
            Sleep(400);
        }
    }
}



void registration()
{
    cls;

    char username[50],password[50];
    bracket_frame();
    gotoxy(51,8);
    printf("Registration\n");
    gotoxy(49,9);
    printf("================\n");
    gotoxy(40,12);
    printf("Username: ");
    scanf("%s",username);
    gotoxy(40,15);
    printf("Password: ");
    password_hider(password,1);
    //scanf("%s",password);
    fflush(stdin);
    if(regi_user(username,password))
    {
        gotoxy(43,17);
        printf("Registration Successful\n");
        gotoxy(41,18);
        printf("Press Enter key to continue..");
        getchar();
        login();
    }
    else
    {
        gotoxy(43,17);
        printf("Account Already exist\n");
        gotoxy(41,18);
        printf("Press Enter key to continue..");
        getchar();
        registration();
    }

}
void login()
{
    cls;
    strcpy(Current_Addr,"C:\\Donkey\\");
    char username[50],password[50],user_id[50]="C:\\Donkey\\",user_pass[50],Hash[50];
    int key;

    bracket_frame();
    gotoxy(55, 8);
    printf("Login\n");
    gotoxy(49,9);
    printf("================\n");
    gotoxy(40,12);
    printf("Username: ");
    scanf("%s",&username);
    fflush(stdin);
    gotoxy(40,15);
    printf("Password: ");
    password_hider(password,1);
    //scanf("%s",&password);

    fflush(stdin);

    strcat(user_id,username);
    strcat(user_id,"\\P.txt");

    FILE *f;
    f=fopen(user_id,"r");
    if(f==NULL)
    {
vulpass:
        gotoxy(40,19);
        printf("Wrong user name or password");
        gotoxy(45,21);
        printf("Please Try Again");
        getchar();
        fflush(stdout);
        login();
    }
    else
    {
        while(!feof(f))
        {
            fscanf(f,"%s",&user_pass);

        }
        fclose(f);

        key=Key(password,1);
        pass_to_hash(password,Hash,key);

        if(strcmp(Hash,user_pass)==0)
        {
            char Hash[1000];
            int key;
            Welcome(username);
            strcpy(Globalun,username);
            strcpy(gp,password);
//Current Location set.
            strcat(Current_Addr,Globalun);
            strcat(Current_Addr,"\\");

            key=Key(password,1);
            pass_to_hash(password,Hash,key);
            pass_decryption(Hash,key);

            Main_Menu();
        }
        else
        {
            goto vulpass;
        }
    }
}
void account()
{
    int x;
    while(1)
    {
        cls;
        system("COLOR 8F");
        Box();
        bracket_frame();
        Small_Box();
        gotoxy(40,14);
        Text_Color(15);
        printf("[1] Login");
        gotoxy(40,15);
        printf("[2] Registration");
        gotoxy(40,16);
        scanf("%d",&x);
        Text_Color(15);
        if(x==1)
        {
            login();
        }
        else if(x==2)
        {
            registration();
        }
        else
        {
            gotoxy(45,17);
            printf("Wrong input.Try again\n");
            fflush(stdin);
            Sleep(200);
        }
    }
}
