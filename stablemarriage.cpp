#include<iostream>
#include<cmath>
using namespace std;
bool ok(int q[],int c){
	//man preference & women preference array
	int mp[3][3]={{0,2,1},{0,2,1},{1,2,0}};
	int wp[3][3]={{2,1,0},{0,1,2},{2,0,1}};
	//test
	//if women is already assigned return false
    for(int i=0;i<c;i++){
        if(q[c]==q[i])return false;
		//if cm prefers nw more than cm && nw prefers cm than nm = false
    	if((mp[i][q[c]]<mp[i][q[i]])&&(wp[q[c]][i]<wp[q[c]][c]))return false;
		//if nm prefers cw more than nw && cw prefers nm than cm = false
    	if((mp[c][q[i]]<mp[c][q[c]])&&(wp[q[i]][c]<wp[q[i]][i]))return false;
	}
	//otherwise true
	return true;
}
void backtrack(int &c){
	c--;
	if(c==-1)exit(1);
}
void print(int q[]){
	//prints couple match and count
	static int count=0;
 	count++;
    cout<<"solution#"<<count<<":"<<endl;
    cout<<"Man Women"<<endl;
    for(int i=0;i<3;i++){
        cout<<" "<<i<<"    "<<q[i]<<endl;
    }
	cout<<endl;
}
int main(){
	int c=0, q[3];
	q[0]=0;
	bool from_backtrack=false;
	while(1){
		while(c<3){
			if(!from_backtrack)
				q[c]=-1;
		from_backtrack=false;
		while(q[c]<3){
			q[c]++;
			while(q[c]==3){					
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
	return 0;
}

