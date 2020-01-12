const express = require('express');
const app = express();
const path = require('path')
var uuid = require('node-uuid');
var fs = require('fs');

app.use(express.static(path.join(__dirname, 'public')))
app.use(express.urlencoded({extended:false}))
app.use(express.json())
app.set('views', path.join(__dirname, 'views'))
app.set('view engine', 'ejs')

app.get('/', (req, res) => {
  res.render('meetwhere');
});

app.post('/create', (req, res) => {

  var randomID = uuid.v4();
  console.log(randomID);
  res.render('link');

  let name = req.body.name;
  let event = req.body.event;
  let date = req.body.date;
 	let location = req.body.location;

 	var obj = {};

 	fs.readFile('meetwhere.json', 'utf8', function(err, data){
 		if(err){
 			console.log(err);
 		}
 		
 		if(data == ""){
 			let array = [{"time": date},{"name":name, "location": location}];
 			obj[event] = array; 			
 			fs.writeFileSync('meetwhere.json', JSON.stringify(obj));
 		}
 		else{
 			let array = [{"time": date},{"name":name,"location": location}];
 			obj = JSON.parse(data);
 			obj[event] = array;
 			fs.writeFileSync('meetwhere.json', JSON.stringify(obj));
 		}
 	});
});

// Listen to the App Engine-specified port, or 8080 otherwise
const PORT = process.env.PORT || 8080;
app.listen(PORT, () => {
  console.log(`Server listening on port ${PORT}...`);
});