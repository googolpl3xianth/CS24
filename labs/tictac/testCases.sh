#!/bin/bash

cat data/bad-line.ttt | ./game-check
cat data/bad-move.ttt | ./game-check
cat data/draw.ttt | ./game-check
cat data/new-game.ttt | ./game-check
cat data/o-wins.ttt | ./game-check
cat data/os-turn.ttt | ./game-check
cat data/x-wins.ttt | ./game-check
cat data/xs-turn.ttt | ./game-check

