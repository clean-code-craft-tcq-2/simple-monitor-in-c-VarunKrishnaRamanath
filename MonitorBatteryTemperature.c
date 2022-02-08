#include "BatteryStatusLib.h"
#include "MonitorBattery.h"

bool BatteryTemperatureIsGood(float chargingTemperature, float dischargingTemperature)
{
    bool IsChargingTempWithinRange = IsWithinRange(chargingTemperature, BatteryChargingTemperatureRange);
    bool IsDischargingTempWithinRange = IsWithinRange(dischargingTemperature, BatteryDischargeTemperatureRange);
    bool TempStatus = (IsChargingTempWithinRange && IsDischargingTempWithinRange);

    if(!TempStatus)
    {
        printf("Temperature out of range!\n");
    }

    return TempStatus;
}
