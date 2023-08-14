#include "NoDelayDelay.h"

NoDelayDelay::NoDelayDelay(uint32_t delay) {
  this->delay = delay;
  this->lastTime = millis();
}

bool NoDelayDelay::check() {
  if(millis() - this->lastTime >= this->delay) {
    reset();
    return true;
  }
  else {
    return false;
  }
}

uint32_t NoDelayDelay::getElapsedTime() {
  return millis() - this->lastTime;
}

void NoDelayDelay::reset() {
  this->lastTime = millis();
}