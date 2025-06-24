#pragma once

#include <iostream>
#include<string>

using namespace std;

class Employe{

    private: 
        string name;
        string email;
        string cpf;

     
    public :
        string getName();
        string getEmail();
        string getCpf();

           bool operator<(const Employe &e){
            return this->name < e.name;
        }

        bool operator>(const Employe &e){
            return this->name > e.name;
        }

        bool operator==(const Employe &e){
            return this->name == e.name;
        }

        bool operator!=(const Employe &e){
            return this->name != e.name;
        }

        friend ostream& operator<<(ostream &out, const Employe &emp){
                out << emp.name + ";" + emp.email + ";" + emp.cpf;
                return out;
        }


        Employe(string name, string email, string cpf);
        Employe(){
            name=email=cpf="";      
        };

        ~Employe(){    
        }

};

Employe::Employe(string name, string email, string cpf){
    this->email = email;
    this->name = name;
    this->cpf = cpf;
}

string Employe::getName(){
    return name;
}

string Employe::getEmail(){
    return email;
}

string Employe::getCpf(){
    return cpf;
}