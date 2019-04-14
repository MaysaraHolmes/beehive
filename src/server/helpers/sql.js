// SQL queries

var connection = require('./db_connection');
var Promise = require('promise');


// get the beehive readings 
exports.getData = function (argument) {
	return new Promise((resolve,reject)=>{
		connection.query("SELECT * FROM readings",(err,result,fields)=>{
			if(err) return reject(err);
			resolve(result);
		});
	});
}


// insert new readings to the database
exports.insertData = function(data){
	return new Promise((resolve,reject)=>{
		var sql = "INSERT INTO readings (itemp,ihum,otemp,ohum,pressure) VALUES ("+data.itemp+","+data.ihum+","+data.otemp+","+data.ohum+","+data.pressure+")";
		connection.query(sql,(err,result)=>{
			if(err) return reject(err);
			resolve(data);
		})
	});
}


// insert new subscriber email to the database
exports.insertEmail = function(email){
	console.log(email);
	return new Promise((resolve,reject)=>{
		var sql = 'INSERT INTO emails (email) VALUES ("'+email+'")';
		connection.query(sql,(err,result)=>{
			if(err) return reject(err);
			resolve(result);
		})
	});
}


// get subscribers emails
exports.getEmails = function(){
	return new Promise((resolve,reject)=>{
		connection.query("SELECT * FROM emails",(err,result,fields)=>{
			if(err) return reject(err);
			resolve(result);
		});
	});
}