# arduino-ilert

[![GitHub release](https://img.shields.io/github/release/iLert/arduino-ilert.svg)](https://github.com/iLert/arduino-ilert/releases)

iLert library for Arduino (and others like ESP8266)

Download the latest version from the [release](https://github.com/iLert/arduino-ilert/releases) section. Or grab the library from [PlatformIO](https://platformio.org/lib/show/617/ILERT).

You can install it by running: `pio lib install "ILERT"`. 

Checkout the 💓 heartbeats [example](examples/heartbeats/ilert_heartbeat.ino).

## In action

```cpp
#include <ILERT.h>

ILERTHeartbeat heartbeat;
heartbeat.begin("APIKEY", 5);
heartbeat.loop();
```

## Compatible Hardware

* ESP8266
* ESP32
* Arduino Ethernet
* Arduino Ethernet Shield
* Intel Galileo/Edison

## Getting help

We are happy to respond to [GitHub issues][issues] as well.

[issues]: https://github.com/iLert/arduino-ilert/issues/new

<br>

#### License

<sup>
Licensed under either of <a href="LICENSE-APACHE">Apache License, Version
2.0</a> or <a href="LICENSE-MIT">MIT license</a> at your option.
</sup>

<br>

<sub>
Unless you explicitly state otherwise, any contribution intentionally submitted for inclusion in ilert-js by you, as defined in the Apache-2.0 license, shall be dual licensed as above, without any additional terms or conditions.
</sub>