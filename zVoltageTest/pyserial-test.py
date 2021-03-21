#!/usr/bin/env python3


import serial 
import time
import csv
import matplotlib


#try:
teensy = serial.Serial(port='COM6',baudrate=115200,timeout=.1)
teensy.flushInput()

def write_read(x):
    teensy.write(bytes(x,'utf-8'))
    time.sleep(0.05)
    data = teensy.readline()
    return data

while True:
   try:
    num = input("Enter a number: ")
    value = write_read(num)
    print(value)
#try:
#    ser_bytes = teensy.readline()
 #   decoded_bytes = float(ser_bytes[0:len(ser_bytes)-2].decode("utf-8"))
  #  print(decoded_bytes)
   # print(ser_bytes)
    #with open("test_data.csv","a") as f:
     #   writer = csv.writer(f,delimiter=",")
      #  writer.writerow([time.time(),decoded_bytes])
#except:
 #   print("Keyboard Interrupt")
  #  break

#except: 
    # print("Could not open COM6")