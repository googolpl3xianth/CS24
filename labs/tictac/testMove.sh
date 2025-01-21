#!/bin/bash

echo "1 X A1" | ./move-check 
echo "1  X A1" | ./move-check  
echo "1 X  A1" | ./move-check    
echo "1 X A1 " | ./move-check  
echo "1     X   A1" | ./move-check   
echo "1 X A1 #" | ./move-check 
echo "1 X A1 #1234asdf!@#$" | ./move-check

echo ""
echo "1 X A" | ./move-check
echo "1\nX\nA1" | ./move-check
echo "" | ./move-check
echo "1 X " | ./move-check 
echo "1  A1" | ./move-check 
echo " X A1" | ./move-check
echo "1 X A 1" | ./move-check
echo "1 X A  1  " | ./move-check
echo "1 X A1#" | ./move-check 
echo "1 X A1#1234asdf!@#$" | ./move-check 
echo "1 X A11234asdf!@#$" | ./move-check  
echo "1 X A1 1234asdf!@#$" | ./move-check 
echo " 1 X A1 " | ./move-check
echo "1 X A0" | ./move-check
echo "1 X A4" | ./move-check
echo "1 X Z1" | ./move-check
echo "1 X z1" | ./move-check
echo "1 X D1" | ./move-check
echo ""
