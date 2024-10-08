#include<iostream>
using namespace std;
int main(){
    int x=121;
    int y=x;

    if (x < 0 || (x % 10 == 0 && x != 0)) {
        cout << "false";
    }

    int digit,ans=0,place=10;
    for(int i=0; x!=0; i++){
        digit=x%10;
        ans=(ans*place)+digit;
        // to reverse number
        x=x/10; 
    }

    cout<<ans<<endl;
    if(ans==y){
        cout<<"true";
    }  
    else{
        cout<<"false";
    }  

    return 0;
}