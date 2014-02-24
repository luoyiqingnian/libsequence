#libsequence - A C++ class library for evolutionary genetic analysis



  Copyright (C) 2002 Kevin Thornton

  libsequence2 is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

Comments are welcome.

	- Kevin Thornton <krthornt@uci.edu>

#Citation

If you use the library for your research, please cite:

@article{libsequence,
author = {Thornton, Kevin},
title = {{Libsequence: a C++ class library for evolutionary genetic analysis.}},
journal = {Bioinformatics (Oxford, England)},
year = {2003},
volume = {19},
number = {17},
pages = {2325--2327},
month = nov
}

The manuscript is available online at http://bioinformatics.oxfordjournals.org/content/19/17/2325.short

##Installation

###Dependencies
GNU Scientific Library: http://gnu.org/software/gsl

Boost C++ libraries: http://www.boost.org

zlib: http://zlib.net

###Simplest installation instructions

The "CXXFLAGS= " part of the command is to over-ride ./configure's desire to add -g -O2 to the compile options

CXXFLAGS= ./configure

CXXFLAGS= make

sudo make install

###More complex installation scenarios

Some users may not have the dependent libraries installed in the standard locations on their systems.  Note that "standard" means wherever the compiler system looks for header files during compilation and libraries during linking.  This scenario is common on OS X systems where users have used some sort of "system" to install various libraries rather than installing from source directly.  In order to accomodate such situations, the user must provide the correct path to the include and lib directories.  For example, assume that the dependend libraries are in /opt on your system.  You would install libsequence as follows:

CXXFLAGS=-I/opt/include LDFLAGS="$LDFLAGS -l/opt/lib" ./configure

make

sudo make install

Note that the modification of LDFLAGS prepends the current value of LDFLAGS if it exists.  This allows for scenarios where the system's search path for libraries may have been modified by the user or sysadmin via a modification of that shell variable.  (One could also do the same with CXXFLAGS, FYI.)

###Installing libsequence locally

If you do not have permission to "sudo make install", you can install the library in your $HOME:

./configure --prefix=$HOME

###A "master" script for local installation

If you want the library installed in your home, and are starting "from scratch" (e.g., you need GSL and boost, too), then there is a script for you online [here](https://github.com/molpopgen/install_libseq).  You need git installed on your machine.

Please read the README in detail for how to use that script.

Then, when compiling any program using libsequence, gsl, and/or boost, you need to add

> -I$HOME/include

to any compilation commands and

> -L$HOME/lib

to any linking commands.

When running programs linking to any of the above run-time libraries, and depending on your system, you may also need to adjust variables like LD _ LIBRARY _ PATH to prepend $HOME/lib to them, etc., but you'll need to figure that out on case-by-case basis, as different systems can behave quite differently.

###Another installation option (not supported by the libsequence author)

I've recently been made aware that there is a method for installing libsequence using the [brew.sh](http://brew.sh/) system.  This system allows the [homebrew-science](https://github.com/Homebrew/homebrew-science) git repo to be used to obtain libsequence.  I do not use this system myself, nor do I know how to.

##Using libsequence to compile other programs

If libsequence is not installed in a standard path, then you must provide the appropriate include (-I) and link path (-L) commands to your compiler.  This may be done in various ways, e.g., via a configure script or your own Makefile.

A program that depends on libsequence must provide at least the following libraries to the linker:

-lsequence -lz -lgsl -lgslcblas