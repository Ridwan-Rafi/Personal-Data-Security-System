int HexToDec(char hex[]);
void dectohex(long long int num_decimal,char hex[]);
long long int hash_function(char str[],int key);
void pass_to_hash(char password[],char Hash[],int key);
int Key(char pass[],bool flag);

int Key(char pass[],bool flag)
{
    int sum=0,ln;
    ln=strlen(pass);
    for(int i=0; i<ln; i++)
        sum+=pass[i];
    if(flag==1)
        return sum%11;
    else
    {
        return sum%51;
    }
}

void dectohex(long long int num_decimal,char hex[])
{
    int temp;
    temp = 0 ;
    while(num_decimal > 0 )
    {
        switch(num_decimal % 16 )
        {
        case 10 :
            hex[temp]='A' ;
            break ;
        case 11 :
            hex[temp]='B';
            break ;
        case 12 :
            hex[temp]='C' ;
            break ;
        case 13 :
            hex[temp]='D';
            break ;
        case 14 :
            hex[temp]='E' ;
            break ;
        case 15 :
            hex[temp]='F';
            break ;
        default :
            hex[temp]=( num_decimal%16 ) + 0x30 ;
        }
        num_decimal = num_decimal / 16 ;
        temp ++ ;
    }
    hex[temp]='\0';
}

int HexToDec(char hex[])
{
    int decimal,i=0,val,len;
    decimal = 0;
    len = strlen(hex);
    len--;
    for(i=0;hex[i]!='\0';i++)
    {
        if(hex[i]>='0' && hex[i]<='9')
        {
            val=hex[i]-48;
        }
        else if(hex[i]>='a' && hex[i]<='f')
        {
            val=hex[i]-97+10;
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            val=hex[i]-65+10;
        }
        else if(hex[i]=='\n')
        {
            continue;
        }
        decimal+=val*pow(16, len);
        len--;
    }
    return decimal;
}

long long int hash_function(char str[],int key)
{
    int cid;
    long long int Hash=0;
    for(int i=0; i<strlen(str); i++)
    {
        cid=str[i];
        Hash=key*Hash+cid;
    }
    return Hash;
}


void pass_to_hash(char password[],char Hash[],int key)
{
    int ln;
    long long int pss;
    pss=hash_function(password,key);
    dectohex(pss,Hash);
}
