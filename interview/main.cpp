#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
ifstream f("intrare.txt");
void afisare(vector<string>vec)
{
    int c=1;
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]==vec[i+1])
            c++;
        else
        {
            if(c==1)
                cout<<"cuvantul "<<vec[i]<<" apare o singura data"<<endl;
            else
            {
                cout<<"cuvantul "<<vec[i]<<" apare de "<<c<<" ori"<<endl;
                c=1;
            }
        }
    }
}
int main()
{
    vector<string> vec;
    char sep[]=" ,.!?;", *cuv;
    char s[1001];
    int k=0;
    f.getline(s,1001); ///citim din fisierul intrare.txt
    cuv=strtok(s,sep); /// cu functia strtok spargem textul in cuvinte
    while(cuv)
    {
        vec.push_back(cuv); ///am folosit STL-uri
        cuv=strtok(NULL,sep);
    }
    sort(vec.begin(),vec.end()); ///sortam cuvintele in ordine alfabetica
    afisare(vec);
    return 0;
}
