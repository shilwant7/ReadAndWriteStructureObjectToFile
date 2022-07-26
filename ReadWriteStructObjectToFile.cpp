/* Following program will store structure object into file and read   * structure object from file. 
 */

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Emp
{
    int id;
    string name;
};

int main()
{
    ofstream wfile;
    wfile.open("employee.DAT");//input and output
    Emp E[2];
    for(int i=0; i< 2; ++i){
        E[i].id = i;
        E[i].name = "Demo";
        wfile.write((char*)&E[i], sizeof(E[i]));
    }
    wfile.close();

    ifstream rfile("employee.DAT");
    for(int i=0; i< 2; ++i){
        rfile.read((char*)&E[i], sizeof(E[i]));
        cout<<E[i].id<<" "<<E[i].name<<endl;
    }
    rfile.close();

    return 0;
}