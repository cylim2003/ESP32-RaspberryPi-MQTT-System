#!/bin/bash

BROKER="localhost"
TOPIC="test/topic"

echo "Subscribing to topic..."
mosquitto_sub -h $BROKER -t $TOPIC