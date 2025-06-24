#pragma once
#include<iostream>
#include "employe.hpp"
#include<vector>
using namespace std;

template<typename T>
class Node{
    private:
        T value;
    public:
        Node * node;
        T getValue() {
            return value;
        }
        Node(T value){
            this->value = value;
            this->node = nullptr;
        }
        ~Node(){};
};


template<typename T>
class LinkedList{
    private:
        Node<T> * startList;

    public:
        void add(T value);
        bool remove(T value);
        T getValue(T key);
        vector<T> getAllValues();
        void printAll();
        LinkedList();
        ~LinkedList();
};

template<typename T>
LinkedList<T>::LinkedList(){
    startList = nullptr;
}

template<typename T>
void LinkedList<T>::add(T value){

    if(startList == nullptr){
        startList = new Node<T>(value);
    }else if(startList->node == nullptr){
        startList->node = new Node<T>(value);
    }else{
        Node<T> * lastValue = startList;
        
        while(lastValue->node != nullptr){
            lastValue = lastValue->node;
        }

        lastValue->node = new Node<T>(value);
    }
}

template<typename T>
bool LinkedList<T>::remove(T value){
    Node<T> * lastValue = startList;

    if(lastValue->getValue() == value){
            Node<T> * temp = lastValue;
            startList = startList->node;
            delete temp;
            return true;
    }

    while(lastValue->node != nullptr){

        if(lastValue->node->getValue() == value){
            Node<T> * temp = lastValue->node;
            lastValue->node = lastValue->node->node;
            delete temp;
            return true;
        }

        lastValue = lastValue->node;
    }
    
    return false;
    
}

template<typename T>
T LinkedList<T>::getValue(T key){
    Node<T> * lastValue = startList;

    if(lastValue->getValue() == key){
          return startList->getValue();
    }

    while(lastValue->node != nullptr){

        if(lastValue->node->getValue() == key){
            return lastValue->node->getValue();
        }

        lastValue = lastValue->node;
    }

    return T();

}

template<typename T>
void LinkedList<T>::printAll(){   
    if(startList == nullptr){
        cout << "VALUE NOT FOUND!" << endl;
    }else{
        Node<T> * lastValue = startList;

        while(lastValue != nullptr){
            cout << "Value : " << lastValue->getValue() << endl;
            lastValue = lastValue->node;
        }
        
    }
}

template<typename T>
vector<T> LinkedList<T>::getAllValues(){
    vector<Node<T>*> values;

    Node<T> * lastValue = startList;

    while(lastValue != nullptr){
        values.push_back(lastValue->getValue());
        lastValue = lastValue->node;
    }
    return values;
}

template<typename T>
LinkedList<T>::~LinkedList(){
    Node<T> * lastValue = startList;
    while(lastValue != nullptr){
            Node<T> * temp = lastValue;
            lastValue = lastValue->node;
            delete temp;
    }
    startList = nullptr;
}
