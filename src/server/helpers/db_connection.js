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
});

// to keep the connection alive
setInterval(function () {
    con.query('SELECT 1');
}, 5000);


module.exports = con;
