# Cisco Networking Configuration Guide for Packet Tracer

## 1. Configuring Interfaces on a Router

### Command Sequence
```
Router> enable
Router# configure terminal
Router(config)# interface <interface-id>
Router(config-if)# ip address <IP> <Subnet Mask>
Router(config-if)# no shutdown
Router(config-if)# exit
```

### Example Configuration
```
Router(config)# interface gigabitethernet0/0
Router(config-if)# ip address 192.168.1.1 255.255.255.0
Router(config-if)# no shutdown
Router(config-if)# exit
```

## 2. Configuring RIP (Routing Information Protocol)

### Command Sequence
```
Router> enable
Router# configure terminal
Router(config)# router rip
Router(config-router)# version 2
Router(config-router)# network <network-ID>
Router(config-router)# exit
```

### Example Configuration
```
Router(config)# router rip
Router(config-router)# version 2
Router(config-router)# network 192.168.1.0
Router(config-router)# network 10.0.0.0
Router(config-router)# exit
```

## 3. Configuring OSPF (Open Shortest Path First)

### Command Sequence
```
Router> enable
Router# configure terminal
Router(config)# router ospf <process-id>
Router(config-router)# network <network-ID> <wildcard-mask> area <area-ID>
Router(config-router)# exit
```

### Example Configuration
```
Router(config)# router ospf 1
Router(config-router)# network 192.168.1.0 0.0.0.255 area 0
Router(config-router)# network 10.0.0.0 0.0.0.3 area 0
Router(config-router)# exit
```

## 4. Configuring DHCP (Dynamic Host Configuration Protocol)

### Command Sequence
```
Router> enable
Router# configure terminal
Router(config)# ip dhcp pool <pool-name>
Router(dhcp-config)# network <network-ID> <subnet-mask>
Router(dhcp-config)# default-router <gateway-IP>
Router(dhcp-config)# dns-server <DNS-IP>
Router(dhcp-config)# exit
Router(config)# ip dhcp excluded-address <start-IP> <end-IP>
Router(config-if)# ip helper-address <DHCP-SERVER-IP>  # Helper Address
```

### Example Configuration
```
Router(config)# ip dhcp pool LAN
Router(dhcp-config)# network 192.168.1.0 255.255.255.0
Router(dhcp-config)# default-router 192.168.1.1
Router(dhcp-config)# dns-server 8.8.8.8
Router(dhcp-config)# exit
Router(config)# ip dhcp excluded-address 192.168.1.1 192.168.1.10
```

## 5. Configuring NAT (Network Address Translation)

### Command Sequence
```
Router> enable
Router# configure terminal
Router(config)# access-list <list-ID> permit <source-IP> <wildcard-mask>
Router(config)# ip nat inside source list <list-ID> interface <interface-id> overload
Router(config)# interface <inside-interface-id>
Router(config-if)# ip nat inside
Router(config-if)# exit
Router(config)# interface <outside-interface-id>
Router(config-if)# ip nat outside
Router(config-if)# exit
```

### Example Configuration
```
Router(config)# access-list 1 permit 192.168.1.0 0.0.0.255
Router(config)# ip nat inside source list 1 interface gigabitethernet0/1 overload
Router(config)# interface gigabitethernet0/0
Router(config-if)# ip nat inside
Router(config-if)# exit
Router(config)# interface gigabitethernet0/1
Router(config-if)# ip nat outside
Router(config-if)# exit
```

## 6. Configuring Static and Floating Routes

### Static Route Command Sequence
```
Router> enable
Router# configure terminal
Router(config)# ip route <destination-network> <subnet-mask> <next-hop-IP>
```

### Example Static Route
```
Router(config)# ip route 192.168.2.0 255.255.255.0 10.0.0.2
```

### Floating Route Command Sequence
```
Router(config)# ip route <destination-network> <subnet-mask> <next-hop-IP> <administrative-distance>
```

### Example Floating Route
```
Router(config)# ip route 192.168.2.0 255.255.255.0 10.0.0.3 200
```

## 7. Configuring a Switch

### Basic VLAN Configuration
```
Switch> enable
Switch# configure terminal
Switch(config)# vlan <vlan-ID>
Switch(config-vlan)# name <vlan-name>
Switch(config-vlan)# exit
Switch(config)# interface <interface-id>
Switch(config-if)# switchport mode access
Switch(config-if)# switchport access vlan <vlan-ID>
Switch(config-if)# exit
```

### Example VLAN Configuration
```
Switch(config)# vlan 10
Switch(config-vlan)# name Sales
Switch(config-vlan)# exit
Switch(config)# interface fastethernet0/1
Switch(config-if)# switchport mode access
Switch(config-if)# switchport access vlan 10
Switch(config-if)# exit
```

### Setting Up Trunk Port
```
Switch(config)# interface <interface-id>
Switch(config-if)# switchport mode trunk
Switch(config-if)# switchport trunk allowed vlan <vlan-ID-list>
Switch(config-if)# exit
```

### Example Trunk Port Configuration
```
Switch(config)# interface fastethernet0/1
Switch(config-if)# switchport mode trunk
Switch(config-if)# switchport trunk allowed vlan 10,20,30
Switch(config-if)# exit
```

### Dynamic NAT
```
Router> enable
Router# configure terminal
Router(config)# ip nat pool <pool-name> <start-ip> <end-ip> netmask <subnet-mask>
Router(config)# access-list <list-number> permit <source-network> <wildcard-mask>
Router(config)# ip nat inside source list <list-number> pool <pool-name>
Router(config)# interface <inside-interface>
Router(config-if)# ip nat inside
Router(config)# interface <outside-interface>
Router(config-if)# ip nat outside
```

### Example Dynamic NAT Configuration
```
Router(config)# ip nat pool NAT-POOL 203.0.113.1 203.0.113.10 netmask 255.255.255.0
Router(config)# access-list 1 permit 192.168.1.0 0.0.0.255
Router(config)# ip nat inside source list 1 pool NAT-POOL
Router(config)# interface gigabitethernet0/0
Router(config-if)# ip nat inside
Router(config)# interface gigabitethernet0/1
Router(config-if)# ip nat outside
```
