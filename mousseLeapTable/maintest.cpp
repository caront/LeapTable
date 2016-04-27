#include "Leap.h"

using namespace Leap;

void display(Vector avgPos)
{
  //std::cout << "finger : " << i;
  std::cout << "X : " << avgPos.x;
  std::cout << "Y : " << avgPos.y;
  std::cout << "Z : " << avgPos.z << std::endl;
}

int main() {
  Listener toto;
  Controller controller;
  controller.addListener(toto);

 /* if (!controller.isConnected()){
    std::cerr << "No leap connected" << std::endl;
    return -1;
  }
  */Frame frame = controller.frame();
  while (true){
    frame = controller.frame();
    if (!frame.hands().isEmpty()) {
      Hand hand = frame.hands()[0];
      Vector handCenter = hand.palmPosition();
      display(handCenter);
      FingerList fingers = hand.fingers();
      if (!fingers.isEmpty()) {
        Vector avgPos;
        for (int i = 0; i < fingers.count(); ++i) {
          avgPos = fingers[i].tipPosition();

        }
      }
    }
    usleep(50000);
  }
  controller.removeListener(toto);
  return 0;
}
