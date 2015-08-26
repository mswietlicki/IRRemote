# IRRemote
This is IR remote library design for use with Particle (Spark) Core or Photon.

Use sample:
-----------

`
	#include "IRRemoteMicrolab.h"

	IRRemoteMicrolab speakersRemote(D1);

	void loop() {
		speakersRemote.SendCommand("VOLUP");
		sleep(500);
	}
`