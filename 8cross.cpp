#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int b[8]={0},c=0,count=0;
	int a[][5]={{-1,-1,-1,-1,-1},{0,-1,-1,-1,-1},{0,1,-1,-1,-1},{0,2,-1,-1,-1},{1,2,-1,-1,-1},{1,2,3,4,-1},{2,3,5,-1,-1},{4,5,6,-1,-1}};
	b[0]=1;
	NC:
		c++;
		if(c==8)goto print;
		b[c]=0;
	NN:	
		b[c]++;
		if(b[c]==9)goto backtrack;
		//test for repeat number
		for(int a=0;a<c;a++){
			if(b[c]==b[a])goto NN;
		}
		//test adjacent 
		  for(int i=0;a[c][i]!=-1;i++){
			if(abs(b[c]-b[a[c][i]])==1)goto NN;
		}
		goto NC;
	backtrack:
		c--;
		if(c==-1)return 0;
		goto NN;
	print:
		count++;
		cout<<"solution#:"<<count<<endl;
		for(int i=0;i<8;i++){
			cout<<b[i]<<" ";
		}
		cout<<endl<<endl;
		cout<<"  "<<b[1]<<" "<<b[4]<<"   "<<endl;
		cout<<b[0]<<" "<<b[2]<<" "<<b[5]<<" "<<b[7]<<endl;
		cout<<"  "<<b[3]<<" "<<b[6]<<"   "<<endl<<endl;
		goto backtrack;
}
		
	
