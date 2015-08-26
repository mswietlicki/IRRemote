#include "IRRemoteBenq.h"

IRRemoteBenq::IRRemoteBenq(int irPin) : IRRemote(irPin){
  setup(38, 32, 9000, 4500, 600, 1600, 520);
}

void IRRemoteBenq::SendCommand(String command) { 
  if(command == "ON")
    send(ON);
  if(command == "OFF")
    send(OFF);
}