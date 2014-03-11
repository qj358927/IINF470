/*import the johnny5 module and create a board object*/
var five = require("johnny-five"), board = new five.Board();
/*declare boolean for board initialization*/
var boardReady = false;
/*delcare vars for the yellow & red LEDs*/
var yellow,red;
/*on event of board being ready*/
/*setflag to true init the LEDs and prompt for input*/
board.on("ready",function(){ 
    boardReady = true;         
    yellow = new five.Led(6);
    red    = new five.Led(8);    
});

ask();

function ask(){
    /*set wakeup stdin stream*/
    process.stdin.resume();
    /*prompt for color to light up*/
    process.stdout.write("color?: ");
    /*read in*/
    process.stdin.once('data', function(text) {
	process.stdout.write("\n");
	text = text.toString().trim();
	/*if r then strobe red lights*/
	if (text == 'r' && boardReady) {
	    red.strobe(100);
	    yellow.off();
	    ask();
	/*if y then light yellow lights*/
	}else if(text =='y' && boardReady){
	    yellow.on();
	    red.off();
	    ask();
	}
	/*if board not ready poll*/
	else if(!boardReady)
	    ask();
	/*on unrecognized input quit*/
	else
	    process.exit();
    });
}
