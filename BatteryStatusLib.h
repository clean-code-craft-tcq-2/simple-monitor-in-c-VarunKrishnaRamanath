#ifndef BATTERYSTATUSLIB_H_INCLUDED
#define BATTERYSTATUSLIB_H_INCLUDED

#include <stdbool.h>

#define BATTERY_HEALTH_IS_GOOD         true
#define BATTERY_HEALTH_IS_NOT_GOOD     false

typedef struct{
    float  MinValue;
    float  MaxValue;
}MinMaxType;

typedef struct{
    float Temperature;
    float SoC;
    float ChargingRate;
    float DischargingRate;
}BMSParameters;

inline bool IsWithinRange(float Value, const MinMaxType Range)
{
    bool WithinRange = true;
    if(Value < Range.MinValue)
    {
        WithinRange = false;
    }
    if(Value > Range.MaxValue)
    {
        WithinRange = false;
    }
    return WithinRange;
}

inline bool IsGreaterThanMinThreshold(float Value, const float MinThreshold)
{
    bool GreaterThanMinThreshold = true;
    if(Value < MinThreshold)
    {
        GreaterThanMinThreshold = false;
    }

    return GreaterThanMinThreshold;
}

inline bool IsLesserThanMaxThreshold(float Value, const float MaxThreshold)
{
    bool LesserThanMaxThreshold = true;
    if(Value > MaxThreshold)
    {
        LesserThanMaxThreshold = false;
    }
    return LesserThanMaxThreshold;
}

/* Note: All above inline functions will return true if value is equal to threshold */

#endif // BATTERYSTATUSLIB_H_INCLUDED
