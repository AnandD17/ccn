// C PROGRAM DEMONSTRATING STUFFING AND DESTUFFING OF DATA.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char data[100],data2[100],stuff[100],destuff[100];
    char h_t2[100],h_t[]={"01111110"};
    int i,a,n,n1,count=0,cnt=0;
    printf("enter the data");
    scanf("%s",data);
    n=strlen(data);
    printf("length of data: %d",n);
    strcpy(data2,data);
    strcpy(h_t2,h_t);
    strcat(data2,h_t2);
    strcat(h_t2,data2);
    //strcpy(data2,h_t2);
    printf("\n on adding header and trailer data is:%s",data2);

    //STUFFING DATA
    for(i=0,a=8;data2[i]!='\0';i++,a++)
    {
        if(data[i]=='1')
            count++;
        else
            count=0;

        if(count==5)
        {
            data2[a]=data[i];
            a++;
            data2[a]='0';
            count=0;
        }
        else
            data2[a]=data[i];
    }

    data2[a]='\0';
    strcat(data2,h_t);
    printf("\n data on stuffing:%s",data2);
    n1=strlen(data2);
    printf("\nlength of data on stuffing =%d",n1);
    strcpy(stuff,data2);
//DESTUFFING
    for(i=0,a=8;a<n1-8;i++,a++)
    {
        if(stuff[a]=='1')
            cnt++;
        else
            cnt=0;
        if(cnt==5)
        {
            destuff[i]=stuff[a];
            a++;
            cnt=0;
        }
        else
            destuff[i]=stuff[a];
    }
    destuff[i]='\0';
    printf("\n the data on destuffing :%s",destuff);

}
