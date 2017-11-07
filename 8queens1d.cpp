#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int q[8],c=0,count=0,board[8][8]={0},r;
	q[0]=0;
	NC: 
		c++;
		if(c==8)goto print;
		q[c]=-1;
	NR:
		q[c]++;
		if(q[c]==8)goto backtrack;
		for(int i=0;i<c;i++)
			if((q[i]==q[c])||(c-i==abs(q[c]-q[i])))goto NR;
		goto NC;
	backtrack:
		c--; 
		if(c==-1){
			cout<<"Number of solution: "<<count<<endl;
			return 0;
		}
		goto NR;
	print:
		++count;
		cout<<"solution # "<<count<<":"<<endl;
		for(int c=0;c<8;c++){
			cout<<q[c]<<" ";
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
		goto backtrack;
}
	
