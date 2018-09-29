/*-- Simulation.h ----------------------------------------------------------
 
  Header file to define a Simulation data type for simulating the operation
  of an information/reservation center that services telephone calls.

  Basic operations:
    constructor:       constructs a Simulation object
    run():             carry out the simulation
    display():         output results of the simulation
    service():         service an incoming call
    checkForNewCall(): check if a new call has come in
    
  Note:  Assumes availability of a queue class with elements of type Call.
 -------------------------------------------------------------------------*/

#include <iostream>       // istream, ostream, >>, <<
#include <ctime>          // time()

#ifndef SIMULATION
#define SIMULATION

#include "Timer.h"
#include "Call.h"
#include "LQueue.h"       // Queue with elements of type Call

const int NUM_CATEGORIES = 5;
class Simulation
{
 public:
  /***** Function Members *****/
 
 private:
  /***** Data Members *****/   
   //-- Inputs
   int    myLengthOfSimulation;
   double myArrivalRate;
   int    myServicePercent[NUM_CATEGORIES];

   //-- Outputs
   int    myCallsReceived;
   double myTotalWaitingTime;

   //-- Countdown Timer
   Timer myTimer;
   
   //-- Queue of calls waiting for service
   Queue myIncomingCalls;

};  // end of class declaration

#endif