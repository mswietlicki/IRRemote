#include "IRRemoteMicrolab.h"

IRRemoteMicrolab::IRRemoteMicrolab(int irPin) : IRRemote(irPin){
  setup(38, 32, 9000, 4500, 600, 1600, 520);
}

void IRRemoteMicrolab::SendCommand(String command) { 
  if(command == "INPUT")
    send(INPUT);
  if(command == "VOLUP")
    send(VOLUP);
  if(command == "VOLDOWN")
    send(VOLDOWN);
  if(command == "RESET")
    send(RESET);
  if(command == "MUTE")
    send(MUTE);
  if(command == "TREBLEUP")
    send(TREBLEUP);
  if(command == "TREBLEDOWN")
    send(TREBLEDOWN);
  if(command == "BASSUP")
    send(BASSUP);
  if(command == "BASSDOWN")
    send(BASSDOWN);
}