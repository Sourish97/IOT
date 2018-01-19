from picamera import PiCamera
from twython import Twython
import RPi.GPIO as g
import time
g.setmode(g.BOARD)
g.setup(7,g.IN)
g.setup(8,g.IN)
print("Mode Set")
camera=PiCamera()
c_k="2QMFfCcGzhhpZRhbGHzK2BWf1"
c_s="lRE1kv7d0SQ4H40SYklRURjS766b5rlyk8QeeGot2c9ueXMk3h"
a_t="2873291198-LAV6KvgOwTgf2VN8GD9foPLTq3tIGGQZNDDnUIh"
a_s="MMgcIFBgi7DVJkF9g8peRcdfKbN824ikwaF46XcWGwcgI"
tw_obj=Twython(c_k,c_s,a_t,a_s)
while 1:
    if g.input(7) == True:
        print("Button Pressed")
        camera.start_preview()
        camera.rotation=180
        time.sleep(5)
        camera.capture('/home/pi/Desktop/image.jpg')
        camera.stop_preview()
        break;
    if g.input(8) == True:
        camera.start_preview()
        camera.rotation=180
        time.sleep(5)
        camera.capture('/home/pi/Desktop/image.jpg')
        camera.stop_preview()
        message="Tweeting from my Raspi"
        with open('/home/pi/Desktop/image.jpg','rb') as photo:
            tw_obj.update_status_with_media(status=message,media=photo)
        break;
