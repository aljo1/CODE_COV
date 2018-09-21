#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

void encdec(char *,int);

int main(int argc,char *argv[])
{
    FILE *fp;
    int i,ret, no_bytes;
    char buffer[100];

    //cehck we have everythig to run
    if (argc < 2) {
        printf("Usage: fcrypt <filename>\n");
        exit(1);
    }

    //get contents of file to buffer
    fp = fopen(argv[1],"rw");
    if(fp == NULL)
        printf("cannot open\n");
    else
        printf("opened\n");
    ret = fread(buffer,1, 1024,fp);
    if (ret == 0 ) {
        printf("fread failed.!\n");
        fclose(fp);
        exit(1);
    }
    no_bytes = ret;
    fclose(fp);

    //start processing buffer now
    for(i = 0;i < no_bytes; i++)
    {
        if(buffer[i]>=97)
        {
            if(buffer[i]<=122)
              encdec(buffer,i);
            else
                buffer[i]=buffer[i];
        }
        else
            buffer[i]=buffer[i];
    }
    printf("encoded=%s\n",buffer);

    //write back buffer to file
    fp = fopen(argv[1],"w");
    if(fp == NULL)
        printf("cannot open\n");
    else
        printf("opened\n");
    ret = fwrite(buffer,1,no_bytes,fp);
    if (ret == 0 ) {
        printf("fwrite failed.! error %d\n", errno);
        fclose(fp);
        exit(1);
    }
    fclose(fp);

    return 0;
}

void encdec(char *p,int i )
{
    if (p[i]>=97)
        p[i]=p[i]-32 + 4;
    else
        p[i]=p[i]+32 - 4;
}
