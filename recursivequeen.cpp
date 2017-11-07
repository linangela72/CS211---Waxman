#include<iostream>
#include<cmath>
using namespace std;
bool ok(int q[],int c){
    //row and diagonal test
    for(int i=0;i<c;i++){
        if((q[i]==q[c])||((c-i)==abs(q[i]-q[c]))){
            return false;
        }
    }
    return true;
}
void print(int q[]){
    //prints q[]array and counts
    static int count=0;
    count++;
    cout<<"solution #"<<count<<":"<<endl;
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
}
void move(int q[],int c){
    //if in column 8 print and return
    if(c==8){
        print(q);
        return;
    }
    //places queen
    for(int j=0;j<8;j++){
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