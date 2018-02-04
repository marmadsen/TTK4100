/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Segway1_data.c
 *
 * Code generated for Simulink model 'Segway1'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Mon Sep 28 10:58:50 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Segway1.h"
#include "Segway1_private.h"

/* Block parameters (auto storage) */
P_Segway1_T Segway1_P = {
  0.00125,                             /* Expression: 1/800
                                        * Referenced by: '<S11>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator1'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S5>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Memory'
                                        */
  1.25,                                /* Expression: 1.25
                                        * Referenced by: '<S5>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Integrator'
                                        */
  0.036651914291880923,                /* Expression: 100*(pi*0.042)/360
                                        * Referenced by: '<S2>/Gain3'
                                        */
  2.75,                                /* Expression: 2.75
                                        * Referenced by: '<S5>/Gain3'
                                        */
  0.036651914291880923,                /* Expression: 100*(pi*2*0.021)/360
                                        * Referenced by: '<S2>/Gain4'
                                        */
  4.25,                                /* Expression: 4.25
                                        * Referenced by: '<S5>/Gain2'
                                        */
  0.03,                                /* Expression: 0.03
                                        * Referenced by: '<Root>/Gain'
                                        */
  0.027777777777777776,                /* Expression: 1/36
                                        * Referenced by: '<S3>/Gain'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S3>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Integrator'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S3>/Saturation'
                                        */
  -100.0,                              /* Expression: -100
                                        * Referenced by: '<S3>/Saturation'
                                        */
  0.027777777777777776,                /* Expression: 1/36
                                        * Referenced by: '<S3>/Gain3'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S3>/Gain4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Integrator1'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S3>/Saturation1'
                                        */
  -100.0,                              /* Expression: -100
                                        * Referenced by: '<S3>/Saturation1'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S3>/Gain2'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S3>/Gain5'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S4>/Dead Zone1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/Dead Zone1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Constant1'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S11>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S11>/Step'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S11>/Hit  Crossing'
                                        */

  { { 0UL, 0x40000000UL } },           /* Computed Parameter: Gain2_Gain_o
                                        * Referenced by: '<S2>/Gain2'
                                        */
  1342177280,                          /* Computed Parameter: Gain_Gain_h
                                        * Referenced by: '<S2>/Gain'
                                        */
  1342177280                           /* Computed Parameter: Gain1_Gain_j
                                        * Referenced by: '<S2>/Gain1'
                                        */
};

/* Constant parameters (auto storage) */
const ConstP_Segway1_T Segway1_ConstP = {
  /* Expression: lcdStr1
   * Referenced by: '<S1>/LCD'
   */
  { 117U, 0U },

  /* Expression: lcdStr1
   * Referenced by: '<S6>/LCD'
   */
  { 120U, 32U, 99U, 111U, 117U, 0U },

  /* Expression: lcdStr1
   * Referenced by: '<S9>/LCD'
   */
  { 75U, 111U, 114U, 32U, 118U, 46U, 0U },

  /* Expression: lcdStr1
   * Referenced by: '<S10>/LCD'
   */
  { 75U, 111U, 114U, 32U, 118U, 104U, 0U },

  /* Expression: lcdStr1
   * Referenced by: '<S12>/LCD'
   */
  { 103U, 121U, 95U, 114U, 101U, 103U, 0U },

  /* Expression: lcdStr1
   * Referenced by: '<S13>/LCD'
   */
  { 101U, 110U, 95U, 114U, 101U, 103U, 0U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
