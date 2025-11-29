#pragma once
#include <iostream>

class Node{
    public:
    int info;
    std::string date;
    std::string doctor;
    Node* next;
    Node(int info , std::string date, std::string doctor){
        this->info=info;
        this->date=date;
        this->doctor=doctor;
        this->next=nullptr;
    }
};

class HistoryList {
    public:
    Node* head , *tail;
    HistoryList(){
        head=tail=nullptr;
    }

    // insert to List
    void visit(int val, std::string date, std::string doctor){
        Node* temp=new Node(val, date, doctor);
        if(head==nullptr){
            head=tail=temp;
            return;
        }
        tail->next=temp;
        tail=temp;
    }

    // print history (all node infos)
    void print(){
        if(head==nullptr){
            std::cout<<"No history to print!"<<std::endl;
            return;
        }
        Node* temp=head;
        while(temp!=nullptr){
            std::cout<<"Visit ID : "<<temp->info
            <<" , Date : "<<temp->date
            <<" , Doctor : "<<temp->doctor<<std::endl;
            temp=temp->next;
        }

    }

    // destructor 
    ~HistoryList(){
        Node* temp=head;
        while(temp!=nullptr){
            Node*next=temp->next;
            delete temp;
            temp=next;
        }
    }

};

