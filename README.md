# IRRemote
This is IR remote library design for use with Particle (Spark) Core or Photon.
For now library support: 

- Microlab speakers
- Benq projector

If you want to add new device just create another IRRemoteXXX class or send me Lirc config file.

Sample code:
-----------

```c
#include "IRRemoteMicrolab.h"

IRRemoteMicrolab speakersRemote(D1);

void loop() {
	speakersRemote.SendCommand("VOLUP");
	sleep(500);
}
```
