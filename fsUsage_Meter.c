/*
htop - fsUsage_Meter.c
(C) 2020 @lex
*/

#include "fsUsage_Meter.h"
#include "Platform.h"
#include "CRT.h"

#include "mountpoint.h"

/*{
#include "Meter.h"
}*/


int fsUsage_Meter_attributes[] = {
   ETH1_INTERFACE
};

static void fsUsage_Meter_setValues(Meter* this, char* buffer, int len) {
    Settings* settings = this->pl->settings;
    int fs = this->param;
    if (this->pl->mountCount > 1 && fs > 1 && fs <= this->pl->mountCount) {
		if (!fs_get_stat( fs - 1, buffer, len )) {
			xSnprintf(buffer, len, "err %d", 99);
		}
	} else {
		xSnprintf(buffer, len, "err %d", 99);
	}
}

static void fsUsageMeter_init(Meter* this) {
   int fs = this->param;
   if (this->pl->mountCount > 1 && fs > 1 && fs <= this->pl->mountCount) {
      char caption[64];

      MountPoint *mount = GetMountPoints();
      if (mount != NULL ) {
		  xSnprintf(caption, sizeof(caption), "fs %s: ", mount[fs - 1].subdir);
	  } else {
		xSnprintf(caption, sizeof(caption), "fs_%d: ", fs);
	  }
      Meter_setCaption(this, caption);
   }
   if (this->param == 0)
      Meter_setCaption(this, "fsAvg");
}   
  

MeterClass fsUsage_Meter_class = {
   .super = {
      .extends = Class(Meter),
      .delete = Meter_delete
   },
   .updateValues = fsUsage_Meter_setValues, 
   .defaultMode = TEXT_METERMODE,
   .maxItems = 8,
   .total = 100.0,
   .attributes = fsUsage_Meter_attributes,
   .name = "fsStat",
   .uiName = "fs stat",
   .caption = "fs stat: ",
   .init = fsUsageMeter_init
};


