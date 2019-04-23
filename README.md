# Pro2_SmartHome_Tiva_c_board_G6
In this project we will implement 3 subsystems that can be used in a smart home. We will use two TM4C123G Launchpads that will communicate with each other using UART.
Launchpad 1 will be connected to a motor (for example it can be used to rotate a surveillance camera), a temperature sensor, and a LED (it can be analogous to lighting system in general).
Launchpad 2 will be connected to two push buttons (one for rotating the motor shaft 30 degrees clockwise and one for rotating it 30 degrees counter clockwise) and both buttons should take actions on press only, LCD to show reading of temperature sensor on Launchpad 1, Potentiometer to control the LED intensity on Launchpad 1.
Of course, in a real smart home Launchpad 2 can be replaced by a mobile application connected to Launchpad 1 through internet or Bluetooth or any other mechanism.
