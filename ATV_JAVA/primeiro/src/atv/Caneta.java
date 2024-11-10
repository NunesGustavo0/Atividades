package atv;

public class Caneta {
    public String cor;
    public String modelo;
    float ponta;
    int carga;
    boolean tampada;


    void status(){
        System.out.println("\n====Caneta====");
        System.out.println("Cor: " + this.cor);
        System.out.println("Modelo: " + this.modelo);
        System.out.println("Ponta: " + this.ponta);
        System.out.println("Carga: " + this.carga);
        System.out.println("Tampada: " + this.tampada);
    }

    void rabiscar(){
        this.carga = carga - 2;
    }

    void tampar(){
        this.tampada = true;
    }

    void destampar(){
        this.tampada = false;
    }

}
