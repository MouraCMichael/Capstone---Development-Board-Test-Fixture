# Capstone Development Board Tst Fixture

Development board test fixture designed to test the hardware features of the Arduino Uno and STM32 Nucleo development boards.

<br/>

## Contributors
Dylan Vetter, Nathan Hanchey, Connor Inglat, Corey Moura

<br/>

## Description
There are several engineering courses where students are required to program and build hardware circuits with their microcontroller. Hardware connections made incorrectly can destroy or damage individual pins and in some cases the entire board.  Therefore, students and professors often have the need to identify whether unusual system behavior is hardware or software related. Unfortunatly it can be quite cumbersome to diagnose damaged GPIO pins, voltage regulators, and other critical hardware peripherals on a microcontroller. This presents a need to find a more expedient way to diagnose these issues when many students may require help. 

This project addressed this issue by providing an interface on the device to test the hardware functionality of the Arduino Uno and STM microcontrollers. This allows students and professors to quickly (under 60 seconds) confirm hardware failures thought to be causing issues. Upon test completion, the device displays the results on a Graphical User Interface for the student and/or professor to view. 

<br/>

# MicroDev Development Board Tester Setup

## Raspbian Setup
- Download Raspbian OS Imager (https://www.raspberrypi.com/software/)
- Insert and locate SD card on computer
- Install Recommended Raspberry Pi OS (w/ Software) to SD card.
- Boot-up Raspi
- Username: microdev | Password: microdev
- Connect to Internet
- Terminal: git clone https://github.com/hancheyn/MicroDev.git
- Terminal: chmod 777 MicroDev/setup.sh
- Terminal: ./MicroDev/setup.sh
- File Manager > Edit > Preferences > Volume Management > 
[uncheck] Show available options for removable media when they are inserted
- Raspberry Pi Configuration > [disable] Screen Blanking


## Arduino CLI Installation & Application
Start up raspberry pi using an hdmi monitor, keyboard, and mouse.

    Download in Add/Remove Software:
- Raspberry OS Start Menu > Preferences > Add/Remove Software
- Search “arduino”
- Check AVR development board IDE
- Check Command Line Tool for compiling Arduino Sketches
- Click Apply and Wait for Download. 


    Download in Terminal:
- Terminal: curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
- Put arduino-cli into a runnable folder so the command will run on its own ($PATH).
- Terminal Command: arduino-cli core install arduino:avr
- Terminal Command View Connected Boards: arduino-cli board list
- Terminal Command Compile .ino example: arduino-cli compile -b arduino:avr:uno Blink.ino -e
- Terminal Command Upload .ino example: arduino-cli upload -b arduino:avr:uno -p /dev/ttyACM0 Blink.ino


### FLASH TO ARDUINO NOTES:
The Arduino CLI does not automatically create a permanent bit file for uploading. In order to do this, one must add the command ‘-e’ while compiling. This looks like the following: arduino-cli compile -b arduino:avr:uno Blink.ino -e.This will create a new folder within the arduino project folder that contains a bit file, “[Project name].ino.with_bootloader.bin”. This should be in a folder with a file path ./build/arduino.avr.uno/. In Terminal, the command arduino-cli upload -b arduino:avr:uno -p /dev/ttyACM0 -i [binary file path] will upload the file.
    
STM32 CLI Installation & Application
Start up raspberry pi using an hdmi monitor, keyboard, and mouse.

    Download in Add/Remove Software:
- Raspberry OS Start Menu  > Preferences > Add/Remove Software
- Search “stlink”
- Check OpenSource ST-Link tools replacement… (x3)
  - …libstlink1-1.6.1+ds-3
  - …stlink-gui-1.6.1+ds-3
  - …stlink-tools-1.6.1+ds-3

- Click Apply and Wait for Download 


### FLASH TO STM32 NOTES:
The STMCubeIDE does not automatically create a permanent bit file for uploading. Since it uses a .elf file (located in the debug folder) this must first be converted to a .bin file before flashing can occur. The .elf file can be converted using the following command from terminal arm-none-eabi-objcopy -O binary F401RE_T.elf main.bin. In the previous example, F401RE_T.elf becomes a binary file called main.bin. Flashing can then occur using the command st-flash write main.bin 0x08000000.



<br/>
<br/>
<br/>


<p align="center">

<img width="432" height=”600” src="https://user-images.githubusercontent.com/37875517/226964836-da47432e-cf38-4e9c-86bd-8de6afd10ea4.JPG">

<br/>

<img width="432" height=”600” src="https://user-images.githubusercontent.com/37875517/226966803-539ed88b-e482-46cf-93f4-b96c79a6cd46.png">

<br/>



## 3D Printing (ABS and Carbon Fiber Nylon)

<br/>

<img width="432" height=”600” src="https://user-images.githubusercontent.com/37875517/226965187-a5dd0e39-5ea7-4892-941d-0d09553bceaf.JPG">

<br/>

<img width="432" height=”600” src="https://user-images.githubusercontent.com/37875517/226965286-b2558b65-4e62-4394-84d4-20011f0cb100.JPG">

<br/>

<img width="432" height=”600” src="https://user-images.githubusercontent.com/37875517/226965617-c36e220e-3953-486f-8e0b-ae1c520db927.png">

<br/>

<img width="432" height=”600” src="">

<br/>

<img width="432" height=”600” src="">

<br/>

<img width="432" height=”600” src="">

<br/>

<img width="432" height=”600” src="">

<br/>
