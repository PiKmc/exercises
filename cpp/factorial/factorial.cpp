// Factorial excercise
// Copyright (C) 2024 by Piotr Kmiecik

#include "factorial.h"

int factorial::getRecursive(const unsigned int n) const
{
        return ((n==0) || (n==1))?1:n*getRecursive(n-1);
}

int factorial::getIterative(const unsigned int n) const
{
        unsigned int ret = n;

        if ((n==0) || (n==1)) 
                return 1;
        
        for (unsigned int i=(n-1);i>0;--i)
                ret *= (n-i);

        return ret;
}
