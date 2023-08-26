#include <bits/stdc++.h>
#define FIN "spectacole.in"
#define FOUT "spectacole.out"
#include <vector>
#include <algorithm>

typedef struct {
    int start,
        end;
} Interval;

bool cmp(Interval I1, Interval I2) {
     return I2.end > I1.end;
}

int main(int argc, char const *argv[]) {

    int n, x, y;
    Interval I;
    std::vector<Interval> spectacles;

    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);

    std::cin>>n;
    for(int i = 0; i < n; ++i) {
        std::cin>>x>>y;
        I.start = x;
        I.end = y;
        spectacles.push_back(I);
    }

    for(auto x: spectacles) {

        std::cout<<x.start<<" "<<x.end<<std::endl;
    }

    //std::cout<<std::endl;

    sort(spectacles.begin(), spectacles.end(), cmp);

    for(std::vector<Interval>::iterator it = spectacles.begin(); it!=spectacles.end(); ++it)

        std::cout<< (*it).start<<" "<<(*it).end<<"\n";

    int curr = spectacles[0].end;

    int i = 1;

    int count = 1;

    while (i < n){

        if(spectacles[i].start >= curr) {

            curr = spectacles[i].end;

            count++;
        }
      i++;}

    std::cout<<count;

  return 0;
}
