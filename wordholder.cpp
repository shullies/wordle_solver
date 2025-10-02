
#include "wordholder.h"



words::words(std::string filename){
	std::ifstream inputFile(filename);
	if (inputFile.is_open()) { 
		std::string line;
		while (std::getline(inputFile, line)) { // Read line by line
			wordvec.push_back(line); // Process each line (e.g., print to console)
		}
		inputFile.close(); // Close the file
	} else {
		std::cerr << "Error opening file for reading." << std::endl;
	}
}
	
bool words::findword(std::string word){
	auto index=std::find(wordvec.begin(),wordvec.end(),word);
	if(index!=wordvec.end()) return true;
	return false;
}

std::string words::randword(){
    static std::mt19937 rng(std::random_device{}()); // random seed
    std::uniform_int_distribution<size_t> dist(0, wordvec.size() - 1);
	return wordvec[dist(rng)];
}

bool words::deleteind(int i){
	if(i>wordvec.size()-1) return false;
	else{
		wordvec.erase(wordvec.begin()+i);
		return true;
	}
}