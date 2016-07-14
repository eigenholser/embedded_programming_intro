Embedded Programming Introduction
=================================

Materials for OpenWest 2016 talk on Friday July 15.

Connect to the serial port to see debugging messages via the UART::

    cu --line /dev/ttyACM0 --speed 115200 --parity=none


Illustration for the slides are implemented in TeX using the Tikz package.
There is a `Makefile` that will build the PNG images needed by the slides.
To make the figures::

    cd figures
    make

To view the slides, just open `index.html` in your browser::

    cd slides
    firefox index.html

To build the code you'll need to download and install Code Composer Studio. You
can find it on the Texas Instruments website with complete instructions.
Import the demo project and it will build.

To run you will need a Stellaris Launchpad board.
