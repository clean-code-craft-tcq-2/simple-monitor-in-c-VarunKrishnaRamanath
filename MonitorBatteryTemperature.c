#include "BatteryStatusLib.h"
#include "MonitorBattery.h"

bool BatteryTemperatureIsGood(float temperature)
{
    bool IsTemperatureWithinRange = IsWithinRange(temperature, BatteryChargingTemperatureRange);
    bool IsTemperatureWithinRange &&= IsWithinRange(temperature, BatteryDischargingTemperatureRange);

    if(!IsTemperatureWithinRange)
    {
        printf("Temperature out of range!\n");
    }

    return IsTemperatureWithinRange;
}
