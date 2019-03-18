var express = require('express');
var path = require('path');
var favicon = require('static-favicon');
var bodyParser = require('body-parser');
var hbs = require('express-hbs');
var results = require('dotenv').config();

var udpserver = require('./helpers/udp_init');
var udphandler = require('./routes/udp_handler');
var index = require('./routes/index');

var app = express();

require('./helpers/db_connection');

app.engine('hbs', hbs.express4({
  partialsDir: __dirname + '/views'
}));
app.set('view engine', 'hbs');
app.set('views', __dirname + '/views');

app.use(favicon());
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', index);

udpserver.on('message', function (message, remote) {
    console.log(remote.address + ':' + remote.port +' - ' + message);
    udphandler.insertData(message);
});

/// catch 404 and forwarding to error handler
app.use(function(req, res, next) {
    var err = new Error('Not Found');
    err.status = 404;
    next(err);
});

/// error handlers

// development error handler
// will print stacktrace
if (app.get('env') === 'development') {
    app.use(function(err, req, res, next) {
        res.status(err.status || 500);
        res.render('error', {
            message: err.message,
            error: err
        });
    });
}

// production error handler
// no stacktraces leaked to user
app.use(function(err, req, res, next) {
    res.status(err.status || 500);
    res.render('error', {
        message: err.message,
        error: {}
    });
});

module.exports = app;
