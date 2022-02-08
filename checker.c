#include <stdio.h>
#include <assert.h>
#include "MonitorBattery.h"
#include "BatteryStatusLib.h"

void BatteryStatusOk(float chargingTemperature, float dischargingTemperature, float SoC, float ChargingRate, float DischargingRate)
{
    BMSParameters BatteryParameters = {chargingTemperature, dischargingTemperature, SoC, ChargingRate, DischargingRate};

    assert(batteryIsOk(BatteryParameters));
}

void BatteryStatusNotOk(float chargingTemperature, float dischargingTemperature, float SoC, float ChargingRate, float DischargingRate)
{
    BMSParameters BatteryParameters = {chargingTemperature, dischargingTemperature, SoC, ChargingRate, DischargingRate};

    assert(!batteryIsOk(BatteryParameters));
}

int main() {

    BatteryStatusOk(50, 10, 50, 0.5, 0.2);
    BatteryStatusNotOk(85, 10, 50, 0.5, 0.3);
    BatteryStatusNotOk(-20, -30, 50, 0.5, 0.3);
    BatteryStatusNotOk(-20, 10, 81, 0.5, 0.3);
    BatteryStatusNotOk(-20, 10, 11, 0.5, 0.3);
    BatteryStatusNotOk(55, 10, 55, 0.81, 0.3);
    BatteryStatusNotOk(50, 10, 50, 0.8, 0.31);
    BatteryStatusNotOk(85, 10, 50, 0.8, 0.3);

  return 0;
}
