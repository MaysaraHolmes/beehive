// this script is used to send emails 

var nodemailer = require("nodemailer");
var Promose = require("promise");

// create reusable transporter object using the default SMTP transport
var transporter = nodemailer.createTransport({
	service: 'gmail',
	auth: {
	  user: process.env.EMAIL, // generated ethereal user
	  pass: process.env.EMAIL_PASSWORD // generated ethereal password
	}
});


exports.send_email = function (account) {
	// setup email data with unicode symbols
	var mailOptions = {
		from: 'beehiveprojectglasgow@gmail.com', // sender address
		to: account, // list of receivers
		subject: "Beehive readings alaram!", // Subject line
		text: "The readings have reached a critical point, please check the website for more info" // plain text body
	};

	transporter.sendMail(mailOptions, function(error, info){
		if (error) {
			console.log(error);
		} else {
			console.log('Email sent: ' + info.response);
		}
	});

}