#include<iostream>
using namespace std;
int main(){
	int b[8][8]={0},r,c=0,count=0;
	b[0][0]=1;
	NC:
		c++;
		if(c==8) goto print;
		r=-1;
	NR:	
		r++;
		if(r==8)goto backtrack;
	//row test
	for(int i=0;i<c;i++)
		if(b[r][i]==1) goto NR;
	//up diagonal test
	for(int i=1;(r-i)>=0&&(c-i)>=0;i++)	
		if(b[r-i][c-i]==1) goto NR;
	//down diagonal test
	for(int i=1; (r+i)<8 && (c+i)>=0;i++)
		if(b[r+i][c-i]==1)goto NR;
	b[r][c]=1;
	goto NC;

	backtrack: 
		c--;
		if(c==-1){
			cout<<"Number of solutions: "<<count<<endl;
			return 0;
		}
		r=0;
	while(b[r][c]!=1)r++;
	b[r][c]=0;
	goto NR;
	print: 
		++count;
		cout<<"Solution#"<<count<<":"<<endl;
		for(int r=0;r<8;r++){
			for(int c=0;c<8;c++){
				cout<<b[r][c]<<" ";
		}
		cout<<endl;
		}
		goto backtrack;
}
