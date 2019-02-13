var mysql = require('mysql');

var con = mysql.createConnection({
  host: "localhost",
  user: "test",
  password: "passpass",
  database:"beehive"
});

con.connect(function(err) {
  if (err) throw err;
  console.log("Connected!");
});

module.exports = con;
