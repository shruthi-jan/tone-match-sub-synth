//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: lowpass_2.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 17-Nov-2020 17:30:25
//

// Include Files
#include <cmath>
#include "rt_nonfinite.h"
#include "synth.h"
#include "lowpass_2.h"

// Function Definitions

//
// UNTITLED5 Summary of this function goes here
//    Input:
//  x - input vector of ones and zeros (1x 1000)
//  fc - cut off frequency of the low pass filter
//  fs - sampling frequency (44.1KHz)
//  Q - Q factor/peak factor ( controls the height of the resonance)
//  zi - vector to store the previous value of the output (1x2)
// Output:
//  y - output vector of the 2nd order low pass filter (1x1000)
//
// b0, b1,b2, a1, a2 - filter coeffecients
// Arguments    : double x
//                double fc
//                double fs
//                double Q
//                double zi[2]
// Return Type  : double
//
double lowpass_2(double x, double fc, double fs, double Q, double zi[2])
{
  double y;
  double K;
  double prev_xh1;
  double xh;
  K = std::tan(3.1415926535897931 * fc / fs);

  //  K depends on fc
  prev_xh1 = zi[0];
  xh = (x - 2.0 * Q * (K * K - 1.0) / ((K * K * Q + K) + Q) * zi[0]) - ((K * K *
    Q - K) + Q) / ((K * K * Q + K) + Q) * zi[1];
  y = (K * K * Q / ((K * K * Q + K) + Q) * xh + 2.0 * (K * K) * Q / ((K * K * Q
         + K) + Q) * zi[0]) + K * K * Q / ((K * K * Q + K) + Q) * zi[1];
  zi[0] = xh;
  zi[1] = prev_xh1;

  // y = filter([b0 b1 b2],[1 a1 a2],x);
  return y;
}

//
// File trailer for lowpass_2.cpp
//
// [EOF]
//
