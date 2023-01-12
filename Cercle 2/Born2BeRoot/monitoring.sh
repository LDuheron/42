#!/bin/bash

arch=$(uname -srvmo | awk '{print $0}')
phy_id=$(cat /proc/cpuinfo | grep "physique_id" | uniq | wc -l | awk '{print $0}')
CPU=$(cat /proc/cpuinfo | grep "processor" | awk '{print $3}')
MEM_U=$(free -h | grep "Mem" | awk '{print $7 "/" $2 " " "(" $7/$2*100 "%" ")"}') //memoire vive utilisee / memoire totale (RAM)
DISK_U=$(df -h --total | grep 'total' | awk '{print $4 "/" $2 " " "(" $4/$2*100 "%" ")"}') // memoire utilisee sur le disque (ROM)
CPU_L=$(top -bn1 | grep "%Cpu" | tail -1 | grep -P '(....|...) id,' | awk '{print 100-$8 "%"}')
BOOT=$(who -b | awk '{print($3 " " $4)}')
LVM=$(if [ $(lsblk | grep lvm | wc -l) -eq 0 ]; then echo no; else echo yes; fi)
TCP_C=$(netstat -an | grep "ESTABLISHED" | wc -l)
USER_L=$(who | cut -d " " -f l | sort -u | wc -l)
IP=$(hostname -I)
MC_ADRESS=$(ip a | grep "link/ether" | awk '{print$2}')
SUDO=$(grep 'sudo' /var/log/auth.log | wc -l)


