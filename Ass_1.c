#include <stdio.h>
#include <stdlib.h>
#include<time.h>
void binarySearch(int a[],int,int,int*);
int interpolationSearch(int [],int,int,int*);
int linearSearch(int a[],int,int,int*);
int main()
{
    int size=10;
    int a[size],i,search,pos,pos2;
    double extime1,extime2,extime3;
    int t=0,b=0,c=0;
    int *counter1,*counter2,*counter3;
    counter1=&t;
    counter2=&b;
    counter3=&c;
    for(i=0;i<size;i++)
    {
        a[i]=i;
    }
    printf("ENTER A NUMBER TO FIND\n");
    scanf("%d",&search);
    //BINARY SEARCH
    clock_t start1,end1;
    start1=clock();
    binarySearch(a,size,search,counter1);
    end1=clock();
    extime1=(double)(end1-start1)*100000/CLOCKS_PER_SEC;
    printf("EXECUTION TIME FOR THE BINARY SEARCH IS %f SECONDS:\n\n",extime1);
    //LINEAR SEARCH
    clock_t start2,end2;
    start2=clock();
    pos=linearSearch(a,size,search,counter2);
    if(pos==-1)
    {
        printf("%d IS NOT PRESENT IN ARRAY.\n",search);
    }
    else
    {
        printf("%d IS PRESENT AT LOCATION %d.\n",search,pos+1);
    }
    end2=clock();
    extime2=(double)(end2-start2)*100000/CLOCKS_PER_SEC;
    printf("EXECUTION TIME FOR THE LINEAR SEARCH IS %f SECONDS:\n\n",extime2);
    //INTERPOLATION SEARCH
    clock_t start3,end3;
    start3=clock();
    pos2=interpolationSearch(a,size,search,counter3);
    if(pos2==-1)
    {
        printf("ELEMENT %d NOT FOUND\n",search);
    }
    else
    {
        printf("ELEMENT %d FOUND AT POSITION %d\n",search,pos2+1);
    }
    end3=clock();
    extime3=(double)(end3-start3)*100000/CLOCKS_PER_SEC;
    printf("EXECUTION TIME FOR THE INTERPOLATION SEARCH IS %f SECONDS:\n\n",extime3);
    //COUNTERS
    printf("%d\n",t);
    printf("%d\n",b);
    printf("%d\n",c);
    return 0;
}

void binarySearch(int a[],int size,int search,int *counter1)
{
    int first=0;
    int last=size-1;
    int middle=(first+last)/2;
    while(first<=last)
    {
        *counter1++;
        if(a[middle]<search)
        {
            first=middle+1;
        }
        else if(a[middle]==search)
        {
            printf("%d FOUND AT LOCATION %d.\n",search,middle+1);
            break;
        }
        else
        {
            last=middle-1;
        }
        middle=(first+last)/2;
    }
    if(first>last)
    {
        printf("NOT FOUND.%d IS NOT PRESENTED INT THE LIST.\n",search);
    }
}

int linearSearch(int a[],int size,int search,int *counter2)
{
    int i;
    for(i=0;i<size;i++)
    {
        *counter2++;
        if(a[i]==search)
        {
            return i;
        }
    }
    return -1;
}

int interpolationSearch(int a[],int n,int k,int *counter3)
{
    int low=0,up=n-1,pos;
    while(low<=up)
    {
        *counter3++;
        if((k<a[low])||(k>a[up]))
        {
            return -1;
        }
        pos=low + (int) ((double) (up - low))*(((double) (k - a[low])) / ((double) (a[up] - a[low])));
        if(a[pos]==k)
        {
            return pos;
        }
        else if(a[pos]>k)
        {
            up=pos-1;
        }
        else
        {
            low=pos+1;
        }
    }
    return (-1);
}