var ArrayPergunta = ("Qual é a soma dos ângulos internos de um triângulo", "Qual é a raiz quadrada de 144");
var ArrayResposta = (180, 12);


function capturarResposta()
{
    var form = document.getElementById ("formimi");
    var valor = form.elements["nome"].value;

    console.log("Nome: " + valor);

}