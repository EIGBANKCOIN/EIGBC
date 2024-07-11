
Debian
====================
This directory contains files used to package eigbankcoind/eigbankcoin-qt
for Debian-based Linux systems. If you compile eigbankcoind/eigbankcoin-qt yourself, there are some useful files here.

## pivx: URI support ##


eigbankcoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install eigbankcoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your eigbankcoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/pivx128.png` to `/usr/share/pixmaps`

eigbankcoin-qt.protocol (KDE)

