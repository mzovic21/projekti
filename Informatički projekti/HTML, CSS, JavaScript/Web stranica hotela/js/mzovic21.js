document.addEventListener("DOMContentLoaded", ucitajStranicu);

function ucitajStranicu(){
    validirajObrazac();
    validirajUpit();
}

function validirajObrazac(){
    var password=document.getElementById("lozinka");
    document.addEventListener("submit");
    var date=document.getElementById("datum");
    password.addEventListener("keyup", validirajLozinku);
    date.addEventListener("keyup", validirajDatum);
}

function validirajUpit(){
    var text=document.getElementById("poruka");
    text.addEventListener("keyup", viselinijski);
}

function validirajLozinku(){
    
    var upisanaVrij=this.value;
    var greskaLozinke="";
    if(upisanaVrij==="" || upisanaVrij===undefined){
        greskaLozinke="Polje lozinke je ostalo prazno!";
        this.style="border: 2px solid red;";
        Event.preventDefault();
        return false;
    }else if(upisanaVrij.length<6){
        greskaLozinke="Lozinka ima premalo znakova, minimum znakova je 6!";
        this.style="border: 2px solid red;";
        event.preventDefault();
        return false;
    }else{
        greskaLozinke="";
        this.style="border: 2px solid green;";
    }
    var div=document.getElementById("greskaLozinke");
    div.innerText=greskaLozinke;
} 


function viselinijski(){
    var upisanaVrij=this.value;
    var greskaTeksta="";
    if(upisanaVrij==="" || upisanaVrij===undefined){
        greskaTeksta="Polje je ostalo prazno!";
        this.style="border: 2px solid red;";
    }else if(upisanaVrij.length<10){
        greskaTeksta="Polje ima premalo znakova, minimum znakova je 10!";
        this.style="border: 2px solid red;";
    }else if(upisanaVrij>1000){
        greskaTeksta="Polje ima previše znakova, maksimum znakova je 1000!";
        this.style="border: 2px solid red;";
    }else if(upisanaVrij==='!' || upisanaVrij==='?' || upisanaVrij==='#' || upisanaVrij==='<' || upisanaVrij==='>'){
        greskaTeksta="Korišteni su nedozvoljeni znakovi!";
        this.style="border: 2px solid red;";
    }else{
        greskaTeksta="";
        this.style="border: 2px solid green;";
    }
    var div=document.getElementById("greskaTeksta");
    div.innerText=greskaTeksta;
}


function provjeriSpecijalneZnakove(tekst) {
    var specijalniZnakovi = /[!#<>?]/;
    return !specijalniZnakovi.test(tekst);
  }
  
  // Primjer korištenja funkcije
  var tekst1 = "Ovo je ispravan tekst";
  var tekst2 = "Ovo je tekst s # specijalnim znakovima";
  
  console.log(provjeriSpecijalneZnakove(tekst1)); // true
  console.log(provjeriSpecijalneZnakove(tekst2)); // false
  