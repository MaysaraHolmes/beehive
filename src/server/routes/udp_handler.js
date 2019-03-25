var sql = require("../helpers/sql");

exports.insertData = function(data){
    console.log("posting data");
    console.log(data.toString('utf8'));
    var validData = validateData(data.toString('utf8'));
    if(validData==null){
        console.log("not a valid data");
        return;
    }
    sql.insertData(validData).then((result)=>{
        console.log("done inserting data");
        console.log(result);
        var io = require('../helpers/socket')();
        io.emit('new_data', { result:result });
    }).catch((err)=>{
        console.log(err);
    });
}

exports.sendAlarm = function(data){
    // TODO
}
    
function validateData(data) {
    var data_array = data.split(" ");
    var validData = {};
    if(data_array[0] && Number(data_array[0])){
        validData.itemp = data_array[0];
    }
    if(data_array[1] && Number(data_array[1])){
        validData.ihum = data_array[1];
    }
    if(data_array[2] &&Number(data_array[2])){
        validData.otemp = data_array[2];
    }
    if(data_array[3] && Number(data_array[3])){
        validData.ohum = data_array[3];
    }
    if(data_array[4] && Number(data_array[4])){
        validData.pressure = data_array[4];
    }

    if(validData.otemp && validData.ohum && validData.itemp && validData.ihum && validData.pressure){
        return validData;
    }
    return null;
}
