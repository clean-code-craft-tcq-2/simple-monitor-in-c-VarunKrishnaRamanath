#include "BatteryStatusLib.h"
#include "MonitorBattery.h"

bool batteryIsOk(BMSParameters BatteryParameters) {
  bool BatteryStatus = BATTERY_HEALTH_IS_GOOD;

  if(!BatteryTemperatureIsGood(BatteryParameters.Temperature))
  {
      BatteryStatus = BATTERY_HEALTH_IS_NOT_GOOD;
  }
  if(!BatteryCapacityIsGood(BatteryParameters.SoC))
  {
      BatteryStatus = BATTERY_HEALTH_IS_NOT_GOOD;
  }
  if(!BatteryChargingAtGoodRate(BatteryParameters.ChargingRate))
  {
      BatteryStatus = BATTERY_HEALTH_IS_NOT_GOOD;
  }
  if(!BatteryDischargingAtGoodRate(BatteryParameters.DischargingRate))
  {
      BatteryStatus = BATTERY_HEALTH_IS_NOT_GOOD;
  }

  return BatteryStatus;
}
