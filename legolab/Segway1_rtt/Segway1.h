/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Segway1.h
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

#ifndef RTW_HEADER_Segway1_h_
#define RTW_HEADER_Segway1_h_
#include <math.h>
#include <string.h>
#ifndef Segway1_COMMON_INCLUDES_
# define Segway1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "driver_nxt.h"
#endif                                 /* Segway1_COMMON_INCLUDES_ */

#include "Segway1_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Memory;                       /* '<S11>/Memory' */
  real_T Gain;                         /* '<S5>/Gain' */
  real_T Gain2;                        /* '<S2>/Gain2' */
  real_T Gain2_d;                      /* '<S5>/Gain2' */
  real_T Gain_j;                       /* '<S3>/Gain' */
  real_T Gain3;                        /* '<S3>/Gain3' */
  real_T Gain2_a;                      /* '<S3>/Gain2' */
  real_T Gain5;                        /* '<S3>/Gain5' */
  real_T DataTypeConversion;           /* '<S4>/Data Type Conversion' */
  real_T DeadZone1;                    /* '<S4>/Dead Zone1' */
  real_T Sum;                          /* '<S11>/Sum' */
  int32_T DataTypeConversion_i;        /* '<S1>/Data Type Conversion' */
  int32_T DataTypeConversion_j;        /* '<S6>/Data Type Conversion' */
  int32_T DataTypeConversion_b;        /* '<S9>/Data Type Conversion' */
  int32_T DataTypeConversion_c;        /* '<S12>/Data Type Conversion' */
  int32_T DataTypeConversion_k;        /* '<S13>/Data Type Conversion' */
  int8_T DataTypeConversion_d;         /* '<S7>/Data Type Conversion' */
  int8_T DataTypeConversion_o;         /* '<S8>/Data Type Conversion' */
  boolean_T HitCrossing;               /* '<S11>/Hit  Crossing' */
} B_Segway1_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<S11>/Memory' */
  int_T HitCrossing_MODE;              /* '<S11>/Hit  Crossing' */
} DW_Segway1_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S4>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S2>/Integrator' */
  real_T Integrator_CSTATE_i;          /* '<S3>/Integrator' */
  real_T Integrator1_CSTATE_p;         /* '<S3>/Integrator1' */
  real_T Integrator_CSTATE_f;          /* '<S4>/Integrator' */
} X_Segway1_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S4>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S2>/Integrator' */
  real_T Integrator_CSTATE_i;          /* '<S3>/Integrator' */
  real_T Integrator1_CSTATE_p;         /* '<S3>/Integrator1' */
  real_T Integrator_CSTATE_f;          /* '<S4>/Integrator' */
} XDot_Segway1_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<S4>/Integrator1' */
  boolean_T Integrator_CSTATE;         /* '<S2>/Integrator' */
  boolean_T Integrator_CSTATE_i;       /* '<S3>/Integrator' */
  boolean_T Integrator1_CSTATE_p;      /* '<S3>/Integrator1' */
  boolean_T Integrator_CSTATE_f;       /* '<S4>/Integrator' */
} XDis_Segway1_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState HitCrossing_Input_ZCE;    /* '<S11>/Hit  Crossing' */
} PrevZCX_Segway1_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: lcdStr1
   * Referenced by: '<S1>/LCD'
   */
  uint8_T LCD_p1[2];

  /* Expression: lcdStr1
   * Referenced by: '<S6>/LCD'
   */
  uint8_T LCD_p1_o[6];

  /* Expression: lcdStr1
   * Referenced by: '<S9>/LCD'
   */
  uint8_T LCD_p1_b[7];

  /* Expression: lcdStr1
   * Referenced by: '<S10>/LCD'
   */
  uint8_T LCD_p1_d[7];

  /* Expression: lcdStr1
   * Referenced by: '<S12>/LCD'
   */
  uint8_T LCD_p1_bp[7];

  /* Expression: lcdStr1
   * Referenced by: '<S13>/LCD'
   */
  uint8_T LCD_p1_n[7];
} ConstP_Segway1_T;

