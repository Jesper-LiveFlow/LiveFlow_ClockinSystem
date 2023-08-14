#pragma once

#include <Arduino.h>

class NoDelayDelay {
  private:
    uint32_t delay; // Delay in milliseconds
    uint32_t lastTime; // Time since last delay was completed

  public:
    NoDelayDelay(uint32_t delay); // Constructor function (delay: desired delay until check function returns true)

    bool check(); // Check whether delay has been passed (true or false)

    uint32_t getElapsedTime(); // Get elapsed time since last delay was completed

    void reset(); // Resets delay
};