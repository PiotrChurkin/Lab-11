#include <iostream>
#include "func.hpp"



int main()
{
    mf::Node* sent = new mf::Node;
    sent->left = sent;
    sent->right = sent;

    mf::AddBack(sent, 11);
    mf::AddBack(sent, 44);
    mf::AddBack(sent, 550);

    if(mf::IsSetOrdered(sent))
    {
        mf::DeletePrimeElements(sent);
        mf::DuplicateElementsWichMultiple10(sent);
    }
    else
        mf::SwapOnFirstDigit(sent);


    mf::PrintList(sent);


    mf::DeleteAll(sent);
    delete sent;
    return 0;
}



