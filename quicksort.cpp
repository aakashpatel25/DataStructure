#include<iostream>
#include<vector>
using namespace std;

void printArr(vector<int> & arr){
	for(int i=0;i<arr.size();i++){
		cout<<arr.at(i)<<" ";
	}
	cout<<endl;
}

void quickSort(vector<int> & arr,int start, int end){
	if(end-start>=1){
	    int pivot = arr.at(end), forward=start,backward=end-1;
    	while(forward<backward){
    		while(arr.at(forward)<=pivot && forward<=backward && forward<end){
    			forward++;
    		}
    		while(arr.at(backward)>=pivot && forward<backward && backward>start){
    			backward--;
    		}
    	    if(forward<end){
            	int temp=arr.at(forward);
            	arr.at(forward)=arr.at(backward);
            	arr.at(backward)=temp;
    	    }
    	}
        if(pivot<arr.at(forward)){
            int temp=arr.at(forward);
            arr.at(forward)=pivot;
            arr.at(end)=temp;
        }
    	printArr(arr);
    	quickSort(arr,start,forward-1);
    	quickSort(arr,forward+1,end);
	}
}

int main(){
	int t,temp;
	vector<int> arr;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>temp;
		arr.push_back(temp);
	}
	
	quickSort(arr,0,t-1);
	return 0;
}