#include <iostream>
using namespace std;
void push_back(int *&arr,int &size,const int value){
     int* newarr=new int(size+1);
     for(int i=0;i<size;i++){
         newarr[i]=arr[i];
     }
     newarr[size]=value;
     delete [] arr;
     arr=newarr;
     size++;
}
void pop_back(int*&arr,int&size){
    size=size-1;
    int * newarr=new int(size);
    for(int i =0; i<size;i++){
        newarr[i]=arr[i];
    }
    delete [] arr;
    arr=newarr; 
}

int main()
{
    int size=5;
    int* arr=new int(size);
    cout<<"last"<<endl;
    for(int i=0;i<size;i++){
        arr[i]=i+1;
        cout<<arr[i]<<"\t";
    }
    push_back(arr,size,15);
    cout<<endl<<"new"<<endl;
    for(int j=0;j<size;j++){
        cout<<arr[j]<<"\t";
    }
    pop_back(arr,size);
    for(int j=0;j<size;j++){
        cout<<arr[j]<<"\t";
    }
    delete [] arr;
}
