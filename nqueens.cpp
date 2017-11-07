#include<iostream>
#include<cmath>
using namespace std;
//function to check solutions
bool ok(int q[],int c){
	for(int i=0;i<c;i++){
		if((q[i]==q[c])||((c-i)==(abs(q[c]-q[i])))){
		return false;
		}
	}
		return true;
}

int main(){
    int queens;
    //ask user for number of queens
    cout<<"Enter the number of queens: ";
    cin>>queens;
    //queen solution code
    //sets the new array size.
    for(int i=1;i<=queens;i++){
        int *q=new int[i];
	    q[0]=1;//set column 0 to have queen in row 1
        int count=-1;//keeps count
	    int c=0;//set column to 0
	    bool from_backtrack=false;
	    while(1){
		    while(c<i){
			    if(!from_backtrack)
				    q[c]=-1;
		    from_backtrack=true;
		    while(q[c]<i){
			    q[c]++;
			    if(q[c]==i){				
				    from_backtrack=true;
				    c--;
                    break;
			    }
			    if(ok(q,c)){//checks if solution is valid
                    from_backtrack=false;
                    c++;
				    break;
			    }
		    }	
	    	if(c==-1)break;
	    }		
        count++;//adds to solution count
		c--;//does what backtrack would do. goes back one column.
		from_backtrack=true;
        if(c<=-1)break;//no more solutions break
	}
    delete []q;//deletes memory in q array
    cout<<"There is/are "<<count<<" solution(s) to the "<<i<<" Queen(s) problem."<<endl; 
}
return 0;
}