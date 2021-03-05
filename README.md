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


