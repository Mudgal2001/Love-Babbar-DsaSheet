#include<bits/stdc++.h>
using namespace std;

class minHeap{
	vector<int>v;
public:
	int size(){
		return v.size();
	}
	bool empty(){
	 	return v.size()==0;
	 }
	 
	 int getMin(){
	 	if(v.size()==0){
	 		return -1;
	 	}
	 	return v[0];
	 }
	void insert(int x){
		v.push_back(x);
		int ci=v.size()-1;
		while(ci>0){
			int pi = (ci-1)/2;
			if(v[pi]>v[ci]){
				swap(v[pi],v[ci]);
				ci=pi;
			}else{
				break;
			}
		}
	}
	
	int RemoveMin(){
		if(v.size()==0){
			return -1;
		}
		int x=v[0];
		int n=v.size();
		swap(v[0],v[n-1]);
		v.pop_back();
		int pi=0;
		int ci=1;
		int ci1=1;
		int ci2=2;
		
		while(ci1<n-1){
			int m = v[pi];
			if(m>v[ci1]){
				m=v[ci1];
				ci=ci1;
			}
			if(m>v[ci2] && ci2<n-1){
				m=v[ci2];
				ci=ci2;
			}
			if(m==v[pi]){
				break;
			}
			swap(v[pi],v[ci]);
			pi = ci;
			ci1=pi*2+1;
			ci2=pi*2+2;
			
		}
		return x;
	}
	
};

int main(){
	minHeap pq;
	pq.insert(23);
	pq.insert(25);
	pq.insert(19);
	pq.insert(18);
	pq.insert(14);
	pq.insert(10);
	cout<<pq.getMin()<<endl;
	cout<<pq.size()<<endl;
	cout<<pq.RemoveMin()<<endl;
	cout<<pq.RemoveMin()<<endl;
	cout<<pq.RemoveMin()<<endl;
	cout<<pq.RemoveMin()<<endl;
	cout<<pq.RemoveMin()<<endl;
	cout<<pq.RemoveMin()<<endl;
	cout<<pq.RemoveMin()<<endl;
	
}