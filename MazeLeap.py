#by Bensu Sicim
import sys, thread, time, Leap, serial
#sys.path.insert(0, "Desktop/Maze/lib")
from serial import Serial
ser = serial.Serial('/dev/tty.usbmodem1421', 9600)
class SampleListener(Leap.Listener):
    def on_connect(self, controller):
        print "Connected"
    def on_frame(self, controller):
        frame = controller.frame()
        hand = frame.hands.rightmost #create rightmost hand
        handCenter = hand.palm_position #get hand palm position
        posX=(int((handCenter.x/200)*(90)+90))+100 #get x coordinate position and convert it to [100,280]
        posY=(int((handCenter.y/200)*(90)+90))+100 #+100 is to equalize the number of digits
        print ("x: " + str(posX) + " y: " + str(posY))
        ser.write(str(posX)+str(posY)) #writes the positions as a 6 digit value
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