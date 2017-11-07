#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
bool ok(int q[],int c){
	for(int i=0;i<c;i++){
		if((q[i]==q[c])||((c-i)==(abs(q[c]-q[i])))){
		return false;
		}
	}
		return true;
}
void backtrack(int &c){
	c--;
	if(c==-1)exit(1);
}
void print(int q[]){
	static int count=0;
 	count++;
	cout<<"solution# "<<count<<":"<<endl;
	for(int i=0;i<8;i++){
		cout<<q[i]<<" ";
	}
	cout<<endl<<endl;
	for(int r=0;r<8;r++){
		for(int c=0;c<8;c++){
			if(q[c]==r)cout<<"1 ";
			else cout<<"0 ";
		}
	cout<<endl;
	}
	cout<<endl;
	
}
int main(){
	//code to find queens
	int q[8];
	q[0]=0;
	int c=1;
	bool from_backtrack=false;
	while(1){
		while(c<8){
			if(!from_backtrack)
				q[c]=-1;
		from_backtrack=false;
		while(q[c]<8){
			q[c]++;
			while(q[c]==8){					
				backtrack(c);
				q[c]++;
			}
			if(ok(q,c)){
				break;
			}
		}	
		c++;
		}		
		print(q);
		backtrack(c);
		from_backtrack=true;
	}
}


