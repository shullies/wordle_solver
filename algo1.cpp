#include "algo1.h"
algo1::algo1(std::string databse): possibilities(databse){
  for(char i='a';i-'a'<26;i++){
    ambiguous[i]=true;
    present[i]=0;
    removed[i]=false;
  }
  assert(possibilities.wordvec.size()!=0);
  int size=possibilities.wordvec[0].size();
  for(int i=0;i<size;i++){
    positions[i]='\0';
    for(char j='a';j-'a'<26;j++){
      absentees[std::make_pair(j,i)]=false;
    }
  }
}
void algo1::remove(std::string input,std::string output){
  for(int i=0;i<output.size();i++){
    if(output[i]=='-') {
      int count=0;
      for(int j=0;j<input.size();j++){
        if(input[i]==input[j] && output[j]!='-'){
          count++;
        }
      }        
      process1(count,input[i]);
      }
    else if(output[i]=='*') process2(i,input[i]);
    else if(output[i]=='$'){
      int count=0;
      for(int j=0;j<input.size();j++){
        if(input[i]==input[j] && output[j]!='-'){
          count++;
        }
      }
      process3(count,i,input[i]);
    }
  }
}
  //This processes the set of words incase letter is confirmed to not exist
void algo1::process1(int count,char a){
  std::vector<std::string> vec;
  std::vector<std::string> vec2;
  if(removed[a]==true) return;
  else{
    if(count==0){
      removed[a]=true;
      for(int i=0;i<possibilities.wordvec.size();i++){
        if(possibilities.wordvec[i].find(a)!=std::string::npos){
        }
        else vec.push_back(possibilities.wordvec[i]);
      }
      for(int i=0;i<possibilities.wordvec.size();i++){
        if(possibilities.wordvec[i].find(a)!=std::string::npos){
        }
        else vec.push_back(possibilities.wordvec[i]);
      }
      possibilities.wordvec=vec;
    }
    else{
      for(int i=0;i<possibilities.wordvec.size();i++){
        int counter=0;
        for(int k=0;k<possibilities.wordvec[i].size();k++){
          if(possibilities.wordvec[i][k]==a) counter++;
        }
        if(counter<=count) vec.push_back(possibilities.wordvec[i]);
      }
      possibilities.wordvec=vec;
    }
  }
}
  //This processes the set of words incase letter position is confirmed
void algo1::process2(int j,char a){
  std::vector<std::string> vec;
  if(positions[j]==a) return;
  else{
    positions[j]=a;
    for(int i=0;i<possibilities.wordvec.size();i++){
      if(possibilities.wordvec[i][j]==a) vec.push_back(possibilities.wordvec[i]);
    }
    possibilities.wordvec=vec;
  }
}
  //This processes incase the position is unconfirmed
void algo1::process3(int count,int j,char a){
  if(count>present[a]){
    present[a]=count;
  }
  absentees[std::make_pair(a,j)]=true;
  std::vector<std::string> vec;
  for(int i=0;i<possibilities.wordvec.size();i++){
      if(possibilities.wordvec[i][j]!=a){
        int counter=0;
        for(int k=0;k<possibilities.wordvec[i].size();k++){
          if(possibilities.wordvec[i][k]==a) counter++;
        }
        if(counter>=count) vec.push_back(possibilities.wordvec[i]);
      }
  }
  possibilities.wordvec=vec;
}

std::string algo1::guess(){
  return possibilities.randword();
}
  
