#include <iostream>
#include <vector>
#include <string>

using namespace std;

//multimea de caractere
const vector<char> X = {'a','b','c','1','2','3'};

bool suntAlaturateValidare(char c1, char c2) {

     return (c1 == '1' && (c2 == '2' || c2 == '3')) ||
            (c1 == '2' && (c2 == '1' || c2 == '3')) ||
            (c1 == '3' && (c2 == '1' || c2 == '2'));
}


void genereazaCuvinte(vector<char>&cuvant, int pozitie, vector<bool> &folosit, vector<string>& rezultate) {

              if(pozitie == X.size()) {

                //a1c2b3
                //cuvant[0] = 'a'
                //cuvant[1] = '1'
                //cuvant[2] = 'c'
                //cuvant[3] = '2'
                //cuvant[4] = 'b'
                //cuvant[5] = '3'

                    rezultate.push_back(string( cuvant.begin(), cuvant.end()));

                    return;
              }

              for(int i = 0; i < X.size(); ++i) {

                       if(!folosit[i] && !suntAlaturateValidare(cuvant[ pozitie-1 ], X[ i ]  )) {

                                   cuvant[pozitie] = X[i];

                                   folosit[i] = true;

                                   genereazaCuvinte(cuvant, pozitie + 1, folosit, rezultate);

                                   folosit[i] = false;
                       }
              }
}


int main(int argc, char const *argv[]) {

  //vectorul pentru a stoca cuvantul generat
  vector<char>  cuvant(6);

  //vector pentru a marca daca un caracter este folosit
  vector<bool> folosit(X.size(), false);

  vector<string> rezultate;

  genereazaCuvinte(cuvant, 0, folosit, rezultate);


  cout<<"URmatoarea permutate(cuvant)" << rezultate[2]<<endl;
    cout<<"URmatoarea permutate(cuvant)" << rezultate[3]<<endl;
      cout<<"URmatoarea permutate(cuvant)" << rezultate[4]<<endl;


  return 0;
}
