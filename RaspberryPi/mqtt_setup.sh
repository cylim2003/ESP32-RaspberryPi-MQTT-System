#!/bin/bash

# install mosquitto
sudo apt update
sudo apt install -y mosquitto mosquitto-clients

# enable service
sudo systemctl enable mosquitto

echo "Mosquitto installed"
