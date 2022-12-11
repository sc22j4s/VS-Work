
    let str_input = "hello World#";
    const mcode = {
      'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.',
  
      'G': '--.', 'H': '....', 'I': '..', 'J': '.---', 'K': '-.-', 'L': '.-..',
  
      'M': '--', 'N': '-.', 'O': '---', 'P': '.--.', 'Q': '--.-', 'R': '.-.',
  
      'S': '...', 'T': '-', 'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-',
  
      'Y': '-.--', 'Z': '--..', ' ': ' ', '0': '-----',
  
      '1': '.----', '2': '..---', '3': '...--', '4': '....-', '5': '.....',
  
      '6': '-....', '7': '--...', '8': '---..', '9': '----.',
  
      '&': '.-...', "'": '.----.', '@': '.--.-.', ')': '-.--.-', '(': '-.--.',
  
      ':': '---...', ',': '--..--', '=': '-...-', '!': '-.-.--', '.': '.-.-.-',
  
      '-': '-....-', '+': '.-.-.', '"': '.-..-.', '?': '..--..', '/': '-..-.'
    }
  
    /*
    write your JavaScript codes below
    
    */
    // lowercase letters translated into uppercase
  
    str_input = str_input.toUpperCase();
    
  
  
  
    // output string variable
  
    var str_output = ""
    



    // encoding
    // valid input check

    var valid_input = true; 
    for (var i = 0; i < str_input.length; i++){
      if (!(str_input.charAt(i) in mcode) && str_input.charAt(i) != ' ') {

        //print to textbox
        //console.log("Invalid input")
        valid_input = false; 

      }

    }
    if(valid_input){
      for (var i = 0; i < str_input.length; i++) {
        // check if char is in dict
        if (str_input.charAt(i) in mcode) {
          // append to output string with space
          str_output += mcode[str_input.charAt(i)] + " ";
        }
        // key not in string 
        else { 
          //console.log("");
        }
    
      }

      // remove last character
      str_output = str_output.slice(0, str_output.length-1)
    }

    
    
    // output to textbox?? 
    //console.log(str_output);
  
  
  
    // decoding

    // valid input check 
    str_input = '.... . .-.. .-.. ---   .-- --- .-. .-.. -..';
    console.log(str_input);
    valid_input = true; 
    str_array = str_input.split(' ');
    str_output = ""
    
    // check if input is valid
    for(var i = 0; i < str_array.length; i++){
      console.log("'" + str_array[i] + "'");
      // if value in dict
      if(!(Object.values(mcode).includes(str_array[i])) && str_array[i] != ''){
        //console.log("bad input " + str_array[i]);
        //alert("Invalid input");
        valid_input = false;
      }
    }

    if(valid_input){
      for(var i = 0; i < str_array.length; i++){
        if(str_array[i] != ''){
          str_output += Object.keys(mcode).find(key => mcode[key] === str_array[i]);
          
        }
        else{
          str_output += ' ';
        }
      }
    }
    console.log(str_output)

    
  
  
  

