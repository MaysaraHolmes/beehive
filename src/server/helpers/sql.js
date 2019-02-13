var connection = require('./db_connection');
var Promise = require('promise');

exports.getData = function (argument) {
	return new Promise((resolve,reject)=>{
		connection.query("SELECT * FROM readings",(err,result,fields)=>{
			if(err) return reject(err);
			resolve(result);
		});
	});
}

exports.insertData = function(data){
	return new Promise((resolve,reject)=>{
		var sql = "INSERT INTO readings (itemp,ihum,otemp,ohum) VALUES ("+data.itemp+","+data.ihum+","+data.otemp+","+data.ohum+")";
		connection.query(sql,(err,result)=>{
			if(err) return reject(err);
			resolve(data);
		})
	});
}
