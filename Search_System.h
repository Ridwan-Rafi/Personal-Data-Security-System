
int Search_List_Count;
struct data
{
    char name[10000];
   // char adress[100];
    struct data *next;
};

struct data *read_list()
{
char faddr[100];
strcpy(faddr,Current_Addr);
strcat(faddr,"check.txt");
    FILE *read = fopen(faddr, "r");
    char s[10000];
    struct data *head=NULL, *last = NULL, *tem;
    int i = 0;

    if(read==NULL)
    {
        printf("File doesn't exist\n");
    }
    else
    {
        while (Reading(s,'~',read))
        {
            tem = (struct data *)malloc(sizeof(struct data));
            strcpy(tem->name, s);
//            fscanf(read, "%s", s);
//            strcpy(tem->adress, s);
            tem->next = NULL;
            if (head == NULL)
                head = tem;
            else
                last->next = tem;
            last = tem;

        }
        return head;
    }
}
bool Compare(char a,char b)
{
    if(a>='A' && a<='Z')a+=32;
    if(b>='A' && b<='Z')b+=32;
    if(a==b)return false;
    else
        return true;
}
bool nibo(char s[], char s1[])
{
    int count = 0;
    for (int i = 0; s[i] && s1[i]; i++)
    {
        if (Compare(s[i],s1[i]))
            return false;
    }
    return true;
}
struct data *show(char s[], struct data *head)
{
    int i = 0;
    struct data *temp = head, *listhead = NULL, *list_temp = NULL, *ob;
    while (temp != NULL)
    {
        if (nibo(s, temp->name))
        {

            list_temp = (struct data *)malloc(sizeof(struct data));
            strcpy(list_temp->name, temp->name);
          //  strcpy(list_temp->adress, temp->adress);
            list_temp->next = NULL;

            if (listhead == NULL)
            {
                listhead = list_temp;
            }
            else
            {
                ob->next = list_temp;
            }

            ob = list_temp;
        }
        temp = temp->next;
    }
    ob = listhead;
    int cnt=1;
    while (ob != NULL)
    {
        gotoxy(40,11+cnt);
        printf("[%d] %s\n",cnt++,ob->name);
        ob = ob->next;
    }
    Search_List_Count=cnt-1;
    return listhead;
}
void Search(bool MorC)
{
    cls;
    char search[10000];
    int i = 0, n, ch,input;
    struct data *ob = read_list(), *list;
    search[0]='\0';
    gotoxy(40,5);
    printf("Press \'Enter'\ Key for select or Press \'Esc\' Key for Back");
    gotoxy(50,7);
    printf("Enter Keyword: ");
    while (1)
    {
        Search_Frame();
        ch = getch();
        if(ch == 27)return;
        if (ch == 13)
            {
                gotoxy(50,Search_List_Count+13);
                printf("Enter list No: ");
                scanf("%d",&input);
                if(input<=0 || input>Search_List_Count)
                {
                    gotoxy(45,Search_List_Count+2);
                printf("      Wrong input        ");
                Sleep(400);
                }
                else
                {
                    n=1;
                while(n!=input)
                {
                    list=list->next;
                    n++;
                }
                if(MorC)
                {
                    int i=0;
                while(1)
                {
                    if(strcmp(Main_Menu_list[i].List_Name,list->name)==0)
                       {
                           Category(i+1);
                        break;
                       }
                       i++;
                }
                }
                else
                {
                    int i=0;
                while(1)
                {
                    if(strcmp(Category_Files_List[i].File_Name,list->name)==0)
                       {
                           Category_File_View_Edit(i);
                        break;
                       }
                       i++;
                }
                }
                }
                return;
            }
        if (ch == 8)
        {
            if(i>0)--i;
            search[i]='\0',system("cls");
        }
        else
        {
            system("cls");
            search[i] = ch;
            search[++i] = '\0';
        }
        gotoxy(35,5);
    printf("Press \'Enter'\ Key for select or Press \'Esc\' Key for Back");
        gotoxy(50,7);
        printf("Enter Keyword: ");
        printf("%s\n",search);
        if(i>0)
        list = show(search, ob);
    }
}
