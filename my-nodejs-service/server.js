const express = require('express');
const app = express();
const path = require('path')
var uuid = require('node-uuid');

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
});

app.post('/location', (req, res) => {
  res.render('map');
});

// Listen to the App Engine-specified port, or 8080 otherwise
const PORT = process.env.PORT || 8080;
app.listen(PORT, () => {
  console.log(`Server listening on port ${PORT}...`);
});