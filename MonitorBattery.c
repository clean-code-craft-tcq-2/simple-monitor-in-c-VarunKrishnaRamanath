#include "BatteryStatusLib.h"
#include "MonitorBattery.h"

bool batteryIsOk(BMSParameters BatteryParameters)
{
  bool BatteryStatus = BATTERY_HEALTH_IS_GOOD;
  bool TempStatus, SoCStatus, ChargingStatus, DischargeStatus = FALSE;

  TempStatus = BatteryTemperatureIsGood(BatteryParameters.ChargingTemperature, BatteryParameters.DischargingTemperature);
  SoCStatus = BatteryCapacityIsGood(BatteryParameters.SoC);
  ChargingStatus = BatteryChargingAtGoodRate(BatteryParameters.ChargingRate);
  DischargeStatus = BatteryDischargingAtGoodRate(BatteryParameters.DischargingRate);
  
  BatteryStatus = (TempStatus && SoCStatus && ChargingStatus && DischargeStatus);

  return BatteryStatus;
}
