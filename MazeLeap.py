import sys, thread, time, Leap, serial
#sys.path.insert(0, "Desktop/Maze/lib")
from serial import Serial
from Leap import CircleGesture, KeyTapGesture, ScreenTapGesture, SwipeGesture
ser = serial.Serial('/dev/tty.usbmodem1421', 9600)
class SampleListener(Leap.Listener):
    def on_connect(self, controller):
        print "Connected"
    def on_frame(self, controller):
        width = 180
        frame = controller.frame()
        hand = frame.hands.rightmost
        handCenter = hand.palm_position
        posX=int((handCenter.x/200)*(width/2)+width/2)
        posY=(handCenter.z/200)*width
        print ("x: " + str(posX) + " y: " + str(posY))
        ser.write(str(posX))
        time.sleep(0.07)

def main():
    listener = SampleListener()
    controller = Leap.Controller()
    controller.add_listener(listener)
    # Keep this process running until Enter is pressed
    print "Press Enter to quit..."
    try:
        sys.stdin.readline()
    except KeyboardInterrupt:
        pass

if __name__ == "__main__":
    main()
