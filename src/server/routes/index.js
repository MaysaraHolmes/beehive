var express = require('express');
var router = express.Router();
var sql = require("../helpers/sql");

/* GET home page. */
router.get('/', function(req, res) {
    sql.getData().then((result)=>{
        console.log("done reading data");
        var recentData = result.length==0 ? {} : result[result.length-1];
        
        var otemp = [];
        var itemp = [];
        var ohum = [];
        var ihum  = [];
    
        for( var i = 0;i<result.length;i++){
            otemp.push({x:((i+1)),y:result[i].otemp});
            itemp.push({x:((i+1)),y:result[i].itemp});
            ohum.push({x:((i+1)),y:result[i].ohum});
            ihum.push({x:((i+1)),y:result[i].ihum});
        }

        console.log(otemp);
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

router.post('/email_sub',function(req,res){
    if(!validateEmail(req.body.email)){
        return res.sendStatus(402);
    }
    sql.insertEmail(req.body.email).then(()=>{
        res.sendStatus(200);
    }).catch((err)=>{
        console.log(err);
        res.sendStatus(500);
    });
}); 

function validateEmail(email) {
    var re = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
    return re.test(String(email).toLowerCase());
}

module.exports = router;
