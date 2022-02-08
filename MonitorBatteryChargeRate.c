#include "BatteryStatusLib.h"
#include "MonitorBattery.h"

bool BatteryChargingAtGoodRate(float ChargeRate)
{
    bool IsChargeRateAboveLimit = IsLesserThanMaxThreshold(ChargeRate, BatteryChargeRateMaxLimit);
    if(!IsChargeRateAboveLimit)
    {
        printf("Charging Rate is out of range!\n");
    }

    return IsChargeRateAboveLimit;
}

bool BatteryDischargingAtGoodRate(float DischargeRate)
{
    bool IsDischargeRateAboveLimit = IsLesserThanMaxThreshold(DischargeRate, BatteryDishargeRateMaxLimit);
    if(!IsDischargeRateAboveLimit)
    {
        printf("Discharging Rate is out of range!\n");
    }

    return IsDischargeRateAboveLimit;
}
