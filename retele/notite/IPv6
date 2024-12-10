# IPv6 Addressing Guide

## 1. LLA (Link-Local Address)

### Definition
A Link-Local Address is a special type of IPv6 address used for communication within a single network segment.

### Key Characteristics
- Prefix: Always starts with `fe80::/10`
- Scope: Limited to the local network link
- Configuration: Automatically generated
- No manual setup or DHCP required

### Generation Methods
- Derived from network interface's MAC address
- Can be randomly generated
- Ensures unique addressing within the local network

## 2. GUA (Global Unicast Address)

### Definition
A Global Unicast Address is a routable IPv6 address used for communication across the internet.

### Key Characteristics
- Prefix: Starts with `2000::/3`
- Globally unique and routable
- Can be statically or dynamically assigned

### Address Components
1. **Global Routing Prefix**: Identifies the network
2. **Subnet ID**: Identifies subnets within the network
3. **Interface Identifier**: Identifies a specific interface

## 3. IPv6 Address Format

### Technical Specifications
- Total Length: 128 bits
- Representation: 8 groups of 4 hexadecimal digits
- Separator: Colon (`:`)

### Examples
**Full Format:**
```
2001:0db8:85a3:0000:0000:8a2e:0370:7334
```

**Compressed Format:**
```
2001:db8:85a3::8a2e:370:7334
```

### Address Compression Rules
- Consecutive zero groups can be replaced with `::`
- Can be used only once in an address
- Helps reduce address length and improve readability

## Best Practices
- Use compression for readability
- Understand the difference between LLA and GUA
- Ensure unique addressing in your network design

# Well-Known IPv6 Multicast Addresses

## Solicited-Node Multicast Addresses
- **Address Range**: `ff02:0:0:0:0:1:ff00:0000/104`
- Used for Neighbor Discovery Protocol (NDP)
- Created for each unicast and anycast address
- Allows efficient address resolution on the local network

## Predefined Multicast Addresses

### All Nodes Multicast Address
- **Address**: `ff02::1`
- Reaches all nodes on the local network segment
- Used for network-wide communications

### All Routers Multicast Address
- **Address**: `ff02::2`
- Reaches all routers on the local network segment
- Used for router-specific communications

### Solicited-Node Multicast Address (Example)
- **Prefix**: `ff02:0:0:0:0:1:ff00:0000/104`
- Derived from unicast address
- Used for Duplicate Address Detection (DAD)

## Special Multicast Scopes
- `ff01::` - Node-local scope
- `ff02::` - Link-local scope
- `ff05::` - Site-local scope
- `ff0e::` - Global scope

## Important Multicast Groups
- `ff02::1:ff00:0/104` - Solicited-node multicast group
- `ff02::1:2` - All DHCP servers and relay agents
- `ff02::16` - MLDv2 multicast listeners

## Address Structure
```
ff[flags][scope]:[rest of address]
```
- First 8 bits: `ff`
- Next 4 bits: Flags
- Next 4 bits: Scope
- Remaining 112 bits: Group ID

# EUI-64 în SLAAC

## Ce este EUI-64?

EUI-64 (Extended Unique Identifier - 64 bits) este un mecanism utilizat pentru a genera 
identificatorul unic al interfeței (ultimii 64 de biți ai adresei IPv6) pornind de la adresa MAC a dispozitivului.

## Procesul de generare

### 1. Punct de plecare: Adresa MAC
- Adresă MAC tipică: XX:XX:XX:XX:XX:XX (48 de biți)

### 2. Inserarea identificatorului suplimentar
- Se inserează valoarea `FFFE` între cele două segmente ale adresei MAC
- Exemplu: 
  - Adresă MAC originală: `00:1A:2B:3C:4D:5E`
  - După inserție: `001A:2BFF:FE3C:4D5E`

### 3. Inversarea bitului universal/local
- Al doilea bit cel mai semnificativ al primului octet se inversează
- Indică dacă adresa este local administrată sau global unică
- Exemplu:
  - `00` (binar: `00000000`) devine `02` (binar: `00000010`)

## Exemplu complet de generare

1. Adresa MAC originală: `00:1A:2B:3C:4D:5E`
2. Inserarea `FFFE`: `001A:2BFF:FE3C:4D5E`
3. Inversarea bitului: `021A:2BFF:FE3C:4D5E`
4. Adresă IPv6 completă (cu prefix): `2001:db8:1:021A:2BFF:FE3C:4D5E`

## Avantajele utilizării SLAAC cu EUI-64

- **Automatizare completă**: Configurare adrese fără intervenție manuală
- **Unicitate garantată**: Adrese bazate pe MAC sunt unice în rețele
- **Simplicitate**: Management ușor al adreselor în rețele mari

## Dezavantaje

- **Confidențialitate redusă**: 
  - Adresele generate conțin adresa MAC
  - Pot expune identitatea hardware-ului și istoricul dispozitivului

## Alternative pentru confidențialitate

- Utilizarea adreselor IPv6 temporare
- Adrese generate aleatoriu (conform RFC 4941)

## Concluzie

EUI-64 oferă o metodă automată și precisă de generare a identificatorilor 
de interfață în IPv6, dar ridică unele preocupări legate de confidențialitate.
