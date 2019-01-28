** This repository is under construction**

<p align="center">
	<a href="https://beehiveproject.herokuapp.com/">
	<img src="https://github.com/MaysaraHolmes/beehive/blob/master/bee_pic.jpg" 
	 title="Bee" alt="FVCproductions" width="500" height="500" ></a></p>




# Real-Time Beehive Monitoring

We want to help beekeepers to keep an eye on their bees. By giving them insight on critical measurements we can monitor different events such as too low temperature, too high moisture, sufficient weight to harvest honey, as well as giving an estimate of how many bees went out of the beehive harvesting. 

Monitoring your beehive and get real-time measurements on the [website](https://beehiveproject.herokuapp.com/)

This project is done in partnership with the [Glasgow University Beekeeping Society](https://www.facebook.com/GUBeekeepingSociety/)


## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)
* [Authors](#authors)

## General info
This projects architecture diagram:

<img src="https://github.com/MaysaraHolmes/beehive/blob/master/ArchitectureDiagram.png" title="Architecture" ></a>
	
## Technologies 

Project is created with:
* Raspberry pi 3.0
* Sensors
	* ADC101C021 ADC
	* FSR400 ForceResistor
	* HIH6131 Temperatur & Humidity x2
	* MPL115A2 Barometer
	* P82B96 I2C Shifter
* Node Js/express Js server
* MySQl database.
	
## Setup
Server setup

you should have Node Js installed on your machine as well as NPM.
```
$ cd src/server
$ npm install
$ npm start
```


## Authors

* **Remy Chatel**  - [Github](https://github.com/RemyChatel)

* **Maysara Alhindi**  - [Github](https://github.com/MaysaraHolmes)

* **Trine Ødegård Olsen**  - [Github](https://github.com/trineoo)


