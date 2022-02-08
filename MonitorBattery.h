#ifndef MONITORBATTERY_H_INCLUDED
#define MONITORBATTERY_H_INCLUDED

#include "BatteryStatusLib.h"

#define BATTERY_TYPE    LITHIUM_ION

extern bool batteryIsOk(BMSParameters BatteryParameters);
extern bool BatteryTemperatureIsGood(float chargingTemperature, float dischargingTemperature);
extern bool BatteryCapacityIsGood(float SoC);
extern bool BatteryChargingAtGoodRate(float ChargeRate);
extern bool BatteryDischargingAtGoodRate(float DischargeRate);

#endif // MONITORBATTERY_H_INCLUDED
