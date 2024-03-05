
 var player1 = document.getElementById("player1");
 var yellow_cards = document.getElementById("yellow_cards");
 

function init()
{
    player1.style.position = "relative";
    player1.style.left = "16vh";  //inicio = 16
    player1.style.top = "-60vh";


   
    //const posTop = parseInt(player1.style.top);
    
}


window.addEventListener("load", init());


document.getElementById("button_right").addEventListener('click', function()
{
    player1.style.left = parseInt(player1.style.left) + 16 + "vh";
    console.log(player1.style.left);

});
document.getElementById("button_left").addEventListener('click', function()
{
    player1.style.left = parseInt(player1.style.left) - (16) + "vh";
    console.log(player1.style.left);


});

document.getElementById("button_top").addEventListener('click', function()
{
    player1.style.top = parseInt(player1.style.top) + (-16) + "vh";
    console.log(player1.style.top);
});

document.getElementById("button_bottom").addEventListener('click', function()
{
    player1.style.top = parseInt(player1.style.top) + 16 + "vh";
    console.log(player1.style.top);
});



document.getElementById("button").addEventListener('click', function()
{
    var random = sortearNumero();
    exibirFaceSorteada(random);

});




function sortearNumero()
{
    var random = Math.floor(Math.random() * 6 + 1);
    return random;
}

function exibirFaceSorteada(random)
{
    random = sortearNumero();   
    switch(random)
    {
        case 1: 
            document.getElementById("dot").src = "images/face1.png";
            break;
        case 2: 
            document.getElementById("dot").src = "images/face2.png";
            break;
        case 3: 
            document.getElementById("dot").src = "images/face3.png";
            break;
        case 4: 
            document.getElementById("dot").src = "images/face4.png";
            break;
        case 5: 
            document.getElementById("dot").src = "images/face5.png";
            break;
        case 6: 
            document.getElementById("dot").src = "images/face6.png";
            break;
        default:
            break;
    }
}

/*function verificaStart()
{
    if(start == 0)
    {
        return true;
    }
}

verificaStart();
if(verificaStart() == true)
{
    inicioPlayer(player1, player2);
}*/







   
  
