

// display stored message from the JSON object 
let existingCard = {
        front: ["大知は愚の如し (taichi ha gu no gotoshi)", 
            ], // an array that stores foreign language expression (with romanized pronounciation)
        back: ["Stay Hungry, Stay Foolish",], // an array that stores corresponding English translation
        annotation: ["《蘇軾「賀歌欧陽少司致仕啓」から》真の知者は、知識や知恵をむやみにひけらかすようなことはしないので、一見愚者のようにみえる。 ",],
        // an array that stores corresponding explanation

    print: function () {
            var text= "Sentence of the Day:  ";
            for (var i = 0; i < this.front.length; i++) {
                text+=  "  " + this.front[i] + "  ";
            }
                text+= "="
            for (var j = 0; j < this.back.length; j++) {
                text+=  "  " + this.back[j] + "  ";
            }
                text+= ""; 
            return text;
        } 
   }
display = existingCard.print();
document.getElementById("displayMessage").innerHTML = display;

// alert the user the submission
function submitContent() {
    var msg = "test";
    msg = "Your word: " + document.getElementById("newWord").value;
    msg += "; Translation:" + document.getElementById("translation").value;
    alert(msg);
}

// clear input;
function clear() {
    document.getElementById("newWord").value = "";
    document.getElementById("translation").value = "";
}

// add input for Card One
function addContent() {
    storeCard();
    document.getElementById("flashcardOutput").innerHTML = display;
}

// clear input for Card One
function clearContent() {
    document.getElementById("flashcardOutput").innerHTML = "";
}

// add input for Card Two
function addContentTwo() {
    storeCard();
    document.getElementById("flashcardOutputTwo").innerHTML = display;
}

// clear input for Card Two
function clearContentTwo() {
    document.getElementById("flashcardOutputTwo").innerHTML = "";
}

// add input for Card Three
function addContentThree() {
    storeCard();
    document.getElementById("flashcardOutputThree").innerHTML = display;
}

// clear input for Card Three
function clearContentThree() {
    document.getElementById("flashcardOutputThree").innerHTML = "";
}

// clear input for all cards
function deleteAll() {
    clearContent();
    clearContentTwo();
    clearContentThree();
}

// turn input flashcard data into a JSON object and print out the string
function storeCard(){
    //  Makes an HTMLElement object and a string of that element
    var front = document.getElementById('newWord').value;
    var back = document.getElementById("translation").value;
    //  Makes a JSON object 
    let card = { 
        front: front,
        back: back,
        print: function () {
            return front + back;
        } };  
    display = card.print();
}


 

