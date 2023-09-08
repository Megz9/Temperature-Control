## Temperature-Control
# Goal
Embedded application to control temperature and take action according to the temperature

# Brief Description
- A temperature sensor will sense the surrounding temperature and convert it to an analogue voltage signal. 
- This signal will pass through the ADC (Analogue to Digital Converter) pins. 
- ADC will convert this analog signal to a digital one so that the microcontroller could figure it out. 
- Then using a map function the input voltage will be converted into a temperature again.
- LCD will print out the current temperature against desired one.
- The system desired temperature can be determined by USART.
- Depending on desired and current temperature the system will take an action by increasing or decreasing motor speed.
- A feedback from the sensor with the new current temperature will help the system to take another appropriate control action.
- Depending on this closed loop concept with continuous feedback, the system will saturate by reaching desired temperature.
- A security system is added to our project:
        - when the current temperature of the surrounding is in predefined limits, A green led is lighting up indicating that everything is normal
        - when the current temperature exceeds a predefined critical point, A warning message will pop up on the LCD, The green led will be turned off, A red led will start blinking.
        - After ten seconds, A buzzer will launch, The red led will stop blinking.
