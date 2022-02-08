#include "BatteryStatusLib.h"
#include "MonitorBattery.h"

bool batteryIsOk(BMSParameters BatteryParameters)
{
  bool BatteryStatus = BATTERY_HEALTH_IS_GOOD;
  bool TempStatus, SoCStatus, ChargingStatus = false;

  TempStatus = BatteryTemperatureIsGood(BatteryParameters.ChargingTemperature, BatteryParameters.DischargingTemperature);
  SoCStatus = BatteryCapacityIsGood(BatteryParameters.SoC);
  ChargingStatus = ChargeAndDischargeIsGood(BatteryParameters.ChargingRate, BatteryParameters.DischargingRate);
  
  BatteryStatus = (TempStatus && SoCStatus && ChargingStatus);

  return BatteryStatus;
}
