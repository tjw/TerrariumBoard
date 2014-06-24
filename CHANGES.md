# v2

### Redesigned to hold Spark

- Sent to OSH Park 2014-03-29
- Received 2014-04-09

### Problems
- Eagle didn't connect wire from the Spark side of the shifter circuit for PILLAR0
- Pads for edge connectors not far enough under where pins are
- Edge connectors for LED strips are not terribly stable; might need to glue them down. The holes are maybe too big or maybe the through pins are not long enough to click in
- Some of the vias are pretty close to other solder pads... might be OK
- Could maybe mount the big capacitor on its side
- Could probably increase the size of the pads on the main power connector and run them together
- 0805 pads could be bigger -- kind hard to solder to them

### Fixes
- Molex 3 pin SMT 43650-310
  - Changed drill from 2.3mm to 2.2mm to get a tighter fit
  - Increased pads from 1.6764 x 0.8128 to 2.54 x 1.27, slid further back under where the pin would be
- Molex 2 pin Sabre power
  - Changed holes to 3.7mm diameter, square so they overlap
- Power netclass
  - Increased width to 60mil (~1.5mm)
  - Updated all +5v wires to at least this width


  
# vA.2

### Problems fixed
- Increased pad size for resistor component from `auto` to 1.2.
- Moved name/version to the tNames layer instead of tSilk.
- Smashed the capacitor and fixed the name size
- Added +/-/S markings to Molex connector component
- Made footprints for Molex Sabre power connector and Molex 4365-310 right angle connectors

### Not fixed
- Missing values -- none of the values showed up; presumably they don't print tValues.
- Markers on DC jack didn't show up; removed the DC jack instead






# vA.1

- Sent to OSH Park 2014-02-15
- Boards shipped 2014-02-21
- Boards received 2014-02-24

### Notes
- Since the DC jack didn't fit, tried running w/o it. This worked (sourcing current from VIN). But with 200 LEDs at maximum brightness the board started to smoke. VIN is rated for much less current. So, the DC jack will be needed!

### Problems/changes to make:
- Replaced DC jack with Molex Sabre connector (rated for 18A instead of 5A for DC barrel jack)
- Test using A0-A7 for digital output on Spark Core. Supposedly works.
- Sparkcore 3.3V, not 5V. Recommended to use a 5V device (or make signal 70% of power). Need to add logic level converters.
  - *Probably* don't need a level shifter with newer strips. See http://forums.adafruit.com/viewtopic.php?f=47&t=47420&hilit=grumpy&start=15 for info about "grumpy" strips and using non-"grumpy" pixels as level shifters
  - Maybe run at 400kHz instead of 800kHz
  - Post on testing level shifters for Teensy -> NeoPixel http://happyinmotion.com/?p=1247
  
- Order some female 0.1" headers (Adafruit http://www.adafruit.com/products/598) for Spark Core rather than soldering built-in headers directly to board
- Mock up board
- Wait for orders from Mouser
- Make footprints for right angle plugs
- Rearrange wire order to match that of LED strips
- Need much bigger pads for DC power jack
- Should make the board bigger than an Arduino shield to make room for stuff
- Vertical connectors are kinda terrible.
- Name/version didn't print on silk screen
- Through holes for DC jack too small
- Probably didn't need to put DC jack on board; can use VIN from Arduino base
- Pads for resistor could be bigger
- Add +/-/S notes on connector footprints
- Markers on DC jack didn't show up
- Name on capacitor too small
- Value on capacitor didn't show up at all
- Only one of the GND pins on the shield is connected to the ground pour. Hopefully not a blocking issue...
- Move data line resistors to the board to avoid needing them on LED strips
- Switch to full custom AVR board with programmer, or to adding headers for Spark Core, maybe with separate power regulator for LEDs.

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
