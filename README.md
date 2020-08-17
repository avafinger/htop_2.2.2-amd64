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

# Block Device speed stats

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


## handlers

Override default handlers for different kernel versions and configs.

Files: ~/.config/htop/htoprc and /root/.config/htop/htoprc

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


