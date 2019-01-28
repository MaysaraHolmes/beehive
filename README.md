** This repository is under construction**

<p align="center">
	<a href="https://beehiveproject.herokuapp.com/"><img src="https://github.com/MaysaraHolmes/beehive/blob/master/bee_pic.jpg" title="Bee" alt="FVCproductions" width="500" height="500" ></a><\p>




# Real-Time Beehive Monitoring

Monitoring your beehive and get real-time meassurement on the webpage
https://beehiveproject.herokuapp.com/


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

* **Rêmy Chatel**  - [Github](https://github.com/RemyChatel)

* **Maysara Alhindi**  - [Github](https://github.com/MaysaraHolmes)

* **Trine Ødegård Olsen**  - [Github](https://github.com/trineoo)


