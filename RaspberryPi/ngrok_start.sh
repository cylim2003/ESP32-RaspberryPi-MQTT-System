#!/bin/bash

PORT=1883

echo "Starting ngrok TCP tunnel on port $PORT..."

ngrok tcp $PORT