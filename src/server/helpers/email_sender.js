var nodemailer = require("nodemailer");
var Promose = require("promise");

var create_test_account = new Promise(function (resolve,reject) {
	nodemailer.createTestAccount(function (err,account) {
		if(err){
			reject(err);
		}else{
			resolve(account);
		}
	});
});

var send_mail = function (transporter,mailOptions) {
	return new Promise(function (resolve,reject) {
		transporter.sendMail(mailOptions,(err,success)=>{
			if(err){
				reject(err);
			}else{
				resolve();
			}
		});
	});
}

create_test_account.then((account)=>{
	
	// create reusable transporter object using the default SMTP transport
	var transporter = nodemailer.createTransport({
	host: "smtp.ethereal.email",
	port: 587,
	secure: false, // true for 465, false for other ports
	auth: {
	  user: account.user, // generated ethereal user
	  pass: account.pass // generated ethereal password
	}
	});

	// setup email data with unicode symbols
	var mailOptions = {
	from: '"someonewanttohackyou@gmail.com', // sender address
	to: "maysaradeveloper@gmail.com", // list of receivers
	subject: "Hello ✔", // Subject line
	text: "Hello world?", // plain text body
	html: "<b>Hello world?</b>" // html body
	};

	send_mail(transporter,mailOptions).then(()=>{
		console.log("email sent successfully !")
	}).catch((err)=>{
		console.log(err);
	});

}).catch((err)=>{
	console.log(err);
});


console.log("Message sent: %s", info.messageId);
// Preview only available when sending through an Ethereal account
console.log("Preview URL: %s", nodemailer.getTestMessageUrl(info));
