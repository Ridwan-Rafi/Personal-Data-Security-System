bool regi_user(char username[],char password[]);
bool Add_New_Category_Files(char category[]);
int  Delete_Category_Files(int CtNo,int Main_Menu_list_Size);
void Delete_Account();
bool New_Category_File_Files(char File_Name[]);
bool Delete_Category_File_Files(CTNO,Category_File_List_Size);

//Structure of Main Menu. Start
struct MML
{
    char List_Name[200];
} Main_Menu_list[100000];
//Structure End.

//Structure of Category files
struct CTF
{
    char File_Name[200];
} Category_Files_List[100000];
//Structure end.

///////Change Password Start////////
void Change_Password()
{
    cls;
        Upper_angel();
        Lower_angel(15);

    char nw[100],cnw[100],addr[100],Hash[111];
    int key;
     gotoxy(51,4);
        printf("Change Password");
        gotoxy(49,5);
        printf("===================");

    gotoxy(45,7);
    printf("Enter new password: ");
    password_hider(nw,2);
    //scanf("%s",nw);
    gotoxy(45,9);
    printf("Confirm new password: ");
    password_hider(cnw,3);
    //scanf("%s",cnw);
    if(strcmp(nw,cnw)==0)
    {
        strcpy(addr,Current_Addr);
        strcat(addr,"P.txt");
        ////////Hashing Start////////
        key=Key(nw,1);
        pass_to_hash(nw,Hash,key);
        ///////Hashing END//////////
        //////Old Password Encryption Start ///////

        pass_encryption(Globalun,prep,Hash,key);

        //////Old Password Encryption End /////////
        FILE *f;
        f=fopen(addr,"w");
        if(f==NULL)printf("File Doesn't exist\n");
        else
        {
            strcpy(gp,nw);
            fprintf(f,"%s\n",Hash);
            fclose(f);
            gotoxy(45,11);
            printf("Password Changed Successfully");
            Sleep(600);
        }
    }
    else
    {
        gotoxy(45,11);
        printf("Password Didnt't match");
        Sleep(600);
    }
}
///////Change Password end/////////
//////saved color/////

void Select_Color_save(char color[])
{
    char caddr[50];
    strcpy(caddr,Current_Addr);
    strcat(caddr,"Color.txt");
    FILE *c;
    c=fopen(caddr,"w");
    if(c==NULL)
    {
        printf("Color file does not exist\n");
        fclose(c);
    }
    else
    {
        fputs(color,c);
        fclose(c);
    }
}
void Select_Color()
{
    char caddr[50],clr[10];
    strcpy(caddr,Current_Addr);
    strcat(caddr,"Color.txt");
    FILE *c;
    c=fopen(caddr,"r");
    if(c==NULL)
    {
        fclose(c);
        c=fopen(caddr,"w");
        fprintf(c,"COLOR 07");
        fclose(c);
    }
    else
    {
        c=fopen(caddr,"r");
        fgets(clr,9,c);
        system(clr);
    }
}


bool Delete_Category_File_Files(CTNO,Category_File_List_Size)
{
    if(CTNO<1 || CTNO>Category_File_List_Size)
        return false;

    char addr[100]="del \"",update_addr[100];

FILE *f;

    strcat(addr,Current_Addr);
    strcat(addr,Category_Files_List[CTNO-1].File_Name);
    strcat(addr,".txt\"");

    strcat(update_addr,Current_Addr);
    strcat(update_addr,"check.txt");
    system(addr);

        for(int i=CTNO-1; i<Category_File_List_Size-1; i++)
        {
            strcpy(Category_Files_List[i].File_Name,Category_Files_List[i+1].File_Name);
        }

        f=fopen(update_addr,"w");
        if(f==NULL)printf("File dosentt exist\n");
        else
        {
            for(int i=0; i<Category_File_List_Size-1; i++)
            {
                fputs(Category_Files_List[i].File_Name,f);
                fputc('~',f);
            }
        }
        fclose(f);
        return true;
}

