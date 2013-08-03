///////////////////////////////////////////////////////////////////////////////
// convolution.h
// =============
// convolution 1D
//
//  AUTHOR: Song Ho Ahn
// CREATED: 2005-07-18
// UPDATED: 2005-09-08
//
// Copyright (c) 2005 Song Ho Ahn
///////////////////////////////////////////////////////////////////////////////

#ifndef CONVOLUTION_H
#define CONVOLUTION_H

// 1D convolution /////////////////////////////////////////////////////////////
// We assume input and kernel signal start from t=0. (The first element of
// kernel and input signal is at t=0)
// it returns false if parameters are not valid.
bool convolve1D(float* in, float* out, int size, float* kernel, int kernelSize);

#endif
