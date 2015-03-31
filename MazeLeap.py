import sys, thread, time, Leap, serial
#sys.path.insert(0, "Desktop/Maze/lib")
from serial import Serial
from Leap import CircleGesture, KeyTapGesture, ScreenTapGesture, SwipeGesture
ser = serial.Serial('/dev/tty.usbmodem1421', 9600)
posXprev=90
class SampleListener(Leap.Listener):
    def on_connect(self, controller):
        print "Connected"
    def on_frame(self, controller):
        global posXprev
        frame = controller.frame()
        hand = frame.hands.rightmost
        handCenter = hand.palm_position
        posX=(int((handCenter.x/200)*(90)+90))+100
        posY=(int((handCenter.y/200)*(90)+90))+100
        print ("x: " + str(posX) + " y: " + str(posY))
        ser.write(str(posX)+str(posY))
        time.sleep(0.1)
def main():
    listener = SampleListener()
    controller = Leap.Controller()
    controller.add_listener(listener)
    try:
        sys.stdin.readline()
    except KeyboardInterrupt:
        pass
if __name__ == "__main__":
    main()