bool New_Category_File_Files(char File_Name[])
{
    char addr[100],update[100];
    strcpy(addr,Current_Addr);
    strcpy(update,Current_Addr);

    strcat(addr,File_Name);
    strcat(update,"check.txt");
    strcat(addr,".Don");

    FILE *f;
    f=fopen(addr,"r");
    if(f==NULL)
    {
        fclose(f);

        f=fopen(update,"a");
        fputs(File_Name,f);
        fputc('~',f);
        fclose(f);

        f=fopen(addr,"w");
        fclose(f);
        return true;
    }
    else
    {
        fclose(f);
        return false;
    }
}

bool Add_New_Category_Files(char category[])
{
    char addr[200],preaddr[200];
    FILE *f;

    strcpy(addr,Current_Addr);
    strcat(addr,category);
    strcat(addr,"\\");
    mkdir(addr);
    strcat(addr,"check.txt");
    f=fopen(addr,"r");
    if(f==NULL)
    {
        f=fopen(addr,"w");
        fclose(f);
        strcpy(preaddr,Current_Addr);
        strcat(preaddr,"check.txt");
        f=fopen(preaddr,"a");
        fputs(category,f);
        fputc('~',f);
        fclose(f);
        return true;
    }
    else
    {
        return false;
    }
}

int  Delete_Category_Files(int CtNo,int Main_Menu_list_Size)
{
    char addr[100]="rmdir /s /q \"",faddr[100],ReListaddr[50];
    bool flag;
    FILE *f;

    strcat(addr,Current_Addr);
    strcat(addr,Main_Menu_list[CtNo-1].List_Name);
    strcat(addr,"\"");
    strcpy(faddr,Current_Addr);
    strcat(faddr,Main_Menu_list[CtNo-1].List_Name);
    strcat(faddr,"\\check.txt");


    f=fopen(faddr,"r");
    if(f==NULL)
    {
        fclose(f);
        flag=0;

    }
    else
    {
        fclose(f);
        system(addr);

        for(int i=CtNo-1; i<Main_Menu_list_Size-1; i++)
        {
            strcpy(Main_Menu_list[i].List_Name,Main_Menu_list[i+1].List_Name);
        }
        strcpy(ReListaddr,Current_Addr);
        strcat(ReListaddr,"\\check.txt");



        f=fopen(ReListaddr,"w");
        if(f==NULL)printf("File dosentt exist\n");
        else
        {
            for(int i=0; i<Main_Menu_list_Size-1; i++)
            {
                fputs(Main_Menu_list[i].List_Name,f);
                fputc('~',f);
            }
        }
        fclose(f);

        flag=1;
    }


    return flag;
}
void Delete_Account()
{
    cls;

    char a[]="rmdir /s /q C:\\Donkey\\";
    int x;
    gotoxy(50,13);
    printf("Deleting Account");
    gotoxy(50,16);
    printf("Are you sure?");
    gotoxy(45,17);
    printf("[1]Yes\t\t[0]No");
    gotoxy(50,18);
    scanf("%d",&x);
    if(x)
    {
        cls;
        strcat(a,Globalun);

        system(a);
        gotoxy(49,20);
        printf("Successfully Deleted");
        gotoxy(43,21);
        printf("Press \"Enter\" Key to continue");
        account();

    }
    else
    {
        return;
    }

}
bool regi_user(char username[],char password[])
{
    char loc[50]="C:\\Donkey\\",ploc[10]="\\P.txt",chek[50],Hash[50];
    int key;
    FILE *f;
    strcat(loc,username);
    strcpy(chek,loc);
    strcat(chek,ploc);
    f=fopen(chek,"r");
    if(f==NULL)
    {
        fclose(f);
        //hashing start
        key=Key(password,1);
        pass_to_hash(password,Hash,key);
        //hashing end

        mkdir(loc);
        strcat(loc,ploc);
        f=fopen(loc,"w");
        fprintf(f,"%s\n",Hash);
        fclose(f);
        // Password Encryption Start//////

        pass_encryption(username,password,Hash,key);

        // Password Encryption End ///////
        return true;
    }
    else
    {
        return false;
    }
}
