#include "game.h"
#include "algo1.cpp"
#include<iostream>

using namespace std;

int main(){
	words vec("valid-wordle-words.txt");
	std::string word=vec.randword();
	std::string worder,checked;
	bool checker=true;
	game gamer(word);
	int moves=0;
	for(;moves<6;){
		cin>>worder;
		if(worder.size()!=word.size() || !vec.findword(worder)){
			cout << "invalid input" << endl;
			continue;
		}
		checked=gamer.verify(worder);
		cout << checked << endl;
		checker=true;
		for(int i=0;i<checked.size();i++){
			if(checked[i]!='*') checker=false;
		}
		if(checker){
			cout << "winning string" << endl;
			return 0;
		}
		moves+=1;
	}
	cout << "better luck next time" << endl;
	cout << "word was " << word;
}