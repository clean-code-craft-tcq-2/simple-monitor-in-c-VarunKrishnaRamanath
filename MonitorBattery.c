#include "BatteryStatusLib.h"
#include "MonitorBattery.h"

bool batteryIsOk(BMSParameters BatteryParameters)
{
  bool BatteryStatus = BATTERY_HEALTH_IS_GOOD;

  BatteryStatus = BatteryStatus &&  BatteryTemperatureIsGood(BatteryParameters.ChargingTemperature, BatteryParameters.DischargingTemperature);
  BatteryStatus = BatteryStatus &&  BatteryCapacityIsGood(BatteryParameters.SoC);
  BatteryStatus = BatteryStatus &&  BatteryChargingAtGoodRate(BatteryParameters.ChargingRate);
  BatteryStatus = BatteryStatus &&  BatteryDischargingAtGoodRate(BatteryParameters.DischargingRate);

  return BatteryStatus;
}
