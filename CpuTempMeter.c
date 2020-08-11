/*
htop - CpuTempMeter.c
(C) 2020 @lex
*/

#include "CpuTempMeter.h"
#include "Platform.h"
#include "CRT.h"

/*{
#include "Meter.h"
}*/

int CpuTempMeter_attributes[] = {
   CPU_TEMP
};

static void CpuTempMeter_setValues(Meter* this, char* buffer, int len) {
   int Temp = Platform_getCpuTemp(this);
   if (Temp > 1000) {
       Temp /= 1000;
   }
   xSnprintf(buffer, len, "%4d C", Temp);
}

MeterClass CpuTempMeter_class = {
   .super = {
      .extends = Class(Meter),
      .delete = Meter_delete
   },
   .updateValues = CpuTempMeter_setValues, 
   .defaultMode = TEXT_METERMODE,
   .maxItems = 1,
   .total = 100.0,
   .attributes = CpuTempMeter_attributes,
   .name = "CpuTemp",
   .uiName = "CpuTemp",
   .caption = "Cpu Temp: "
};

int CoreTempMeter_attributes[] = {
   CORE_TEMP
};

static void CoreTempMeter_setValues(Meter* this, char* buffer, int len) {
   int cpu = this->param;
   if (cpu > this->pl->cpuCount) {
      xSnprintf(buffer, len, "absent");
      return;
   }
   int Temp = Platform_getCoreTemp(this, cpu + 1);
   if (Temp > 1000) {
       Temp /= 1000;
   }
   xSnprintf(buffer, len, "%4d C", Temp);
}

static void CoreTempMeter_init(Meter* this) {
   int cpu = this->param;
   if (this->pl->cpuCount > 1) {
      char caption[20];
      xSnprintf(caption, sizeof(caption), "CPU%d Temp: ", cpu);
      Meter_setCaption(this, caption);
   }
   if (this->param == 0)
      Meter_setCaption(this, "Avg");
}

MeterClass CoreTempMeter_class = {
   .super = {
      .extends = Class(Meter),
      .delete = Meter_delete
   },
   .updateValues = CoreTempMeter_setValues, 
   .defaultMode = TEXT_METERMODE,
   .maxItems = 1,
   .total = 100.0,
   .attributes = CoreTempMeter_attributes,
   .name = "CoreTemp",
   .uiName = "CoreTemp",
   .caption = "CoreTemp",
   .init = CoreTempMeter_init
};
