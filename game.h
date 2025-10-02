#include<iostream>
#include<map>
#include<vector>
#include<string>

class game{
	public:
	std::string winner;
	game(std::string win): winner(win){}
	std::string verify(std::string input);
};