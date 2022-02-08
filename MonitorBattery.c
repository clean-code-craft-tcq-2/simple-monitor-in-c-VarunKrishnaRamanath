#include "BatteryStatusLib.h"
#include "MonitorBattery.h"

bool batteryIsOk(BMSParameters BatteryParameters) 
{
  bool BatteryStatus = BATTERY_HEALTH_IS_GOOD;

  BatteryStatus &&= BatteryTemperatureIsGood(BatteryParameters.ChargingTemperature, BatteryParameters.DischargingTemperature);
  BatteryStatus &&= BatteryCapacityIsGood(BatteryParameters.SoC);
  BatteryStatus &&= BatteryChargingAtGoodRate(BatteryParameters.ChargingRate);
  BatteryStatus &&= BatteryDischargingAtGoodRate(BatteryParameters.DischargingRate);

  return BatteryStatus;
}
