#include "BatteryStatusLib.h"
#include "MonitorBattery.h"

bool BatteryCapacityIsGood(float SoC)
{
    bool IsSoCWithinRange = IsWithinRange(SoC, BatterySoCRange);
    if(!IsSoCWithinRange)
    {
        printf("State Of Charge out of range!\n");
    }

    return IsSoCWithinRange;
}
