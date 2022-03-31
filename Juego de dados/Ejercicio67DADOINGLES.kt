import kotlin.random.Random

// Ultimo ejercicio de Kotlin para divertise!!!
// ********* Ej 67  *********
// Juego de dados (Pase Ingles)
// Desarroyar para poder realizar este juego teniendo en cuenta el valor de los dados
// Tambien subo el PDF -> de la clase
// Cantidad de tiros realizados hasta ganar por partido.
// Contar cuantas jugadas de realizaron tanto para ganar o perder.

class PaseIngles{
    var dados :Int = 0
    var cantTirosRealizados :Int = 0
    var cantJugadasRealizadas :Int = 0

    fun inicializar(dados :Int, cantTirosRealizados :Int, cantJugadasRealizadas :Int){
        this.dados = dados
        this.cantTirosRealizados = cantTirosRealizados
        this.cantJugadasRealizadas = cantJugadasRealizadas
    }
    fun tiradaDados() :Int{
        var sumaDados = 0
        sumaDados = 2 + Random.nextInt(10)
        print("\nTirando los dados...\n\nLos dados fueron lanzados y dieron de resultado: $sumaDados")
        return sumaDados
    }
    fun contadorTiros(tirosRealizados :Int) :Int{
        var tirosTotales :Int = 1
        tirosTotales += tirosRealizados
        print("\nTiros realizados: $tirosTotales")
        return tirosTotales
    }
    fun contadorJugadas(){

    }
}

fun main(){
    var juegoPaseIngles :PaseIngles = PaseIngles()
    var aceptar :String = ""
    var dados :Int = 0
    var cantTirosRealizados :Int = 1
    var cantJugadasRealizadas :Int = 0
    print("\nBienvenido al juego: PASE INGLES!!\n\n¿Desea comenzar a jugar?\nEscriba si para empezar o no para terminar:  ")
    aceptar = readLine()!!.toString()
    while (aceptar != "si" && aceptar != "no"){
        print("Error!! Ingrese si para comenzar a jugar o ingrese no para terminar el juego!:  ")
        aceptar = readLine()!!.toString()
    }
    while (aceptar == "si"){
    juegoPaseIngles.inicializar(dados, cantTirosRealizados, cantJugadasRealizadas)
    dados = juegoPaseIngles.tiradaDados()
    cantTirosRealizados = juegoPaseIngles.contadorTiros(cantTirosRealizados)



        print("\n\n¿Desea volver a jugar?\nEscriba si para empezar o no para terminar el juego:  ")
        aceptar = readLine()!!.toString()
        while (aceptar != "si" && aceptar != "no"){
            print("Error!! Ingrese si para volver a jugar o ingrese no para terminar el juego!:  ")
            aceptar = readLine()!!.toString()
        }
    }
    print("\n\nEl juego a finalizado!! gracias por jugar!\n")
}