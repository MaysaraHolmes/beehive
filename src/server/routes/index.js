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
    sql.getData().then((result)=>{
        console.log("done reading data");
        console.log(result);
        var recentData = result.length==0 ? {} : result[result.length-1];
        
        var otemp = [];
        var itemp = [];
        var ohum = [];
        var ihum  = [];
    
        for( var i = 0;i<result.length;i++){
            console.log(result[i]);
            otemp.push({x:((i+1)*10),y:result[i].otemp});
            itemp.push({x:((i+1)*10),y:result[i].itemp});
            ohum.push({x:((i+1)*10),y:result[i].ohum});
            ihum.push({x:((i+1)*10),y:result[i].ihum});
        }
    
        res.render('index', {
            recentData:recentData,
            otemp: encodeURIComponent(JSON.stringify(otemp)),
            itemp:encodeURIComponent(JSON.stringify(itemp)),
            ihum:encodeURIComponent(JSON.stringify(ihum)),
            ohum:encodeURIComponent(JSON.stringify(ohum)),
            title:"BeeHive" 
        });
    
    }).catch((err)=>{
        console.log(err);
    });
});

router.post('/alarm',function (req,res) {
    console.log("alarm");
    res.send(200); 
});

// router.get('/test',(req,res)=>{
//     var io = require('../helpers/socket')();
//     io.emit('new_data', { hello: 'world' });
//     res.sendStatus(200);
// });

router.post('/data',(req,res)=>{
    var validData = validateData(req.body);
    if(validData==null){
        console.log("not valid data");
        return;
    }
    sql.insertData(validData).then((result)=>{
        console.log("done inserting data");
        io.emit('new_data', { resul:t result });
        res.sendStatus(200);
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