/* Parameters (auto storage) */
struct P_Segway1_T_ {
  real_T Gain_Gain;                    /* Expression: 1/800
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S4>/Integrator1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 10
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S11>/Memory'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 1.25
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S2>/Integrator'
                                        */
  real_T Gain3_Gain;                   /* Expression: 100*(pi*0.042)/360
                                        * Referenced by: '<S2>/Gain3'
                                        */
  real_T Gain3_Gain_h;                 /* Expression: 2.75
                                        * Referenced by: '<S5>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: 100*(pi*2*0.021)/360
                                        * Referenced by: '<S2>/Gain4'
                                        */
  real_T Gain2_Gain;                   /* Expression: 4.25
                                        * Referenced by: '<S5>/Gain2'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 0.03
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 1/36
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: 5
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T Integrator_IC_e;              /* Expression: 0
                                        * Referenced by: '<S3>/Integrator'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 100
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -100
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Gain3_Gain_c;                 /* Expression: 1/36
                                        * Referenced by: '<S3>/Gain3'
                                        */
  real_T Gain4_Gain_n;                 /* Expression: 5
                                        * Referenced by: '<S3>/Gain4'
                                        */
  real_T Integrator1_IC_e;             /* Expression: 0
                                        * Referenced by: '<S3>/Integrator1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 100
                                        * Referenced by: '<S3>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -100
                                        * Referenced by: '<S3>/Saturation1'
                                        */
  real_T Gain2_Gain_d;                 /* Expression: 10
                                        * Referenced by: '<S3>/Gain2'
                                        */
  real_T Gain5_Gain;                   /* Expression: 10
                                        * Referenced by: '<S3>/Gain5'
                                        */
  real_T DeadZone1_Start;              /* Expression: -1
                                        * Referenced by: '<S4>/Dead Zone1'
                                        */
  real_T DeadZone1_End;                /* Expression: 1
                                        * Referenced by: '<S4>/Dead Zone1'
                                        */
  real_T Integrator_IC_m;              /* Expression: 0
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T Constant1_Value_a;            /* Expression: 0
                                        * Referenced by: '<S11>/Constant1'
                                        */
  real_T Step_Time;                    /* Expression: 4
                                        * Referenced by: '<S11>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S11>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<S11>/Step'
                                        */
  real_T HitCrossing_Offset;           /* Expression: 0.5
                                        * Referenced by: '<S11>/Hit  Crossing'
                                        */
  int64m_T Gain2_Gain_o;               /* Computed Parameter: Gain2_Gain_o
                                        * Referenced by: '<S2>/Gain2'
                                        */
  int32_T Gain_Gain_h;                 /* Computed Parameter: Gain_Gain_h
                                        * Referenced by: '<S2>/Gain'
                                        */
  int32_T Gain1_Gain_j;                /* Computed Parameter: Gain1_Gain_j
                                        * Referenced by: '<S2>/Gain1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Segway1_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_Segway1_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[5];
    real_T odeF[3][5];
    ODE3_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTick3;
    struct {
      uint16_T TID[4];
    } TaskCounters;

    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[4];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Segway1_T Segway1_P;

/* Block signals (auto storage) */
extern B_Segway1_T Segway1_B;

/* Continuous states (auto storage) */
extern X_Segway1_T Segway1_X;

/* Block states (auto storage) */
extern DW_Segway1_T Segway1_DW;

/* Constant parameters (auto storage) */
extern const ConstP_Segway1_T Segway1_ConstP;

/* Model entry point functions */
extern void Segway1_initialize(void);
extern void Segway1_output(void);
extern void Segway1_update(void);
extern void Segway1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Segway1_T *const Segway1_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Segway1'
 * '<S1>'   : 'Segway1/LCD'
 * '<S2>'   : 'Segway1/encodere'
 * '<S3>'   : 'Segway1/motor'
 * '<S4>'   : 'Segway1/navigasjon'
 * '<S5>'   : 'Segway1/regulator'
 * '<S6>'   : 'Segway1/encodere/LCD'
 * '<S7>'   : 'Segway1/motor/Motor'
 * '<S8>'   : 'Segway1/motor/Motor1'
 * '<S9>'   : 'Segway1/navigasjon/LCD'
 * '<S10>'  : 'Segway1/navigasjon/LCD2'
 * '<S11>'  : 'Segway1/navigasjon/kalibrering'
 * '<S12>'  : 'Segway1/regulator/LCD'
 * '<S13>'  : 'Segway1/regulator/LCD1'
 */
#endif                                 /* RTW_HEADER_Segway1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
