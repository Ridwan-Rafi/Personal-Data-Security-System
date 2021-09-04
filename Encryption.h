void password_hider(char p[],int pos)
{

    int ln,i=0,cnt=0,x,y;
    char c;
    if(pos==1)
    {
        x=50;
        y=15;
    }
    else if(pos==2)
    {
        x=65;
        y=7;
    }
    else if(pos==3)
    {
        x=67;
        y=9;
    }
     while(1)
    {
        c=getch();
        if(c==13)
        {
            p[i]='\0';
            ln=strlen(p);
            printf("\n");
            //for(int j=0;j<ln;j++)printf("%c",p[j]);
            break;
        }
        else if(c==8)
        {

            i--;
            if(i<0)
                i=0;
            else
                cnt++;

            p[i]='\0';
            gotoxy(x,y);
            for(int j=0;j<i;j++)printf("*");
            for(int j=0;j<cnt;j++)printf(" ");
            gotoxy(x+i,y);
            fflush(stdout);
        }
        else if((c>=32 && c<=126))
        {
            cnt=0;
            p[i++]=c;
            printf("*");
        }
    }
}

void reverse(char data[])
{
    int len,j=0;
    len=strlen(data);
    char re[len+5];
    for(int i=len-1; i>=0; i--)
    {
        re[j++]=data[i];
    }
    re[j]='\0';
    strcpy(data,re);
}

void encryption(char File_Name[],char Hash[],int Key)
{
    char addr[200],Eaddr[200],Del[200]="del \"";
    strcpy(addr,Current_Addr);
    strcat(addr,File_Name);
    strcpy(Eaddr,addr);
    strcat(Eaddr,".Don");
    strcat(addr,".txt");

    FILE *fdata,*fencrypt;

    fdata=fopen(addr,"r");
    if(fdata==NULL)printf("Data file not found\n");
    else
    {
        char c,hex[20];
        int intc,hi=0,inth,gun,hashlen;
        hashlen=strlen(Hash);
        fencrypt=fopen(Eaddr,"w");
        while(!feof(fdata))
        {
            c=fgetc(fdata);
            if(c=='\n')
            {
                fputc('\n',fencrypt);
            }
            intc=c;
            inth=Hash[hi++];

            if(hi==hashlen)hi=0;

            gun=(intc*inth)+Key;
            dectohex(gun,hex);
            fputs(hex,fencrypt);
            fputc(',',fencrypt);
        }
        fclose(fencrypt);
    }
    fclose(fdata);
    strcat(Del,addr);
    strcat(Del,"\"");
    system(Del);
}

void Display_Files(char File_Name[],char Hash[],int Key,bool fileornot)
{
    char addr[200],txtaddr[200];
    strcpy(addr,Current_Addr);
    strcat(addr,File_Name);
    strcpy(txtaddr,addr);
    strcat(addr,".Don");
    strcat(txtaddr,".txt");

    FILE *Data,*txtData;
    Data=fopen(addr,"r");
    if(Data==NULL)
    {
        printf("File Not exist\n");
        fclose(Data);
    }
    else
    {
        if(fileornot)
        {
            txtData=fopen(txtaddr,"w");
        }

        char c,hex[50];
        int x,hi=0,inth,intc,hashlen;
        hashlen=strlen(Hash);
        while(Reading(hex,',',Data))
        {
            reverse(hex);
            x=HexToDec(hex);
            x=x-Key;
            inth=Hash[hi++];
            if(hi==hashlen)hi=0;
            intc=x/inth;
            c=intc;
            if(fileornot)
            {
                fputc(c,txtData);
            }
            else
                printf("%c",c);
        }
        if(fileornot)
            fclose(txtData);
        else
            printf("\n");
        fclose(Data);
    }
}
void pass_encryption(char Username[],char pass[],char Hash[],int Key)
{
    char addr[200]="C:\\Donkey\\",Eaddr[200];
    strcat(addr,Username);
    strcat(addr,"\\pp.Don");
    FILE *fdata;

    fdata=fopen(addr,"w");

    char hex[50];
    int intc,hi=0,inth,gun,hashlen,Psslen;
    hashlen=strlen(Hash);
    Psslen=strlen(pass);
    for(int i=0; i<Psslen; i++)
    {
        intc=pass[i];
        inth=Hash[hi++];

        if(hi==hashlen)hi=0;

        gun=(intc*inth)+Key;
        dectohex(gun,hex);
        fputs(hex,fdata);
        fputc(',',fdata);
    }
    fclose(fdata);
}
void pass_decryption(char Hash[],int Key)
{
    char addr[200];
    strcpy(addr,Current_Addr);
    strcat(addr,"pp.Don");

    FILE *Data;
    Data=fopen(addr,"r");
    if(Data==NULL)
    {
        printf("File Not exist\n");
        fclose(Data);
    }
    else
    {

        char c,hex[50];
        int x,hi=0,inth,intc,hashlen,i=0;
        hashlen=strlen(Hash);
        while(Reading(hex,',',Data))
        {
            reverse(hex);
            x=HexToDec(hex);
            x=x-Key;
            inth=Hash[hi++];
            if(hi==hashlen)hi=0;
            intc=x/inth;
            c=intc;
            prep[i++]=c;
        }
        prep[i]='\0';
        fclose(Data);
    }
}
