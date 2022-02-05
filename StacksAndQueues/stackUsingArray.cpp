#include<iostream>
using namespace std;

template <typename T>
class stack
{
private:
	T *arr;
	int size;
	int capacity;
	
public:
	stack(int n){
		arr = new T [n];
		capacity=n;
		size=0;
	}
	 void insert(T x)	{
	 	if(size!=capacity){
	 		arr[size++]=x;
	 	}else{
	 		cout<<"stack is full"<<endl;
	 	}
	 }
	 T top(){
	 	if(isEmpty()){
	 		cout<<"stack is empty"<<endl;
	 		return -1;
	 	}else{
	 		T k=arr[size-1];
	 		return k;
	 	}
	 }
	 bool isEmpty(){
	 	return size==0;
	 }
	 T pop(){
	 	if(isEmpty()){
	 		return -1;
	 	}
	 	T k=arr[size-1];
	 	size--;
	 	return k;
	 }
	 int Size(){
	 	
	 	return size;
	 }
};

int main(){
	stack<int> s1(3);
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);
	s1.insert(5);
	s1.pop();
	s1.pop();
	cout<<s1.top()<<endl;
	cout<<s1.Size()<<endl;
	cout<<s1.isEmpty()<<endl;
	s1.pop();
}