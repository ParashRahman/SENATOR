#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cstdlib>

class TITLEGenerator {
private:
  std::vector<std::string> Words_txt = {
    "hi",
    "my",
    "name",
    "is",
    "parash",
    "rahman",
    "and",
    "im",
    "here",
    "to",
    "say",
    "all",
    "you",
    "people",
    "are",
    "super",
    "cool",
  };
  
public:
  TITLEGenerator() {
    int seed = time(NULL);
    srand(seed);
  }
  std::string sentence(int complexity) {
    int NUM_RULES = 1;

    int random_choice = rand() % NUM_RULES;
    
    if (complexity <= 0) {
      std::string p1 = word(complexity - 1);
      std::string p2 = word(complexity - 1);
      
      std::string ret = p1 + " " + p2;
      return ret;
    }
    else if (random_choice == 0) {
      std::string p1 = word(complexity - 1);
      std::string p2 = word(complexity - 1);
      
      std::string ret = p1 + " " + p2;
      return ret;
    }
    
    printf("ERRAR SENTENCE\n");
    exit(1);
  }

  std::string word(int complexity) {
    int NUM_RULES = 2;
    
    int random_choice = rand() % NUM_RULES;
    
    if (complexity <= 0) {
      // base case goes here
      
      int dex = rand() % Words_txt.size();

      std::string ret = Words_txt[dex];
      return ret;
    }
    else if (random_choice == 0) {
      int dex = rand() % Words_txt.size();

      std::string ret = Words_txt[dex];
      return ret;
    }
    else if (random_choice == 1) {
      std::string p1 = word(complexity - 1);
      std::string p2 = word(complexity - 1);

      std::string ret = p1 + " " + p2;
      return ret;
    }

    printf("ERRAR WORD\n");
    exit(1);
  }
};

int main() {
  TITLEGenerator tG;
  
  std::cout << tG.sentence(3) << std::endl;
}

