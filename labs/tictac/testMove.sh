#!/bin/bash

echo "1 X A1" | ./move-check 
echo "1  X A1" | ./move-check  
echo "1 X  A1" | ./move-check  
echo "1 X A 1" | ./move-check  
echo "1 X A1 " | ./move-check  
echo "1     X   A1" | ./move-check  
echo "1 X A  1  " | ./move-check    


echo "1 X " | ./move-check 
echo "1  A1" | ./move-check 
echo " X A1" | ./move-check 
