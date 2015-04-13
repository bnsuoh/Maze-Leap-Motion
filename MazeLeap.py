#by Bensu Sicim
import sys, thread, time, Leap, serial
#sys.path.insert(0, "Desktop/Maze/lib")
from serial import Serial
ser = serial.Serial('/dev/tty.usbmodem1421', 9600)
beforeX,beforeY=190,190
class SampleListener(Leap.Listener):
    def on_connect(self, controller):
        print "Connected"
    def on_frame(self, controller):
        global beforeX,beforeY
        frame = controller.frame()
        hand = frame.hands.rightmost #create rightmost hand
        handCenter = hand.palm_position #get hand palm position
        posX=(int((handCenter.x/200)*(90)+90))+100 #get x coordinate position and convert it to [100,280]
        posY=(int((handCenter.z/200)*(90)+90))+100 #+100 is to equalize the number of digits
        if(posX<=100):
            posX=100
        elif(posX>=280):
            posX=280
        elif(posX==190):
            posX=beforeX
        if(posY<=100):
            posY=100
        elif(posY>=280):
            posY=280
        elif(posY==190):
            posY=beforeY
        beforeX=posX
        beforeY=posY
        print ("x: " + str(posX) + " y: " + str(posY))
        ser.write(str(posX)+str(posY)) #writes the positions as a 6 digit value
        time.sleep(0.05)
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