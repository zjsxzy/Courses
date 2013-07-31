//ans : 138382 comparisons
#include<iostream>
#include<cstdio>

using namespace std;
int sz;
int median(int arr[],int x1,int x2,int x3){
    if(arr[x1]>arr[x2]){
        if(arr[x2]>arr[x3]) return x2;
        else{
             if(arr[x3]>arr[x1]) return x1;
             else return x3;
        }
    }
    else{
         if(arr[x1]>arr[x3]) return x1;
         else{
              if(arr[x2]>arr[x3]) return x3;
              else return x2;
         }
    }
}

int Partition(int arr[],int lower,int upper){
    int pivot_index=median(arr,lower,upper,(upper+lower)/2);
    // u made a mistake here. the middle element in the range i to j is not j-i but (i+j)/2. ur mid works fine only when i=0
    /*cout<<pivot_index<<endl;
    system("pause");
    */
    int temp1=arr[lower];
    arr[lower]=arr[pivot_index];
    arr[pivot_index]=temp1;
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