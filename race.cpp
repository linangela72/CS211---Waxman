#include <iostream> 
#include<algorithm> 
#include<cstdlib> 
#include<cstring> 
using namespace std;
bool valid(string race){
    


}
int main(){
    string race,teams;
    cout<<"Please enter the results of the race: "; 
    cin>>race;
    // Check that the race is valid, and each team has the same number of members. 
    //Write a function bool valid(string race). Do the input in a loop.
    teams=get_teams(race); 
    // teams in sorted order 
    cout<<"\nThere are "<<teams.length()<<" teams."<<endl<<endl;
    cout<<"Each team has "<<race.length()/teams.length()<<" runners."<<endl<<endl; 
    //teams and scores
    cout<<'\t'<<"Team"<<'\t'<<"Score"<<endl<<endl;
    double min_score=score(race,teams[0]); 
    for(char c:teams){
        double s=score(race,c); cout<<'\t'<<c<<'\t'<<score(race,c)<<endl; 
        if(s<min_score)
            min_score=s; 
    }
    cout<<endl<<"min score= "<<min_score<<endl;
    //system("pause"); 
}