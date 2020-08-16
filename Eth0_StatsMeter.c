/*
htop - Eth0_StatsMeter.c
(C) 2020 @lex
*/

#include "Eth0_StatsMeter.h"
#include "Platform.h"
#include "CRT.h"

#include "interfaces.h"

/*{
#include "Meter.h"
}*/


int Eth0_StatsMeter_attributes[] = {
   ETH0_INTERFACE
};

/* borrowed from slurm */
static void Eth0_StatsMeter_setValues(Meter* this, char* buffer, int len) {
    int ret;
    float rxspeed;
    float txspeed;
    Settings* settings = this->pl->settings;

    if (settings->eth0_alias[0] != 0) {
        ret = Platform_getEth_stats(settings->eth0_alias, 0);
    } else {
        ret = Platform_getEth_stats("eth0", 0);
    }
    
    if (ret) {
        if (Platform_stats.rx_bytes_comp > Platform_stats.rx_bytes)
            Platform_stats.rx_bytes_comp = 0;
        if (Platform_stats.tx_bytes_comp > Platform_stats.tx_bytes)
            Platform_stats.tx_bytes_comp = 0;

        /* we assume here the refresdelay is 1 sec which sometimes is 1.5, so we have a peak */ 
        rxspeed = (Platform_stats.rx_bytes - Platform_stats.rx_bytes_comp); // fix me -> / refreshdelay;
        txspeed = (Platform_stats.tx_bytes - Platform_stats.tx_bytes_comp); // fix me -> / refreshdelay;

        xSnprintf(buffer, len, "%.2f KB/s - %.2f KB/s (TX/RX)", (float) txspeed / 1024, (float) rxspeed / 1024);

        Platform_stats.rx_bytes_comp = Platform_stats.rx_bytes;
        Platform_stats.tx_bytes_comp = Platform_stats.tx_bytes;

    } else {
        xSnprintf(buffer, len, "%s", "00.00 KB/s - 0.00 KB/s");
    }
}

MeterClass Eth0_StatsMeter_class = {
   .super = {
      .extends = Class(Meter),
      .delete = Meter_delete
   },
   .updateValues = Eth0_StatsMeter_setValues, 
   .defaultMode = TEXT_METERMODE,
   .maxItems = 8,
   .total = 100.0,
   .attributes = Eth0_StatsMeter_attributes,
   .name = "Eth0stat",
   .uiName = "Eth0 stat",
   .caption = " Eth0 stat: ",
};


