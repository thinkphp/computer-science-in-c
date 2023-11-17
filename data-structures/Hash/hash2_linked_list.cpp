#include <fstream>

using namespace std;

ifstream fin("hashuri.in");
ofstream fout("hashuri.out");

struct nod{
    nod* urm;
    int nr;
};

nod* v[1000000];

int main(){
    int n, op, val;
    fin >> n;
    nod* x,*tmp;

    while(n--)
    {
        fin>>op>>val;
        x=v[val%1000000];
        switch(op){
            case 1:
                tmp=new nod;
                tmp->nr=val;
                tmp->urm=x;
                v[val%1000000]=tmp;
                break;
            case 2:
                if(!x)
                    break;
                if(x->nr==val)
                    v[val%1000000]=x->urm;
                else{
                    while(x->urm&&x->urm->nr!=val)
                        x=x->urm;
                    if(x->urm){
                        tmp=x->urm;
                        x->urm=x->urm->urm;
                        delete tmp;
                    }
                }
                break;
            case 3:
                while(x&&x->nr!=val)
                    x=x->urm;
                if(x)
                    fout << "1" << endl;
                else
                    fout << "0" << endl;
        }
    }

    return 0;
}
