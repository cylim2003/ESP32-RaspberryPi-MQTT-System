#!/bin/bash

BROKER="localhost"
TOPIC="test/topic"
MESSAGE="Hello from Raspberry Pi"

echo "Publishing message..."
mosquitto_pub -h $BROKER -t $TOPIC -m "$MESSAGE"