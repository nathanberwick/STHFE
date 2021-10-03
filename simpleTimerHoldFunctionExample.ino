#include <SimpleTimer.h>
//SYSTEM VARIABLES
SimpleTimer timer;
const int switchPin = 7;
bool switchPressed = false;
bool resetFlag = false;
bool switchDebouncer = false;
const int timerLengthMs = 2000;
int timerID;

void setup()
{
  
  pinMode(switchPin, INPUT);
  timerID = timer.setInterval(timerLengthMs, setTimerFlag);
  timer.enable(timerID);
}

void loop()
{
  timer.run();
  timerCheck();

  //reset LEDs if timer exceeded
  if (resetFlag)
    reset();
}

void setTimerFlag()
{
  resetFlag = true;
}

void timerCheck()
{
    switchPressed = digitalRead(switchPin);
    //switch released
    if (!switchPressed && switchDebouncer)
    {
      switchDebouncer = false;
      timer.disable(timerID);
    }
    //switch pressed
    else if (switchPressed && !switchDebouncer)
    {
      //resetTimer
      resetFlag = false; //TODO: check whether this is necessary here
      timer.enable(timerID);
    }
}

void reset()
{
    resetFlag = false;
    timer.disable(timerID);
}
