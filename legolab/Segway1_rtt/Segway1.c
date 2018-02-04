/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Segway1.c
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
#include "nxt_util.h"

/* Block signals (auto storage) */
B_Segway1_T Segway1_B;

/* Continuous states */
X_Segway1_T Segway1_X;

/* Block states (auto storage) */
DW_Segway1_T Segway1_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Segway1_T Segway1_PrevZCX;

/* Real-time model */
RT_MODEL_Segway1_T Segway1_M_;
RT_MODEL_Segway1_T *const Segway1_M = &Segway1_M_;
static void rate_scheduler(void);
real_T sMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real_T y;
  int32_T i;
  int32_T exp_0;
  uint32_T u1i;
  uint32_T cb;
  y = 0.0;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648U) != 0U) {
    cb = 1U;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= ldexp(cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += ldexp(u1[i], exp_0);
      exp_0 += 32;
    }
  }

  return y;
}

void MultiWordAdd(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
                  int32_T n)
{
  uint32_T yi;
  uint32_T u1i;
  uint32_T carry = 0U;
  int32_T i;
  for (i = 0; i < n; i++) {
    u1i = u1[i];
    yi = (u1i + u2[i]) + carry;
    y[i] = yi;
    carry = carry != 0U ? (uint32_T)(yi <= u1i) : (uint32_T)(yi < u1i);
  }
}

void sMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
                   n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T nj;
  uint32_T u1i;
  uint32_T yk;
  uint32_T a1;
  uint32_T a0;
  uint32_T b1;
  uint32_T w10;
  uint32_T w01;
  uint32_T cb;
  boolean_T isNegative1;
  boolean_T isNegative2;
  uint32_T cb1;
  uint32_T cb2;
  isNegative1 = ((u1[n1 - 1] & 2147483648U) != 0U);
  isNegative2 = ((u2[n2 - 1] & 2147483648U) != 0U);
  cb1 = 1U;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    cb = 0U;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535U;
    cb2 = 1U;
    k = n - i;
    nj = n2 <= k ? n2 : k;
    k = i;
    for (j = 0; j < nj; j++) {
      yk = y[k];
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

      b1 = u1i >> 16U;
      u1i &= 65535U;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk += cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1U;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Segway1_M->Timing.TaskCounters.TID[2])++;
  if ((Segway1_M->Timing.TaskCounters.TID[2]) > 19) {/* Sample time: [0.1s, 0.0s] */
    Segway1_M->Timing.TaskCounters.TID[2] = 0;
  }

  (Segway1_M->Timing.TaskCounters.TID[3])++;
  if ((Segway1_M->Timing.TaskCounters.TID[3]) > 199) {/* Sample time: [1.0s, 0.0s] */
    Segway1_M->Timing.TaskCounters.TID[3] = 0;
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Segway1_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Segway1_output();
  Segway1_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Segway1_output();
  Segway1_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Segway1_output(void)
{
  int8_T tmp;
  int8_T tmp_0;
  ZCEventType zcEvent;
  int16_T rtb_GyroSensor;
  real_T rtb_Sum1_n;
  real_T rtb_Gain3_b;
  int32_T rtb_Encoder;
  int32_T rtb_Encoder1;
  real_T rtb_Sum;
  real_T rtb_Sum2;
  real_T rtb_Sum2_p;
  real_T rtb_Sum_f;
  int64m_T tmp_1;
  int64m_T tmp_2;
  uint32_T tmp_3;
  uint32_T tmp_4;
  int64m_T tmp_5;
  real_T u0;
  if (rtmIsMajorTimeStep(Segway1_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&Segway1_M->solverInfo,((Segway1_M->Timing.clockTick0+
      1)*Segway1_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Segway1_M)) {
    Segway1_M->Timing.t[0] = rtsiGetT(&Segway1_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Segway1_M) &&
      Segway1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Memory: '<S11>/Memory' */
    Segway1_B.Memory = Segway1_DW.Memory_PreviousInput;

    /* S-Function (nxt_gyro_sensor): '<S4>/Gyro Sensor' */
    rtb_GyroSensor = getGyroSensorValue(1U, 1U, 600);

    /* Sum: '<S4>/Sum1' incorporates:
     *  S-Function (nxt_gyro_sensor): '<S4>/Gyro Sensor'
     */
    rtb_Sum1_n = (real_T)rtb_GyroSensor - Segway1_B.Memory;

    /* Gain: '<S5>/Gain' */
    Segway1_B.Gain = Segway1_P.Gain_Gain_e * rtb_Sum1_n;
  }

  /* Sum: '<S5>/Sum' incorporates:
   *  Constant: '<S5>/Constant'
   *  Gain: '<S5>/Gain1'
   *  Integrator: '<S4>/Integrator1'
   *  Sum: '<S5>/Sum1'
   */
  rtb_Sum = Segway1_P.Constant_Value - (Segway1_P.Gain1_Gain *
    Segway1_X.Integrator1_CSTATE + Segway1_B.Gain);

  /* Gain: '<S2>/Gain3' incorporates:
   *  Integrator: '<S2>/Integrator'
   */
  rtb_Gain3_b = Segway1_P.Gain3_Gain * Segway1_X.Integrator_CSTATE;
  if (rtmIsMajorTimeStep(Segway1_M) &&
      Segway1_M->Timing.TaskCounters.TID[2] == 0) {
    /* S-Function (nxt_encoder): '<S2>/Encoder' */
    rtb_Encoder = getEncoderValueSampleReset(1U);

    /* S-Function (nxt_encoder): '<S2>/Encoder1' */
    rtb_Encoder1 = getEncoderValueSampleReset(3U);

    /* Gain: '<S2>/Gain' incorporates:
     *  S-Function (nxt_encoder): '<S2>/Encoder'
     */
    tmp_3 = (uint32_T)Segway1_P.Gain_Gain_h;
    tmp_4 = (uint32_T)rtb_Encoder;
    sMultiWordMul(&tmp_3, 1, &tmp_4, 1, &tmp_2.chunks[0U], 2);

    /* Gain: '<S2>/Gain1' incorporates:
     *  S-Function (nxt_encoder): '<S2>/Encoder1'
     */
    tmp_3 = (uint32_T)Segway1_P.Gain1_Gain_j;
    tmp_4 = (uint32_T)rtb_Encoder1;
    sMultiWordMul(&tmp_3, 1, &tmp_4, 1, &tmp_5.chunks[0U], 2);

    /* Sum: '<S2>/Sum' */
    MultiWordAdd(&tmp_2.chunks[0U], &tmp_5.chunks[0U], &tmp_1.chunks[0U], 2);

    /* Gain: '<S2>/Gain2' */
    Segway1_B.Gain2 = sMultiWord2Double(&Segway1_P.Gain2_Gain_o.chunks[0U], 2, 0)
      * 1.0842021724855044E-19 * (sMultiWord2Double(&tmp_1.chunks[0U], 2, 0) *
      7.4505805969238281E-9);

    /* Gain: '<S5>/Gain2' incorporates:
     *  Gain: '<S2>/Gain4'
     */
    Segway1_B.Gain2_d = Segway1_P.Gain4_Gain * Segway1_B.Gain2 *
      Segway1_P.Gain2_Gain;
  }

  /* Sum: '<S5>/Sum2' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Gain: '<S5>/Gain3'
   *  Sum: '<S5>/Sum3'
   */
  rtb_Sum2 = Segway1_P.Constant1_Value - (Segway1_P.Gain3_Gain_h * rtb_Gain3_b +
    Segway1_B.Gain2_d);

  /* Gain: '<Root>/Gain' incorporates:
   *  Sum: '<S5>/Sum4'
   */
  rtb_Sum2_p = (rtb_Sum + rtb_Sum2) * Segway1_P.Gain_Gain_n;

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  u0 = floor(rtb_Sum2_p);
  if (rtIsNaN(u0) || rtIsInf(u0)) {
    u0 = 0.0;
  } else {
    u0 = fmod(u0, 4.294967296E+9);
  }

  Segway1_B.DataTypeConversion_i = u0 < 0.0 ? -(int32_T)(uint32_T)-u0 : (int32_T)
    (uint32_T)u0;

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */
  if (rtmIsMajorTimeStep(Segway1_M) &&
      Segway1_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (nxt_lcd): '<S1>/LCD' */
    lcdDisplay(Segway1_B.DataTypeConversion_i, Segway1_ConstP.LCD_p1, 3U, 1U);
  }

  if (rtmIsMajorTimeStep(Segway1_M) &&
      Segway1_M->Timing.TaskCounters.TID[2] == 0) {
    /* Gain: '<S3>/Gain' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion'
     */
    Segway1_B.Gain_j = Segway1_P.Gain_Gain_o * (real_T)rtb_Encoder;
  }

  /* Sum: '<S3>/Sum' */
  rtb_Sum_f = rtb_Sum2_p - Segway1_B.Gain_j;

  /* Sum: '<S3>/Sum1' incorporates:
   *  Gain: '<S3>/Gain1'
   *  Integrator: '<S3>/Integrator'
   */
  u0 = Segway1_P.Gain1_Gain_o * rtb_Sum_f + Segway1_X.Integrator_CSTATE_i;

  /* Saturate: '<S3>/Saturation' */
  if (u0 > Segway1_P.Saturation_UpperSat) {
    u0 = Segway1_P.Saturation_UpperSat;
  } else {
    if (u0 < Segway1_P.Saturation_LowerSat) {
      u0 = Segway1_P.Saturation_LowerSat;
    }
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Saturate: '<S3>/Saturation'
   */
  u0 = floor(u0);
  if (u0 < 128.0) {
    if (u0 >= -128.0) {
      Segway1_B.DataTypeConversion_d = (int8_T)u0;
    } else {
      Segway1_B.DataTypeConversion_d = MIN_int8_T;
    }
  } else {
    Segway1_B.DataTypeConversion_d = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S7>/Data Type Conversion' */
  if (rtmIsMajorTimeStep(Segway1_M) &&
      Segway1_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (nxt_motor): '<S7>/Motor' */
    tmp = Segway1_B.DataTypeConversion_d;
    setMotor(&tmp, 1U, 1U);
  }

  if (rtmIsMajorTimeStep(Segway1_M) &&
      Segway1_M->Timing.TaskCounters.TID[2] == 0) {
    /* Gain: '<S3>/Gain3' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion1'
     */
    Segway1_B.Gain3 = Segway1_P.Gain3_Gain_c * (real_T)rtb_Encoder1;
  }

  /* Sum: '<S3>/Sum2' */
  rtb_Sum2_p -= Segway1_B.Gain3;

  /* Sum: '<S3>/Sum3' incorporates:
   *  Gain: '<S3>/Gain4'
   *  Integrator: '<S3>/Integrator1'
   */
  u0 = Segway1_P.Gain4_Gain_n * rtb_Sum2_p + Segway1_X.Integrator1_CSTATE_p;

  /* Saturate: '<S3>/Saturation1' */
  if (u0 > Segway1_P.Saturation1_UpperSat) {
    u0 = Segway1_P.Saturation1_UpperSat;
  } else {
    if (u0 < Segway1_P.Saturation1_LowerSat) {
      u0 = Segway1_P.Saturation1_LowerSat;
    }
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion' incorporates:
   *  Saturate: '<S3>/Saturation1'
   */
  u0 = floor(u0);
  if (u0 < 128.0) {
    if (u0 >= -128.0) {
      Segway1_B.DataTypeConversion_o = (int8_T)u0;
    } else {
      Segway1_B.DataTypeConversion_o = MIN_int8_T;
    }
  } else {
    Segway1_B.DataTypeConversion_o = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S8>/Data Type Conversion' */
  if (rtmIsMajorTimeStep(Segway1_M) &&
      Segway1_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (nxt_motor): '<S8>/Motor' */
    tmp_0 = Segway1_B.DataTypeConversion_o;
    setMotor(&tmp_0, 3U, 1U);
  }

  /* Gain: '<S3>/Gain2' */
  Segway1_B.Gain2_a = Segway1_P.Gain2_Gain_d * rtb_Sum_f;

  /* Gain: '<S3>/Gain5' */
  Segway1_B.Gain5 = Segway1_P.Gain5_Gain * rtb_Sum2_p;

  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  u0 = floor(rtb_Gain3_b);
  if (rtIsNaN(u0) || rtIsInf(u0)) {
    u0 = 0.0;
  } else {
    u0 = fmod(u0, 4.294967296E+9);
  }

  Segway1_B.DataTypeConversion_j = u0 < 0.0 ? -(int32_T)(uint32_T)-u0 : (int32_T)
    (uint32_T)u0;

  /* End of DataTypeConversion: '<S6>/Data Type Conversion' */
  if (rtmIsMajorTimeStep(Segway1_M) &&
      Segway1_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (nxt_lcd): '<S6>/LCD' */
    lcdDisplay(Segway1_B.DataTypeConversion_j, Segway1_ConstP.LCD_p1_o, 4U, 1U);
  }

  /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
   *  Integrator: '<S4>/Integrator1'
   */
  u0 = floor(Segway1_X.Integrator1_CSTATE);
  if (rtIsNaN(u0) || rtIsInf(u0)) {
    u0 = 0.0;
  } else {
    u0 = fmod(u0, 4.294967296E+9);
  }

  Segway1_B.DataTypeConversion_b = u0 < 0.0 ? -(int32_T)(uint32_T)-u0 : (int32_T)
    (uint32_T)u0;

  /* End of DataTypeConversion: '<S9>/Data Type Conversion' */
  if (rtmIsMajorTimeStep(Segway1_M) &&
      Segway1_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (nxt_lcd): '<S9>/LCD' */
    lcdDisplay(Segway1_B.DataTypeConversion_b, Segway1_ConstP.LCD_p1_b, 1U, 1U);

    /* DataTypeConversion: '<S10>/Data Type Conversion' */
    u0 = floor(rtb_Sum1_n);
    if (rtIsNaN(u0) || rtIsInf(u0)) {
      u0 = 0.0;
    } else {
      u0 = fmod(u0, 4.294967296E+9);
    }

    /* S-Function (nxt_lcd): '<S10>/LCD' incorporates:
     *  DataTypeConversion: '<S10>/Data Type Conversion'
     */
    lcdDisplay(u0 < 0.0 ? -(int32_T)(uint32_T)-u0 : (int32_T)(uint32_T)u0,
               Segway1_ConstP.LCD_p1_d, 2U, 1U);

    /* DataTypeConversion: '<S4>/Data Type Conversion' */
    Segway1_B.DataTypeConversion = rtb_GyroSensor;

    /* DeadZone: '<S4>/Dead Zone1' */
    if (rtb_Sum1_n > Segway1_P.DeadZone1_End) {
      Segway1_B.DeadZone1 = rtb_Sum1_n - Segway1_P.DeadZone1_End;
    } else if (rtb_Sum1_n >= Segway1_P.DeadZone1_Start) {
      Segway1_B.DeadZone1 = 0.0;
    } else {
      Segway1_B.DeadZone1 = rtb_Sum1_n - Segway1_P.DeadZone1_Start;
    }

    /* End of DeadZone: '<S4>/Dead Zone1' */
  }

  if (rtmIsMajorTimeStep(Segway1_M) &&
      Segway1_M->Timing.TaskCounters.TID[3] == 0) {
    /* Step: '<S11>/Step' */
    if (((Segway1_M->Timing.clockTick3) ) < Segway1_P.Step_Time) {
      rtb_Sum1_n = Segway1_P.Step_Y0;
    } else {
      rtb_Sum1_n = Segway1_P.Step_YFinal;
    }

    /* End of Step: '<S11>/Step' */

    /* HitCross: '<S11>/Hit  Crossing' */
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&Segway1_PrevZCX.HitCrossing_Input_ZCE,
                       (rtb_Sum1_n - Segway1_P.HitCrossing_Offset));
    if (Segway1_DW.HitCrossing_MODE == 0) {
      if (zcEvent != NO_ZCEVENT) {
        Segway1_B.HitCrossing = !Segway1_B.HitCrossing;
        Segway1_DW.HitCrossing_MODE = 1;
      } else if (Segway1_B.HitCrossing) {
        if (rtb_Sum1_n != Segway1_P.HitCrossing_Offset) {
          Segway1_B.HitCrossing = false;
        }
      } else {
        if (rtb_Sum1_n == Segway1_P.HitCrossing_Offset) {
          Segway1_B.HitCrossing = true;
        }
      }
    } else {
      if (rtb_Sum1_n != Segway1_P.HitCrossing_Offset) {
        Segway1_B.HitCrossing = false;
      }

      Segway1_DW.HitCrossing_MODE = 0;
    }

    /* End of HitCross: '<S11>/Hit  Crossing' */
  }

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S11>/Constant1'
   *  Gain: '<S11>/Gain'
   *  Integrator: '<S4>/Integrator'
   */
  if (Segway1_B.HitCrossing) {
    u0 = Segway1_P.Gain_Gain * Segway1_X.Integrator_CSTATE_f;
  } else {
    u0 = Segway1_P.Constant1_Value_a;
  }

  /* End of Switch: '<S11>/Switch' */

  /* Sum: '<S11>/Sum' */
  Segway1_B.Sum = u0 + Segway1_B.Memory;

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  u0 = floor(rtb_Sum);
  if (rtIsNaN(u0) || rtIsInf(u0)) {
    u0 = 0.0;
  } else {
    u0 = fmod(u0, 4.294967296E+9);
  }

  Segway1_B.DataTypeConversion_c = u0 < 0.0 ? -(int32_T)(uint32_T)-u0 : (int32_T)
    (uint32_T)u0;

  /* End of DataTypeConversion: '<S12>/Data Type Conversion' */
  if (rtmIsMajorTimeStep(Segway1_M) &&
      Segway1_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (nxt_lcd): '<S12>/LCD' */
    lcdDisplay(Segway1_B.DataTypeConversion_c, Segway1_ConstP.LCD_p1_bp, 5U, 1U);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  u0 = floor(rtb_Sum2);
  if (rtIsNaN(u0) || rtIsInf(u0)) {
    u0 = 0.0;
  } else {
    u0 = fmod(u0, 4.294967296E+9);
  }

  Segway1_B.DataTypeConversion_k = u0 < 0.0 ? -(int32_T)(uint32_T)-u0 : (int32_T)
    (uint32_T)u0;

  /* End of DataTypeConversion: '<S13>/Data Type Conversion' */
  if (rtmIsMajorTimeStep(Segway1_M) &&
      Segway1_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (nxt_lcd): '<S13>/LCD' */
    lcdDisplay(Segway1_B.DataTypeConversion_k, Segway1_ConstP.LCD_p1_n, 1U, 1U);
  }
}

/* Model update function */
void Segway1_update(void)
{
  if (rtmIsMajorTimeStep(Segway1_M) &&
      Segway1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<S11>/Memory' */
    Segway1_DW.Memory_PreviousInput = Segway1_B.Sum;
  }

  if (rtmIsMajorTimeStep(Segway1_M)) {
    rt_ertODEUpdateContinuousStates(&Segway1_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ++Segway1_M->Timing.clockTick0;
  Segway1_M->Timing.t[0] = rtsiGetSolverStopTime(&Segway1_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Segway1_M->Timing.clockTick1++;
  }

  if (rtmIsMajorTimeStep(Segway1_M) &&
      Segway1_M->Timing.TaskCounters.TID[3] == 0) {
    /* Update absolute timer for sample time: [1.0s, 0.0s] */
    /* The "clockTick3" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 1.0, which is the step size
     * of the task. Size of "clockTick3" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Segway1_M->Timing.clockTick3++;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void Segway1_derivatives(void)
{
  XDot_Segway1_T *_rtXdot;
  _rtXdot = ((XDot_Segway1_T *) Segway1_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S4>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = Segway1_B.DeadZone1;

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE = Segway1_B.Gain2;

  /* Derivatives for Integrator: '<S3>/Integrator' */
  _rtXdot->Integrator_CSTATE_i = Segway1_B.Gain2_a;

  /* Derivatives for Integrator: '<S3>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_p = Segway1_B.Gain5;

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE_f = Segway1_B.DataTypeConversion;
}

/* Model initialize function */
void Segway1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Segway1_M, 0,
                sizeof(RT_MODEL_Segway1_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Segway1_M->solverInfo, &Segway1_M->Timing.simTimeStep);
    rtsiSetTPtr(&Segway1_M->solverInfo, &rtmGetTPtr(Segway1_M));
    rtsiSetStepSizePtr(&Segway1_M->solverInfo, &Segway1_M->Timing.stepSize0);
    rtsiSetdXPtr(&Segway1_M->solverInfo, &Segway1_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Segway1_M->solverInfo, (real_T **)
                         &Segway1_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Segway1_M->solverInfo,
      &Segway1_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Segway1_M->solverInfo, (&rtmGetErrorStatus(Segway1_M)));
    rtsiSetRTModelPtr(&Segway1_M->solverInfo, Segway1_M);
  }

  rtsiSetSimTimeStep(&Segway1_M->solverInfo, MAJOR_TIME_STEP);
  Segway1_M->ModelData.intgData.y = Segway1_M->ModelData.odeY;
  Segway1_M->ModelData.intgData.f[0] = Segway1_M->ModelData.odeF[0];
  Segway1_M->ModelData.intgData.f[1] = Segway1_M->ModelData.odeF[1];
  Segway1_M->ModelData.intgData.f[2] = Segway1_M->ModelData.odeF[2];
  Segway1_M->ModelData.contStates = ((X_Segway1_T *) &Segway1_X);
  rtsiSetSolverData(&Segway1_M->solverInfo, (void *)
                    &Segway1_M->ModelData.intgData);
  rtsiSetSolverName(&Segway1_M->solverInfo,"ode3");
  rtmSetTPtr(Segway1_M, &Segway1_M->Timing.tArray[0]);
  Segway1_M->Timing.stepSize0 = 0.005;

  /* block I/O */
  (void) memset(((void *) &Segway1_B), 0,
                sizeof(B_Segway1_T));

  /* states (continuous) */
  {
    (void) memset((void *)&Segway1_X, 0,
                  sizeof(X_Segway1_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Segway1_DW, 0,
                sizeof(DW_Segway1_T));
  Segway1_PrevZCX.HitCrossing_Input_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Integrator: '<S4>/Integrator1' */
  Segway1_X.Integrator1_CSTATE = Segway1_P.Integrator1_IC;

  /* InitializeConditions for Memory: '<S11>/Memory' */
  Segway1_DW.Memory_PreviousInput = Segway1_P.Memory_X0;

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  Segway1_X.Integrator_CSTATE = Segway1_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S3>/Integrator' */
  Segway1_X.Integrator_CSTATE_i = Segway1_P.Integrator_IC_e;

  /* InitializeConditions for Integrator: '<S3>/Integrator1' */
  Segway1_X.Integrator1_CSTATE_p = Segway1_P.Integrator1_IC_e;

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  Segway1_X.Integrator_CSTATE_f = Segway1_P.Integrator_IC_m;
}

/* Model terminate function */
void Segway1_terminate(void)
{
  /* Terminate for S-Function (nxt_motor): '<S7>/Motor' */
  terminateMotor(1U, 1U);

  /* Terminate for S-Function (nxt_motor): '<S8>/Motor' */
  terminateMotor(3U, 1U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
