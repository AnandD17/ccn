#include<stdio.h>
int main()
{
    int size;
    int flag[8]={0,1,1,1,1,1,1,0};

    //Data Collection
    printf("Enter the size of data to be transmitting : ");
    scanf("%d",&size);

    int tx[size];
    printf("Enter the data: \n");
    for(int i=0; i<size; i++)
    {
        scanf("%d",&tx[i]);
    }

    int stuff[100];
    int destuff[size];
    int count=0,i=0,key=0;
    int s=0;

    //Stuffing process
    while(i<size)
    {
        if(tx[i]==0)
        {
            stuff[s]=tx[i];
            s++;
            count=0;
            int j;
            for(j=i+1;j<i+6;j++)
            {
                if(j==size) break;
                if(tx[j]==1)
                {
                    stuff[s]=tx[j];
                    s++;
                    count++;
                }
                else
                {
                    break;
                }
            }
            if(count==5)
            {
                key=key+1;
                stuff[s]=0;
                s++;
                i=j;
            }
            else{
                i=j;
            }
        }
        else
        {
            stuff[s]=tx[i];
            s++;
            i++;
        }
    }

    printf("Processed data : ");
    for(int i=0;i<size+key;i++)
    {
        printf("%d ",stuff[i]);
    }

    printf("\nThe data to be transmitted after stuffing is.... \n");
    for(int i=0;i<8;i++)
    {
        printf("%d ",flag[i]);
    }
    for(int i=0;i<size+key;i++)
    {
        printf("%d ",stuff[i]);
    }
    for(int i=0;i<8;i++)
    {
        printf("%d ",flag[i]);
    }

    count=0,i=0;
    s=0;

    //DeStuffing process
    while(i<size+key)
    {
        if(stuff[i]==0)
        {
            destuff[s]=stuff[i];
            s++;
            count=0;
            int j;
            for(j=i+1;j<i+6;j++)
            {
                if(j==size+key) break;
                if(stuff[j]==1)
                {
                    destuff[s]=stuff[j];
                    s++;
                    count++;
                }
                else
                {
                    break;
                }
            }
            if(count==5)
            {
                i=j+1;
            }
            else{
                i=j;
            }
        }
        else
        {
            destuff[s]=stuff[i];
            s++;
            i++;
        }
    }


    printf("\n\nThe data after destuffing is.... \n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",destuff[i]);
    }
}

