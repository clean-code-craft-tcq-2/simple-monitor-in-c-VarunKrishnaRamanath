#include "BatteryStatusLib.h"
#include "MonitorBattery.h"

static bool BatteryChargingAtGoodRate(float ChargeRate)
{
    bool IsChargeRateAboveLimit = IsLesserThanMaxThreshold(ChargeRate, BatteryChargeRateMaxLimit);
    if(!IsChargeRateAboveLimit)
    {
        printf("Charging Rate is out of range!\n");
    }

    return IsChargeRateAboveLimit;
}

static bool BatteryDischargingAtGoodRate(float DischargeRate)
{
    bool IsDischargeRateAboveLimit = IsLesserThanMaxThreshold(DischargeRate, BatteryDischargeRateMaxLimit);
    if(!IsDischargeRateAboveLimit)
    {
        printf("Discharging Rate is out of range!\n");
    }

    return IsDischargeRateAboveLimit;
}

bool ChargeAndDischargeIsGood(float ChargeRate, float DischargeRate)
{
    bool IsChargeAndDischargeGood = (BatteryChargingAtGoodRate(ChargeRate) && BatteryDischargingAtGoodRate(DischargeRate));
    
    return IsChargeAndDischargeGood;
}
