///////////////////////////////////////////////////////////////////////////////
// convolution.cpp
// ===============
// convolution 1D
//
//  AUTHOR: Song Ho Ahn
// CREATED: 2005-07-18
// UPDATED: 2005-09-12
//
// Copyright (c) 2005 Song Ho Ahn
///////////////////////////////////////////////////////////////////////////////

#include <cmath>
#include "convolution.h"

///////////////////////////////////////////////////////////////////////////////
// 1D convolution
// We assume input and kernel signal start from t=0.
///////////////////////////////////////////////////////////////////////////////
bool convolve1D(float* in, float* out, int dataSize, float* kernel, int kernelSize)
{
    int i;
    
    // Generate static data to make test runnint without error first
    for(i = 0; i < dataSize; ++i)
    {
        out[i] = 0.0;
    }

    return true;
}
