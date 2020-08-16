/* Do not edit this file. It was automatically generated. */

#ifndef HEADER_Platform
#define HEADER_Platform
/*
htop - linux/Platform.h
(C) 2014 Hisham H. Muhammad
(C) 2020 Alexander Finger
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/

#ifdef WIN32
#elif _POSIX_C_SOURCE >= 199309L
#else
#endif

#include "Action.h"
#include "MainPanel.h"
#include "BatteryMeter.h"
#include "LinuxProcess.h"
#include "SignalsPanel.h"
#ifdef WIN32
#include <windows.h>
#elif _POSIX_C_SOURCE >= 199309L
#include <time.h>   
#else
#include <unistd.h> 
#endif
#include <string.h>


typedef enum vendor_id_ {
   VENDOR_INTEL,
   VENDOR_AMD,
   VENDOR_CYRIX,
   VENDOR_VIA,
   VENDOR_TRANSMETA,
   VENDOR_UMC,
   VENDOR_NEXGEN,
   VENDOR_RISE,
   VENDOR_SIS,
   VENDOR_NSC,
   VENDOR_VORTEX,
   VENDOR_RDC,
   VENDOR_UNKNOWN 
} vendor_id;

typedef struct Stats_ {
    int rx_over;
    int tx_over;
    double rx_bytes;
    double tx_bytes;
    double rx_bytes_comp;
    double tx_bytes_comp;
    unsigned long connect_time;
    unsigned long current_time;
} Stats;



#ifndef CLAMP
#define CLAMP(x,low,high) (((x)>(high))?(high):(((x)<(low))?(low):(x)))
#endif

extern char *Platform_Vendor_CPU[];

extern ProcessField Platform_defaultFields[];

extern int Platform_cpuBigLITTLE;
extern int Platform_numberOfFields;
extern vendor_id Platform_CPU_vendor_id;

extern const SignalItem Platform_signals[];

extern const unsigned int Platform_numberOfSignals;

void Platform_setBindings(Htop_Action* keys);

extern MeterClass* Platform_meterTypes[];

/* cross-platform sleep function */
void sleep_ms(int milliseconds);

int Platform_getGpuTemp(Meter* this);

/*
 * INTEL tempX_input
 * where X is core_id + 1 despite the docs say otherwise:
 * 
 * All Sysfs entries are named with their core_id (represented here by 'X').
 * tempX_input	 - Core temperature (in millidegrees Celsius).
 * tempX_max	 - All cooling devices should be turned on (on Core2).
 * tempX_crit	 - Maximum junction temperature (in millidegrees Celsius).
 * tempX_crit_alarm - Set when Out-of-spec bit is set, never clears.
 * 		   Correct CPU operation is no longer guaranteed.
 * tempX_label	 - Contains string "Core X", where X is processor
 * 		   number. For Package temp, this will be "Physical id Y",
 * 		   where Y is the package number.
 */ 
int Platform_getCpuTemp(Meter* this);

/*
 * INTEL tempX_input
 * where X is core_id + 1 despite the docs say otherwise:
 * 
 * All Sysfs entries are named with their core_id (represented here by 'X').
 * tempX_input	 - Core temperature (in millidegrees Celsius).
 * tempX_max	 - All cooling devices should be turned on (on Core2).
 * tempX_crit	 - Maximum junction temperature (in millidegrees Celsius).
 * tempX_crit_alarm - Set when Out-of-spec bit is set, never clears.
 * 		   Correct CPU operation is no longer guaranteed.
 * tempX_label	 - Contains string "Core X", where X is processor
 * 		   number. For Package temp, this will be "Physical id Y",
 * 		   where Y is the package number.
 */ 
int Platform_getCoreTemp(Meter* this, int cpu);

int Platform_getCpuFreq(Meter* this, int cpu);

int Platform_getCoreFreq(Meter* this, int cpu);

int Platform_getCpuVcore();

int Platform_getCpuVcore_l(Meter* this);

int Platform_getCpuVcore_b(Meter* this);

int Platform_getCpuBigLITTLE();

int Platform_findCpuBigLITTLE(int cpucount, int *cpuBigLITTLE);

int Platform_getUptime();

void Platform_getLoadAverage(double* one, double* five, double* fifteen);

int Platform_getMaxPid();

double Platform_setCPUValues(Meter* this, int cpu);

void Platform_setMemoryValues(Meter* this);

void Platform_setSwapValues(Meter* this);

char* Platform_getProcessEnv(pid_t pid);

vendor_id Platform_getCPU_vendor_id(void);

Stats Platform_Eth0_stats;
Stats Platform_Eth1_stats;

int Platform_getEth_stats(char *devname, int id, int close_fp);

double get_wall_time(void);

#endif
