===========
edisondrone
===========

.. image:: https://travis-ci.org/greghaynes/edisondrone.svg?branch=master
    :target: https://travis-ci.org/greghaynes/edisondrone

.. image:: https://img.shields.io/github/license/greghaynes/edisondrone.svg?style=flat-square
    :target: https://github.com/greghaynes/edisondrone/blob/master/LICENSE

A quadcopter drone using the Intel Edison platform.


Why
---

To greatly decrease the barrier to entry for writing custom drone applications
by providing an x86, Linux based drone platform.

The intel edison board is an x86 SOC module with an easy to use interface
for many peripherals (such as those needed to control a quadcopter). By
combining this with Linux real-time thread scheduling we can make a drone
platform which runs as a typical x86 application on Linux. This greatly lowers
the bar required to write custom applications, develop the platform, or add
peripherals to the drone.


Hardware
--------

The brain of the edison drone is an "Intel Edison Compute Module"
(http://amzn.com/B00PTVSS4A). This is plugged in to a Series of SparkFun
Blocks, starting with the Base block. The blocks used are:

 * Base (https://www.sparkfun.com/products/13045)
 * 9 DOF (https://www.sparkfun.com/products/13033)
 * I2C (https://www.sparkfun.com/products/13034)
 * Battery (https://www.sparkfun.com/products/13037)

These blocks snap together and require no additional wiring or soldering. It
is recommended that you attach these with the additional hardware pack
(https://www.sparkfun.com/products/13187).


Compiling
---------

The following commands can be used to build:

.. code-block:: bash

    git clone https://github.com/greghaynes/edisondrone.git
    cd edisondrone
    cmake -Dtest=on .
    make


Running
-------

Simply run the `edison-server` binary generated from compilation on the
Edison computer to start the drone. In its current state only debug information
is output and no control is possile.


Tests
-----

Make sure the code was built with `-Dtest=on` passed to the `cmake` command
(see Building section for an example). You can then run:

.. code-block:: bash

    ./edisondrone-test


Simulator
---------

The Simulator runs a series of generated inputs fed in to the control code and
then outputs data files which can be graphed using a tool like gnuplot.

Run the edisondrone-simulator-img to generate a gnuplot image
(after running the commands in `Compiling`):

.. code-block:: bash

    ./edisondrone-simulator-img simulator.png

Or create a gnuplot graph on your own:

.. code-block:: bash

    ./edisondrone-simulator > simulator.dat
    gnuplot < simulator.gnuplot > graph.png

You can then view graph.png in any image viewing tool.
