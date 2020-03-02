var serial;           // variable to hold an instance of the serialport library
var portName = 'COM3' // name of serialport
var datastring;       // data string coming in over serial

var dataarray = [0, 0]; // declare dataarray

var minWidth = 600;   // set min width for canvas
var minHeight = 400;  // set min hieght for canvas
var width, height;    // actual width and height for the sketch

function setup() {
  serial = new p5.SerialPort();          // make a new instance of the serialport library
  serial.on('list', printList);          // set a callback function for the serialport list event
  serial.on('connected', serverConnected); // callback for connecting to the server
  serial.on('open', portOpen);           // callback for the port opening
  serial.on('data', serialEvent);        // callback for when new data arrives
  serial.on('error', serialError);       // callback for errors
  serial.on('close', portClose);         // callback for the port closing

  serial.list();                         // list the serial ports
  serial.open(portName);                 // open a serial port

  // set the canvas to match the window size
  if (window.innerWidth > minWidth) {
    width = window.innerWidth;
  } else {
    width = minWidth;
  }
  if (window.innerHeight > minHeight) {
    height = window.innerHeight;
  } else {
    height = minHeight;
  }
  // set up actual canvas
  createCanvas(width, height);
}

// following functions print the serial communication status to the console for debugging
function printList(portList) {
  for (var i = 0; i < portList.length; i++) {
    print(i + " " + portList[i]);
  }
}
function serverConnected() {
  print('connected to server.');
}
function portOpen() {
  print('the serial port opened.')
}
function serialError(err) {
  print('Something went wrong with the serial port. ' + err);
}
function portClose() {
  print('The serial port closed.');
}
// read data from serial
function serialEvent() {
  if (serial.available()) {              // check if there is data over serial
	datastring = serial.readLine();        // read data string line by line
	var newarray;
	try {
  	  newarray = JSON.parse(datastring); // try parse the serial with JSON
  	} catch(err) {
      	console.log(err);                // log JSON error to console
	}
	if (typeof(newarray) == 'object') {
  	  dataarray = newarray;              // store received data in an array 
	}
	console.log("got back " + datastring); // log received array to console
  }
}
// serial communication to Arduino
function keyPressed() {
  console.log("writing key");            // log event to console
	serial.write(key);                     // send pressed key over serial
}

// draw square canvas based on Arduino data
function draw() {
  background(0x08, 0x16, 0x40);          // set background colour
  fill(255);                             // set fill colour
  text("PRESS ANY KEY TO TURN OFF LED", 55, 30); // write text on canvas
	rect(dataarray[0],dataarray[1],50,50); // draw 50x50 square whose position is controlled by Arduino data
}