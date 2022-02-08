#ifndef MONITORBATTERY_H_INCLUDED
#define MONITORBATTERY_H_INCLUDED

#define BATTERY_TYPE    LITHIUM_ION

extern bool batteryIsOk(BMSParameters BatteryParameters);
extern bool BatteryTemperatureIsGood(float temperature);
extern bool BatteryCapacityIsGood(float SoC);
extern bool BatteryChargingAtGoodRate(float ChargeRate);
extern bool BatteryDischargingAtGoodRate(float DischargeRate);

#endif // MONITORBATTERY_H_INCLUDED
