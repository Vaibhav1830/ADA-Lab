#include <stdio.h>
#include <time.h>
void merge_sort(int[],int,int);
void simple_sort(int[],int,int,int);
void main(){
int a[100];
int n;
double start,end,time;
printf("Enter array size: ");
scanf("%d",&n);
for (int i=0;i<n;i++){
    printf("Print value at index %d: ",i);
    scanf("%d",&a[i]);
}
start=clock();
merge_sort(a,0,n-1);
end=clock();
time=(double)(end-start)/CLOCKS_PER_SEC;

printf("Sorted Array:\n");
for (int i=0;i<n;i++)
    printf("%d ",a[i]);

printf("\nTime taken to sort is %lf",time);
}

void merge_sort(int a[],int low,int high){
if (low<high){
    int mid=(low+high)/2;
    merge_sort(a,low,mid);
    merge_sort(a,mid+1,high);
    simple_sort(a,low,mid,high);
    }
}

void simple_sort(int a[],int low,int mid,int high){
int i=low,j=mid+1,k=low;
int c[100];
while (i<=mid && j<=high){
    if (a[i]<a[j]){
        c[k++]=a[i];
        i++;
    }
    else {
        c[k++]=a[j];
        j++;
    }
}
while (i<=mid){
    c[k++]=a[i];
    i++;
}
while (j<=high){
    c[k++]=a[j];
    j++;
}
for (i=low;i<=high;i++)
    a[i]=c[i];
}
