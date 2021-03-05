# htop_2.2.2-amd64

* htop 2.2.2-2

  https://github.com/avafinger/htop_2.2.2-amd64/releases/tag/v0.1

  ![F2 config](https://github.com/avafinger/htop_2.2.2-amd64/raw/master/amd64.png)

* htop 2.2.2-2 (fix)

  https://github.com/avafinger/htop_2.2.2-amd64/releases/tag/v0.2

  ![Core Freq and Temp](https://github.com/avafinger/htop_2.2.2-amd64/raw/master/htop-core-monitor-freq-temp.png)
  
  
  ![Eth0 stats](https://github.com/avafinger/htop_2.2.2-amd64/raw/master/eth0_stats.png)


  https://github.com/avafinger/htop_2.2.2-amd64/releases/tag/v0.3

* htop 2.2.2-3 (Eth speed)

  ![Eth0 stats](https://github.com/avafinger/htop_2.2.2-amd64/raw/master/eth-stat-speed.png)


## Block Device speed stats

Add support for Block speed stats for the following:
* sda
* sdb
* sdc
* sdd
* mmcblk0
* mmcblk1
* mmcblk2
* mmcblk3

https://github.com/avafinger/htop_2.2.2-amd64/releases/tag/v0.4

![sda stats](https://github.com/avafinger/htop_2.2.2-amd64/raw/master/block_dev_stats.png)


* htop 2.2.2-7 (fs and fix)

  Add support for **fs** stats on mount points subdir compatible with **df** info.
  Display Size  Used Avail Use% 

  Minor fix for CoreFreq and CoreTemp


  https://github.com/avafinger/htop_2.2.2-amd64/releases/tag/v0.7

* htop 2.2.2-8 (Logged in users meter)

  Add logged in user counter
  
  https://github.com/avafinger/htop_2.2.2-amd64/releases/tag/v0.8
  
  ![sda stats](https://github.com/avafinger/htop_2.2.2-amd64/raw/master/htop_users.png)

  Htop 2.2.2-9 running on RockPi X
  
  ![RockPi X](https://github.com/avafinger/htop_2.2.2-amd64/raw/master/rockpix.png)
  
  **htop config for RockPiX (Ubuntu Kernel)**
  
      # Beware! This file is rewritten by htop when settings are changed in the interface.
      # The parser is also very primitive, and not human-friendly.
      fields=0 48 17 18 38 39 40 2 46 47 49 1
      sort_key=46
      sort_direction=1
      hide_threads=0
      hide_kernel_threads=1
      hide_userland_threads=0
      shadow_other_users=0
      show_thread_names=0
      show_program_path=1
      highlight_base_name=0
      highlight_megabytes=1
      highlight_threads=1
      tree_view=0
      header_margin=1
      detailed_cpu_time=0
      cpu_count_from_zero=0
      update_process_names=0
      account_guest_in_cpu_meter=0
      color_scheme=0
      delay=15
      left_meters=AllCPUs Memory Swap CoreTemp(1) CoreTemp(2) CoreTemp(3) CoreTemp(4) fsStat(2) fsStat(1) Eth0
      left_meter_modes=1 1 1 2 2 2 2 2 2 2
      right_meters=Tasks LoadAverage Uptime Hostname Kernelversion OSversion CoreFreq(1) CoreFreq(2) CoreFreq(3) CoreFreq(4) UserLoggedIn mmcblk0stat Wlan0
      right_meter_modes=2 2 2 2 2 2 2 2 2 2 2 2 2
      # SBC hardware and Kernel specific path.
      # Editable manually.
      BoardName=
      CpuFreq_handler=
      CpuTemp_handler=/sys/devices/platform/coretemp.0/hwmon/hwmon5/temp%d_input
      CpuVCore_l_handler=
      CpuVCore_b_handler=
      GpuVCore_handler=
      GpuTemp_handler=
      # Wlan / Eth alias
      eth0_alias=enp1s0
      eth1_alias=
      wlan0_alias=
      wlan1_alias=


## handlers

Override default handlers for different kernel versions and configs.

Files: ~/.config/htop/htoprc-ng and /root/.config/htop/htoprc-ng

    # SBC hardware and Kernel specific path.
    # Editable manually.
    BoardName=
    CpuFreq_handler=
    CpuTemp_handler=/sys/class/hwmon/hwmon2/temp%d_input
    CpuVCore_l_handler=
    CpuVCore_b_handler=
    GpuVCore_handler=
    GpuTemp_handler=/sys/class/hwmon/hwmon1/temp1_input
    # Wlan / Eth alias
    eth0_alias=enp2s0
    eth1_alias=
    wlan0_alias=
    wlan1_alias=


## Finding the handlers in your Hardware

You can search /sys tree or have some clues running **sensors**.

Install and run sensors:

	@rockpix:~$ sudo sensors-detect
	# sensors-detect version 3.6.0
	# System: Radxa ROCK Pi X [v1.4]
	# Kernel: 5.11.1-rockpix x86_64
	# Processor: Intel(R) Atom(TM) x5-Z8350 CPU @ 1.44GHz (6/76/4)
	
	This program will help you determine which kernel modules you need
	to load to use lm_sensors most effectively. It is generally safe
	and recommended to accept the default answers to all questions,
	unless you know what you're doing.
	
	Some south bridges, CPUs or memory controllers contain embedded sensors.
	Do you want to scan for them? This is totally safe. (YES/no): y
	Module cpuid loaded successfully.
	Silicon Integrated Systems SIS5595...                       No
	VIA VT82C686 Integrated Sensors...                          No
	VIA VT8231 Integrated Sensors...                            No
	AMD K8 thermal sensors...                                   No
	AMD Family 10h thermal sensors...                           No
	AMD Family 11h thermal sensors...                           No
	AMD Family 12h and 14h thermal sensors...                   No
	AMD Family 15h thermal sensors...                           No
	AMD Family 16h thermal sensors...                           No
	AMD Family 17h thermal sensors...                           No
	AMD Family 15h power sensors...                             No
	AMD Family 16h power sensors...                             No
	Hygon Family 18h thermal sensors...                         No
	Intel digital thermal sensor...                             Success!
	    (driver `coretemp')
	Intel AMB FB-DIMM thermal sensor...                         No
	Intel 5500/5520/X58 thermal sensor...                       No
	VIA C7 thermal sensor...                                    No
	VIA Nano thermal sensor...                                  No
	
	Some Super I/O chips contain embedded sensors. We have to write to
	standard I/O ports to probe them. This is usually safe.
	Do you want to scan for Super I/O sensors? (YES/no): y
	Probing for Super-I/O at 0x2e/0x2f
	Trying family `National Semiconductor/ITE'...               No
	Trying family `SMSC'...                                     No
	Trying family `VIA/Winbond/Nuvoton/Fintek'...               No
	Trying family `ITE'...                                      No
	Probing for Super-I/O at 0x4e/0x4f
	Trying family `National Semiconductor/ITE'...               No
	Trying family `SMSC'...                                     No
	Trying family `VIA/Winbond/Nuvoton/Fintek'...               No
	Trying family `ITE'...                                      No
	
	Some systems (mainly servers) implement IPMI, a set of common interfaces
	through which system health data may be retrieved, amongst other things.
	We first try to get the information from SMBIOS. If we don't find it
	there, we have to read from arbitrary I/O ports to probe for such
	interfaces. This is normally safe. Do you want to scan for IPMI
	interfaces? (YES/no): y
	Probing for `IPMI BMC KCS' at 0xca0...                      Success!
	    (confidence 4, driver `to-be-written')
	Probing for `IPMI BMC SMIC' at 0xca8...                     Success!
	    (confidence 4, driver `to-be-written')
	
	Some hardware monitoring chips are accessible through the ISA I/O ports.
	We have to write to arbitrary I/O ports to probe them. This is usually
	safe though. Yes, you do have ISA I/O ports even if you do not have any
	ISA slots! Do you want to scan the ISA I/O ports? (YES/no): y
	Probing for `National Semiconductor LM78' at 0x290...       No
	Probing for `National Semiconductor LM79' at 0x290...       No
	Probing for `Winbond W83781D' at 0x290...                   No
	Probing for `Winbond W83782D' at 0x290...                   No
	
	Lastly, we can probe the I2C/SMBus adapters for connected hardware
	monitoring devices. This is the most risky part, and while it works
	reasonably well on most systems, it has been reported to cause trouble
	on some systems.
	Do you want to probe the I2C/SMBus adapters now? (YES/no): y
	Sorry, no supported PCI bus adapters found.
	
	Next adapter: Synopsys DesignWare I2C adapter (i2c-0)
	Do you want to scan it? (YES/no/selectively): y
	Adapter doesn't support all probing functions.
	Some addresses won't be probed.
	
	Next adapter: Synopsys DesignWare I2C adapter (i2c-1)
	Do you want to scan it? (YES/no/selectively): y
	Adapter doesn't support all probing functions.
	Some addresses won't be probed.
	Client at address 0x1a can not be probed - unload all client drivers first!
	
	Next adapter: Synopsys DesignWare I2C adapter (i2c-2)
	Do you want to scan it? (YES/no/selectively): y
	Adapter doesn't support all probing functions.
	Some addresses won't be probed.
	
	Next adapter: Synopsys DesignWare I2C adapter (i2c-3)
	Do you want to scan it? (YES/no/selectively): y
	Adapter doesn't support all probing functions.
	Some addresses won't be probed.
	
	Next adapter: Synopsys DesignWare I2C adapter (i2c-4)
	Do you want to scan it? (YES/no/selectively): y
	Adapter doesn't support all probing functions.
	Some addresses won't be probed.
	
	Next adapter: Synopsys DesignWare I2C adapter (i2c-5)
	Do you want to scan it? (YES/no/selectively): y
	Adapter doesn't support all probing functions.
	Some addresses won't be probed.
	
	Next adapter: Synopsys DesignWare I2C adapter (i2c-6)
	Do you want to scan it? (YES/no/selectively): y
	Adapter doesn't support all probing functions.
	Some addresses won't be probed.
	
	Next adapter: i915 gmbus ssc (i2c-7)
	Do you want to scan it? (yes/NO/selectively): y
	
	Next adapter: i915 gmbus vga (i2c-8)
	Do you want to scan it? (yes/NO/selectively): y
	
	Next adapter: i915 gmbus panel (i2c-9)
	Do you want to scan it? (yes/NO/selectively): y
	
	Next adapter: i915 gmbus dpc (i2c-10)
	Do you want to scan it? (yes/NO/selectively): y
	
	Next adapter: i915 gmbus dpb (i2c-11)
	Do you want to scan it? (yes/NO/selectively): y
	
	Next adapter: i915 gmbus dpd (i2c-12)
	Do you want to scan it? (yes/NO/selectively): y
	
	Next adapter: AUX D/DP D (i2c-13)
	Do you want to scan it? (yes/NO/selectively): y
	
	
	Now follows a summary of the probes I have just done.
	Just press ENTER to continue: 
	
	Driver `to-be-written':
	  * ISA bus, address 0xca0
	    Chip `IPMI BMC KCS' (confidence: 4)
	  * ISA bus, address 0xca8
	    Chip `IPMI BMC SMIC' (confidence: 4)
	
	Driver `coretemp':
	  * Chip `Intel digital thermal sensor' (confidence: 9)
	
	Note: there is no driver for IPMI BMC KCS yet.
	Check https://hwmon.wiki.kernel.org/device_support_status for updates.
	
	To load everything that is needed, add this to /etc/modules:
	#----cut here----
	# Chip drivers
	coretemp
	#----cut here----
	If you have some drivers built into your kernel, the list above will
	contain too many modules. Skip the appropriate ones!
	
	Do you want to add these lines automatically to /etc/modules? (yes/NO)n
	
	Unloading cpuid... OK
	

We know now coretemp is our driver and can read a more accurate Temp for each core:

	ubuntu@rockpix:~$ sudo find / -name coretemp*
	/media/ubuntu/kodi/linux-5.11.1/include/config/sensors/coretemp.h
	/media/ubuntu/kodi/linux-5.11.1/drivers/hwmon/coretemp.mod
	/media/ubuntu/kodi/linux-5.11.1/drivers/hwmon/coretemp.ko
	/media/ubuntu/kodi/linux-5.11.1/drivers/hwmon/coretemp.c
	/media/ubuntu/kodi/linux-5.11.1/drivers/hwmon/coretemp.mod.o
	/media/ubuntu/kodi/linux-5.11.1/drivers/hwmon/coretemp.o
	/media/ubuntu/kodi/linux-5.11.1/drivers/hwmon/coretemp.mod.c
	/media/ubuntu/kodi/linux-5.11.1/Documentation/hwmon/coretemp.rst
	/home/ubuntu/linux-5.10/Documentation/hwmon/coretemp.rst
	/home/ubuntu/linux-5.10/drivers/hwmon/coretemp.c
	/usr/lib/modules/5.11.1-rockpix/kernel/drivers/hwmon/coretemp.ko
	/usr/lib/modules/5.10.18-rockpix/kernel/drivers/hwmon/coretemp.ko
	/sys/devices/platform/coretemp.0
	/sys/bus/platform/devices/coretemp.0
	/sys/bus/platform/drivers/coretemp
	/sys/bus/platform/drivers/coretemp/coretemp.0
	/sys/module/coretemp

Run **sensors**, so we have have some output to choose:

	ubuntu@rockpix:~$ sensors
	soc_dts1-virtual-0
	Adapter: Virtual device
	temp1:        +55.0°C  
	
	acpitz-acpi-0
	Adapter: ACPI interface
	temp1:        +54.9°C  (crit = +100.0°C)
	
	coretemp-isa-0000
	Adapter: ISA adapter
	Core 0:       +58.0°C  (high = +90.0°C, crit = +90.0°C)
	Core 1:       +58.0°C  (high = +90.0°C, crit = +90.0°C)
	Core 2:       +58.0°C  (high = +90.0°C, crit = +90.0°C)
	Core 3:       +58.0°C  (high = +90.0°C, crit = +90.0°C)
	
	soc_dts0-virtual-0
	Adapter: Virtual device
	temp1:        +58.0°C  
	
	ubuntu@rockpix:~$

Check if you have coretemp modules loaded:

	ubuntu@rockpix:~$ lsmod
	Module                  Size  Used by
	fuse                  126976  1
	ntfs                  212992  0
	msdos                  20480  0
	uvcvideo              110592  0
	videobuf2_vmalloc      20480  1 uvcvideo
	videobuf2_memops       20480  1 videobuf2_vmalloc
	snd_usb_audio         274432  0
	videobuf2_v4l2         24576  1 uvcvideo
	videobuf2_common       45056  2 videobuf2_v4l2,uvcvideo
	snd_hwdep              16384  1 snd_usb_audio
	videodev              212992  3 videobuf2_v4l2,uvcvideo,videobuf2_common
	snd_usbmidi_lib        36864  1 snd_usb_audio
	mc                     53248  5 videodev,snd_usb_audio,videobuf2_v4l2,uvcvideo,videobuf2_common
	cmac                   16384  1
	snd_soc_sst_cht_bsw_nau8824    20480  0
	gpio_keys              20480  0
	coretemp               20480  0
	wdat_wdt               20480  0
	watchdog               24576  1 wdat_wdt
	axp20x_pek             16384  0
	nls_ascii              16384  1
	nls_cp437              20480  1
	vfat                   20480  1
	fat                    77824  2 msdos,vfat
	input_leds             16384  0
	btsdio                 20480  0
	brcmfmac              266240  0
	mousedev               24576  0
	snd_intel_sst_acpi     20480  1
	snd_intel_dspcfg       16384  1 snd_intel_sst_acpi
	snd_soc_acpi_intel_match    32768  1 snd_intel_sst_acpi
	snd_soc_acpi           16384  2 snd_soc_acpi_intel_match,snd_intel_sst_acpi
	snd_intel_sst_core     57344  1 snd_intel_sst_acpi
	snd_soc_sst_atom_hifi2_platform    98304  2 snd_intel_sst_core
	snd_soc_nau8824        61440  2 snd_soc_sst_cht_bsw_nau8824
	snd_hdmi_lpe_audio     32768  2
	snd_soc_core          233472  3 snd_soc_sst_cht_bsw_nau8824,snd_soc_nau8824,snd_soc_sst_atom_hifi2_platform
	snd_compress           28672  1 snd_soc_core
	hci_uart               45056  0
	cfg80211              393216  1 brcmfmac
	btbcm                  20480  1 hci_uart
	brcmutil               16384  1 brcmfmac
	processor_thermal_device    20480  0
	snd_pcm               102400  7 snd_soc_sst_cht_bsw_nau8824,snd_usb_audio,snd_soc_nau8824,snd_compress,snd_hdmi_lpe_audio,snd_soc_sst_atom_hifi2_platform,snd_soc_core
	mei_txe                28672  0
	snd_seq_midi           20480  0
	processor_thermal_rfim    16384  1 processor_thermal_device
	processor_thermal_mbox    16384  1 processor_thermal_device
	bluetooth             585728  25 btsdio,hci_uart,btbcm
	processor_thermal_rapl    20480  1 processor_thermal_device
	mei                   110592  1 mei_txe
	snd_seq_midi_event     16384  1 snd_seq_midi
	intel_soc_dts_iosf     20480  1 processor_thermal_device
	snd_rawmidi            36864  2 snd_seq_midi,snd_usbmidi_lib
	intel_atomisp2_pm      16384  0
	jitterentropy_rng      16384  1
	snd_seq                81920  2 snd_seq_midi,snd_seq_midi_event
	drbg                   28672  1
	ansi_cprng             16384  0
	ecdh_generic           16384  2 bluetooth
	snd_seq_device         16384  3 snd_seq,snd_seq_midi,snd_rawmidi
	ecc                    32768  1 ecdh_generic
	snd_timer              36864  2 snd_seq,snd_pcm
	snd                    86016  17 snd_seq,snd_soc_sst_cht_bsw_nau8824,snd_seq_device,snd_hwdep,snd_usb_audio,snd_usbmidi_lib,snd_timer,snd_compress,snd_hdmi_lpe_audio,snd_soc_sst_atom_hifi2_platform,snd_soc_core,snd_pcm,snd_rawmidi
	8250_dw                16384  0
	tpm_crb                20480  0
	8250                   49152  1 8250_dw
	8250_base              49152  2 8250,8250_dw
	soundcore              16384  1 snd
	tpm_tis                16384  0
	serial_mctrl_gpio      16384  2 8250,8250_base
	tpm_tis_core           28672  1 tpm_tis
	serial_core            45056  4 8250,serial_mctrl_gpio,8250_base
	tpm                    65536  3 tpm_tis,tpm_crb,tpm_tis_core
	pwm_lpss_platform      16384  0
	pwm_lpss               16384  1 pwm_lpss_platform
	rng_core               16384  1 tpm
	evdev                  20480  18
	int3400_thermal        20480  0
	int3403_thermal        20480  0
	int3406_thermal        16384  0
	acpi_thermal_rel       16384  1 int3400_thermal
	int340x_thermal_zone    16384  2 int3403_thermal,processor_thermal_device
	acpi_pad               20480  0
	intel_int0002_vgpio    16384  1
	soc_button_array       20480  0
	sch_fq_codel           20480  3
	efivarfs               16384  1
	ip_tables              28672  0
	x_tables               36864  1 ip_tables
	mmc_block              49152  3
	crc32_pclmul           16384  0
	crc32c_intel           24576  3
	spi_pxa2xx_platform    32768  0
	aesni_intel           368640  1
	crypto_simd            16384  1 aesni_intel
	cryptd                 20480  1 crypto_simd
	glue_helper            16384  1 aesni_intel
	r8169                  86016  0
	realtek                28672  1
	mdio_devres            16384  1 r8169
	libphy                 94208  3 r8169,mdio_devres,realtek
	lpc_ich                28672  0
	thermal                20480  0
	axp20x_i2c             16384  0
	regmap_i2c             16384  2 snd_soc_nau8824,axp20x_i2c
	axp20x                 32768  1 axp20x_i2c
	mfd_core               20480  2 axp20x,lpc_ich
	sdhci_acpi             24576  0
	sdhci                  61440  1 sdhci_acpi
	dw_dmac                16384  8
	dw_dmac_core           32768  1 dw_dmac
	mmc_core              143360  5 sdhci,mmc_block,btsdio,brcmfmac,sdhci_acpi
	hid_generic            16384  0
	usbhid                 57344  0
	hid                   126976  2 usbhid,hid_generic
	ubuntu@rockpix:~$ lsmod|grep coretemp
	coretemp               20480  0
	ubuntu@rockpix:~$ 

Finding the handlers for CoreTemp:

	ubuntu@rockpix:~$ sudo su
	root@rockpix:/home/ubuntu# cd /sys/bus/platform/drivers/coretemp
	root@rockpix:/sys/bus/platform/drivers/coretemp# ll
	total 0
	drwxr-xr-x  2 root root    0 Feb 25 21:07 ./
	drwxr-xr-x 43 root root    0 Feb 25 21:07 ../
	--w-------  1 root root 4096 Mar  5 21:42 bind
	lrwxrwxrwx  1 root root    0 Mar  5 21:42 coretemp.0 -> ../../../../devices/platform/coretemp.0/
	lrwxrwxrwx  1 root root    0 Mar  5 21:36 module -> ../../../../module/coretemp/
	--w-------  1 root root 4096 Feb 25 21:07 uevent
	--w-------  1 root root 4096 Mar  5 21:42 unbind
	root@rockpix:/sys/bus/platform/drivers/coretemp# cat coretemp.0/
	driver/          hwmon/           power/           uevent
	driver_override  modalias         subsystem/       
	root@rockpix:/sys/bus/platform/drivers/coretemp# cat coretemp.0/hwmon/hwmon3/
	device/           temp2_label       temp4_crit        temp5_input
	name              temp2_max         temp4_crit_alarm  temp5_label
	power/            temp3_crit        temp4_input       temp5_max
	subsystem/        temp3_crit_alarm  temp4_label       uevent
	temp2_crit        temp3_input       temp4_max         
	temp2_crit_alarm  temp3_label       temp5_crit        
	temp2_input       temp3_max         temp5_crit_alarm  
	root@rockpix:/sys/bus/platform/drivers/coretemp# cat coretemp.0/hwmon/hwmon3/temp*_label
	Core 0
	Core 1
	Core 2
	Core 3
	root@rockpix:/sys/bus/platform/drivers/coretemp# cat coretemp.0/hwmon/hwmon3/temp*_input
	57000
	57000
	58000
	58000
	root@rockpix:/sys/bus/platform/drivers/coretemp# 

or a short path for the kernel 5.11.1 on RockPi X:

    ubuntu@rockpix:~$ cat /sys/class/hwmon/hwmon3/temp*_input
    57000
    57000
    57000
    57000

and the longest would be:

    ubuntu@rockpix:~$ cat /sys/bus/platform/drivers/coretemp/coretemp.0/hwmon/hwmon3/temp*_input
    56000
    56000
    57000
    57000

![htop 2.2.2-10 on RockPi X](https://github.com/avafinger/htop_2.2.2-amd64/raw/master/rockpix_handlers.png
