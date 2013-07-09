//ans : 162085 comparisons
#include<iostream>
#include<cstdio>
using namespace std;
int sz;
int Partition(int arr[],int lower,int upper){
    int pivot=arr[lower],i=lower+1,j=lower+1;
    for(int j=lower+1;j<=upper;j++){
            if(arr[j]<pivot){
                 int temp=arr[i];
                 arr[i]=arr[j];
                 arr[j]=temp;
                 i++;
            }
    }
    int temp=arr[lower];
    arr[lower]=arr[i-1];
    arr[i-1]=temp;
    /*for(int i=0;i<sz;i++) printf("%d ",arr[i]);
    cout<<endl;
    system("pause");
    */
    return (i-1);//returns partition index or final index of pivot after swap
}
int comp=0;
int QuickSort(int arr[],int lower,int upper){
    if(lower<upper){
            int part=Partition(arr,lower,upper);
            /*cout<<"comps :"<<comp<<endl;
            system("pause");
            */
            comp+=upper-lower;
            QuickSort(arr,lower,part-1);
            QuickSort(arr,part+1,upper);
    }
    return comp;
}
int main()
{
    //scanf("%d",&sz);
    sz = 10000;
    int arr[sz];
    for(int i=0;i<sz;i++) scanf("%d",&arr[i]);
    cout<<"Comparisons :"<<QuickSort(arr,0,sz-1)<<endl;
    //for(int i=0;i<sz;i++) printf("%d ",arr[i]);
    system("pause");
    return 0;
}