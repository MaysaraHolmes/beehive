// initing the UDP connection

var dgram = require('dgram');
var udpserver = dgram.createSocket('udp4');

udpserver.on('listening', function () {
    var address = udpserver.address();
    console.log('UDP Server listening on ' + address.port);
});

udpserver.bind(33333);

module.exports = udpserver;