/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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
#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"
#include "ecrobot_private.h"

int tick = 0;
double period = 0.005;
int sampleTime = 0;
int or_ext = 0;
int or_mdl = 0;
int timesup = 0;
DeclareEvent(TIMESUP);
DeclareTask(OSEK_Task_main);
DeclareTask(OSEK_Task_background);
void user_1ms_isr_type2(void)
{
  tick++;
  if (tick >= sampleTime) {
    tick = 0;
    or_ext++;
    or_mdl++;
    SetEvent(OSEK_Task_main, TIMESUP);
    timesup = 0;
  }
}

void ecrobot_device_initialize(void)
{
  Segway1_initialize();
}

TASK(OSEK_Task_main)
{
  sampleTime = (int)(period/0.001);
  while (1) {
    WaitEvent(TIMESUP);
    ClearEvent(TIMESUP);
    Segway1_output();

    /* Get model outputs here */
    Segway1_update();
    or_mdl = 0;
  }

  TerminateTask();
}

TASK(OSEK_Task_background)
{
  TerminateTask();
}

void ecrobot_device_terminate(void)
{
  Segway1_terminate();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
