#include <iostream>
#include "func.hpp"

struct Node
{
    int data;
    Node* right;
    Node* left;
};

namespace mf
{

void AddBack(Node* sent, int data)
{
    Node* p = new Node;

    p->data = data;
    p->left = sent->left;
    p->right = sent;
    sent->left->right = p;
    sent->left = p;
}

void PrintList(Node* sent)
{
    Node* p = sent->right;
    while(p!=sent)
    {
        std::cout << p->data << "\t";
        p = p->right;
    }
}

void DeleteAll(Node* sent)
{
    Node* p = sent->right;
    while(p!=sent)
    {
        Node* tmp = p;
        p = p->right;
        delete tmp;
    }
}

bool IsSetOrdered(Node* sent)
{
    Node* p = sent->right;
    if(p == sent || p->right == sent)
        return false;

    int i = 0;
    int fromMINtoMAX = 0;
    int fromMAXtoMIN = 0;

    while(p->right!=sent)
    {
        if(p->data <= p->right->data)
            fromMINtoMAX+=1;
        if(p->data >= p->right->data)
            fromMAXtoMIN+=1;

        i++;
        p = p->right;
    }

    if((fromMAXtoMIN==i) || (fromMINtoMAX==i))
        return true;

    return false;
}

void DeletePrimeElements(Node* sent)
{
    Node* p = sent->right;
    while(p!=sent)
    {
        if(IsPrimeElement(p))
        {
            Node* tmp = p;
            p->right->left = p->left;
            p->left->right = p->right;
            p = p->right;
            delete tmp;
        }
        else
            p = p->right;
    }
}

bool IsPrimeElement(Node* sent)
{
    if(sent->data == 1)
        return true;
    
    for(unsigned short i = 2; i < sqrt(sent->data); i++)
    {
        if((sent->data)%i==0)
            return false;
    }
    return true;
}

void DuplicateElementsWichMultiple10(Node* sent)
{
    Node* p = sent->right;
    if(p==sent)
        return;
    
    while(p!=sent)
    {
        if((p->data)%10 == 0)
        {
            Node* tmp = new Node;
            tmp->data = p->data;

            tmp->right = p->right;
            tmp->right->left = tmp;
            p->right = tmp;
            tmp->left = p;
        

            p = p->right->right;
        }
        else
            p = p->right;
    }
}

void SwapOnFirstDigit(Node* sent)
{
    Node* p = sent->right;
    Node* t;
    int tmp = 0;

    while(p->right!=sent)
    {
        t = p->right;
        while(t!=sent)
        {
            if(FirstDigit(p) > FirstDigit(t))
            {
                tmp = p->data;
                p->data = t->data;
                t->data = tmp;
            }
            t = t->right;
        }
        p = p->right;
    }
}

unsigned short FirstDigit(Node* sent)
{
    int p = abs(sent->data);
    unsigned short digit = 0;
    while(p!=0)
    {
        digit = p%10;
        p = p/10;
    }
    return digit;
}

}