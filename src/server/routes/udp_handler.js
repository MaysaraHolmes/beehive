// handling the UDP requests from the PI

var sql = require("../helpers/sql");
var emails_sender = require('../helpers/email_sender');


// insert new readings
exports.insertData = function(data){

    var validData = validateData(data.toString('utf8'));
    if(validData==null){
        console.log("not a valid data");
        return;
    }
    sql.insertData(validData).then((result)=>{
        var io = require('../helpers/socket')();
        io.emit('new_data', { result:result });
        if(result.ihum > 60){
            console.log("alarm !!");
            sql.getEmails().then((results)=>{
                for(var i =0;i<results.length;i++){
                    emails_sender.send_email(results[i].email);
                }
            }).catch((err)=>{
                console.log(err);
            });   
        }
    }).catch((err)=>{
        console.log(err);
    });

}

// check if the readings are valid before inserting them to the database    
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
