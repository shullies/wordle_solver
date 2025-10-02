#include "algo1.h"
using namespace std;
int main(){
  algo1 alg("valid-wordle-words.txt");
  int moves=0;
  std::string output,input;
  cin>>input;
  for(;moves<6;){
    cin>>output;
    alg.remove(input,output);
    input=alg.guess();
    cout << input << endl;
    moves++;
  }
}