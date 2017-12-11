/*
    Copyright (c) 2017 Declan Freeman-Gleason. All rights reserved.

    This file is part of Ferries Over Winslow.

    Ferries Over Winslow is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Ferries Over Winslow is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this Ferries Over Winslow.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MotorManager_h
#define MotorManager_h

#include <functional>
#include <Wire.h>
#include <AccelStepper.h>
#include <Adafruit_MotorShield.h>

class MotorManager {
  public:
    enum class Modes {
      DOUBLE_CLOCK,
      DOUBLE_SLIDE,
      SINGLE_TEST
    };

    MotorManager(Modes mode);

    void update();
    void setMode(Modes mode);
  private:
    Modes mode;

    Adafruit_MotorShield motorShield;
    Adafruit_StepperMotor *primaryAdafruitStepper = NULL;
    Adafruit_StepperMotor *secondaryAdafruitStepper = NULL;
    AccelStepper *primaryStepper = NULL;
    AccelStepper *secondaryStepper = NULL;
};

#endif
