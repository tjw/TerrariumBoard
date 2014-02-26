## vA.1

- Sent to OSH Park 2014-02-15
- Boards shipped 2014-02-21
- Boards received 2014-02-24

### Problems/changes to make:
- Name/version didn't print on silk screen
- Through holes for DC jack too small
- Probably didn't need to put DC jack on board; can use VIN from Arduino base
- Pads for resistor could be bigger
- Add +/-/S notes on connector footprints
- Markers on DC jack didn't show up
- Name on capacitor too small
- Value on capacitor didn't show up at all
- Only one of the GND pins on the shield is connected to the ground pour. Hopefully not a blocking issue...

### To check:
  
- Check that reset button works
	
### Already checked:
- Through holes for switch OK
- Through holes for Molex connectors a little tight, but doable
- Spacing and sizing for orientation bump on Molex connector is good
- Molex footprint good
- Resistor footprint good for some resistors (bix box from eProjects), Radio Shack resistors are bigger.
- Capacitor footprint good.
- Position of holes and footprint look good for DC jack
- Header position/spacing for attaching as shield
- Electrical connectivity
  - Ground all connected, top and bottom
  - 5V all connected to VIN, top and bottom
  - Signal pins connected, top and bottom