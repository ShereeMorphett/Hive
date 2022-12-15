#!/bin/bash
architecture=$(uname -a)
physic_cpu=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)
virt_cpu=$(grep "^processor" /proc/cpuinfo | wc -l)
free_ram=$(free -m | awk '$1 == "Mem:" {print $2}')
used_ram=$(free -m | awk '$1 == "Mem:" {print $3}')
perc_ram=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
free_disk=$(df -Bg | grep '^/dev/' | grep -v '/boot$' | awk '{ft += $2} END {print ft}')
used_disk=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} END {print ut}')
perc_disk=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} {ft+= $2} END {printf("%d"), ut/ft*100}')
cpu_load=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}')
last_boot=$(who -b | awk '$1 == "system" {print $3 " " $4}')
lvm_total=$(lsblk | grep "lvm" | wc -l)
lvm_used=$(if [ $lvm_total -eq 0 ]; then echo no; else echo yes; fi)
# *ATTENTION* the next step will need ($ sudo apt install net-tools) *ATTENTION*
connect_tcp=$(ss -t | grep -i estab | )
user_log=$(users | wc -w)
ip=$(hostname -I)
comp_id=$(ip link show | awk '$1 == "link/ether" {print $2}')
cmds=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
wall "	#Architecture: $architecture
	#CPU physical: $physic_cpu
	#vCPU: $virt_cpu
	#Memory Usage: $used_ram/${free_ram}MB ($perc_ram%)
	#Disk Usage: $used_disk/${free_disk}Gb ($perc_disk%)
	#CPU load: $cpu_load
	#Last boot: $last_boot
	#LVM use: $lvm_used
	#Connexions TCP: $connect_tcp ESTABLISHED
	#User log: $user_log
	#Network: IP $ip ($comp_id)
	#Sudo: $cmds cmd" 
