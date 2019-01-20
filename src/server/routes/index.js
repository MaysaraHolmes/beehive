var express = require('express');
var router = express.Router();

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
        iw:readings.inside.weight[0],
        ot:readings.outside.temp[0],
        oh:readings.outside.humidity[0]
    };
    res.render('index', {it:data.it, data: data,title:"BeeHive" });
});

router.get('/details/it',(req,res)=>{
    res.render('details',{data:readings.inside.temp});    
});
router.get('/details/ih',(req,res)=>{
    res.render('details',{data:readings.inside.humidity}); 
});
router.get('/details/iw',(req,res)=>{
    res.render('details',{data:readings.inside.weight}); 
});
router.get('/details/ot',(req,res)=>{
    res.render('details',{data:readings.outside.temp}); 
});
router.get('/details/oh',(req,res)=>{
    res.render('details',{data:readings.outside.humidity}); 
});

module.exports = router;
