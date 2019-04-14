// initing the DB connection and read values from the evnironment and creating tables

var mysql = require('mysql');

var con = mysql.createConnection({
  host:process.env.DB_HOST,
  user: process.env.DB_USER,
  password: process.env.DB_PASS,
  database:process.env.DB_NAME
});

con.connect(function(err) {
  if (err) throw err;
  console.log("Database is connected successfully");
  
  var readings_table = "CREATE TABLE if not exists readings (itemp float,ihum float,otemp float,ohum float,pressure float)";
  var emails_table = "CREATE TABLE if not exists emails (email varchar(50))";

  con.query(readings_table, function (err, result) {
    if (err) throw err;
  });
  con.query(emails_table, function (err, result) {
	if (err) throw err;
  });

});

// to keep the connection alive
setInterval(function () {
    con.query('SELECT 1');
}, 5000);


module.exports = con;
