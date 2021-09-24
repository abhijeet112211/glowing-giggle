#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int parent(int i){
    return((i-1)/2);
}
int leftnode(int i){
    return(2*i+1);
}
int rightnode(int i){
    return(2*i+2);
}
void swap(int &x,int &y){
    int temp=x;
      x=y;
    y=temp;
}

void insert(int* arr,int &heap_size,int key,int n){
    if(heap_size==n)
     return;//cout<<"heap array is overflow";

    heap_size++;
    int i=heap_size-1;
    arr[i]=key;
    while(i!=0 && arr[i]<arr[parent(i)]){
        swap(arr[i],arr[parent(i)]);
        i=parent(i);
    }
}

void minheapfy(int* arr,int heap_size,int i){

    int l=leftnode(i);
    int r=rightnode(i);
    int ind;
    if(l>=heap_size && r>=heap_size)
       return;
    if(l<heap_size && r<heap_size){
        arr[l]>arr[r]?ind=r:ind=l;

    }
    else if(l<heap_size){
        ind=l;
    }
    if(arr[i]>arr[small])
     swap(arr[i],arr[small]);
    
    minheapfy(arr,heap_size,ind);
}

void minheapSort(int* arr,int &heap_size){
      vector<int>v;
    while(heap_size >0){
        v.push_back(arr[0]);
        heap_size--;
        arr[0]=arr[heap_size]
        minheapfy(arr,heap_size,0);
    }
    for(int i=0;i<v.size();i++) 
      cout<<v[i]<<" ";
}


int main(){
    int capacity;
    cin>>capacity;
    int *arr=new int[capacity];
    int heap_size=0;
    for(int i=0;i<capacity;i++){
        int key;
        cin>>key;
        insert(arr,heap_size,key,capacity);
    }
    return 0;
}