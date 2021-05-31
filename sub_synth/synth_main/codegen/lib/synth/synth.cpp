//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: synth.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 17-Nov-2020 17:30:25
//

// Include Files
#include <cmath>
#include <math.h>
#include "rt_nonfinite.h"
#include "synth.h"
#include "ADSR_envelope1.h"
#include "lowpass_2.h"
#include "rand.h"
#include "synth_emxutil.h"
#include "rdivide.h"
#include "abs.h"

// Function Declarations
static double rt_powd_snf(double u0, double u1);
static double rt_roundd_snf(double u);

// Function Definitions

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_powd_snf(double u0, double u1)
{
  double y;
  double d0;
  double d1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    d0 = std::abs(u0);
    d1 = std::abs(u1);
    if (rtIsInf(u1)) {
      if (d0 == 1.0) {
        y = 1.0;
      } else if (d0 > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = rtNaN;
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

//
// Arguments    : double u
// Return Type  : double
//
static double rt_roundd_snf(double u)
{
  double y;
  if (std::abs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = std::floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = std::ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

//
// function [y,y1,y2,fc,zi,amp1,amp2,amp2_db,amp2_r] = synth(note,fs,f0,Q,wf,N,zi,a1,d1,s1,r1,a2,d2,s2,r2,fa)
// UNTITLED4 Summary of this function goes here
//    Detailed explanation goes here
//  add amp2_db , amp2_r, y1 - when memory optimization code not used
//
//  fc = zeros(N,1);
//  y = zeros(N,1);
//  y1 = zeros(N,1); %m
//  y2 = zeros(N,1); %m
//
//  amp1 = zeros(1,length(note));
//  amp2 = zeros(1,length(note));
//  amp2_db = zeros(N,1);
//  amp2_r = zeros(N,1);
//
//
//
//  for i = 1: N
//      [amp1(i),zi(1,:)] = ADSR_envelope1(a1,d1,s1,r1,note(i),fs,zi(1,:));
//      [y(i),zi(2:4,:)] = multi_OSC(f0,fs,1,wf,zi(2:4,:)); % output of the oscillator which takes the f0 ( fundamental frequency) from the note and the waveform. This is then ghiven to the LPF.
//      fc(i) = fa*(amp1(i)*(19980))+ 20;  % To calculate fc at each sample of the note, which is given to the filter for shaping the signal.
//      [y1(i), zi(5,:)] = lowpass_2(y(i),fc(i),fs ,Q,zi(5,:));% output of the VCF after modulation with ADSR envelope 1
//      [amp2(i),zi(6,:)] = ADSR_envelope1(a2,d2,s2,r2,note(i),fs,zi(6,:));
//      amp2_db(i) = amp2(i)*80 -80; % amplitude of ADSR Envelope 2 mapped from -80db(0) to 0db(1)
//      amp2_r(i) = 10^(amp2_db(i)/20); % amplitude converted back to linear scale
//      y2(i)= amp2_r(i)'.*y1(i) ;
//  end
//
//   y1= y1./max(abs(y));
//   y2 = y2./max(abs(y2));
// Arguments    : const emxArray_boolean_T *note
//                double fs
//                double f0
//                double Q
//                double wf
//                double N
//                double zi[12]
//                double a1
//                double d1
//                double s1
//                double r1
//                double a2
//                double d2
//                double s2
//                double r2
//                double fa
//                emxArray_real_T *y
//                emxArray_real_T *y2
//                double *amp1
//                double *amp2
// Return Type  : void
//
void synth(const emxArray_boolean_T *note, double fs, double f0, double Q,
           double wf, double N, double zi[12], double a1, double d1, double s1,
           double r1, double a2, double d2, double s2, double r2, double fa,
           emxArray_real_T *y, emxArray_real_T *y2, double *amp1, double *amp2)
{
  int i1;
  int idx;
  emxArray_real_T *varargin_1;
  double dv0[2];
  double omega_c;
  int k;
  boolean_T exitg1;
  double x;
  double b_d2;
  double b_zi[2];
  double c_zi[6];

  //  %   g1 = max(abs(y1));
  //  %   %g1_db = 20*log10(g1);
  //  %   y1 = y1./g1;
  //  memory optimization
  // fc =0;
  i1 = y->size[0];
  y->size[0] = (int)N;
  emxEnsureCapacity_real_T(y, i1);
  idx = (int)N;
  for (i1 = 0; i1 < idx; i1++) {
    y->data[i1] = 0.0;
  }

  i1 = y2->size[0];
  y2->size[0] = (int)N;
  emxEnsureCapacity_real_T(y2, i1);
  idx = (int)N;
  for (i1 = 0; i1 < idx; i1++) {
    y2->data[i1] = 0.0;
  }

  *amp1 = 0.0;
  *amp2 = 0.0;
  for (idx = 0; idx < (int)N; idx++) {
    for (i1 = 0; i1 < 2; i1++) {
      dv0[i1] = zi[6 * i1];
    }

    *amp1 = ADSR_envelope1(a1, d1, s1, r1, note->data[idx], fs, dv0);

    //
    //
    //  Input:
    // f0 - fundamental frequency from the note
    //  fs - sampling frequency
    //  N - length of the time vector t
    //  zi - matrix that stores the previous values of the output.(3 x 2) ( 1strow - Oscillator, 2nd row - lowpass filter, 3rd row - sawtooth waveform ) 
    //  wf - integer value to choose waveform type ( 0 -sine, 1 - square, 2-
    //  triangle, 3 - sawtooth)
    //  Output
    // y - Output vector (1xN) of the oscillator + 2nd order LPF (multi oscillator) 
    //  %%
    //  y1 = zeros(N,1);
    //
    //  Input :
    //  f0 - fundamental frequency from the note
    //  fs - sampling frequency
    //  N - length of the time vector t
    //  zi - stores the previous values of the output (1 x 2)
    //  Output
    // y1 - output vector 1 of the GR Oscillator ( Nx1)
    // y2 - output vector 2 of the GR Oscillator ( 90  degree phase shift) ( Nx1) 
    //
    omega_c = 6.2831853071795862 * f0 / fs;
    x = std::sin(omega_c);
    omega_c = std::cos(omega_c);
    b_d2 = omega_c * zi[1] + x * zi[7];
    b_zi[0] = b_d2;
    b_zi[1] = -x * zi[1] + omega_c * zi[7];
    for (i1 = 0; i1 < 2; i1++) {
      zi[6 * i1] = dv0[i1];
      for (k = 0; k < 3; k++) {
        c_zi[k + 3 * i1] = zi[(k + 6 * i1) + 1];
      }

      c_zi[3 * i1] = b_zi[i1];
    }

    switch ((int)rt_roundd_snf(wf)) {
     case 0:
      break;

     case 1:
      if (b_d2 < 0.0) {
        b_d2 = -1.0;
      }

      if (b_d2 == 0.0) {
        b_d2 = 0.0;
      }

      if (b_d2 > 0.0) {
        b_d2 = 1.0;
      }
      break;

     case 2:
      omega_c = 4.0 * (1.0 / (fs / f0));

      // y = zeros(N,1);
      if (b_d2 >= 0.0) {
        b_d2 = c_zi[5] + omega_c;
      } else {
        if (b_d2 < 0.0) {
          b_d2 = c_zi[5] - omega_c;
        }
      }

      // [y] = taylor_series(y,p);
      c_zi[5] = b_d2;
      break;

     case 3:
      b_d2 = c_zi[2] + 2.0 * (1.0 / (fs / f0));
      if (b_d2 >= 1.0) {
        b_d2 = -1.0;
      }

      c_zi[2] = b_d2;
      break;

     case 4:
      b_d2 = 2.0 * b_rand() - 1.0;

      //  rand;
      break;
    }

    for (i1 = 0; i1 < 2; i1++) {
      dv0[i1] = c_zi[1 + 3 * i1];
    }

    b_d2 = lowpass_2(b_d2, 20000.0, fs, 0.7, dv0);
    for (i1 = 0; i1 < 2; i1++) {
      c_zi[1 + 3 * i1] = dv0[i1];
    }

    y->data[idx] = b_d2;

    //  output of the oscillator which takes the f0 ( fundamental frequency) from the note and the waveform. This is then ghiven to the LPF. 
    //  To calculate fc at each sample of the note, which is given to the filter for shaping the signal. 
    for (i1 = 0; i1 < 2; i1++) {
      for (k = 0; k < 3; k++) {
        zi[(k + 6 * i1) + 1] = c_zi[k + 3 * i1];
      }

      dv0[i1] = zi[4 + 6 * i1];
    }

    y->data[idx] = lowpass_2(y->data[idx], fa * (*amp1 * 19980.0 + 20.0), fs, Q,
      dv0);

    //  output of the VCF after modulation with ADSR envelope 1
    for (i1 = 0; i1 < 2; i1++) {
      zi[4 + 6 * i1] = dv0[i1];
      dv0[i1] = zi[5 + 6 * i1];
    }

    *amp2 = ADSR_envelope1(a2, d2, s2, r2, note->data[idx], fs, dv0);
    for (i1 = 0; i1 < 2; i1++) {
      zi[5 + 6 * i1] = dv0[i1];
    }

    //  amplitude of ADSR Envelope 2 mapped from -80db(0) to 0db(1)
    *amp2 = rt_powd_snf(10.0, (*amp2 * 80.0 - 80.0) / 20.0);

    //  amplitude converted back to linear scale
    y2->data[idx] = *amp2 * y->data[idx];
  }

  emxInit_real_T(&varargin_1, 1);
  b_abs(y, varargin_1);
  if (varargin_1->size[0] <= 2) {
    if (varargin_1->size[0] == 1) {
      omega_c = varargin_1->data[0];
    } else if ((varargin_1->data[0] < varargin_1->data[1]) || (rtIsNaN
                (varargin_1->data[0]) && (!rtIsNaN(varargin_1->data[1])))) {
      omega_c = varargin_1->data[1];
    } else {
      omega_c = varargin_1->data[0];
    }
  } else {
    if (!rtIsNaN(varargin_1->data[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= varargin_1->size[0])) {
        if (!rtIsNaN(varargin_1->data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      omega_c = varargin_1->data[0];
    } else {
      omega_c = varargin_1->data[idx - 1];
      while (idx + 1 <= varargin_1->size[0]) {
        if (omega_c < varargin_1->data[idx]) {
          omega_c = varargin_1->data[idx];
        }

        idx++;
      }
    }
  }

  i1 = varargin_1->size[0];
  varargin_1->size[0] = y->size[0];
  emxEnsureCapacity_real_T(varargin_1, i1);
  idx = y->size[0];
  for (i1 = 0; i1 < idx; i1++) {
    varargin_1->data[i1] = y->data[i1];
  }

  rdivide(varargin_1, omega_c, y);
  b_abs(y2, varargin_1);
  if (varargin_1->size[0] <= 2) {
    if (varargin_1->size[0] == 1) {
      omega_c = varargin_1->data[0];
    } else if ((varargin_1->data[0] < varargin_1->data[1]) || (rtIsNaN
                (varargin_1->data[0]) && (!rtIsNaN(varargin_1->data[1])))) {
      omega_c = varargin_1->data[1];
    } else {
      omega_c = varargin_1->data[0];
    }
  } else {
    if (!rtIsNaN(varargin_1->data[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= varargin_1->size[0])) {
        if (!rtIsNaN(varargin_1->data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      omega_c = varargin_1->data[0];
    } else {
      omega_c = varargin_1->data[idx - 1];
      while (idx + 1 <= varargin_1->size[0]) {
        if (omega_c < varargin_1->data[idx]) {
          omega_c = varargin_1->data[idx];
        }

        idx++;
      }
    }
  }

  i1 = varargin_1->size[0];
  varargin_1->size[0] = y2->size[0];
  emxEnsureCapacity_real_T(varargin_1, i1);
  idx = y2->size[0];
  for (i1 = 0; i1 < idx; i1++) {
    varargin_1->data[i1] = y2->data[i1];
  }

  rdivide(varargin_1, omega_c, y2);

  //  to find out the db values
  //  %   g1 = max(abs(y));
  //  %   %g1_db = 20*log10(g1);
  //  %   y = y./g1;
  //  %   g2 =  max(abs(y2));
  //  %   y2 = y2./g2;
  emxFree_real_T(&varargin_1);
}

//
// File trailer for synth.cpp
//
// [EOF]
//
