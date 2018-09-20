#include<stdio.h>
void encdec(char *,int);
int main()
{
    FILE *fp;
    int i;
    char c[100]="hello world";
    char buffer[100];
    printf("original=%s\n",c);
    for(i=0;i<12;i++)
    {
        if(c[i]>=97)
        {
            if(c[i]<=122)
            {  encdec(c,i);
                buffer[i]=c[i];
            }
            else
                buffer[i]=c[i];
        }
        else
            buffer[i]=c[i];
    }
    printf("encoded=%s\n",buffer);
    fp=fopen("sample.txt","rw");
    fwrite(buffer,1,11,fp);
    fclose(fp);
    fp=fopen("sample.txt","rw");
    fread(buffer,1,11,fp);
    for(i=0;i<12;i++)
    {
        if(buffer[i]>=65)
        {
            if(buffer[i]<=97)
            {
                encdec(buffer,i);
                buffer[i]=buffer[i];
            }
            else
                buffer[i]=buffer[i];
        }
        else
            buffer[i]=buffer[i];
    }
    printf("decoded=%s",buffer);
    return 0;
}
void encdec(char *p,int i )
{
   
    if (p[i]>=97)
        p[i]=p[i]-32;
    else
        p[i]=p[i]+32;
}
