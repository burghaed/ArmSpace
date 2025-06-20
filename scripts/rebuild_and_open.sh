#!/bin/bash

if [ -d "build" ]; then
    echo "Removing existing build folder..."
    rm -rf build
else
    echo "Error: 'build' directory does not exist. Aborting."
    exit 1
fi

echo "Creating build folder..."
mkdir build
cd build || { echo "Failed to enter build directory"; exit 1; }

echo "Running CMake with -G Xcode..."
if cmake .. -G Xcode; then
    echo "CMake configuration succeeded"
    # Step 4: Open the generated Xcode project
    echo "Opening ArmSpace.xcodeproj..."
    open ArmSpace.xcodeproj/
else
    echo "CMake failed — Xcode project will not be opened."
    exit 1
fi