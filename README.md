# htop_2.2.2-amd64

https://github.com/avafinger/htop_2.2.2-amd64/releases/tag/v0.1

![F2 config](https://github.com/avafinger/htop_2.2.2-amd64/raw/master/amd64.png)


https://github.com/avafinger/htop_2.2.2-amd64/releases/tag/v0.2

![Core Freq and Temp](https://github.com/avafinger/htop_2.2.2-amd64/raw/master/htop-core-monitor-freq-temp.png)


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


