Figures For Slides
==================

Illustrations for the slides are implemented in TeX using the Tikz package.
There is a ``Makefile`` that will build the PNG images needed by the slides.
Some LaTeX packages will be required in order to build the figures. On
Ubuntu 16.04 that starts with TeX Live but requires more than the base.
AMS Math is required. A comprehensive list is beyond the scope of these
instructions and probably will differ based on Linux distribution.

To make the figures::

    cd figures
    make

