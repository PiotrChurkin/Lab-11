#pragma once



namespace mf
{
    
    struct Node
    {
    int data;
    Node* right;
    Node* left;
    };

    void AddBack(Node* sent, int data);
    void PrintList(Node* sent);
    void DeleteAll(Node* sent);
    bool IsPrimeElement(Node* sent);
    void DeletePrimeElements(Node* sent);
    bool IsSetOrdered(Node* sent);
    void DuplicateElementsWichMultiple10(Node* sent);
    unsigned short FirstDigit(Node* sent);
    void SwapOnFirstDigit(Node* sent);
}