//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ADSR_envelope1.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 17-Nov-2020 17:30:25
//

// Include Files
#include "rt_nonfinite.h"
#include "synth.h"
#include "ADSR_envelope1.h"

// Function Definitions

//
// UNTITLED3 Summary of this function goes here
//   Input:
// atime - attack time (in s)
// dtime - decay time ( in s)
// slevel - sustain is a level
// rtime - release time (in s)
// note - vector of ones and zeros( 1 - when noteON, 0 - when noteOFF) ( 1 xN)
// fs - sampling frequency
// Arguments    : double atime
//                double dtime
//                double slevel
//                double rtime
//                boolean_T note
//                double fs
//                double zi[2]
// Return Type  : double
//
double ADSR_envelope1(double atime, double dtime, double slevel, double rtime,
                      boolean_T note, double fs, double zi[2])
{
  double amp;
  double prev_out;
  double b_state;

  // Output:
  // amp - amplitude vector of the ADSR envelope (1 xN)
  // zi- vector that stores 2 values. zi(1)- previous amplitude, zi(2)- sores
  // the state at each sample.
  //
  //  if nargin < 7
  //      zi = [0 0];
  //  end
  //  sample_a = fs*atime;
  //  step_a = 1/sample_a;
  //
  //  sample_d = fs*dtime;
  //  step_d = (1-slevel)/sample_d;
  //
  //  sample_r = fs*rtime;
  //  step_r = slevel/sample_r;
  prev_out = zi[0];
  b_state = zi[1];

  //  si = 0;
  //  prev_state = si;
  amp = 0.0;
  switch ((int)zi[1]) {
   case 0:
    if (note) {
      b_state = 1.0;
    }
    break;

   case 1:
    amp = zi[0] + 1000.0 / (fs * atime);
    prev_out = amp;
    if (amp >= 1.0) {
      b_state = 2.0;
    }

    if (!note) {
      b_state = 4.0;
    }
    break;

   case 2:
    amp = zi[0] - 1000.0 * (1.0 - slevel) / (fs * dtime);
    prev_out = amp;
    if (amp <= slevel) {
      b_state = 3.0;
    }

    if (!note) {
      b_state = 4.0;
    }
    break;

   case 3:
    amp = slevel;
    if (!note) {
      b_state = 4.0;
    }
    break;

   case 4:
    amp = zi[0] - 1000.0 * slevel / (fs * rtime);
    prev_out = amp;
    if (amp <= 0.0) {
      b_state = 0.0;
    }
    break;
  }

  zi[0] = prev_out;
  zi[1] = b_state;
  return amp;
}

//
// File trailer for ADSR_envelope1.cpp
//
// [EOF]
//
