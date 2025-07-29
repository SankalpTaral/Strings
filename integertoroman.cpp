#include<iostream>
#include<string>
using namespace std;
string conversion(int num){
     // Step 1 ->  ill Map all roman number  to values 
     // Tricky Part- Subtraction Form
     // dont forget to abb subtracational form values like 4 9 90 400 900 like this

     // values mapped from larger to smaller because of roman rule

     // it should be string array ha roman cauz ur containing strings in it
     // we cannont make cahr cauz storing multiple chars in one string so
string romanSymbol[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
     int values[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    

     string ans="";
     // Step 2 Algorithm
     //ill iterate 
     for(int i=0;i<13;i++){
        // ill come from largest to smallest here 
        while(num>=values[i]){  
            ans+=romanSymbol[i]; // ill add that to answer
            num=num-values[i]; // check for next number 
        }
     }
     return ans;


}
int main(){
int num=3749;
// convert it to roman number
string ans=conversion(num);
cout <<"CONVERTED INTEGER TO ROMAN NUMBER: " <<  ans << endl;
 
}