#include<iostream>
#include<cmath>
using namespace std;
bool ok(int q[],int c){
    //preference test
    //man preference & women preference array
	int mp[3][3]={{0,2,1},{0,2,1},{1,2,0}};
	int wp[3][3]={{2,1,0},{0,1,2},{2,0,1}};
	//test
	//if women is already assigned return false
    for(int i=0;i<c;i++){
        if(q[i]==q[c])return false;
		//if cm prefers nw more than cm && nw prefers cm than nm = false
    	if((mp[i][q[c]]<mp[i][q[i]])&&(wp[q[c]][i]<wp[q[c]][c]))return false;
		//if nm prefers cw more than nw && cw prefers nm than cm = false
    	if((mp[c][q[i]]<mp[c][q[c]])&&(wp[q[i]][c]<wp[q[i]][i]))return false;
	}
	//otherwise true
	return true;
	}
void print(int q[]){
    //prints couple match and count
    static int count=0;
    count++;
    cout<<"solution #"<<count<<":"<<endl;
    cout<<"Man Women"<<endl;
    for(int i=0;i<3;i++){
        cout<<" "<<i<<"    "<<q[i]<<endl;
    }
    cout<<endl;
}
void move(int q[],int c){
    //if in column 3 print and return
    if(c==3){
        print(q);
        return;
    }
    //places couples
    for(int j=0;j<3;j++){
        q[c]=j;
        //test
        if(ok(q,c)){
            //if ok goto next column
            move(q,c+1);
        }
    }
    //no other possibilities return
    return;
}
int main(){
    int q[8];
    move(q,0);
}