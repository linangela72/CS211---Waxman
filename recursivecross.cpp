#include<iostream>
#include<cmath>
using namespace std;
bool ok(int b[],int c){
    //helper array
    int a[][5]={{-1,-1,-1,-1,-1},{0,-1,-1,-1,-1},{0,1,-1,-1,-1},{0,2,-1,-1,-1},{1,2,-1,-1,-1},{1,2,3,4,-1},{2,3,5,-1,-1},{4,5,6,-1,-1}};
    //run test
    //test for repeat numbers
    for(int a=0;a<c;a++){
			if(b[c]==b[a])return false;
    }
    //test adjacent numbers
    for(int i=0;a[c][i]!=-1;i++){
			if(abs(b[c]-b[a[c][i]])==1)return false;
    }
    return true;
}
void print(int b[]){
    static int count=0;
    count++;
    cout<<"solution#"<<count<<":"<<endl;
    for(int i=0;i<8;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl<<endl;
    //place numbers in correct position
    cout<<"  "<<b[1]<<" "<<b[4]<<"  "<<endl;
    cout<<b[0]<<" "<<b[2]<<" "<<b[5]<<" "<<b[7]<<endl;
    cout<<"  "<<b[3]<<" "<<b[6]<<" "<<endl;
}
void move(int b[],int c){
    //if in column 8 print solution
    if(c==8){
        print(b);
        return;
    }
    //place numbers
    for(int n=1;n<=8;n++){
        b[c]=n;
    //test
        if(ok(b,c)){
            //if ok goto next column
            move(b,c+1);
        }
    }
    //if no more solution
    return;
}
int main(){
    int b[8];
    move(b,0);
}