#include "wordholder.h"
#include <assert.h>

struct PairHash {
  size_t operator()(const std::pair<char,int>& p) const {
    return std::hash<char>()(p.first) ^ (std::hash<int>()(p.second) << 1);
  }
};

class algo1{
  public:
  words possibilities;
  std::unordered_map<char,bool> removed;
  std::unordered_map<char,int> present;
  std::unordered_map<char,bool> ambiguous;
  std::unordered_map<int,char> positions;
  std::unordered_map<std::pair<char,int>, bool, PairHash> absentees;
  algo1(std::string databse);
  void remove(std::string input,std::string output);
  void process1(int count,char a);
  void process2(int j,char a);
  void process3(int count,int j,char a);
  std::string guess();
};

