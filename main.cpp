#include "list.hpp"
#include<fstream>
#include<sstream>
#include<ostream>

int main()
{
    LinkedList<Employe> linked;
    ifstream file("funcionarios.txt");
    string line;
    while(getline(file,line)){
        stringstream ss(line);
        string name, cpf, email;

        getline(ss,name,';');
        getline(ss,cpf,';');
        getline(ss,email,';');

        linked.add((Employe(name,cpf,email)));
    }

    cout << linked.getNode(Employe("Rafael Porto","","")) << endl;

   
    return 0;
}
