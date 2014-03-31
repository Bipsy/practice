var fs = require('fs');

function route(pathname, response) {
	abs = process.cwd() + "/web";
	pieces = pathname.split('/');
	var filename;
	if (pieces[pieces.length-1] == "") {
	    pathname += "index.html"
		filename = "index.html"
    } else {
		filename = pieces[pieces.length-1];
	}

	pieces = filename.split('.');
	var type;
	switch (pieces[pieces.length-1]) {
		case "txt":		type = "text/plain";
						break;
		case "html":	type = "text/html";
						break;
		case "jpg":		type = "image/jpeg";
						break;
		case "gif":		type = "image/gif";
						break;
		case "png":		type = "image/png";
						break;
		case "pdf":		type = "application/pdf";
						break;
		default:		type = "text/plain";
						break;
	}

	fs.readFile(abs+pathname, function (err, data) {
		if (!err) {	
			response.writeHead(200, {"Content-Type": type, 
									 "Content-Length": data.length,
									 "Server": "Nodejs"});
			response.write(data);
			response.end();
		} else {
			message = "Not Found";
			response.writeHead(404, {"Content-Type": "text/plain",
									 "Content-Length": message.length,
									 "Server": "Nodejs"});
			response.write(message);
			response.end();
			console.log(err);
		}
	});
}

exports.route = route;
