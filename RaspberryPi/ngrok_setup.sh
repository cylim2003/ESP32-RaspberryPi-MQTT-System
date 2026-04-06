#!/bin/bash

# check ngrok installed
if command -v ngrok &> /dev/null
then
    echo "ngrok already installed"
else
    echo "installing ngrok..."

    # download ngrok
    wget https://bin.equinox.io/c/bNyj1mQVY4c/ngrok-v3-stable-linux-amd64.tgz

    # unzip
    tar -xvzf ngrok-v3-stable-linux-amd64.tgz

    # move to /usr/local/bin
    sudo mv ngrok /usr/local/bin

    echo "ngrok installed"

    echo "IMPORTANT: Add your token:"
    echo "ngrok config add-authtoken YOUR_TOKEN"

fi
