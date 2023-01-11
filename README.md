# esp32-spdlog
Basic spdlog example on ESP32

Sample output
```
I (446) main_task: Started on CPU0
I (456) main_task: Calling app_main()
[649440278] [00-01-00 00:00:00.136] [main] [trace] spdlog on ESP32
[649440278] [00-01-00 00:00:00.140] [main] [debug]   |ESP32               |
[649440278] [00-01-00 00:00:00.147] [main] [info]    |ESP32               |
[649440278] [00-01-00 00:00:00.154] [main] [warning] |_______________ESP32|
[649440278] [00-01-00 00:00:00.162] [main] [error]   |_______ESP32________|
[649440278] [00-01-00 00:00:00.170] [main] [critical]
0000: 0102030405060708090A0B0C0D0E0F101112131415161718191A1B1C1D1E1F20
0020: 2122232425262728292A2B2C2D2E2F303132333435363738393A3B3C3D3E3F40
I (496) main_task: Returned from app_main()
```
