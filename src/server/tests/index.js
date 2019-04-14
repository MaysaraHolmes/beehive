var request = require("request");
var expect = require('chai').expect;

var API_URL = "http://localhost:80/";

it('should return 200 with HTML response', function (done) {
  request.get(API_URL, function (err, res, body){
    expect(res.statusCode).to.equal(200);
    expect(res.headers['content-type']).to.equal('text/html; charset=utf-8');
    done();
  });
});
