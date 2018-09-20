#include<stdio.h>
main()
{
    FILE *fp;
    int i;
    char c[100]="hello world";
    char buffer[100];
//    char buf[100];
    fp=fopen("sample.txt","rw");
    if (fp==NULL)
    {
        printf("cannot open file: \n");
    }
    else {
        printf("opened file: \n");
        //fclose(fp);
    }
    for(i=0;i<12;i++)
    {
        buffer[i]=c[i]+1;
    }
    fseek(fp,0,SEEK_SET);
    fwrite(buffer,1,11,fp);
    printf("BE=%s",buffer);
    fseek(fp,0,SEEK_SET);
    fread(buffer,1,11,fp);
    printf("AE=%s",buffer);
    for(i=0;i<12;i++)
    {
        buffer[i]=buffer[i]-1;
    }
    printf("decoded=%s",buffer);
}

