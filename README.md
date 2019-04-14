

<p align="center">
	<a href="https://beehiveproject.herokuapp.com/">
	<img src="bee_pic.jpg"
	 title="Bee" alt="FVCproductions" width="500" height="500" ></a></p>




# Real-Time Beehive Monitoring

We want to help beekeepers to keep an eye on their bees. By giving them insight on critical measurements we can monitor different events such as too low temperature, too high moisture, sufficient weight to harvest honey, as well as giving an estimate of how many bees went out of the beehive harvesting.

Monitoring your beehive and get real-time measurements on the [website](https://beehiveproject.herokuapp.com/)

This project is done in partnership with the [Glasgow University Beekeeping Society](https://www.facebook.com/GUBeekeepingSociety/)

## Table of contents
* [Setup](#setup)
* [General info](#general-info)
* [Technologies](#technologies)
* [Authors](#authors)
* [Images](#images)

## Setup

Instructions for installation can be found on the [installation wiki](https://github.com/MaysaraHolmes/beehive/wiki/Installation).

## General info
This projects architecture diagram:

<img src="ArchitectureDiagram.png" title="Architecture" ></a>

Dependency graph for the C++ code:
<img src="dependency_graph.png" title="Dependency_graph" ></a>
The doxygen generated c++ documentation can be found here: [beehive_code_documentation](https://github.com/MaysaraHolmes/beehive/blob/master/documentation/beehive_code_documentation.pdf)


## Technologies

Project is created with:
* Raspberry pi 3.0
* Sensors
	* ADC101C021 ADC
	* HIH6131 Temperatur & Humidity x2
	* MPL115A2 Barometer
	* P82B96 I2C Shifter
* Node Js/express Js server
* MySQl database.
* [WiringPi](http://wiringpi.com/reference/core-functions/) 

## Authors

* **Remy Chatel, 2411062**  - [Github](https://github.com/RemyChatel) (Main responsibility: Hardware)

* **Maysara Alhindi, 2417665**  - [Github](https://github.com/MaysaraHolmes) (Main responsibility: Front end)

* **Trine Ødegård Olsen, 2420036**  - [Github](https://github.com/trineoo) (Main responsibility: C++ code)

## Images

The beehives in the backyard in the university of Glasgow
<p align="center">
	<a href="https://beehiveproject.herokuapp.com/">
	<img src="beehive.jpg"
	 title="hive" alt="beehive" width="800" height="500" ></a></p>
	 
Picture of the hardware, without the fan, soldered
<p align="center">
	<a href="https://beehiveproject.herokuapp.com/">
	<img src="hardware.jpg"
	 title="hw" alt="hardware" width="800" height="500" ></a></p>



