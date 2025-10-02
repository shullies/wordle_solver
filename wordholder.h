#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include<random>

class words{
	public:
	std::vector<std::string> wordvec;
	words(std::string filename);
	bool findword(std::string word);
	std::string randword();
	bool deleteind(int i);
};