var express = require('express');
var router = express.Router();
var sql = require("../helpers/sql");
var socket = require('socket.io')();
const readings = {
    inside:{
        temp:[1,2,3],
        humidity:[10,2,3],
        weight:[12,2,3]
    },
    outside:{
        temp:[11,2,3],
        humidity:[13,2,3]
    }  
};

/* GET home page. */
router.get('/', function(req, res) {
    sql.getData().then((result)=>{
        console.log("done reading data");
        res.render('index', {data: result[0], title:"BeeHive" });
    }).catch((err)=>{
        console.log(err);
    });
});

router.post('/alarm',function (req,res) {
    console.log("alarm");
    res.send(200); 
});

router.get('/test',(req,res)=>{
    console.log("emiting data");
    console.log(socket);
    //socket.emit('new_data', { hello: 'world' });
    console.log("done emiting data");
    res.send(200);
});

router.post('/data',(req,res)=>{
    var validData = validateData(req.body);
    if(validData==null){
        console.log("not valid data");
        return;
    }
    sql.insertData(validData).then((result)=>{
        console.log("done inserting data");
        socket.emit('new_data', { hello: 'world' });
    }).catch((err)=>{
        console.log(err);
    });
});

function validateData(data) {
    var validData = {};
    if(data.itemp && Number.isInteger(data.itemp)){
        validData.itemp = data.itemp;
    }
    if(data.ihum && Number.isInteger(data.ihum)){
        validData.ihum = data.ihum;
    }
    if(data.otemp &&Number.isInteger(data.otemp)){
        validData.otemp = data.otemp;
    }
    if(data.ohum && Number.isInteger(data.ohum)){
        validData.ohum = data.ohum;
    }
    if(validData.otemp && validateData.ohum && validateData.itemp && validateData.ihum){
        return validateData;
    }
    return null;
}

module.exports = router;
