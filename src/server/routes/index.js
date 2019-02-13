var express = require('express');
var router = express.Router();
var sql = require("../helpers/sql");

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
    var data = {
        it:readings.inside.temp[0],
        ih:readings.inside.humidity[0],
        ot:readings.outside.temp[0],
        oh:readings.outside.humidity[0]
    };
    sql.getData().then((result)=>{
        console.log("done reading data");
        console.log(result);
    }).catch((err)=>{
        console.log(err);
    });
    res.render('index', {data: data, title:"BeeHive" });
});

router.post('/alarm',function (req,res) {
    console.log("alarm");
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
    if(data.otemp && && Number.isInteger(data.otemp)){
        validData.otemp = data.otemp;
    }
    if(data.ohum && && Number.isInteger(data.ohum)){
        validData.ohum = data.ohum;
    }
    if(validData.otemp && validateData.ohum && validateData.itemp && validateData.ihum){
        return validateData;
    }
    return null;
}

module.exports = router;
