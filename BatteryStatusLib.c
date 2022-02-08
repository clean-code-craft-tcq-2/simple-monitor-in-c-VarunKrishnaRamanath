#include "BatteryStatusLib.h"

#if (BATTERY_TYPE == LITHIUM_ION)

const MinMaxType BatteryChargingTemperatureRange = {0.0, 45.0};
const MinMaxType BatteryDischargeTemperatureRange = {-20.0, 60.0};

#elif (BATTERY_TYPE == LEAD_ACID)
const MinMaxType BatteryChargingTemperatureRange = {-20.0, 50.0};
const MinMaxType BatteryDischargeTemperatureRange = {-20.0, 50.0};

#elif ((BATTERY_TYPE == NiCAD) || ((BATTERY_TYPE == NiMH)))
const MinMaxType BatteryChargingTemperatureRange = {0.0, 45.0};
const MinMaxType BatteryDischargeTemperatureRange = {-20.0, 65.0};

#endif

const MinMaxType BatterySoCRange = {20.0, 80.0};

const float BatteryChargeRateMaxLimit = 0.8;

const float BatteryDischargeRateMaxLimit = 0.3;
