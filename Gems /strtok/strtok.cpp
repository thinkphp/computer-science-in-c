/*
  string = "Hello, world! This is an example."

  Output: Salut
          lume
          Acesta
          este
          un
          exemplu
*/
#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

string translateintoRomanian(const string& token) {

       unordered_map<string, string> dictinary = {

                 {"Hello","Salut"},
                 {"world", "lume"},
                 {"This","acesta"},
                 {"is","este"},
                 {"an","un"},
                 {"string","sir"}
       };

       auto it = dictinary.find(token);

       if(it!=dictinary.end()) {

           return it->second;//returneaza cuvantul tradus

       } else {

          return token;//daca nu este gasita o traducere va return tokenul original
       }

}

int main(int argc, char const *argv[]) {


  //input string
  char str[] = "Hello, world! This is an example.";

  //delimitatori
  const char* delimitatori = " ,.!";

  char *token = strtok(str, delimitatori);

  while(token != nullptr) {

        string tokenStr(token);

        string transledToken = translateintoRomanian(tokenStr);

        cout<<transledToken<<" ";

        token = strtok(nullptr, delimitatori);
  }

  return 0;
}
