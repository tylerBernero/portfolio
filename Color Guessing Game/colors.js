/*Author: Tyler Bernero
Date Created: December 2018
Course: Web Developer Bootcampt (Udemy)
*/

// NOTE: Change all style.background to style.backgroundColor
// It is compatible with more browsers

//Variables
var numSquares = 6;
var colors = generateRandomColors(numSquares)
var pickedColor = pickColor();
var colorDisplay = document.getElementById("colorDisplay");
var messageDisplay = document.getElementById("message");
var topScreen = document.getElementById("top");
var resetButton = document.querySelector("#reset");
var easyButton = document.querySelector("#easy");
var hardButton = document.querySelector("#hard");
var modeButtons = document.querySelectorAll(".mode");
var h1 = document.querySelector("h1");

colorDisplay.textContent = pickedColor;

var squares = document.querySelectorAll(".square");


//Event Listeners
for(var i = 0; i < modeButtons.length; i++){
	modeButtons[i].addEventListener("click", function(){
		modeButtons[0].classList.remove("selected");
		modeButtons[1].classList.remove("selected");

		this.classList.add("selected");
		if(this.textContent === "Easy"){
			numSquares = 3;
		}
		else{
			numSquares = 6;
		}

		reset();
	});
}


for(var i = 0; i < squares.length; i++){
	//add initial color
	squares[i].style.backgroundColor = colors[i];

	//add click listeners
	squares[i].addEventListener("click", function(){
		//grab color of clicked square and compare color to pickedColor
		var clickedColor = this.style.backgroundColor;

		//Compare to picked color
		if(clickedColor === pickedColor){
			messageDisplay.textContent = "Correct!"

			changeColors(clickedColor);

			h1.style.backgroundColor = clickedColor;	//This doesn't work anymore?
			resetButton.textContent = "Play Again?";

		}
		else{
			this.style.backgroundColor = "#232323";
			messageDisplay.textContent = "Try again";
		}
	});
}

resetButton.addEventListener("click", function(){
	reset();
});

//Functions

function changeColors(color){
	for(var i = 0; i < squares.length; i++){
		squares[i].style.backgroundColor = color;
	}
}

function pickColor(){
	var randomColor = Math.floor(Math.random() * colors.length);
	return colors[randomColor];
}

function generateRandomColors(num){
	//create array
	var arr = [];

	//add num random colors to array
	for(var i = 0; i < num; i++){
		//get random color and push into array
		arr.push(randomColor());
	}

	//return array
	return arr;
}

function randomColor(){
	//pick random values for red, blue, and green between 0-255
	var red = Math.floor(Math.random() * 255 + 1);
	var blue = Math.floor(Math.random() * 255 + 1);
	var green = Math.floor(Math.random() * 255 + 1);

	// return color;
	return "rgb(" + red + ", " + blue + ", " + green + ")";
}

function reset(){
	//generate all new colors
	colors = generateRandomColors(numSquares);

	//pick a new random color from array
	pickedColor = pickColor();
	colorDisplay.textContent = pickedColor;
	topScreen.style.backgroundColor = "steelblue";

	//change colors of squares
	for(var i = 0; i < squares.length; i++){
		if(colors[i]){
			squares[i].style.display = "block";
			squares[i].style.backgroundColor = colors[i];
		}
		else{
			squares[i].style.display = "none";
		}
	}

	resetButton.textContent = "New Colors";
	messageDisplay.textContent = "";
}