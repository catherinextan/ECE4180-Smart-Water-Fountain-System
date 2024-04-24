A# ECE4180-Smart-Water-Fountain-System
ECE4180 Spring 2024 Final Project Section B | Georgia Institute of Technology  
Dylan Jarvis and Catherine Tan   

## Overview
The Smart Water Fountain System is a solution designed to ensure our cats always have access to fresh, flowing water. Using Sparkfun Load Cells for water level monitoring, this system gives visual and audible cues to pet owners as a reminder to refill the fountain.

## Background Information
As full-time college students, we are busy and out of the house often. Sometimes, we notice our cats' water fountain has stopped flowing from the spout because the water level is so low. However, we do not know how long it has stopped or how long they have gone without water unless we physically check inside the fountain. We did not want to have to buy a different fountain that has a water level guage since our cats are already used to their current one. Therefore, we decided to build a system that would notify us of the water level visually and audibly remind us to refill it. This ensures they will have access to fresh water and reduce the risk of dehydration, which cats are more prone to. 

## Electronics Parts List:
- 4x [Sparkfun Load Sensors - 50kg (Generic)](https://www.sparkfun.com/products/10245)
- 1x [Sparkfun Load Sensor Combinator](https://www.sparkfun.com/products/13878?_ga=2.234454110.1535232509.1712881816-1816657009.1711669502)
- 1x [Sparkfun Load Cell Amplifier HX711](https://www.sparkfun.com/products/13879?_ga=2.27940281.441763782.1713937099-1816657009.1711669502)
- 1x [Sparkfun Diffused LED - RGB 10mm](https://www.sparkfun.com/products/11120)
- 3x [100 Ohm Resistors](https://www.sparkfun.com/products/14493)
- 1x [mbed LPC1768](https://www.sparkfun.com/products/retired/9564)
- 1x [Sparkfun Accessories Speaker - PCB Mount](https://www.electromaker.io/shop/product/speaker-pcb-mount?gad_source=1&gclid=CjwKCAjwuJ2xBhA3EiwAMVjkVEWHcDyhnI3EJPf082CJfzoy2JA1GvtTF2LUusRH2YvoY_jHlv0_uRoCpioQAvD_BwE)
- 1x [Sparkfun Mono Audio Amp Breakout - TPA2005D1](https://www.sparkfun.com/products/11044)
## Structural Parts List:
- 2x Flat, sturdy platforms for placing fountain to weigh
- Water fountain

## Part 1 Instructions (Soldering Load Cells to Combinator Board)
1. Prepare the work area
   - Clear a workspace for soldering.
   - Heat your soldering iron to the appropriate temperature (We used 650°F for lead-free solder).
2. Strip and Tin the Load Cell wires
   - Use wire strippers to carefully strip 1-2cm of insulation from the ends of the wires coming from each load cell (should be 12 total).
   - Twist the wires several times then apply a small amount of solder to the stripped ends of each wire.
3. Solder the Load Cell Wires to the Combinator Board
   - We used 3-wire load cells which match the Combinator Board as such:
     - ![image](https://github.com/catherinextan/ECE4180-Smart-Water-Fountain-System/assets/65838825/d2c32d04-e73f-4688-b66d-c4b3c0c8735a)
     - ![image](https://github.com/catherinextan/ECE4180-Smart-Water-Fountain-System/assets/65838825/95c091a6-4620-4164-875a-730c75212c14)
4. Ensure connections are good by inspection and gently tugging on each wire to make sure they are secure

## Part 2 Instructions (Structural Setup)
1. Take 1 flat, sturdy platform and align each load cell equidistant from each other on top.
   - ![image](https://github.com/catherinextan/ECE4180-Smart-Water-Fountain-System/assets/65838825/d76bbcea-90ce-4c36-906d-068f81e08905)




