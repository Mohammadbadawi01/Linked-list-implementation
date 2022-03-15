#pragma once

#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int conf=0;
    int pow=0;
    Node* next=NULL;
};

class Poly
{
private:
    Node* head, * tali;
public:
    Poly();
    Poly(int Coeff_arr[], int Pow_arr[],int size);
    void insert_Node(int c,int p);
    void delete_Node(int w);
    Node *get_head();
    Node *get_tali();
    friend int degree(Poly p);
    double Eval_poly(double x);
    void merge(Poly & parametr);
    void del();
    friend Poly& operator +(Poly& p1, Poly& p2);
    friend istream& operator >>(istream& in,Poly& op);
    friend ostream& operator <<(ostream& out, Poly& o);
    ~Poly();
};