// this script is used to server the front-end to the client side, also to handel the requests from the client side

var express = require('express');
var router = express.Router();
var sql = require("../helpers/sql");


// get the readings from the database and return them in JSON format
router.get('/', function(req, res) {
    
    sql.getData().then((result)=>{
        var recentData = result.length==0 ? {} : result[result.length-1];
        
        var otemp = [];
        var itemp = [];
        var ohum = [];
        var ihum  = [];
        var pressure = [];

        for( var i = 0;i<result.length;i++){
            otemp.push({x:((i+1)),y:result[i].otemp});
            itemp.push({x:((i+1)),y:result[i].itemp});
            ohum.push({x:((i+1)),y:result[i].ohum});
            ihum.push({x:((i+1)),y:result[i].ihum});
            pressure.push({x:((i+1)),y:result[i].pressure});
        }

        res.render('index', {
            recentData:recentData,
            otemp: encodeURIComponent(JSON.stringify(otemp)),
            itemp:encodeURIComponent(JSON.stringify(itemp)),
            ihum:encodeURIComponent(JSON.stringify(ihum)),
            ohum:encodeURIComponent(JSON.stringify(ohum)),
            pressure:encodeURIComponent(JSON.stringify(pressure)),
            title:"BeeHive" 
        });
    
    }).catch((err)=>{
        console.log(err);
    });

});


// add new subscriber email to the database
router.post('/email_sub',function(req,res){
    if(!validateEmail(req.body.email)){
        return res.sendStatus(406);
    }
    sql.insertEmail(req.body.email).then(()=>{
        res.sendStatus(200);
    }).catch((err)=>{
        console.log(err);
        res.sendStatus(500);
    });
}); 


// check the email format if it is correct
function validateEmail(email) {
    var re = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
    return re.test(String(email).toLowerCase());
}

module.exports = router;
