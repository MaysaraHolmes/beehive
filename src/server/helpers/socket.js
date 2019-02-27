const socketIo = require('socket.io');

let io;

module.exports = function(server) {
  if (server) {
    io = socketIo(server);
  }
  return io;
};
