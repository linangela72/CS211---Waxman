#include<iostream>
#include<cmath>
using namespace std;
bool ok(int q[],int c, int n){
    //diagonal test
    for (int i=0; i<c; i++){
       //(q[i]/n=row)(q[i]%n=column)
       if(((q[i]/n)+(q[i]%n))==((q[c]/n)+(q[c]%n)))return false;
       if(((q[i]/n)-(q[i]%n))==((q[c]/n)-(q[c]%n))) return false;
    }
    return true;
}
int factorial(int n){
    if (n==1) return n;
    return n*factorial(n-1);
}
void backtrack(int &c, int q[], int count, int n, int k){
	c--;
	if(c==-1){
        cout<<"bishops: "<<k<<"\n board: "<<n<<"\n solutions: "<<count/factorial(k)<<endl;
        delete []q;
        exit(1);
    }
}

int main(){
    int k,n;
    //ask user for number of bishops
    cout<<"Enter the number of bishops: ";
    cin>>k;//k=bishop
    cout<<"Enter the size of your nxn board: ";
    cin>>n;
    while(n<k){
        cout<<"sorry, please enter a number bigger than the number of bishops: ";
        cin>>n;
    }
    //bishop solution code
    //sets the new array size.
        int *q=new int[k];
	    q[0]=0;//q[c]=where the bishop is on the board
        int count=0;//keeps count
	    int c=0;//c=which # bishop
    bool from_backtrack=false;
	while(1){
		while(c<k){
			if(!from_backtrack)
				q[c]=-1;
		from_backtrack=false;
		while(q[c]<n*n){//n*n because there are n*n spaces(boxes)on the board
			q[c]++;
			while(q[c]==n*n){					
				backtrack(c,q,count,n,k);
				q[c]++;
			}
			if(ok(q,c,n)){
                c++;//next bishop
				break;
			}
		}	
	}	
        count++;
		backtrack(c,q,count,n,k);
		from_backtrack=true;
	}
    return 0;
}

