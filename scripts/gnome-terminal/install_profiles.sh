#!/bin/bash
echo "Copying files..."
cp -R gconf-default/* ~/.gconf/apps/gnome-terminal
echo "Restarting GCONF server..."
gconftool-2 --shutdown
gconftool-2 --spawn
echo "Installation ok!"
