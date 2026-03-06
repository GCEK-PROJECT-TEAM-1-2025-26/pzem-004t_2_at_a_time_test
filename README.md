# PZEM-004T 
2 PZEM-004T used where the 2 split coils are in series. Due to which the first pzem-004t show the power equal to the sum of the power outputs from both the loads and the second pzem-004t shows only power output of second load
230vc----split_coil_1----|----load-----neutral
                       |
                       ---split_coil_2-----load-----neutral
# Solid State Relay (SSR-25DA)
A Solid state realy which is in series with the second load turns on after 10 second from the time when the microcontroller (ESP8266) turns on
-It is coded in such a was there is no sufficient pins for placing any switch in esp8266 microcontroller (A simple issue which will be solved after using esp32 Board)
