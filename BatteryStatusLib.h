#ifndef BATTERYSTATUSLIB_H_INCLUDED
#define BATTERYSTATUSLIB_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>

#define BATTERY_HEALTH_IS_GOOD         true
#define BATTERY_HEALTH_IS_NOT_GOOD     false

typedef struct{
    float  MinValue;
    float  MaxValue;
}MinMaxType;

typedef struct{
    float ChargingTemperature;
    float DischargingTemperature;
    float SoC;
    float ChargingRate;
    float DischargingRate;
}BMSParameters;

extern const MinMaxType BatteryChargingTemperatureRange;
extern const MinMaxType BatteryDischargeTemperatureRange;
extern const MinMaxType BatterySoCRange;
extern const float BatteryChargeRateMaxLimit;
extern const float BatteryDischargeRateMaxLimit;

static inline bool IsWithinRange(float Value, const MinMaxType Range)
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

static inline bool IsGreaterThanMinThreshold(float Value, const float MinThreshold)
{
    bool GreaterThanMinThreshold = true;
    if(Value < MinThreshold)
    {
        GreaterThanMinThreshold = false;
    }

    return GreaterThanMinThreshold;
}

static inline bool IsLesserThanMaxThreshold(float Value, const float MaxThreshold)
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
