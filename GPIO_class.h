#ifndef GPIO_CLASS_H
#define GPIO_CLASS_H

enum PinMode
{
    Input           = 0,
    Output          = 1,
    PwmOutput       = 2,
    GpioClock       = 3,
    SoftPwmOutput   = 4,
    SoftToneOutput  = 5,
    PwmToneOutput   = 6
};

enum PudMode
{
    PudOff  = 0,
    PudDown = 1,
    PudUp   = 2
};

class GPIO_class
{
  int PinNum;
  enum PinMode PinMode;
  enum PudMode PudMode;

public:
  GPIO_class();
  ~GPIO_class();

};

#endif // GPIO_CLASS_H
