#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
bool ok(int q[],int c){
	for(int i=0;i<c;i++){
		if((q[c]==q[i])||((c-i)==(abs(q[c]-q[i])))){
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
	//8 queens sollution
	for(int i=0;i<8;i++){
		cout<<q[i]<<" ";
	}
	cout<<endl<<endl;
	//fancy chessboard code
	typedef char box[5][7];
	box bb,wb,wq,bq,*board[8][8];
	//fills in the wb & bb arrays
	for(int r=0;r<5;r++){
		for(int c=0;c<7;c++){
			wb[r][c]=' ';
			bb[r][c]=char(219);
		}
	}
	//fil in array for white queen (wq)
	for(int r=0;r<5;r++){
		for(int c=0;c<7;c++){
			wq[r][c]=' ';
		}
	}
	wq[1][1]=char(219);
	wq[2][1]=char(219);
	wq[3][1]=char(219);
	wq[3][2]=char(219);
	wq[1][3]=char(219);
	wq[2][3]=char(219);
	wq[3][3]=char(219);
	wq[3][4]=char(219);
	wq[1][5]=char(219);
	wq[2][5]=char(219);
	wq[3][5]=char(219);
	//fill in array for black queen (bq)
	for(int r=0;r<5;r++){
		for(int c=0;c<7;c++){
			bq[r][c]=char(219);
		}
	}
	bq[1][1]=' ';
	bq[2][1]=' ';
	bq[3][1]=' ';
	bq[3][2]=' ';
	bq[1][3]=' ';
	bq[2][3]=' ';
	bq[3][3]=' ';
	bq[3][4]=' ';
	bq[1][5]=' ';
	bq[2][5]=' ';
	bq[3][5]=' ';
	//fill board with alternating wb/wq and bb/bq arrays
	for(int r=0;r<8;r++){
		for(int c=0;c<8;c++){
			if((r+c)%2==0){
				if(q[c]==r){
					board[r][c]=&wq;
				}
				else{
					board[r][c]=&wb;
				}
			}
			else{
				if(q[c]==r){
					board[r][c]=&bq;
			}
			else{
				board[r][c]=&bb;
			}
			}
		}
	}
	//start printing board
	//upper boarder
	cout<<" ";
	for(int i=0;i<7*8;i++){
		cout<<'_';
	}
	cout<<endl;
	//board
	for(int r=0;r<8;r++){
		for(int i=0;i<5;i++){
			//left boarder
			cout<<" "<<char(179);
	for(int c=0;c<8;c++){
		for(int j=0;j<7;j++){
			cout<<(*board[r][c])[i][j];
		}
	}
			cout<<char(179)<<endl;
		}
	}
	//lower boarder
	cout<<" ";
	for(int i=0;i<7*8;i++){
		cout<<char(169);
	}
	cout<<endl<<endl;
	//end of fancy chessboard
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

