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

void TestBatteryWithParam(void)
{
    /* All Ok*/
    BatteryStatusOk(0, -20.0, 20.0, 0.8, 0.3);
    BatteryStatusOk(45.0, 60.0, 80.0, 0.8, 0.3);

    /* Charging Temp not ok */
    BatteryStatusNotOk(-1, -20.0, 20.0, 0.8, 0.3);
    BatteryStatusNotOk(45.1, 60.0, 80.0, 0.8, 0.3);

    /* Discharging Temp not ok */
    BatteryStatusNotOk(0, -20.1, 20.0, 0.8, 0.3);
    BatteryStatusNotOk(45.0, 60.1, 80.0, 0.8, 0.3);

    /* Soc not ok */
    BatteryStatusNotOk(0, -20.0, 19.9, 0.8, 0.3);
    BatteryStatusNotOk(45.0, 60.0, 80.1, 0.8, 0.3);

    /* Charging rate not ok */
    BatteryStatusNotOk(0, -20.0, 20.0, 0.81, 0.3);
    /* Discharging rate not ok */
    BatteryStatusNotOk(45.0, 60.0, 80.0, 0.8, 0.31);
}

int main() {

    TestBatteryWithParam();


  return 0;
}
