#include<iostream> 
using namespace std;
const int rows = 5; 
const int cols = 6;
int cost(int i, int j){ 
    // i is the row, j is the column 
    int weight[rows][cols]={
        {3,4,1,2,8,6},
        {6,1,8,2,7,4},
        {5,9,3,9,9,5},
        {8,4,1,3,2,6},
        {3,7,2,8,6,4}
    };
    static int memo[rows][cols]={
        {3,0,0,0,0,0},
        {6,0,0,0,0,0},
        {5,0,0,0,0,0},
        {8,0,0,0,0,0},
        {3,0,0,0,0,0}
    };
    //base case 
    if(j==0){
        return memo[i][0];
    }
    if(memo[i][j]!=0){
        return memo[i][j];
    }
    // recursive call 
    int left = weight[i][j]+cost(i,j-1);//j-1 to the left 
    int up = weight[i][j]+cost((i+4)%5,j-1);//%5 for the 5 rows
    int down = weight[i][j]+cost((i+1)%5,j-1);//i+1 b/c as you go down row number increase.%5 for the 5 rows.
    // find the value of the shortest path through cell (i,j) 
    int min = left;
    if(up<min){
        min=up;
    }
    if(down<min){
        min=down;
    }
    return memo[i][j]=min; 
}//end of cost function
int main(){
    int ex[rows];
    // get the shortest path out of each cell on the right 
    for( int i=0; i<rows; i++){
        ex[i]=cost(i,cols-1);//col-1 moves col to the right
    }
    // now find the smallest of them 
    int min=ex[0];
    for( int i=0; i<rows; i++){
        if(ex[i]<min){
            min=ex[i];
        }
    }
    cout<<"the sortest path is of length "<<min<<endl; 
return 0;
}